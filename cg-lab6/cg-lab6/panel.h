#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>

class QDoubleSpinBox;

class Panel : public QWidget {
    Q_OBJECT

  public:
    explicit Panel(QWidget *parent = nullptr);

    double getAccuracy() const;
    double getA() const;
    double getLightpower() const;
    double getAmbientfactor() const;
    double getSpecularfactor() const;
    double getAbsorptionfactor() const;
    double getHeight() const;
    double getLength() const;
    bool getAnimation() const;

  signals:
    void accuracyChange(double);
    void aChange(double);
    void heightChange(double);
    void lengthChange(double);
    void lightPowerChange(double);
    void ambientFactorChange(double);
    void specularFactorChange(double);
    void absorptionFactorChange(double);
    void buttonClicked();

protected slots:
    void handleButton();

  private:
    QDoubleSpinBox *accuracy;
    QDoubleSpinBox *a;
    QDoubleSpinBox *length;
    QDoubleSpinBox *height;
    QDoubleSpinBox *lightPower;
    QDoubleSpinBox *ambientFactor;
    QDoubleSpinBox *specularFactor;
    QDoubleSpinBox *absorptionFactor;
    QPushButton *animation;

    bool anim;
};

#endif // PANEL_H
