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
	glEnable(GL_COLOR_MATERIAL);
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

//Draws the 3D scene
void drawScene(){
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
 	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0f, 0.0f, -5.0f);

	glPushMatrix();
	glTranslatef(0.0f, -1.0f, 0.0f);
	//glRotatef(_angle, 0.0f, 0.0f,1.0f); //Rotate about the z-axis

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//Parallelogram
	
    glColor3f(0.0f, 1.0f, 0.3f);
	glVertex3f(0.7f, 0.3f, 0.0f);
    glColor3f(0.5f, 0.0f, 0.3f);
	glVertex3f(-0.7f, 0.3f, 0.0f);
    glColor3f(0.3f, 0.8f, 0.0f);
	glVertex3f(-0.4f, -0.3f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.3f);
	glVertex3f(1.0f, -0.3f, 0.0f);

	//front bottom quad


	glEnd(); //End quadrilateral coordinates

	
	glBegin(GL_QUADS);
	glColor3f(0.8f,0.2f,0.0f);
    glVertex3f(0.9f, -0.20f, 0.0f);
    glVertex3f(0.9f, -0.7f, 0.0f);
    glVertex3f(-0.45f, -0.75f, 0.0f);
    glVertex3f(-0.45f, -0.20f, 0.0f);
    
    

    //glVertex3f(0.85f, -1.8f, 0.0f);
    //glVertex3f(-0.45f, -1.85f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5f,0.0f,0.5f);
	glVertex3f(-0.7f, 0.3f, 0.0f);
	glVertex3f(-0.45f, -0.20f, 0.0f);
	glVertex3f(-0.45f, -0.75f, 0.0f);
	glVertex3f(-0.9f, -0.7f, 0.0f);
	glVertex3f(-0.9f, -0.20f, 0.0f);
	glEnd();

/*
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f); //Rotate about the y-axis
    glScalef(0.7f, 0.7f, 0.7f);

	glBegin(GL_TRIANGLES); //Begin triangle coordinates

	//Pentagon
	glColor3f(0.5f, 1.0f, 0.8f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glColor3f(0.2f, 0.2f, 0.3f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

    glColor3f(0.5f, 0.6f, 0.3f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glColor3f(0.2f, 0.6f, 0.3f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glColor3f(0.6f, 0.0f, 0.3f);
	glVertex3f(0.5f, 0.0f, 0.0f);

    glColor3f(0.5f, 0.6f, 0.3f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.2f, 0.3f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.3f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();

	glPopMatrix(); //Undo the move to the center of the pentagon
    glPushMatrix(); //Save the current state of transformations
    glTranslatef(-1.0f, 1.0f, 0.0f); //Move to the center of the triangle
    glRotatef(_angle, 1.0f, 2.0f, 3.0f); //Rotate about the vector (1, 2, 3)

	glBegin(GL_TRIANGLES);

	//Triangle
    glColor3f(0.3f, 1.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.3f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(0.5f, 0.9f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glEnd(); //End triangle coordinates
	glPopMatrix();
*/
glPopMatrix();
	glutSwapBuffers(); //Send the 3D scene to the screen
}

void update(int value){
	_angle += 2.0f;
	if(_angle > 360){
		_angle -= 360;
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
