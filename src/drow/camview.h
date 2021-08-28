#ifndef CAMVIEW_H
#define CAMVIEW_H

#include <QGLWidget>
#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include <QMouseEvent>
#include <QWheelEvent>

#include "MultipleViewTriangulation.h"

class CamView : public QOpenGLWidget ,
                     protected QOpenGLFunctions
{
    Q_OBJECT

public:

    int view_fps_1s = 0;
    int point_fps_1s = 0;
    
    CamView(QWidget *parent = 0);
    ~CamView();
    void setAngle(float rol, float pit, float yaw);
    void setPosition(Vector3d *Xr,int size);

protected:
    //Three basic override function
    void initializeGL() Q_DECL_OVERRIDE;          //Initialize the OpenGL funciton and send data
    void paintGL() Q_DECL_OVERRIDE;               //Do opengl paint job
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;  //When the widget size changed it will work to

    
    
    void mousePressEvent(QMouseEvent*event);        //按下
    void mouseMoveEvent(QMouseEvent*event);         //按下移动
    void mouseReleaseEvent(QMouseEvent*event);      //松开
    void mouseDoubleClickEvent(QMouseEvent*event);  //双击
    void wheelEvent(QWheelEvent*event);             //滚轮
    
private:
    
    double eye[3];
    double center[3];
    double up[3];
    
    double yawCam, pitchCam, farCam;
    
    int clickX,clickY;
    float rol = 0,pit = 0,yaw = 0;
    float px = 0,py = 0,pz = 0;

    Vector3d *Xr;
    int size;

    void cameraTurn(double yaw, double pitch, double R_long);
    void cameraInit(double yaw, double pitch, double R_long);
    
private slots:
    void updateGL();
};
#endif // CAMVIEW_H
