#include<stdio.h>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,4,0,4);
	glMatrixMode(GL_MODELVIEW);
}

void queen()
{
	
	//X(a) = Ax·a² + Bx·2·a·b + Cx·b²
	//Y(a) = Ay·a² + By·2·a·b + Cy·b²
	//for 3d -> Z(a) = Az·a² + Bz·2·a·b + Cz·b²

	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	
	double px=0.0,py=0.0; //for generalization. This should be the coordinate of the lower left corner of the box.
	
	double Ax = px+1.0, Ay = py+1.0;
	double Bx = px+1.7, By = py+1.5;
	double Cx = px+1.2, Cy = py+3.5;
	
	// Points on the curve
	double X;
	double Y;
	
	// Variable
	double a = 0;
	double b = 1.0 - a;
	
	// Tell OGL to start drawing a line strip with line width =2
	glLineWidth(1.5);
	glBegin(GL_LINE_STRIP);
		
	/* We will divide the curve into small points and draw a line between each point. If
	 the points are close enough, it will appear as a curved line. Here we are using 20 
	 points and since the variable goes from 0.0 to 1.0 we must change it by 1/20 = 0.05
	 each time. Points can be increased. */
	
	//for the left hand curve.
	
	for(int i = 0; i <= 20; i++)
	{
		// Get a point on the curve
		X = Ax*a*a + 2*Bx*a*b + Cx*b*b;
		Y = Ay*a*a + 2*By*a*b + Cy*b*b;
		//Z = Az*a*a*a + 2*Bz*a*a + Cz*b*b;
		
		// Draw the line from point to point
		glVertex2f(X, Y);
		
		// Change the variable
		a += 0.05;
		b = 1.0 - a;
	}
	
	glEnd();
	
	a = 0;
	b = 1.0 - a;
	
	Ax = px + 3.0; Ay = py + 1.0;
	Bx = px + 2.3; By = py + 1.5;
	Cx = px + 2.8; Cy = py + 3.5;
	
	//for the right hand curve
	
	glBegin(GL_LINE_STRIP);
	
	for(int i = 0; i <= 20; i++)
	{
		// Get a point on the curve
		X = Ax*a*a + 2*Bx*a*b + Cx*b*b;
		Y = Ay*a*a + 2*By*a*b + Cy*b*b;
		//Z = Az*a*a*a + 2*Bz*a*a + Cz*b*b;
		
		// Draw the line from point to point
		glVertex2f(X, Y);
		
		// Change the variable
		a += 0.05;
		b = 1.0 - a;
	}
		
	glEnd();
	
	a = 0;
	b = 1.0 - a;
	
	Ax = px + 1.0; Ay = py + 1.0;
	Bx = px + 2.0; By = py + 0.5;
	Cx = px + 3.0; Cy = py + 1.0;
	
	//for the base curve
	
	glBegin(GL_LINE_STRIP);
	
	for(int i = 0; i <= 20; i++)
	{
		// Get a point on the curve
		X = Ax*a*a + 2*Bx*a*b + Cx*b*b;
		Y = Ay*a*a + 2*By*a*b + Cy*b*b;
		//Z = Az*a*a*a + 2*Bz*a*a + Cz*b*b;
		
		// Draw the line from point to point
		glVertex2f(X, Y);
		
		// Change the variable
		a += 0.05;
		b = 1.0 - a;
	}
		
	glEnd();
	
	a = 0;
	b = 1.0 - a;
	
	Ax = px + 1.12; Ay = py + 1.1;
	Bx = px + 2.0; By = py + 0.6;
	Cx = px + 2.88; Cy = py + 1.1;
	
	//for the upper base curve
	
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i <= 20; i++)
	{
		// Get a point on the curve
		X = Ax*a*a + 2*Bx*a*b + Cx*b*b;
		Y = Ay*a*a + 2*By*a*b + Cy*b*b;
		//Z = Az*a*a*a + 2*Bz*a*a + Cz*b*b;
		
		// Draw the line from point to point
		glVertex2f(X, Y);
		
		// Change the variable
		a += 0.05;
		b = 1.0 - a;
	}
	glEnd();
	
	a = 0;
	b = 1.0 - a;
	
	Ax = px + 1.4; Ay = py + 2.2;
	Bx = px + 2.0; By = py + 1.6;
	Cx = px + 2.6; Cy = py + 2.2;
	
	//for the middle horizontal curve
	
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i <= 20; i++)
	{
		// Get a point on the curve
		X = Ax*a*a + 2*Bx*a*b + Cx*b*b;
		Y = Ay*a*a + 2*By*a*b + Cy*b*b;
		//Z = Az*a*a*a + 2*Bz*a*a + Cz*b*b;
		
		// Draw the line from point to point
		glVertex2f(X, Y);
		
		// Change the variable
		a += 0.05;
		b = 1.0 - a;
	}
	glEnd();
	
	a = 0;
	b = 1.0 - a;
	
	Ax = px + 1.4; Ay = py + 2.3;
	Bx = px + 2.0; By = py + 1.7;
	Cx = px + 2.6; Cy = py + 2.3;
	
	//for the upper middle horizontal curve
	
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i <= 20; i++)
	{
		// Get a point on the curve
		X = Ax*a*a + 2*Bx*a*b + Cx*b*b;
		Y = Ay*a*a + 2*By*a*b + Cy*b*b;
		//Z = Az*a*a*a + 2*Bz*a*a + Cz*b*b;
		
		// Draw the line from point to point
		glVertex2f(X, Y);
		
		// Change the variable
		a += 0.05;
		b = 1.0 - a;
	}
	glEnd();
	
	
	//for crown jags
	
	glBegin(GL_LINE_STRIP);
		glVertex2f(px+1.2,py+3.5);
		glVertex2f(px+1.55,py+3.0);
		glVertex2f(px+1.77,py+3.5);
		glVertex2f(px+2.0,py+3.0);
		
		glVertex2f(px+2.27,py+3.5);
		glVertex2f(px+2.475,py+3.0);
		glVertex2f(px+2.80,py+3.5);
	glEnd();
	
	//for vertical line
	
	glBegin(GL_LINES);
		glVertex2f(px+2.0,py+3.0);
		glVertex2f(px+2.0,py+0.75);
	glEnd();
	
	glFlush();
	/*Save coordinates for later use?*/
		
}


void main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("1");
	myinit();
	glutDisplayFunc(queen);
	glutMainLoop();
}
