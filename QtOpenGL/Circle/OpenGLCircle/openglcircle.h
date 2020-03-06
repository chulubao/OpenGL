#ifndef OPENGLCIRCLE_H
#define OPENGLCIRCLE_H

#include <QGLWidget>

namespace Ui {
class OpenGLCircle;
}

class OpenGLCircle : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit OpenGLCircle(QGLWidget *parent = 0);
    ~OpenGLCircle();
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual  void paintGL();
private:
    Ui::OpenGLCircle *ui;
};

#endif // OPENGLCIRCLE_H
