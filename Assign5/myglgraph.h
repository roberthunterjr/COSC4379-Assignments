// myglwidget.h 
#ifndef MYGLGRAPH_H 
#define MYGLGRAPH_H 

#include <QGLWidget> 

class MyGLGraph : public QGLWidget 
{
	Q_OBJECT 
	
public: 
	explicit MyGLGraph(QWidget *parent = 0); 
	~MyGLGraph(); 
	
signals: 

public slots: 

protected: 
	void initializeGL();
	void paintGL(); 
	void resizeGL(int width, int height);

public slots: // slots for xyz-rotation slider 
	
signals: // signaling rotation from mouse movement 

private: 
	void draw();
	float zfunction(int a, int b, int c, float x);

}; 
#endif // MYGLGRAPH_H