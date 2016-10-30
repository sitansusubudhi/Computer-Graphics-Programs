#include<stdio.h>
#include<stdlib.h>


#include<GL/glut.h>


void handleKeypress(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
	}
}

void initRendering()
{
	//makes 3D drawing work when something is in front of something
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h)
{
	glViewport(10,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w/(double)h, 1.0, 200.0);
}

float _angle = 30.0f;
float _x = 0.5f;
float _y = 0.5f;
float _z = 0.5f;
int _flag = 1;

float _trans_x = 0.0f;
float _trans_y = 0.0f;
float _trans_z = 0.0f;
int _trans_flag = 1;

void Line(int x0, int y0, int xn, int yn, int depth)
{
   // save the current state of transformation

	//int x0=0,y0=0,xn=30,yn=20,x,y;
	int x,y;
	int dx,dy;
	int pk;
	int k;

    glBegin(GL_POINTS);
	//glBegin(GL_POINTS);
 	glVertex3f(x0,y0, depth);
 	//glEnd();

	dx=xn-x0;
	dy=yn-y0;
	pk=2*dy-dx;
	x=x0;
	y=y0;
	for(k=0;k<dx-1;++k)
	{
		if(pk<0)
  		{
   			pk=pk+2*dy;
  		}
  		else
  		{
   			pk=pk+2*dy-2*dx;
   			++y;
  		}
  		++x;
  		//glBegin(GL_POINTS);
 		glVertex3f(x,y, depth);
 		//glEnd();
 	}
    glEnd();
    
}

void Line_1(int x0, int y0, int xn, int yn, int depth)
{
   // save the current state of transformation

	//int x0=0,y0=0,xn=30,yn=20,x,y;
	int x,y;
	int dx,dy;
	int pk;
	int k;

    glBegin(GL_POINTS);
	//glBegin(GL_POINTS);
 	glVertex3f(x0,y0, depth);
 	//glEnd();

	dx=xn-x0;
	dy=yn-y0;
	pk=2*dx-dy;
	x=x0;
	y=y0;
	for(k=0;k<dy-1;++k)
	{
		if(pk<0)
  		{
   			pk=pk+2*dx;
  		}
  		else
  		{
   			pk=pk+2*dx-2*dx;
   			++x;
  		}
  		++y;
  		//glBegin(GL_POINTS);
 		glVertex3f(x,y, depth);
 		//glEnd();
 	}
    glEnd();

}

void update (int value)
{
	_angle+= 2.0f;
	if(_angle > 360)
	{
		_angle-=360;
	}
	glutPostRedisplay();   //tell glut that scene has changed
	glutTimerFunc(25, update,0);   //tell glut to call update again in 25 millisecond
}

void shrink (int value)
{
	if(_flag ==1)
	{
		_x-= 0.01f;
		_y-= 0.01f;
		_z-= 0.01f;

		if(_x <= 0.2f && _y <= 0.2f && _z <= 0.2f)
			_flag=2;
	}
	else if(_flag == 2)
	{
		_x+= 0.01f;
		_y+= 0.01f;
		_z+= 0.01f;

		if(_x >= 0.5f && _y >= 0.5f && _z >= 0.5f)
			_flag=1;
	}
	glutPostRedisplay();   //tell glut that scene has changed
	glutTimerFunc(25, shrink,0);   //tell glut to call update again in 25 millisecond
}

void trans (int value)
{
	if(_trans_flag==1)
	{
		_trans_x+= 0.01f;
		if(_trans_x >= 2.0f)
			_trans_flag = 2;
	}
	else if(_trans_flag==2)
	{
		_trans_y+= 0.01f;
		if(_trans_y >= 2.0f)
			_trans_flag = 3;
	}
	else if(_trans_flag==3)
	{
		_trans_x-= 0.01f;
		if(_trans_x <= -2.0f)
			_trans_flag = 4;
	}
	else if(_trans_flag==4)
	{
		_trans_y-= 0.01f;
		if(_trans_y <= -2.0f)
			_trans_flag = 1;
	}

	glutPostRedisplay();   //tell glut that scene has changed
	glutTimerFunc(25, trans,0);   //tell glut to call update again in 25 millisecond
}



void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-20.0f, -20.0f, -190.0f);    //Move forward 5 units

	glPushMatrix();   // save the current state of transformation
	//glTranslatef(_trans_x, _trans_y, _trans_z);

	glRotatef(_angle, 0.0f, 1.0f, 0.0f);  //Rotate about the vector (1,2,3)
	//glScalef(_x, _y, _z);    //scale by 0.7 in x, y, and z direction
    
    Line(  0,  20, 30, 20, 0);
    Line_1(0,  0,  0,  20, 0);
    Line_1(30, 0,  30, 20, 0);
    Line(  0,  0,  30, 0,  0);
    
    Line(0,20,30,20, -20);
    Line_1(0,0,0,20, -20);
    Line_1(30,0,30,20, -20);
    Line(0,0,30,0, -20);
    
    //glTranslatef(0.0f, -10.0f, 0.0f);
    glRotatef(-30, 10.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 5.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 10.0f);
    Line(0,10,30,10, 0);
    Line_1(0,10,0,30, 0);
    Line_1(30,10,30,30, 0);
    Line(0,30,30,30, 0);
    
    //glRotatef(-80, -10.0f, 0.0f, 0.0f);
    glRotatef(66, 10.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -3.0f, 0.0f);
    //glTranslatef(0.0f, 0.0f, 0.0f);
    Line(0,-5,30,-5, -27);
    Line_1(0,-5,0,15, -27);
    Line_1(30,-5,30,15, -27);
    Line(0,15,30,15, -27);
    
    glTranslatef(0.0f, -8.5f, 0.0f);
    glRotatef(-126, 1.0f, 0.0f, 0.0f);
    Line_1(  0,  0,  0, 20,  0);
    Line_1(  30,  0,  30, 20,  0);


    //glutTimerFunc(5000, shrink,0);
    //glutTimerFunc(5000, trans,0);
	glPopMatrix();

	glutSwapBuffers();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);

	glutCreateWindow("BASIC SHAPES");
	initRendering();
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(drawScene);

	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);


	glutTimerFunc(25, update,0);
    glutTimerFunc(25, shrink,0);
    glutTimerFunc(25, trans,0);
	glutMainLoop();

	return 0;
}
