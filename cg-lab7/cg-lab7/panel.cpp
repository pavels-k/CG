#include "panel.h"
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStateMachine>
#include <QVBoxLayout>
#include <QDebug>
#include <QPainter>
//#include <QtMath>
#include <QDockWidget>
#include <QAction>
#include <QApplication>
#include <QDockWidget>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>

Panel::Panel(QWidget *parent) : QWidget(parent) {
    QVector<QPair<QLabel *, QLabel *>> labels(7);
    per = false;

    QVector<QPair<float, float>> tmp = {
        qMakePair(50.f, 25.f), qMakePair(59.f, 12.f), qMakePair(65.f, 16.f),
        qMakePair(68.f, 5.f),  qMakePair(57.f, 2.f),  qMakePair(40.f, 4.f),
        qMakePair(40.f, 14.f)};

    for (int i = 0; i < 7; ++i) {
        labels[i].first = new QLabel(QString("X") + QString::number(i + 1));
        labels[i].second = new QLabel(QString("Y") + QString::number(i + 1));

        points.push_back(qMakePair(new QSlider(Qt::Horizontal), new QSlider(Qt::Horizontal)));

        points[i].first->setRange(-100, 100);
        points[i].first->setSingleStep(1);
        points[i].first->setValue(static_cast<int>(tmp[i].first));

        points[i].second->setRange(-100, 100);
        points[i].second->setSingleStep(1);
        points[i].second->setValue(static_cast<int>(tmp[i].second));

        connect(points[i].first, SIGNAL(valueChanged(int)), this,
                SIGNAL(pointsChanged(int)));
        connect(points[i].second, SIGNAL(valueChanged(int)), this,
                SIGNAL(pointsChanged(int)));
    }


    auto *lout(new QGridLayout);

    for (int i = 0; i < 7; ++i) {
        lout->addWidget(labels[i].first, i, 0);
        lout->addWidget(points[i].first, i, 1);
        lout->addWidget(labels[i].second, i, 2);
        lout->addWidget(points[i].second, i, 3);
    }

    periodic = new QPushButton("Open");

    connect(periodic, SIGNAL (released()), this, SLOT(handleButton()));
    connect(periodic, SIGNAL(released()), this,
            SIGNAL(buttonClicked()));


    lout->addWidget(periodic, 8, 0, 1, 4);

    setLayout(lout);
}

bool Panel::getPeriodic() const {
    return per;
}

QPair<float, float> Panel::getPoints(int idx) const {
    return qMakePair((float)points[idx].first->value(), (float)points[idx].second->value());
}

void Panel::handleButton()
{
   per = not per;

   periodic->setText(per ? "Closed" : "Open");
}

