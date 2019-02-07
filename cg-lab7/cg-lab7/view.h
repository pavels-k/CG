#ifndef VIEW_H
#define VIEW_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QWidget>
#include "qcustomplot.h"
#include "panel.h"

class View : public QWidget {
    Q_OBJECT

  public:
    explicit View(QWidget *parent = nullptr);
    ~View() = default;

    const Panel *controlPanel() const;
    void setControlPanel(const Panel *p);
    void DrawBSpline(QCustomPlot *customPlot);
    QCustomPlot *customPlot;
    void updateValues();
    void init();

  private:
    void SetKnotVector();
    float CoxDeBoor(float u, int k, int d);
    const Panel *pan;

    int degree;
    int n;
    QVector<float> knots;
    QVector<float> u;
    QVector<QPair<float, float>> cv;
};

#endif // VIEW_H
