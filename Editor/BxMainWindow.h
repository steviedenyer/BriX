#ifndef BXMAINWINDOW_H
#define BXMAINWINDOW_H

#include <QMainWindow>
#include "BxActorItem.h"
#include "BxLevelScene.h"
#include "BxLevelView.h"

QT_BEGIN_NAMESPACE
class QAction;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QToolButton;
class QAbstractButton;
class QGraphicsView;
QT_END_NAMESPACE


class BxMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    BxMainWindow();
    
signals:
    
public slots:
    void actorButtonGroupClick(QAbstractButton* );
    void aboutMessage();
    void selectionChanged();
    void itemInserted(QGraphicsItem*);

private:
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolBars();
    void populateAttributeEditor();


    QToolBar* aboutToolBar;
    QToolButton* toolButtonAbout;

    QMenu* aboutMenu;

    QAction* aboutAction;

    QButtonGroup* actorButtonGroup;

    QToolBox* mainToolBox;
    QWidget* attributeEditor;

    BxLevelScene* scene;
    BxLevelView* view;

};

#endif // BXMAINWINDOW_H
