#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

static GLfloat _angleRotate[]={0.0f,0.0f,0.0f};
GLint axis =1;

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}

void mouseButtonpress(int button,int state,int x,int y){
    if(button== GLUT_LEFT_BUTTON && state ==GLUT_DOWN) axis =0;   
	if(button== GLUT_MIDDLE_BUTTON && state ==GLUT_DOWN) axis =1; 
	if(button== GLUT_RIGHT_BUTTON && state ==GLUT_DOWN) axis =2;  

}


//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 90.0f;
/*
void draw_line(int x0, int y0, int xn, int yn, int depth)
{

	int x,y;
	int dx,dy;
	int pk;
	int k;

    glBegin(GL_POINTS);

 	glVertex3f(x0,y0, depth);


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

 		glVertex3f(x,y, depth);

 	}
    glEnd();

}
*/

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -4.0f);

	
	

	glRotatef(_angleRotate[0], 1.0f, 0.0f,0.0f); 
	glRotatef(_angleRotate[1], 0.0f, 1.0f,0.0f); 
    glRotatef(_angleRotate[2], 0.0f, 0.0f,1.0f);
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Front side

	glColor3f(0.3f,0.2f,0.8f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor3f(0.3f,0.6f,0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor3f(1.0f,0.5f,0.1f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
    glColor3f(0.7f,0.4f,0.1f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glEnd();

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Back side
	glColor3f(0.4f,0.4f,0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
    glColor3f(0.5f, 1.0f, 0.8f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glColor3f(0.8f, 0.8f, 0.4f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glEnd(); //End quadrilateral coordinates

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Left side
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glColor3f(1.0f,0.5f,0.1f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(0.3f,0.6f,0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor3f(0.5f, 1.0f, 0.8f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd(); //End quadrilateral coordinates

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Right side
	glColor3f(0.7f,0.4f,0.1f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glColor3f(0.8f, 0.8f, 0.4f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glColor3f(0.4f,0.4f,0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glColor3f(0.3f,0.2f,0.8f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glEnd(); //End quadrilateral coordinates
	
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
		//Top side
	glColor3f(0.3f,0.6f,0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glColor3f(0.3f,0.2f,0.8f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glColor3f(0.4f,0.4f,0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glColor3f(0.5f, 1.0f, 0.8f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd(); //End quadrilateral coordinates
	
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
		//Bottom side
	glColor3f(1.0f,0.5f,0.1f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glColor3f(0.7f,0.4f,0.1f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glColor3f(0.8f, 0.8f, 0.4f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glColor3f(0.8f, 0.0f, 0.3f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd(); //End quadrilateral coordinates



	/*
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front side parallelogram
	glColor3f(1.0f,1.0f,0.0f);
	glVertex3f(-0.75f, 0.85f, -0.8f);
	glVertex3f(-0.75f, 0.42f, 0.2f);
	glVertex3f(0.75f, 0.42f, 0.2f);
	glVertex3f(0.75f, 0.85f, -0.8f);


	glEnd(); //End quadrilateral coordinates

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//back side parallelogram
	glColor3f(1.0f,1.0f,0.0f);
	glVertex3f(-0.75f, 0.85f, -0.8f);
	glVertex3f(-0.75f, 0.42f, -1.8f);
	glVertex3f(0.75f, 0.42f, -1.8f);
	glVertex3f(0.75f, 0.85f, -0.8f);

	glEnd(); //End quadrilateral coordinates
	*/

	
	glFlush();
	glutSwapBuffers(); //Send the 3D scene to the screen
}

void update(int value){
	_angleRotate[axis] += 2.0f;
	if(_angleRotate[axis] > 360){
		_angleRotate[axis]-= 360;
	}

	glutPostRedisplay();    //Tells GLUT that the scene has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}


int main(int argc, char** argv){
	//Initizlize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700); //Set the window size

	//Create the window
	glutCreateWindow("Spinning Cube");
	initRendering(); //Initialize rendering


	//Set handler functions for drawing, keypressing, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(mouseButtonpress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0);

	glutMainLoop(); //Start the main loop. glutMainLoop doesn't return
	return 0;
}



