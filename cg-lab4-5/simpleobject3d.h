#ifndef SIMPLEOBJECT3D_H
#define SIMPLEOBJECT3D_H

#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include <QVector2D>

struct VertexData {
    VertexData() {}
    VertexData(QVector3D p, QVector2D t, QVector3D n)
        : position(p), texCoord(t), normal(n) {}

    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

class QOpenGLTexture;
class QOpenGLFunctions;
class QOpenGLShaderProgram;

class SimpleObject3D
{
public:
    SimpleObject3D();
    SimpleObject3D(const QVector<VertexData> &vertData,
                   const QVector<GLuint> &indexes,
                   const QImage &tex);
    ~SimpleObject3D();
    void init(const QVector<VertexData> &vertData,
              const QVector<GLuint> &indexes,
              const QImage &tex);
    void draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions);

private:
    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer;
    QMatrix4x4 modelMatrix;
    QOpenGLTexture *texture;
    GLuint step;
};

#endif // SIMPLEOBJECT3D_H
