#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QSlider>
#include <QStateMachine>

class Panel : public QWidget {
    Q_OBJECT

  public:
    explicit Panel(QWidget *parent = nullptr);
    bool getPeriodic() const;
    QPair<float, float> getPoints(int idx) const;

    void setValues() const;

  signals:
    void pointsChanged(int);
    void buttonClicked();

protected slots:
    void handleButton();

  private:
    QVector<QPair<QSlider *, QSlider *>> points;

    QPushButton *periodic;
    bool per;
};

#endif // PANEL_H
