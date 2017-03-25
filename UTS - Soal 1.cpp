// Template-Lab6.cpp, template untuk latihan penggunaan gluLookAt
// oleh Dadan Hardianto - Fasilkom UI 2014-2017

// Jawaban Lab6 B
// Muhammad Iddad
// 1306381603

#define NONE 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define HOR 5
#define VER 6
#define BOTH 7

#include <stdlib.h>
#include <glut.h>
#include <iostream>

GLfloat wh = 500.0;
GLfloat ww = 500.0;

GLfloat r = 0.0; GLfloat g = 0.0; GLfloat b = 0.0;

GLint lx1 = ww/2; GLint lx2 = ww/2;
GLint ly1 = wh/2; GLint ly2 = wh/2;

GLint mx1 = ww/2; GLint mx2 = ww/2;
GLint my1 = wh/2; GLint my2 = wh/2;

GLint nx1 = ww/2; GLint nx2 = ww/2;
GLint ny1 = wh/2; GLint ny2 = wh/2;

GLint ox1 = ww/2; GLint ox2 = ww/2;
GLint oy1 = wh/2; GLint oy2 = wh/2;

int delay = 10;
bool isRun = false;
int state = NONE;
int mode = VER;

void clear() {
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	lx1 = ww / 2; lx2 = ww / 2; ly1 = wh / 2; ly2 = wh / 2;
	mx1 = ww / 2; mx2 = ww / 2; my1 = wh / 2; my2 = wh / 2;
	nx1 = ww / 2; nx2 = ww / 2; ny1 = wh / 2; ny2 = wh / 2;
	ox1 = ww / 2; ox2 = ww / 2; oy1 = wh / 2; oy2 = wh / 2;
	isRun = false;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void arrowInput(int key, int x, int y) {
	isRun = true;
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (state != RIGHT && state != LEFT) {
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			state = RIGHT;
		}
		break;
	case GLUT_KEY_LEFT:
		if (state != RIGHT && state != LEFT) {
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			state = LEFT;
		}
		break;
	case GLUT_KEY_UP:
		if (state != UP && state != DOWN) {
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			state = UP;
		}
		break;
	case GLUT_KEY_DOWN:
		if (state != UP && state != DOWN) {
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			state = DOWN;
		}
		break;
	}
}

