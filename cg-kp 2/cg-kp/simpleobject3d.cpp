#include "simpleobject3d.h"
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

SimpleObject3D::SimpleObject3D(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes, const QImage &tex, bool fl)
    : indexBuffer(QOpenGLBuffer::IndexBuffer), texture(nullptr), f(fl) {
    init(vertData, indexes, tex);
}

SimpleObject3D::~SimpleObject3D() {
    if (vertexBuffer.isCreated()) {
        vertexBuffer.destroy();
    }

    if (indexBuffer.isCreated()) {
        indexBuffer.destroy();
    }

    if (texture != nullptr) {
        if (texture->isCreated()) {
            texture->destroy();
        }
    }
}

void SimpleObject3D::init(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes, const QImage &tex) {
    if (vertexBuffer.isCreated()) {
        vertexBuffer.destroy();
    }

    if (indexBuffer.isCreated()) {
        indexBuffer.destroy();
    }

    if (texture != nullptr) {
        if (texture->isCreated()) {
            texture->destroy();
        }
    }

    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(vertData.constData(),
                          vertData.size() * sizeof(VertexData));
    vertexBuffer.release();

    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
    indexBuffer.release();

    texture = new QOpenGLTexture(tex.mirrored());
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    texture->setWrapMode(QOpenGLTexture::Repeat);

    modelMatrix.setToIdentity();
}

void SimpleObject3D::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions) {
    if (!vertexBuffer.isCreated() || !indexBuffer.isCreated()) {
        return;
    }

    texture->bind(0);
    program->setUniformValue("u_texture", 0);
    program->setUniformValue("u_modelMatrix", modelMatrix);

    vertexBuffer.bind();

    int offset = 0;

    int vertLoc = program->attributeLocation("a_position");
    program->enableAttributeArray(vertLoc);
    program->setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    int texLoc = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texLoc);
    program->setAttributeBuffer(texLoc, GL_FLOAT, offset, 2, sizeof(VertexData));

    offset += sizeof(QVector2D);

    int normLoc = program->attributeLocation("a_normal");
    program->enableAttributeArray(normLoc);
    program->setAttributeBuffer(normLoc, GL_FLOAT, offset, 3,sizeof(VertexData));

    indexBuffer.bind();
    functions->glDrawElements((f ? GL_TRIANGLES : GL_LINES), indexBuffer.size(), GL_UNSIGNED_INT,nullptr);

    vertexBuffer.release();
    indexBuffer.release();
    texture->release();
}
