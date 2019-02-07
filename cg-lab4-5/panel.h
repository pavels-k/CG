#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

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

  signals:
    void accuracyChange(double);
    void aChange(double);
    void heightChange(double);
    void lengthChange(double);
    void lightPowerChange(double);
    void ambientFactorChange(double);
    void specularFactorChange(double);
    void absorptionFactorChange(double);

  private:
    QDoubleSpinBox *accuracy;
    QDoubleSpinBox *a;
    QDoubleSpinBox *length;
    QDoubleSpinBox *height;
    QDoubleSpinBox *lightPower;
    QDoubleSpinBox *ambientFactor;
    QDoubleSpinBox *specularFactor;
    QDoubleSpinBox *absorptionFactor;
};

#endif // PANEL_H
