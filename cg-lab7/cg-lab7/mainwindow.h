#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class View;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void RedrawOnChangedValue(int);
    void RedrawOnButtonClicked();

  private:
    View *view;
};

#endif // MAINWINDOW_H
