#include "mainwindow.h"
#include "panel.h"
#include "view.h"
#include <QAction>
#include <QApplication>
#include <QDockWidget>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto *pan(new Panel);

    QDockWidget *dock(new QDockWidget("Coordinates:"));

    dock->setWidget(pan);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    view = new View;
    view->setControlPanel(pan);

    setCentralWidget(view);

    connect(pan, SIGNAL(buttonClicked()), this,
            SLOT(toggleAnimation()));

    connect(pan, SIGNAL(accuracyChange(double)), this,
            SLOT(redrawFigure(double)));
    connect(pan, SIGNAL(aChange(double)), this,
            SLOT(redrawFigure(double)));

    connect(pan, SIGNAL(lightPowerChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(ambientFactorChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(specularFactorChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(absorptionFactorChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(pointsChanged(double)), this,
            SLOT(redrawOnChangedValue(double)));

    QAction *quitAct(new QAction(QIcon(":/buttons/quit.png"), "&Quit", this));
    quitAct->setShortcut(QKeySequence("Ctrl+W"));
    quitAct->setToolTip("Quit application");
    quitAct->setStatusTip("Closes the application");
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    QAction *panelAct(dock->toggleViewAction());
    panelAct->setStatusTip("Toggle panel");
    setWindowTitle ("Сourse project Shevchuk P.V.");
}

void MainWindow::redrawOnValueChange(double) {
    view->update();
}

void MainWindow::redrawOnChangedValue(double) {
    view->initSpline(1.0);
    view->update();
}

void MainWindow::redrawFigure(double)
{
    view->initSpline(1.0);
    view->update();
}

void MainWindow::toggleAnimation()
{
    view->toggleTimer();
}
