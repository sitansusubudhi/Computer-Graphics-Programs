#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include "math.h"

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

static GLfloat _angleRotate[]={0.0f,0.0f,0.0f};
GLint axis =1;

float _angle = 90.0f;


void mouseButtonpress(int button,int state,int x,int y){
    if(button== GLUT_LEFT_BUTTON && state ==GLUT_DOWN) axis =0;
	if(button== GLUT_MIDDLE_BUTTON && state ==GLUT_DOWN) axis =1;
	if(button== GLUT_RIGHT_BUTTON && state ==GLUT_DOWN) axis =2;

}

/*void drawCircle(float radius, float x1, float y1)
{
 float angle = 0;
 float x2,y2,cx,cy,fx,fy;
 int cache = 0;
 glBegin(GL_LINES);
 for (angle = 0; angle < 360; angle+=1.0) {
  float rad_angle = angle * 3.14 / 180;
  x2 = radius * sin((double)rad_angle);
  y2 = radius * cos((double)rad_angle);
  if (cache) {
   glVertex2f(cx,cy);
   glVertex2f(x2,y2);

  } else {
   fx = x2;
   fy = y2;
  }
  cache = 1;
     cx = x2;
  cy = y2;
 }
 glVertex2f(x2,y2);
 glVertex2f(fx,fy);

 glEnd();
}
*/
void update(int value){
	_angleRotate[axis] += 2.0f;
	if(_angleRotate[axis] > 360){
		_angleRotate[axis]-= 360;
	}

	glutPostRedisplay();    //Tells GLUT that the scene has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

void display(void) {
 glClearColor (0.0,0.0,0.0,1.0);
 glClear (GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(-10,0,-70);
 glColor3f(1,0,0);
 //drawCircle(10,0,0);
 float angle = 0;
 int radius = 10;
 float x2,y2,cx,cy,fx,fy;
 int cache = 0;
 
 glBegin(GL_LINES);
 for (angle = 0; angle < 360; angle+=1.0) {
  float rad_angle = angle * 3.14 / 180;
  x2 = radius * sin((double)rad_angle);
  y2 = radius * cos((double)rad_angle);
  if (cache) {
   glVertex2f(cx,cy);
   glVertex2f(x2,y2);

  } else {
   fx = x2;
   fy = y2;
  }
  cache = 1;
     cx = x2;
  cy = y2;
 }
 glVertex2f(x2,y2);
 glVertex2f(fx,fy);

 glEnd();

//glRotatef(_angleRotate[0], 1.0f, 0.0f,0.0f);
//	glRotatef(_angleRotate[1], 0.0f, 1.0f,0.0f);
    glRotatef(_angleRotate[2], 0.0f, 0.0f,1.0f);
    glPushMatrix();
glTranslatef(20,0,0);
glColor3f(0,1,0);
float angle2 = 0;
float x22,y22,cx2,cy2,fx2,fy2;
int radius2 = 10;
glBegin(GL_LINES);

for (angle2 = 0; angle2 < 360; angle2+=1.0) {
  float rad_angle2 = angle2 * 3.14 / 180;
  x22 = radius2 * sin((double)rad_angle2);
  y22 = radius2 * cos((double)rad_angle2);
  if (cache) {
   glVertex2f(cx2,cy2);
   glVertex2f(x22,y22);

  } else {
   fx2 = x22;
   fy2 = y22;
  }
  cache = 1;
     cx2 = x22;
  cy2 = y22;
 }
 glVertex2f(x22,y22);
 glVertex2f(fx2,fy2);


 glEnd();
glPopMatrix();

 glutSwapBuffers();
}

void reshape (int w, int h) {
 glViewport (0, 0, (GLsizei)w, (GLsizei)h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
 glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main (int argc, char **argv) {
 glutInit (&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE);
 glutInitWindowSize (1200, 800);
 glutInitWindowPosition (0, 0);
 glutCreateWindow ("A Pendulum");

 glutDisplayFunc (display);
 glutIdleFunc (display);
 glutReshapeFunc (reshape);
    glutKeyboardFunc (keyboard);
    glutMouseFunc(mouseButtonpress);
    glutTimerFunc(25, update, 0);
 glutMainLoop ();
 return 0;
}
