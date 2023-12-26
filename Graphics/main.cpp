// 206262719_208140111

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include <vector>
using namespace std;


const int W = 600;
const int H = 600;
const double PI = 3.14;

double offset = 0;
bool isMoving = false;
double radius = 0.02;
double bx = 0.5, by = 0;
double bx0 = 0.5, by0 = 0, vx, vy, a = -3, t = 0;


void init()
{
	int i, j;
	srand(time(0));

	glClearColor(0, 0.5,1, 0);// color of window background

}


void DrawWheel()
{
	double alpha, teta = PI / 60;
	double x, y;

	glColor3d(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	for (alpha = 0; alpha <= 2 * PI; alpha += teta)
	{
		x = cos(alpha);
		y = sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();

	teta = PI / 6;
	glBegin(GL_LINES);
	for (alpha = 0; alpha <= 2 * PI; alpha += teta)
	{
		x = cos(alpha);
		y = sin(alpha);
		glVertex2d(x, y);
		glVertex2d(0, 0);
	}
	glEnd();

}

void DrawBall()
{
	double alpha, teta = PI / 60;
	double x, y;
	// ball
	glColor3d(1, 0.6, 0);
	glBegin(GL_POLYGON);
	for (alpha = 0; alpha <= 2 * PI; alpha += teta)
	{
		x = cos(alpha);
		y = sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (alpha = 0; alpha <= 2 * PI; alpha += teta)
	{
		x = cos(alpha);
		y = sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();
	// lines

	glBegin(GL_LINES);
	glVertex2d(-1, 0);
	glVertex2d(1, 0);
	glVertex2d(0, -1);
	glVertex2d(0, 1);

	glEnd();

	glPushMatrix();
	glTranslated(-1.5, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (alpha = -PI / 4; alpha <= PI / 4; alpha += teta)
	{
		x = cos(alpha);
		y = sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScaled(-1, 1, 1);
	glTranslated(-1.5, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (alpha = -PI / 4; alpha <= PI / 4; alpha += teta)
	{
		x = cos(alpha);
		y = sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();
	glPopMatrix();

}


void DrawFloor()
{
	// floor
	glColor3d(0.5, 0.2, 0);
	glBegin(GL_POLYGON);
	glVertex2d(-1, -0.8);
	glVertex2d(1, -0.8);
	glVertex2d(1, -1);
	glVertex2d(-1, -1);
	glEnd();


}

void drawBasket() { 
	
	// basket
	glLineWidth(6);
	glColor3d(0.8, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2d(-1, 0.5);
	glVertex2d(-0.6, 0.5);
	
	glEnd();

	//net
	glLineWidth(1);
	glColor3d(1, 1, 1);
	
	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.9, 0.5);
	glVertex2d(-0.85, 0.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.6, 0.5);
	glVertex2d(-0.65, 0.3);
	glEnd();

	
	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.89, 0.45);
	glVertex2d(-0.61, 0.45);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.88, 0.4);
	glVertex2d(-0.62, 0.4);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.86, 0.35);
	glVertex2d(-0.64, 0.35);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.85, 0.3);
	glVertex2d(-0.65, 0.3);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.88, 0.5);
	glVertex2d(-0.88, 0.45);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.85, 0.5);
	glVertex2d(-0.85, 0.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.80, 0.5);
	glVertex2d(-0.80, 0.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.75, 0.5);
	glVertex2d(-0.75, 0.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.65, 0.5);
	glVertex2d(-0.65, 0.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.7, 0.5);
	glVertex2d(-0.70, 0.3);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(-0.62, 0.5);
	glVertex2d(-0.62, 0.45);
	glEnd();
	

	//board
	glLineWidth(3);
	glColor3d(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2d(-1, 0.49);
	glVertex2d(-1, 0.75);
	glVertex2d(-0.95, 0.75);
	glVertex2d(-0.95, 0.49);
	glEnd();
	

}





// put here all the drawings
void display()
{
	double y, beta;
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer
	glLoadIdentity();// set Transformation matrix to unity

	glPushMatrix();
	glTranslated(bx, by, 0);
	glScaled(0.1, 0.1, 1);
	glRotated(offset, 0, 0, 1);
	DrawBall();
	glPopMatrix();
	DrawFloor();
	drawBasket();


	glutSwapBuffers(); // show the hidden buffer and switch to the active buffer
}


void idle()
{
	offset += 0.05;

	if (isMoving) // compute new ball position
	{
		t += 0.00018;
		bx = bx0 + vx * t;
		by = by0 + vy * t + a * t * t;

		// wall bouncing
		if (vx < 0 && bx - 0.1 < -1 || vx > 0 && bx + 0.1 > 1)
		{ // start new motion
			bx0 = bx;
			by0 = by;
			vx = -vx;
			vy = vy + 2 * a * t;
			t = 0; // time counter

		}
		// floor bouncing
		if ((by - 0.1) < -0.8 && vy + 2 * a * t < 0  || (by - 0.1) > 0.9 )
		{ // start new motion
			bx0 = bx;
			by0 = by;
			vy = -0.95 * (vy + 2 * a * t);
			t = 0; // time counter

		}
		
		
		// board collision
		if (vx < 0 && (bx - 0.1) < -0.95 && (by - 0.1) > 0.35 && (by - 0.1) <  0.75 )
		{
			bx0 = bx;
			by0 = by;
			vx = -vx;
			vy = vy + 2 * a * t;
			t = 0; // time counter

		}
		
		// basket collision
		if ( bx  < -0.5 && bx > -0.6) {
			if ( (by) > 0.45 && (by) < 0.55)
			{
				bx0 = bx;
				by0 = by;
				vx = -vx;
				vy = vy + 2 * a * t;
				t = 0; // time counter

			}
		}

		if (bx <= -0.8) {
			if (vy > 0 && (by) > 0.45 && (by) < 0.55)
			{
				bx0 = bx;
				by0 = by;
				vx = -vx;
				vy = vy + 2 * a * t;
				t = 0; // time counter

			}
		}
		
		
	}
	glutPostRedisplay(); // indirect call to display
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // start rectangle
	{
		// x and y is the mouse click
		double xx, yy;
		xx = 2 * (x / (double)W) - 1; // xx is now in range [-1..1]
		yy = 2 * ((H - y) / (double)H) - 1; // yy is now in range [-1..1]
		// start moving ball
		isMoving = true;
		bx0 = bx;
		by0 = by;
		vx = 3.5 * (xx - bx); // difference between click and current ball position
		vy = 3.5 * (yy - by);
		t = 0; // time counter
	}

}





void main(int argc, char* argv[])
{
	glutInit(&argc, argv);  // add windowing
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // each pixel is based on RGB values and there are 2 buffers
	glutInitWindowSize(W, H);
	glutInitWindowPosition(400, 100); // pixel coordinates of top left corner of the window
	glutCreateWindow("Let's play basketball");

	glutDisplayFunc(display); // display is the function of window refresh (drawings)
	glutIdleFunc(idle); // idle is the function that runs on background and changes visual parameters

	// mouse
	glutMouseFunc(mouse);
	// keyboard
	//glutKeyboardFunc(keyboard);

	// menu


	init();

	glutMainLoop();
}