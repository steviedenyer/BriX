import "Eks/EksBuild" as Eks;

Eks.Application {
  name: "Game"

  cpp.includePaths: base.concat([ "." ])

  files: [ "Game/**/*.h", "Game/**/*.cpp"]

  Depends { name: "cpp" }
  Depends { name: "Eks3D" }
  Depends { name: "EksGui" }
  Depends { name: "Qt.gui"}
  Depends { name: "Qt.widgets" }
}
