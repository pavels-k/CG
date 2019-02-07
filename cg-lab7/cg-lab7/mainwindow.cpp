#include "panel.h"
#include "view.h"
#include "mainwindow.h"
#include <QDockWidget>
#include <QAction>
#include <QApplication>
#include <QDockWidget>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto *pan(new Panel);

    QDockWidget *dock(new QDockWidget(""));

    dock->setWidget(pan);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    view = new View;
    view->setControlPanel(pan);
    view->init();
    view->customPlot->rescaleAxes();

    setCentralWidget(view);

    QAction *quitAct(new QAction(QIcon(":/buttons/quit.png"), "&Quit", this));
    quitAct->setShortcut(QKeySequence("Ctrl+W"));
    quitAct->setToolTip("Quit application");
    quitAct->setStatusTip("Closes the application");
    connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

   // statusBar()->setStyleSheet("QStatusBar { background-color: rgb(90, 90, 90)}");

   // statusBar()->showMessage("Ready");

    connect(pan, SIGNAL(pointsChanged(int)), this,
            SLOT(RedrawOnChangedValue(int)));
    connect(pan, SIGNAL(buttonClicked()), this,
            SLOT(RedrawOnButtonClicked()));
    setWindowTitle ("Laboratory work № 7 Shevchuk P.V.");
}

MainWindow::~MainWindow()
{

}

void MainWindow::RedrawOnChangedValue(int)
{
    view->updateValues();
    view->DrawBSpline(view->customPlot);
    view->customPlot->replot();
}

void MainWindow::RedrawOnButtonClicked()
{
    view->init();
    view->customPlot->replot();
}
