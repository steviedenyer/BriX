#include "Game.h"
#include "../examples/ExampleBase.h"
#include "XShader.h"
#include "XGeometry.h"
#include "XRasteriserState.h"
#include "XTransform.h"
#include "XModeller.h"

#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"

using namespace Eks;

class GameViewer
  {
public:
  GameViewer()
    {
    _t = 0.0f;
    }

  static void buildGeometry(Eks::Renderer *r, Eks::IndexGeometry *igeo, Eks::Geometry *geo)
    {
    Eks::Modeller m(Eks::Core::defaultAllocator());

    m.drawCube();

    auto drawSphere = [&m](float x, float y, float rad)
      {
      Eks::Transform tx = Eks::Transform::Identity();
      tx.translate(Eks::Vector3D(x, y, 0));

      m.setTransform(tx);
      m.drawSphere(rad);
      };


    QFile loadFile("/Volumes/User/BriX/Game/deets.json");

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    float scale = 0.01f;

    QByteArray saveData = loadFile.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(saveData));

    QJsonArray arr = doc.object()["actors"].toArray();
    for (int i = 0; i < arr.size(); ++i)
      {
      QJsonObject obj(arr[i].toObject());

      auto first = obj.begin();
      QJsonObject data = first.value().toObject();

      auto pos = data["pos"].toObject();
      auto x = pos["x"].toDouble();
      auto y = pos["y"].toDouble();

      auto attr = data["attr"].toObject();
      auto rad = attr["radius"].toDouble();

      drawSphere(x * scale, y * scale, rad * scale);
      }

    ShaderVertexLayoutDescription::Semantic semantics[] = {
      ShaderVertexLayoutDescription::Position,
      ShaderVertexLayoutDescription::Normal,
      ShaderVertexLayoutDescription::TextureCoordinate,
    };

    m.bakeTriangles(r, semantics, X_ARRAY_COUNT(semantics), igeo, geo);
    }

  void initialise(Renderer* r)
    {
    buildGeometry(r, &_igeo, &_geo);

    const char *fsrc =
        "#if X_GLSL_VERSION >= 130 || defined(X_GLES)\n"
        "precision mediump float;\n"
        "#endif\n"
        "in vec3 colOut;"
        "out vec4 outColour;"
        "void main(void)"
        "  {"
        "  outColour = vec4(abs(colOut), 1.0);"
        "  }";

    const char *vsrc =
        "layout (std140) uniform cb0 { mat4 model; mat4 modelView; mat4 modelViewProj; };"
        "layout (std140) uniform cb1 { mat4 view; mat4 proj; };"
        "in vec3 position;"
        "in vec2 textureCoordinate;"
        "out vec3 colOut;"
        "void main(void)"
        "  {"
        "  colOut = vec3(textureCoordinate, 0);"
        "  gl_Position = modelViewProj * vec4(position, 1.0);"
        "  }";

    ShaderVertexLayoutDescription desc[] =
      {
      ShaderVertexLayoutDescription(ShaderVertexLayoutDescription::Position,
        ShaderVertexLayoutDescription::FormatFloat3),
      ShaderVertexLayoutDescription(ShaderVertexLayoutDescription::Normal,
        ShaderVertexLayoutDescription::FormatFloat3),
      ShaderVertexLayoutDescription(ShaderVertexLayoutDescription::TextureCoordinate,
        ShaderVertexLayoutDescription::FormatFloat2),
      };

    ShaderVertexComponent::delayedCreate(_v, r, vsrc, strlen(vsrc), desc, X_ARRAY_COUNT(desc), &_layout);
    ShaderComponent::delayedCreate(_f, r, ShaderComponent::Fragment, fsrc, strlen(fsrc));

    ShaderComponent* comps[] = { &_v, &_f };
    const char *outputs[] = { "outColour" };
    Shader::delayedCreate(_shader, r, comps, X_ARRAY_COUNT(comps), outputs, X_ARRAY_COUNT(outputs));
    }

  void resize(Renderer*, xuint32 width, xuint32 height)
    {
    float aspect = (float)width / (float)height;

    _proj = TransformUtilities::perspective(Eks::degreesToRadians(45.0f), aspect, 0.1f, 100.0f);
    }

  void render(Renderer* r, Eks::FrameBuffer *buffer)
    {
    Eks::FrameBufferRenderFrame fr(r, buffer);

    r->setProjectionTransform(_proj);

    _t += 0.02f;

    Transform l = TransformUtilities::lookAt(
      Vector3D(sinf(_t) * 3.0f, 1.5f, cosf(_t) * 3.0f),
      Vector3D(0, 1, 0),
      Vector3D(0, 1, 0));
    r->setViewTransform(l);

    r->setTransform(Transform::Identity());

    r->setShader(&_shader, &_layout);
    r->drawTriangles(&_igeo, &_geo);
    }

  float _t;
  ComplexTransform _proj;
  Geometry _geo;
  IndexGeometry _igeo;
  ShaderVertexLayout _layout;
  Shader _shader;
  ShaderComponent _f;
  ShaderVertexComponent _v;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  };


ExampleViewer::ExampleViewer()
  {
  _viewer = new GameViewer();

  resize(800, 600);
  auto layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  _viewport = Eks::Canvas3D::createBest(this, &_canvas);
  layout->addWidget(_viewport);

  _timer.start(1000/fps);

  connect(_viewport, SIGNAL(initialise3D(Eks::Renderer*)), this, SLOT(initialise3D(Eks::Renderer*)));
  connect(_viewport, SIGNAL(paint3D(Eks::Renderer*,Eks::FrameBuffer*)), this, SLOT(paint3D(Eks::Renderer*,Eks::FrameBuffer*)));
  connect(_viewport, SIGNAL(resize3D(Eks::Renderer*,xuint32,xuint32)), this, SLOT(resize3D(Eks::Renderer*,xuint32,xuint32)));

  connect(&_timer, SIGNAL(timeout()), _viewport, SLOT(update()));
  }

void ExampleViewer::initialise3D(Eks::Renderer *r)
  {
  _viewer->initialise(r);
  }

void ExampleViewer::paint3D(Eks::Renderer *r, Eks::FrameBuffer *buffer)
  {
  _viewer->render(r, buffer);
  }

void ExampleViewer::resize3D(Eks::Renderer *r, xuint32 w, xuint32 h)
  {
  _viewer->resize(r, w, h);
  }

int main(int argc, char** argv)
  {
  QApplication app(argc, argv);

  Eks::Core core;

  ExampleViewer viewer;
  viewer.show();

  return app.exec();
  }