void idle() {
	if (isRun) {
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glColor3f(r, g, b);
		switch (state) {
		case UP:
			if (ly2 < wh) {
				ly2++;
				glBegin(GL_LINES);
				glVertex2i(lx1, ly1);
				glVertex2i(lx2, ly2);
				glEnd(); 
				if (mode == VER || mode == BOTH) {
					my2++;
					glBegin(GL_LINES);
					glVertex2i(mx1, my1);
					glVertex2i(mx2, my2);
					glEnd();
				}
				if (mode == HOR || mode == BOTH) {
					ny2--;
					glBegin(GL_LINES);
					glVertex2i(nx1, ny1);
					glVertex2i(nx2, ny2);
					glEnd();
				}
				if (mode == BOTH) {
					oy2--;
					glBegin(GL_LINES);
					glVertex2i(ox1, oy1);
					glVertex2i(ox2, oy2);
					glEnd();
				}
			}
			break;
		case DOWN:
			if (ly2 > 0) {
				ly2--;
				glBegin(GL_LINES);
				glVertex2i(lx1, ly1);
				glVertex2i(lx2, ly2);
				glEnd();
				if (mode == VER || mode == BOTH) {
					my2--;
					glBegin(GL_LINES);
					glVertex2i(mx1, my1);
					glVertex2i(mx2, my2);
					glEnd();
				}
				if (mode == HOR || mode == BOTH) {
					ny2++;
					glBegin(GL_LINES);
					glVertex2i(nx1, ny1);
					glVertex2i(nx2, ny2);
					glEnd();
				}
				if (mode == BOTH) {
					oy2++;
					glBegin(GL_LINES);
					glVertex2i(ox1, oy1);
					glVertex2i(ox2, oy2);
					glEnd();
				}
			}
			break;
		case LEFT:
			if (lx2 > 0) {
				lx2--;
				glBegin(GL_LINES);
				glVertex2i(lx1, ly1);
				glVertex2i(lx2, ly2);
				glEnd();
				if (mode == VER || mode == BOTH) {
					mx2++;
					glBegin(GL_LINES);
					glVertex2i(mx1, my1);
					glVertex2i(mx2, my2);
					glEnd();
				}
				if (mode == HOR || mode == BOTH) {
					nx2--;
					glBegin(GL_LINES);
					glVertex2i(nx1, ny1);
					glVertex2i(nx2, ny2);
					glEnd();
				}
				if (mode == BOTH) {
					ox2++;
					glBegin(GL_LINES);
					glVertex2i(ox1, oy1);
					glVertex2i(ox2, oy2);
					glEnd();
				}
			}
			break;
		case RIGHT:
			if (lx2 < ww) {
				lx2++;
				glBegin(GL_LINES);
				glVertex2i(lx1, ly1);
				glVertex2i(lx2, ly2);
				glEnd();
				if (mode == VER || mode == BOTH) {
					mx2--;
					glBegin(GL_LINES);
					glVertex2i(mx1, my1);
					glVertex2i(mx2, my2);
					glEnd();
				}
				if (mode == HOR || mode == BOTH) {
					nx2++;
					glBegin(GL_LINES);
					glVertex2i(nx1, ny1);
					glVertex2i(nx2, ny2);
					glEnd();
				}
				if (mode == BOTH) {
					ox2--;
					glBegin(GL_LINES);
					glVertex2i(ox1, oy1);
					glVertex2i(ox2, oy2);
					glEnd();
				}
			}
			break;
		}
		glPopAttrib();
		glFlush();
		_sleep(delay);
	}
}

void keyboardInput(unsigned char key, int xmouse, int ymouse) {
	switch (key) {
		case '1':
			mode = VER;
			clear();
			break;
		case '2':
			mode = HOR;
			clear();
			break;
		case '3':
			mode = BOTH;
			clear();
			break;
		case 's': 
			isRun = !isRun;
			break;
		case 'a':
			if (delay > 5) {
				delay--;
			}
			break;
		case 'd':
			if (delay < 30) {
				delay++;
			}
			break;
		case 'c':
			clear();
			break;
		case 'q':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 0.0; g = 0.0; b = 0.0;
			break;
		case 'w':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 1.0; g = 0.0; b = 0.0;
			break;
		case 'e':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 0.0; g = 1.0; b = 0.0;
			break;
		case 'r':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 0.0; g = 0.0; b = 1.0;
			break;
		case 't':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 1.0; g = 1.0; b = 0.0;
			break;
		case 'y':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 1.0; g = 0.0; b = 1.0;
			break;
		case 'u':
			lx1 = lx2; ly1 = ly2;
			mx1 = mx2; my1 = my2;
			nx1 = nx2; ny1 = ny2;
			ox1 = ox2; oy1 = oy2;
			r = 0.0; g = 1.0; b = 1.0;
	}
}
void myinit(void)
{

	glViewport(0, 0, ww, wh);


	/* Pick 2D clipping window to match size of X window
	This choice avoids having to scale object coordinates
	each time window is resized */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)ww, 0.0, (GLdouble)wh, -1.0, 1.0);
	/* set clear color to black and clear window */

	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{

	/* adjust clipping box */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* adjust viewport and  clear */

	ww = w;
	wh = h;
	glViewport(0, 0, w, h);
	clear();
	glFlush();

	/* set global size for use by drawing routine */


}

void display(void)
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(r, g, b);
	glBegin(GL_LINES);
	glVertex2i(lx1, ly1);
	glVertex2i(lx2, ly2);
	glEnd();
	glPopAttrib();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("Sesuatu");
	glutSpecialFunc(arrowInput);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(keyboardInput);
	myinit();
	glutMainLoop();
}