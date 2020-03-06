#include "openglcircle.h"
#include "ui_openglcircle.h"
#include  <stdlib.h>
#include  <math.h>
#include <QDebug>
#include <QDesktopWidget>
#define  DEBUG  qDebug()<<__FILE__<<__FUNCTION__<<__LINE__<<":"

const GLdouble PI = 3.1415926535898;
OpenGLCircle::OpenGLCircle(QGLWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::OpenGLCircle)
{
    ui->setupUi(this);
    /*The current ui is displayed in the center.*/
    QDesktopWidget* desktop = QApplication::desktop();
    int desktopWidth=desktop->width() ;
    int desktopHeight=desktop->height();
    move((desktopWidth - this->width())/2, (desktopHeight - this->height())/2);
    this->resize(600,400);
}

OpenGLCircle::~OpenGLCircle()
{
    delete ui;
}
/**
 *设置OpenGL渲染环境，定义显示列表等。在调用resizeGL、paintGL前被调用一次。
 */
void OpenGLCircle::initializeGL(){

    /*设置背景颜色，红、绿、蓝、Alpha值 取值范围[0,1]*/
    glClearColor(1.0, 1.0, 1.0, 1.0);/*白色背景*/

    /*设置阴影平滑，使色彩光照更加精细。*/
    glShadeModel(GL_SMOOTH);/*启用阴影平滑*/

    /*设置深度缓存和启用深度测试，记录图形在屏幕内的深度值。*/
    /*设置深度缓存*/
    glClearDepth(1.0);
    /*启用深度测试*/
    glEnable(GL_DEPTH_TEST);
}

/**
*设置OpenGL的视口、投影等。每次部件改变大小时都会调用该函数。
*/
void OpenGLCircle::resizeGL(int w, int h){
    /*设置视口大小*/
    glViewport(0,0,(GLint)w,(GLint)h);
    /*设置投影矩阵*/
    glMatrixMode(GL_PROJECTION);
    /*重置矩阵:把当前可修改的矩阵重置为单位矩阵(初始态)*/
    glLoadIdentity();


    /*设置投影矩阵:视角为45度,纵横比为窗口的在纵横比,这两值是场景中所绘深度的临界值*/
    gluPerspective(45.0,(GLfloat)w/(GLfloat)h,0.1,100);
    /*投影变化*/
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();/*重置矩阵:把当前可修改的矩阵重置为单位矩阵(初始态)*/


}

/**
*渲染OpenGL场景，每当部件需要更新时都会调用该函数。
*/
void OpenGLCircle::paintGL(){
    GLdouble r=0.3;
    GLdouble offset=0;
    /*清除屏幕和深度缓存*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();/*重置矩阵:把当前可修改的矩阵重置为单位矩阵(初始态)*/

    /*移动坐标原点：相对于当前点来移动的*/
    // glTranslatef(0, 0, -1);
     glTranslatef(0, 0, -1);

     /*设置渲染点的大小(单位：像素)*/
      glPointSize(3);
      glColor4f(1,0,1,0);
      glBegin(GL_POINTS);
      /*glVertex2f(0,0);*/
      for(float i=0.0f;i<2*PI;i+=0.001)
      {
          glVertex2f(r*cos(i)-offset,r*sin(i)-offset);
      }
      glEnd();
}
