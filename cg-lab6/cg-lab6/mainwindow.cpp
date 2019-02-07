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

    QDockWidget *dock(new QDockWidget());
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
    setWindowTitle ("Laboratory work № 6 Shevchuk P.V.");
}

void MainWindow::redrawOnValueChange(double) {
    view->update();
}

void MainWindow::redrawFigure(double)
{
    view->initFigure(1.0f);
    view->update();
}

void MainWindow::toggleAnimation()
{
    view->toggleTimer();
}
