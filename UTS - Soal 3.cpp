/*
Referensi dari transformation.c
Nate Robins, 1997

Tool for teaching about OpenGL transformations.

Soal3 UTS
Muhammad Iddad & Desi Ratna Mukti
1306381603 & 1306397904

*/

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <glut.h>
#include "glm.cpp"


#pragma comment( linker, "/entry:\"mainCRTStartup\"" )  // set the entry point to be main()

// melahirkan obyek
struct Camera {
	float translation[3];
};
Camera camera[4];

//mode kamera yang aktif
int mode = ONE;
float rotasi = 0;
bool isRotating = 1;

typedef struct _cell {
	int id;
	int x, y;
	float min, max;
	float value;
	float step;
	char* info;
	char* format;
} cell;

cell scale[3] = {
	{ 8, 120, 120, -5.0, 5.0, 1.0, 0.01,
	"Specifies scale factor along X axis.", "%.2f" },
	{ 9, 180, 120, -5.0, 5.0, 1.0, 0.01,
	"Specifies scale factor along Y axis.", "%.2f" },
	{ 10, 240, 120, -5.0, 5.0, 1.0, 0.01,
	"Specifies scale factor along Z axis.", "%.2f" },
};

GLfloat eye[3] = { 0.0, 0.0, 2.0 };
GLfloat at[3] = { 0.0, 0.0, 0.0 };
GLfloat up[3] = { 0.0, 1.0, 0.0 };


GLboolean swapped = GL_FALSE;
GLboolean world_draw = GL_TRUE;
GLMmodel* pmodel = NULL;
GLint selection = 0;

void redisplay_all(void);
GLdouble projection[16], modelview[16], inverse[16];
GLuint window, obyek1, obyek2, obyek3, obyek4;
GLuint sub_width = 256, sub_height = 256;



void reshapeSeluruh(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)width / height, 0.01, 256.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
}

void reshapeObyek1(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)width / height, 0.5, 8.0);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	glTranslatef(camera[0].translation[0], camera[0].translation[1], camera[0].translation[2]);
	glScalef(scale[0].value, scale[1].value, scale[2].value);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glClearColor(0.2, 0.2, 0.2, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void reshapeObyek2(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)width / height, 0.5, 8.0);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	glRotatef(90, 0, 1, 0);
	glTranslatef(camera[1].translation[0], camera[1].translation[1], camera[1].translation[2]);
	glScalef(scale[0].value, scale[1].value, scale[2].value);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glClearColor(0.2, 0.2, 0.2, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void reshapeObyek3(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)width / height, 0.5, 8.0);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(camera[2].translation[0], camera[2].translation[1], camera[2].translation[2]);
	glScalef(scale[0].value, scale[1].value, scale[2].value);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glClearColor(0.2, 0.2, 0.2, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void reshapeObyek4(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)width / height, 0.5, 8.0);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	glTranslatef(camera[3].translation[0], camera[3].translation[1], camera[3].translation[2]);
	glRotatef(180, 0, 1, 0);
	glScalef(scale[0].value, scale[1].value, scale[2].value);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glClearColor(0.2, 0.2, 0.2, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

// menggambar obyek di tengah kotak
void gambarObyek(void)
{
	if (!pmodel) {
		pmodel = glmReadOBJ("data/flowers.obj");
		if (!pmodel) exit(0);
		glmUnitize(pmodel);
		glmFacetNormals(pmodel);
		glmVertexNormals(pmodel, 90.0);
	}

	glRotatef(rotasi, 0, 1, 0);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}



// method untuk mengaktifkan screen untuk digeser-geser
void main_keyboard(unsigned char key, int x, int y)
{

	switch (key) {
	case '1':
		mode = ONE;
		break;
	case '2':
		mode = TWO;
		break;
	case '3':
		mode = THREE;
		break;
	case '4':
		mode = FOUR;
		break;

		// berhenti rotasi
	case 's':
		isRotating = !isRotating;
	}
	redisplay_all();
}

// klik 1/2/3/4 lalu gerakkan dengan klik tombol panah
void arrow(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		if (mode == ONE & camera[0].translation[1] < 1) camera[0].translation[1] += 0.05;
		if (mode == TWO & camera[1].translation[1] < 1) camera[1].translation[1] += 0.05;
		if (mode == THREE & camera[2].translation[1] < 1) camera[2].translation[1] += 0.05;
		if (mode == FOUR & camera[3].translation[1] < 1) camera[3].translation[1] += 0.05;
		break;
	case GLUT_KEY_DOWN:
		if (mode == ONE & camera[0].translation[1] > -1) camera[0].translation[1] -= 0.05;
		if (mode == TWO & camera[1].translation[1] > -1) camera[1].translation[1] -= 0.05;
		if (mode == THREE & camera[2].translation[1] > -1) camera[2].translation[1] -= 0.05;
		if (mode == FOUR & camera[3].translation[1] > -1) camera[3].translation[1] -= 0.05;
		break;
	case GLUT_KEY_LEFT:
		if (mode == ONE & camera[0].translation[0] > -1) camera[0].translation[0] -= 0.05;
		if (mode == TWO & camera[1].translation[2] > -1) camera[1].translation[2] -= 0.05;
		if (mode == THREE & camera[2].translation[2] < 1) camera[2].translation[2] += 0.05;
		if (mode == FOUR & camera[3].translation[0] > -1) camera[3].translation[0] -= 0.05;
		break;
	case GLUT_KEY_RIGHT:
		if (mode == ONE & camera[0].translation[0] < 1) camera[0].translation[0] += 0.05;
		if (mode == TWO & camera[1].translation[2] < 1) camera[1].translation[2] += 0.05;
		if (mode == THREE & camera[2].translation[2] > -1) camera[2].translation[2] -= 0.05;
		if (mode == FOUR & camera[3].translation[0] < 1) camera[3].translation[0] += 0.05;
		break;
	}

	redisplay_all();
}


