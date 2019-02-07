/*
Шевчук П.В.М80-304Б
Вариант 15
Фигура - прямой цилиндр, основание – сектор параболы.
Для поверхности, созданной в л.р. No5, обеспечить выполнение 
вращения относительно направления на источник света.
*/


#include "view.h"
#include "panel.h"
#include "simpleobject3d.h"
#include <QOpenGLContext>


// сигнал
View::View(QWidget *parent) : QOpenGLWidget(parent), pan(nullptr) {
}
const Panel *View::controlPanel() const { return pan; }
void View::setControlPanel(const Panel *p) {
    pan = p;
    update();
}
View::~View() {}

// инициализация графика
void View::initializeGL() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
 // glPolygonMode(GL_FRONT, GL_LINE); // смена режима
    glLineWidth(1.0f);

    scale = -4.0f;

    initShaders();
    initFigure(1.0f);
}

// настраивается область просмотра
void View::resizeGL(int w, int h) {
    float aspect = w / static_cast<float>(h);

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45, aspect, 0.1f, 10.0f);
}

// перерисовка содержимого
void View::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 viewMatrix;
    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, scale);
    viewMatrix.rotate(rotation);

    m_program.bind();
    m_program.setUniformValue("u_projectionMatrix", projectionMatrix);
    m_program.setUniformValue("u_viewMatrix", viewMatrix);

    m_program.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 1.0));
    m_program.setUniformValue("u_lightPower", static_cast<float>(pan->getLightpower()));
    m_program.setUniformValue("u_ambientFactor", static_cast<float>(pan->getAmbientfactor()));
    m_program.setUniformValue("u_specularFactor", static_cast<float>(pan->getSpecularfactor()));
    m_program.setUniformValue("u_absorptionFactor", static_cast<float>(pan->getAbsorptionfactor()));


    for (int i = 0; i < objects.size(); ++i) {
        objects[i]->draw(&m_program, context()->functions());
    }
}

// инициализация шейдеров
void View::initShaders() {
    if (!m_program.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/vshader.vsh")) {
        close();
    }

    if (!m_program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/fshader.fsh")) {
        close();
    }

    if (!m_program.link()) {
        close();
    }
}

