#include <iostream>
#include <stdlib.h> //for exit function

//include openGL header files, so that we can use OpenGL

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key,  //the key pressed
					int x, int y){     //the current position
	switch (key){
		case 27: //Escape key
		    exit(0); //Exut the program
	}
}

//Initialize the 3D rendering
void initRendering(){
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

float _angle = 30.0f;
float _translate = 0.2f;


//Draws the 3D scene
void drawScene(){
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glPushMatrix();
	glRotatef(_angle, 0.0f, 0.0f, 1.0f);
	glScalef(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//Trapezoid
	glColor3f(0.0f, 0.5f, 0.2f);
	glVertex3f(0.3f, 0.3f, 0.0f);  //front side
	glColor3f(0.0f, 0.7f, 0.3f);
	glVertex3f(-0.3f, 0.3f, 0.0f);
    glColor3f(0.4f, 0.1f, 0.3f);
	glVertex3f(-0.3f, -0.3f, 0.0f);
	glColor3f(0.5f, 0.6f, 0.3f);
	glVertex3f(0.3f, -0.3f, 0.0f);
	
	glColor3f(0.9f, 0.7f, 0.3f);
	glVertex3f(-0.3f, -0.3f, 0.0f); //left side
    glColor3f(0.4f, 1.0f, 0.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);
	glColor3f(0.1f, 0.4f, 0.3f);
	glVertex3f(-0.75f, 0.75f, -5.0f);
    glColor3f(0.0f, 0.9f, 0.0f);
	glVertex3f(-0.75f, -0.75f, -5.0f);
	
    glColor3f(0.0f, 0.1f, 0.1f);
	glVertex3f(0.3f, -0.3f, 0.0f);  //right side
    glColor3f(1.0f, 0.9f, 0.2f);
	glVertex3f(0.3f, 0.3f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.3f);
	glVertex3f(0.75f, 0.75f, -5.0f);
	glColor3f(0.2f, 0.9f, 0.3f);
	glVertex3f(0.75f, -0.75f, -5.0f);
	
	
	glColor3f(0.2f, 0.9f, 0.3f);
	glVertex3f(0.75f, 0.75f, -5.0f);  //back side
	glColor3f(0.2f, 0.9f, 0.3f);
	glVertex3f(-0.75f, 0.75f, -5.0f);
	glColor3f(0.2f, 0.9f, 0.3f);
	glVertex3f(-0.75f, -0.75f, -5.0f);
    glColor3f(0.8f, 0.7f, 0.6f);
	glVertex3f(0.75f, -0.75f, -5.0f);
	
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);  //top side
	glColor3f(0.2f, 0.0f, 0.3f);
	glVertex3f(0.3f, 0.3f, 0.0f);
	glColor3f(0.2f, 0.9f, 0.0f);
	glVertex3f(0.75f, 0.75f, -5.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.75f, 0.75f, -5.0f);
	
    glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.3f, -0.3f, 0.0f);     //bottom side
	glColor3f(0.2f, 0.0f, 0.1f);
	glVertex3f(0.3f, -0.3f, 0.0f);
	glColor3f(0.7f, 0.3f, 0.3f);
	glVertex3f(0.75f, -0.75f, -5.0f);
	glColor3f(0.6f, 0.7f, 0.7f);
	glVertex3f(-0.75f, -0.75f, -5.0f);
	
	

	glEnd(); //End quadrilateral coordinates

	glPopMatrix();
	/*
	glBegin(GL_LINES); //Begin LINE coordinates

    //front side
	glVertex3f(0.3f, 0.3f, 0.0f); 
    glVertex3f(0.3f, -0.3f, 0.0f);

    glVertex3f(0.3f, -0.3f, 0.0f);
	glVertex3f(-0.3f, -0.3f, 0.0f);
	
	glVertex3f(-0.3f, -0.3f, 0.0f);
	glVertex3f(0.3f, -0.3f, 0.0f);
	
	glVertex3f(0.3f, -0.3f, 0.0f);
	glVertex3f(0.3f, 0.3f, 0.0f);

	//back side
	glVertex3f(0.75f, 0.75f, -5.0f);
	glVertex3f(0.75f, -0.75f, -5.0f);
	
	glVertex3f(0.75f, -0.75f, -5.0f);
	glVertex3f(-0.75f, -0.75f, -5.0f);
	
	glVertex3f(-0.75f, -0.75f, -5.0f);
	glVertex3f(-0.75f, 0.75f, -5.0f);
	
	glVertex3f(-0.75f, 0.75f, -5.0f);
	glVertex3f(0.75f, 0.75f, -5.0f);
	
	//join the front and back side

	glVertex3f(0.3f, 0.3f, 0.0f);
	glVertex3f(0.75f, 0.75f, -5.0f);
	
	glVertex3f(-0.3f, -0.3f, 0.0f);
	glVertex3f(-0.75f, -0.75f, -5.0f);
	
	glVertex3f(0.3f, -0.3f, 0.0f);
	glVertex3f(0.75f, -0.75f, -5.0f);

	glVertex3f(-0.3f, 0.3f, 0.0f);
	glVertex3f(-0.75f, 0.75f, -5.0f);
	
	


	glEnd(); //End LINE coordinates
	*/

	glutSwapBuffers(); //Send the 3D scene to the screen
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv){
	//Initizlize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypressing, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0);
	glutMainLoop(); //Start the main loop. glutMainLoop doesn't return
	return 0;
}
