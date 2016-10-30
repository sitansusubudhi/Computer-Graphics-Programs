#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> //Needed for "exit" function

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>

#include <windows.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
                                        int x, int y) {    //The current mouse coordinates
        switch (key) {
                case 27: //Escape key
                        exit(0); //Exit the program
        }
}

//Initializes 3D rendering
void initRendering() {
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

void drawLine(float m, float c){
    glBegin(GL_POINTS);
    glColor3f(c*0.2,1,c);
    double y=0;
    double x=0;
    if(m<1){
        for(int i =0;i<20;i++){
            glVertex3f(x*0.01,y*0.01,-2);
            glVertex3f(-(x*0.01),y*0.01,-2);
            y=y+m;
            x++;
        }
    }
    else {
        if(m==99){
            for(int i =0; i<20; i++) {
                    glVertex3f(x*0.01,y*0.01,-2);
                    y++;

                }
            }
        else{
        	double m1=1/m;
        	for(int i =0; i<20; i++){
            	glVertex3f(x*0.01,y*0.01,-2);
           		glVertex3f(-(x*0.01),y*0.01,-2);
           		y++;
            	x=x+m1;
			}
        }
        }

    glEnd();
}


void disp_Line() {
      
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
        glLoadIdentity(); //Reset the drawing perspective

        float m = sqrt(0); //0 degree
        drawLine(m, 0.1);

        m = sqrt(0.333);  //30 degree
        drawLine(m, 0.5);

    	m = 1;  //45 degree
        drawLine(m, 0.8);

        m= sqrt(3); // 60 degree
    	drawLine(m, 0.75);

    	m = 99;     //90 degree
    	drawLine(m, 0.1);
    	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
        
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(700, 700); 

        //Create the window
        glutCreateWindow("Line Drawing");
        initRendering(); //Initialize rendering

        glutDisplayFunc(disp_Line);
        glutKeyboardFunc(handleKeypress);
        glutReshapeFunc(handleResize);

        glutMainLoop();
        return 0; 
}
