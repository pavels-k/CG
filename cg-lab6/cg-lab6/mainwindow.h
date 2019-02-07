#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class View;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

  private slots:
    void redrawOnValueChange(double);
    void redrawFigure(double);
    void toggleAnimation();

  private:
    View *view;
};

#endif // MAINWINDOW_H
