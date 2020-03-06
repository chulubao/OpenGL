#include "openglcircle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLCircle w;
    w.show();
    
    return a.exec();
}