void screen_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gambarObyek();
	glutSwapBuffers();
}

void redisplay_all(void)
{
	glutSetWindow(window);
	glutPostRedisplay();
	glutSetWindow(obyek1);
	reshapeObyek1(sub_width, sub_height);
	glutPostRedisplay();
	glutSetWindow(obyek2);
	reshapeObyek2(sub_width, sub_height);
	glutPostRedisplay();
	glutSetWindow(obyek3);
	reshapeObyek3(sub_width, sub_height);
	glutPostRedisplay();
	glutSetWindow(obyek4);
	reshapeObyek4(sub_width, sub_height);
	glutPostRedisplay();
}

// method untuk menampilkan animasi rotasi pada obyek bunga
void animation() {
	if (isRotating) rotasi += 0.1;
	redisplay_all();
}

void main_display(void)
{
	glClearColor(0.8, 0.8, 0.8, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(0, 0, 0);
	glutSwapBuffers();
}

void reshapeModel(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	#define spasi  20 
	sub_width = (width - spasi * 3) / 2.0;
	sub_height = (height - spasi * 3) / 2.0;

	glutSetWindow(obyek1);
	glutPositionWindow(spasi, spasi);
	glutReshapeWindow(sub_width, sub_height);
	glutSetWindow(obyek2);
	glutPositionWindow(spasi + sub_width + spasi, spasi);
	glutReshapeWindow(sub_width, sub_height);
	glutSetWindow(obyek3);
	glutPositionWindow(spasi, spasi + sub_height + spasi);
	glutReshapeWindow(sub_width, sub_height);
	glutSetWindow(obyek4);
	glutPositionWindow(spasi + sub_width + spasi, spasi + sub_height + spasi);
	glutReshapeWindow(sub_width, sub_height);
}

int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(512 + spasi * 3, 512 + spasi * 3);
	glutInitWindowPosition(50, 50);
	glutInit(&argc, argv);

	window = glutCreateWindow("Soal3 UTS - Desi & Iddad");
	glutKeyboardFunc(main_keyboard);
	glutSpecialFunc(arrow);
	glutReshapeFunc(reshapeModel);
	glutDisplayFunc(main_display);

	obyek1 = glutCreateSubWindow(window, spasi, spasi, 256, 256);
	glutKeyboardFunc(main_keyboard);
	glutSpecialFunc(arrow);
	glutReshapeFunc(reshapeObyek1);
	glutDisplayFunc(screen_display);

	obyek2 = glutCreateSubWindow(window, spasi + 256 + spasi, spasi, 256, 256);
	glutKeyboardFunc(main_keyboard);
	glutSpecialFunc(arrow);
	glutReshapeFunc(reshapeObyek2);
	glutDisplayFunc(screen_display);

	obyek3 = glutCreateSubWindow(window, spasi, spasi + 256 + spasi, 256, 256);
	glutKeyboardFunc(main_keyboard);
	glutSpecialFunc(arrow);
	glutReshapeFunc(reshapeObyek3);
	glutDisplayFunc(screen_display);

	obyek4 = glutCreateSubWindow(window, spasi + 256 + spasi, spasi + 256 + spasi, 256, 256);
	glutKeyboardFunc(main_keyboard);
	glutSpecialFunc(arrow);
	glutReshapeFunc(reshapeObyek4);
	glutDisplayFunc(screen_display);
	redisplay_all();
	glutIdleFunc(animation);
	glutMainLoop();

	return 0;
}
