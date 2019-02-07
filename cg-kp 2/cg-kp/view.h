#ifndef VIEW_H
#define VIEW_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLWidget>
#include <QKeyEvent>

class Panel;
class SimpleObject3D;
class VertexData;

class View : public QOpenGLWidget {
    Q_OBJECT

  public:
    explicit View(QWidget *parent = nullptr);
    ~View() = default;

    const Panel *controlPanel() const;
    void setControlPanel(const Panel *p);
    void initFigure(float width);
    void initCinematic(QVector<VertexData> &curve);
    void toggleTimer();
    void init();
    void initSpline(float width);

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();
    void initPyramid(float width);
    void interpolate(QVector<VertexData> &res, QVector3D p1, QVector3D p2, QVector3D t1, QVector3D t2, size_t steps);


    void timerEvent(QTimerEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

  private:
    const Panel *pan;

    QMatrix4x4 projectionMatrix;
    QOpenGLShaderProgram m_program;
    QVector2D mousePosition;
    QQuaternion rotation;
    QVector4D lightPosition;
    float scale;
    float lr;
    float ud;
    int timer;
    bool animation;

    QVector<SimpleObject3D *> objects;
};

#endif // VIEW_H
