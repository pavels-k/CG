#include "panel.h"
#include <QDoubleSpinBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QVector3D>

Panel::Panel(QWidget *parent) : QWidget(parent) {
    QVector<std::tuple<QLabel *, QLabel *, QLabel *>> labels(7);

    QVector<std::tuple<float, float, float>> tmp(7);
    tmp[0] = std::make_tuple(-0.3f, 2 * 1.5f, 0.2f);
    tmp[1] = std::make_tuple(-0.1f, 2 * 0.6f, 0.0f);
    tmp[2] = std::make_tuple(-0.5f, 2 * 0.0f, -0.5f);
    tmp[3] = std::make_tuple(0.1f, -2 * 0.35f, 0.3f);
    tmp[4] = std::make_tuple(0.3f, -2 * 0.9f, 0.2f);
    tmp[5] = std::make_tuple(0.6f, -2 * 1.5f, -1.0f);
    tmp[6] = std::make_tuple(1.2f, -2 * 2.0f, -1.5f);

    for (int i = 0; i < 7; ++i) {
        std::get<0>(labels[i]) = new QLabel(QString("X") + QString::number(i + 1));
        std::get<1>(labels[i]) = new QLabel(QString("Y") + QString::number(i + 1));
        std::get<2>(labels[i]) = new QLabel(QString("Z") + QString::number(i + 1));

        points.push_back(std::tuple<QDoubleSpinBox*, QDoubleSpinBox*, QDoubleSpinBox*>(new QDoubleSpinBox,
                                                                                       new QDoubleSpinBox,
                                                                                       new QDoubleSpinBox));

        std::get<0>(points[i])->setRange(-10.0, 10.0);
        std::get<0>(points[i])->setSingleStep(0.1);
        std::get<0>(points[i])->setValue(static_cast<float>(std::get<0>(tmp[i])));
        std::get<0>(points[i])->setStyleSheet("QDoubleSpinBox { color: black; }");

        std::get<1>(points[i])->setSingleStep(0.1);
        std::get<1>(points[i])->setRange(-10.0, 10.0);
        std::get<1>(points[i])->setValue(static_cast<float>(std::get<1>(tmp[i])));
        std::get<1>(points[i])->setStyleSheet("QDoubleSpinBox { color: black; }");


        std::get<2>(points[i])->setSingleStep(0.1);
        std::get<2>(points[i])->setRange(-10.0, 10.0);
        std::get<2>(points[i])->setValue(static_cast<float>(std::get<2>(tmp[i])));
        std::get<2>(points[i])->setStyleSheet("QDoubleSpinBox { color: black; }");


        std::get<0>(labels[i])->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        std::get<0>(points[i])->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed));
        std::get<1>(labels[i])->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        std::get<1>(points[i])->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
        std::get<2>(labels[i])->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
        std::get<2>(points[i])->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));


        connect(std::get<0>(points[i]), SIGNAL(valueChanged(double)), this,
                SIGNAL(pointsChanged(double)));
        connect(std::get<1>(points[i]), SIGNAL(valueChanged(double)), this,
                SIGNAL(pointsChanged(double)));
        connect(std::get<2>(points[i]), SIGNAL(valueChanged(double)), this,
                SIGNAL(pointsChanged(double)));
    }


    auto *lout(new QGridLayout);

    for (int i = 0, j = 0; i < 7; ++i, j += 2) {
        lout->addWidget(std::get<0>(labels[i]), j, 0, Qt::AlignCenter);
        lout->addWidget(std::get<0>(points[i]), j + 1, 0, Qt::AlignCenter);
        lout->addWidget(std::get<1>(labels[i]), j, 1, Qt::AlignCenter);
        lout->addWidget(std::get<1>(points[i]), j + 1, 1, Qt::AlignCenter);
        lout->addWidget(std::get<2>(labels[i]), j, 2, Qt::AlignCenter);
        lout->addWidget(std::get<2>(points[i]), j + 1, 2, Qt::AlignCenter);
    }

    QLabel *lblAccuracy(new QLabel("Approximation:"));
    accuracy = new QDoubleSpinBox;
    accuracy->setRange(1, 300);
    accuracy->setSingleStep(1);
    accuracy->setValue(17);
    accuracy->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblA(new QLabel("a:"));
    a = new QDoubleSpinBox;
    a->setRange(0.01, 1000);
    a->setSingleStep(0.05);
    a->setValue(1);
    a->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblLightPower(new QLabel("Light power:"));
    lightPower = new QDoubleSpinBox;
    lightPower->setRange(0.01, 100);
    lightPower->setSingleStep(1);
    lightPower->setValue(3);
    lightPower->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblAmbientFactor(new QLabel("Ambient factor:"));
    ambientFactor = new QDoubleSpinBox;
    ambientFactor->setRange(0.01, 1);
    ambientFactor->setSingleStep(0.01);
    ambientFactor->setValue(0.7);
    ambientFactor->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblSpecularFactor(new QLabel("Specular factor:"));
    specularFactor = new QDoubleSpinBox;
    specularFactor->setRange(0.01, 100);
    specularFactor->setSingleStep(0.01);
    specularFactor->setValue(20);
    specularFactor->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblAbsorptionFactor(new QLabel("Absorption factor:"));
    absorptionFactor = new QDoubleSpinBox;
    absorptionFactor->setRange(0.01, 1);
    absorptionFactor->setSingleStep(0.01);
    absorptionFactor->setValue(0.78);
    absorptionFactor->setStyleSheet("QDoubleSpinBox { color: black; } ");

    lout->addWidget(lblAccuracy, 8 * 2, 0);
    lout->addWidget(accuracy, 8 * 2, 1);
    lout->addWidget(lblLightPower, 10 * 2, 0);
    lout->addWidget(lightPower, 10 * 2,1);
    animation = new QPushButton("Animation");

    connect(animation, SIGNAL (released()), this, SLOT(handleButton()));
    connect(animation, SIGNAL (released()), this, SIGNAL(buttonClicked()));

    lout->addWidget(animation, 14 * 2, 0, Qt::AlignCenter);

    setLayout(lout);

    connect(accuracy, SIGNAL(valueChanged(double)), this,
            SIGNAL(accuracyChange(double)));
    connect(a, SIGNAL(valueChanged(double)), this,
            SIGNAL(aChange(double)));
    connect(lightPower, SIGNAL(valueChanged(double)), this,
            SIGNAL(lightPowerChange(double)));
    connect(ambientFactor, SIGNAL(valueChanged(double)), this,
            SIGNAL(ambientFactorChange(double)));
    connect(specularFactor, SIGNAL(valueChanged(double)), this,
            SIGNAL(specularFactorChange(double)));
    connect(absorptionFactor, SIGNAL(valueChanged(double)), this,
            SIGNAL(absorptionFactorChange(double)));
}

double Panel::getAccuracy() const
{
    return accuracy->value();
}

double Panel::getA() const
{
    return a->value();
}

double Panel::getLightpower() const
{
    return lightPower->value();
}

double Panel::getAmbientfactor() const
{
    return ambientFactor->value();
}

double Panel::getSpecularfactor() const
{
    return specularFactor->value();
}

double Panel::getAbsorptionfactor() const
{
    return absorptionFactor->value();
}

bool Panel::getAnimation() const {
    return anim;
}

std::tuple<float, float, float> Panel::getPoint(int idx) const {
    return std::make_tuple(std::get<0>(points[idx])->value(), std::get<1>(points[idx])->value(), std::get<2>(points[idx])->value());
}


void Panel::handleButton()
{
    animation->setText(anim ? "On" : "Off");
    anim = not anim;
}