// инициализация фигуры
void View::initFigure(float width)
{
    if (objects.size() > 0) {
        objects[0]->~SimpleObject3D();
        objects.pop_back();
    }

    float width_div_2 = width / 2.0f;
    QVector<VertexData> vertexes;

    float cnt = static_cast<float>(pan->getAccuracy());
    float step = width / cnt;
    float a = static_cast<float>(pan->getA());

    vertexes.append(VertexData(QVector3D(0, -width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)));

    for (int i = 1; i <= cnt; ++i) {
        float z = i * step;

        vertexes.append(VertexData(QVector3D(0, -width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)));

        vertexes.append(VertexData(QVector3D(sqrt(z / a), -width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)));
        vertexes.append(VertexData(QVector3D(-sqrt(z / a), -width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)));
    }

    QVector<GLuint> indexes;

    indexes.append(1);
    indexes.append(2);
    indexes.append(0);

    indexes.append(1);
    indexes.append(0);
    indexes.append(3);

    for (GLuint i = 1; i < 3 * (cnt - 1) + 1; i += 3) {
        indexes.append(i + 3);
        indexes.append(i + 4);
        indexes.append(i);

        indexes.append(i + 1);
        indexes.append(i);
        indexes.append(i + 4);

        indexes.append(i);
        indexes.append(i + 2);
        indexes.append(i + 5);

        indexes.append(i);
        indexes.append(i + 5);
        indexes.append(i + 3);
    }

    GLuint offset = vertexes.size();

    vertexes.append(VertexData(QVector3D(0, width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)));

    for (GLuint i = 1; i <= cnt; ++i) {
        float z = i * step;

        vertexes.append(VertexData(QVector3D(0, width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)));

        vertexes.append(VertexData(QVector3D(sqrt(z / a), width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)));
        vertexes.append(VertexData(QVector3D(-sqrt(z / a), width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)));
    }

    indexes.append(offset + 1);
    indexes.append(offset + 0);
    indexes.append(offset + 2);

    indexes.append(offset + 1);
    indexes.append(offset + 3);
    indexes.append(offset + 0);

    for (GLuint i = 1; i < 3 * (cnt - 1) + 1; i += 3) {
        indexes.append(offset + i + 3);
        indexes.append(offset + i);
        indexes.append(offset + i + 4);

        indexes.append(offset + i + 1);
        indexes.append(offset + i + 4);
        indexes.append(offset + i);

        indexes.append(offset + i);
        indexes.append(offset + i + 5);
        indexes.append(offset + i + 2);

        indexes.append(offset + i);
        indexes.append(offset + i + 3);
        indexes.append(offset + i + 5);
    }

    vertexes.append(VertexData(QVector3D(0, -width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, 1.0)));

    for (GLuint i = 1; i <= cnt; ++i) {
        float z = i * step;

        vertexes.append(VertexData(QVector3D(0, -width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)));
        float dx1 = sqrt(z / a) - vertexes[(i == 1 ? vertexes.size() - 2 : vertexes.size() - 3)].position.x();
        float dz1 = width_div_2 - z - vertexes[(i == 1 ? vertexes.size() - 2 : vertexes.size() - 3)].position.z();

        vertexes.append(VertexData(QVector3D(sqrt(z / a), -width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(-dz1, 0.0, dx1)));

        float dx2 = -sqrt(z / a) - vertexes[vertexes.size() - 3].position.x();
        float dz2 = width_div_2 - z - vertexes[vertexes.size() - 3].position.z();

        vertexes.append(VertexData(QVector3D(-sqrt(z / a), -width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(dz2, 0.0, -dx2)));
    }

    vertexes.append(VertexData(QVector3D(0, width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, 1.0)));

    for (GLuint i = 1; i <= cnt; ++i) {
        float z = i * step;

        vertexes.append(VertexData(QVector3D(0, width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)));

        float dx1 = sqrt(z / a) - vertexes[(i == 1 ? vertexes.size() - 2 : vertexes.size() - 3)].position.x();
        float dz1 = width_div_2 - z - vertexes[(i == 1 ? vertexes.size() - 2 : vertexes.size() - 3)].position.z();

        vertexes.append(VertexData(QVector3D(sqrt(z / a), width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(-dz1, 0.0, dx1)));

        float dx2 = -sqrt(z / a) - vertexes[vertexes.size() - 3].position.x();
        float dz2 = width_div_2 - z - vertexes[vertexes.size() - 3].position.z();

        vertexes.append(VertexData(QVector3D(-sqrt(z / a), width_div_2, width_div_2 - z), QVector2D(0.0, 0.0), QVector3D(dz2, 0.0, -dx2)));
    }

    for (GLuint i = 3; i <= cnt * 3; i += 3) {
        indexes.append(i + offset * 3);
        indexes.append(i + offset * 2);
        indexes.append(i - 3 + offset * 2);

        indexes.append(i + offset * 3);
        indexes.append(i - 3 + offset * 2);
        indexes.append(i - 3 + offset * 3);
    }

    indexes.append(offset * 3);
    indexes.append(offset * 2);
    indexes.append(offset * 3 + 2);

    indexes.append(offset * 2);
    indexes.append(offset * 2 + 2);
    indexes.append(offset * 3 + 2);

    for (GLuint i = 5; i <= cnt * 3; i += 3) {
        indexes.append(i + offset * 3);
        indexes.append(i - 3 + offset * 2);
        indexes.append(i + offset * 2);

        indexes.append(i + offset * 3);
        indexes.append(i + offset * 3 - 3);
        indexes.append(i - 3 + offset * 2);
    }

    vertexes.append(VertexData(QVector3D(sqrt(width / a), width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)));
    vertexes.append(VertexData(QVector3D(sqrt(width / a), -width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)));
    vertexes.append(VertexData(QVector3D(-sqrt(width / a), width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)));
    vertexes.append(VertexData(QVector3D(-sqrt(width / a), -width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)));

    indexes.append(vertexes.size() - 4);
    indexes.append(vertexes.size() - 3);
    indexes.append(vertexes.size() - 2);

    indexes.append(vertexes.size() - 3);
    indexes.append(vertexes.size() - 1);
    indexes.append(vertexes.size() - 2);

    objects.append(new SimpleObject3D(vertexes, indexes, QImage(":/cube.jpg")));
}

// мыш
void View::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        mousePosition = QVector2D(event->localPos());
    }

    event->accept();
}

void View::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() != Qt::LeftButton) {
        return;
    }

    QVector2D diff = QVector2D(event->localPos()) - mousePosition;
    mousePosition = QVector2D(event->localPos());

    float angle = diff.length() / 2.0f;

    QVector3D axis = QVector3D(diff.y(), diff.x(), 0);

    rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;

    update();
}

void View::wheelEvent(QWheelEvent *event) {
    scale += (event->angleDelta().y() / 150.0f);
    scale = std::min(scale, -3.0f);
    scale = std::max(scale, -20.0f);
    update();
}
