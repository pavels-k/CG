#include "panel.h"
#include <QDoubleSpinBox>
#include <QLabel>
#include <QVBoxLayout>

Panel::Panel(QWidget *parent) : QWidget(parent) {
    QLabel *lblAccuracy(new QLabel("Approximation accuracy:"));
    accuracy = new QDoubleSpinBox;
    accuracy->setRange(1, 300);
    accuracy->setSingleStep(1);
    accuracy->setValue(1);
    accuracy->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblA(new QLabel("Coefficient a:"));
    a = new QDoubleSpinBox;
    a->setRange(0.01, 1000);
    a->setSingleStep(0.05);
    a->setValue(1);
    a->setStyleSheet("QDoubleSpinBox { color: black; } ");

    QLabel *lblLightPower(new QLabel("Light power:"));
    lightPower = new QDoubleSpinBox;
    lightPower->setRange(0.01, 100);
    lightPower->setSingleStep(1);
    lightPower->setValue(10);
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

    auto *lout(new QVBoxLayout);
    lout->addWidget(lblAccuracy);
    lout->addWidget(accuracy);
    lout->addWidget(lblA);
    lout->addWidget(a);
    lout->addWidget(lblLightPower);
    lout->addWidget(lightPower);
    lout->addWidget(lblAmbientFactor);
    lout->addWidget(ambientFactor);
    lout->addWidget(lblSpecularFactor);
    lout->addWidget(specularFactor);
    lout->addWidget(lblAbsorptionFactor);
    lout->addWidget(absorptionFactor);

    animation = new QPushButton("Animation");

    connect(animation, SIGNAL (released()), this, SLOT(handleButton()));
    connect(animation, SIGNAL (released()), this, SIGNAL(buttonClicked()));

    lout->addWidget(animation);

    lout->addStretch();

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


void Panel::handleButton()
{
   animation->setText(anim ? "On" : "Off");
   anim = not anim;
}

