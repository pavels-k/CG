#ifndef VIEW_H
#define VIEW_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLWidget>

class Panel;
class SimpleObject3D;

class View : public QOpenGLWidget {
    Q_OBJECT

  public:
    explicit View(QWidget *parent = nullptr);
    ~View() = default;

    const Panel *controlPanel() const;
    void setControlPanel(const Panel *p);
    void initFigure(float width);
    void toggleTimer();

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();
    void initPyramid(float width);


    void timerEvent(QTimerEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

  private:
    const Panel *pan;

    QMatrix4x4 projectionMatrix;
    QOpenGLShaderProgram m_program;
    QVector2D mousePosition;
    QQuaternion rotation;
    QVector4D lightPosition;
    float scale;
    int timer;
    bool animation;

    QVector<SimpleObject3D *> objects;
};

#endif // VIEW_H
