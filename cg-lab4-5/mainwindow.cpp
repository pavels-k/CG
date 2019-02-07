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
    Panel *pan(new Panel);

    QDockWidget *dock(new QDockWidget("Controls"));

    dock->setWidget(pan);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    view = new View;
    view->setControlPanel(pan);

    setCentralWidget(view);

    connect(pan, SIGNAL(accuracyChange(double)), this,
            SLOT(redrawFigure(double)));
    connect(pan, SIGNAL(aChange(double)), this,
            SLOT(redrawFigure(double)));
    connect(pan, SIGNAL(heightChange(double)), this,
            SLOT(redrawFigure(double)));
    connect(pan, SIGNAL(lengthChange(double)), this,
            SLOT(redrawFigure(double)));

    connect(pan, SIGNAL(lightPowerChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(ambientFactorChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(specularFactorChange(double)), this,
            SLOT(redrawOnValueChange(double)));
    connect(pan, SIGNAL(absorptionFactorChange(double)), this,
            SLOT(redrawOnValueChange(double)));

    QAction *quitAct(new QAction(QIcon(":/buttons/quit.png"), "&Quit", this));
    quitAct->setShortcut(QKeySequence("Ctrl+Q"));
    quitAct->setToolTip("Quit application");
    quitAct->setStatusTip("Closes the application");
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *fileMenu(menuBar()->addMenu("&File"));
    fileMenu->addAction(quitAct);
    QAction *panelAct(dock->toggleViewAction());
    panelAct->setStatusTip("Toggle panel");
    QMenu *viewMenu(menuBar()->addMenu("&View"));
    viewMenu->addAction(panelAct);

    QToolBar *bar(addToolBar("Application"));
    bar->addAction(quitAct);
    statusBar()->showMessage("Ready");
    setWindowTitle ("Лабораторная работа № 4-5 Шевчук П.В.");
}

MainWindow::~MainWindow() {}

void MainWindow::redrawOnValueChange(double) {
    view->update();
}

void MainWindow::redrawFigure(double)
{
    view->initFigure(1.0f);
    view->update();
}
