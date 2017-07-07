#include <QtGui> 
#include <QtOpenGL> 
#include "myglgraph.h" 

MyGLGraph::MyGLGraph(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent) { 
	
} 

MyGLGraph::~MyGLGraph() { } 



static void qNormalizeAngle(int &angle) {
	while (angle < 0) 
		angle += 360 * 16;
	while (angle > 360) 
		angle -= 360 * 16;
}


void MyGLGraph::initializeGL() {
	qglClearColor(Qt::black);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 }; 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
} 
void MyGLGraph::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//glTranslatef(0.0, 0.0, -10.0);
	//glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
	//glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
	//glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
	draw();
	
		
	
}
void MyGLGraph::resizeGL(int width, int height) {
	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);
	//glViewport(0,0,300,300);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	/*
	#ifdef QT_OPENGL_ES_1
		glOrthof(-2, +2, -2, +2, 1.0, 15.0);
	#else 
		glOrtho(-2, +2, -2, +2, 1.0, 15.0);
	#endif 
	*/
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
} 


void MyGLGraph::draw() {
	
	float t = 12.0;
	float i = 0.0;
	glBegin(GL_LINE_STRIP);
		while(i < t){
			glVertex2f(i, zfunction(4,2,1,i));
			i = i + 0.1;
		}
	glEnd();
	
}

float MyGLGraph::zfunction(int a, int b, int c, float x){
	return float(a + b*x + c*x*x);
}