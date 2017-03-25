// Template-Lab6.cpp, template untuk latihan penggunaan gluLookAt
// oleh Dadan Hardianto - Fasilkom UI 2014-2017

// Soal2 UTS
// Muhammad Iddad & Desi Ratna Mukti 
// 1306381603 & 1306397904

#include <stdlib.h>
#include <glut.h>
#include <iostream>

typedef struct _param {
	GLfloat eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz;
} param;

param parameter[8][5] = {
	{
		{  0.0, 10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
		{  0.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,  0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,-10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,-10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
	},
	{
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
		{ 10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{ 10.0,  0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{ 10.0,-10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	},
	{
		{  0.0, 10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
		{ 10.0, 10.0,  0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{ 10.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{ 10.0,-10.0,  0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,-10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
	},
	{
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
		{ 10.0, 10.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{ 10.0,  0.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{ 10.0,-10.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	},
	{
		{  0.0, 10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
		{  0.0, 10.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,  0.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,-10.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,-10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
	},
	{
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
		{-10.0, 10.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{-10.0,  0.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{-10.0,-10.0,-10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	},
	{
		{  0.0, 10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
		{-10.0, 10.0,  0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{-10.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{-10.0,-10.0,  0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,-10.0,  0.0, 0.0, 0.0, 0.1, 0.0, 1.0, 0.0 },
	},
	{
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
		{-10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{-10.0,  0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{-10.0,-10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },
		{  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
	},
};

// camera coordinates
int kx = 0;
int ky = 2;

// teapot coordinates
GLfloat tx = 0;
GLfloat ty = 0;
GLfloat tz = 0;
int tstate = 1;
GLfloat speed = 0.01;
//cube view volume
GLfloat vertices[] =
{ -10.0,-10.0,-10.0, 10.0,-10.0,-10.0,
   10.0, 10.0,-10.0,-10.0, 10.0,-10.0,
  -10.0,-10.0, 10.0, 10.0,-10.0, 10.0,
   10.0, 10.0, 10.0,-10.0, 10.0, 10.0 };

//cube index
GLubyte cubeIndices[] = { 0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4 };

int SetupViewport(int cx, int cy)
{

	glViewport(0, 0, cx, cy);
	return 1;
}

int SetupPerspectiveViewing(GLdouble aspect_ratio)
{
	gluPerspective(60.0f, aspect_ratio, -10.0f, 10.0f);
	return 1;
}

int SetupViewingTransform()
{

	gluLookAt(parameter[kx][ky].eyex, parameter[kx][ky].eyey, parameter[kx][ky].eyez, 
		parameter[kx][ky].centerx, parameter[kx][ky].centery, parameter[kx][ky].centerz, 
		parameter[kx][ky].upx, parameter[kx][ky].upy, parameter[kx][ky].upz);

	return 1;
}

void arrowInput(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (ky == 0 || ky == 4) {
			break;
		} else if (kx != 0) {
			kx--;
		}
		else {
			kx = 7;
		}
		break;
	case GLUT_KEY_LEFT:
		if (ky == 0 || ky == 4) {
			break;
		}
		else if (kx != 7) {
			kx++;
		}
		else {
			kx = 0;
		}
		break;
	case GLUT_KEY_DOWN:
		if (kx % 2 == 1 && ky == 1) {
			break;
		}
		else if(ky != 0) {
			ky--;
		}
		break;
	case GLUT_KEY_UP: 
		if (kx % 2 == 1 && ky == 3) {
			break;
		}
		if (ky != 4) {
			ky++;
		}
		break;
	}
	glLoadIdentity();
	SetupViewingTransform();
	glutPostRedisplay();
}
void keyboardInput(unsigned char key, int xmouse, int ymouse) {
	switch (key) {
	}
	
	glLoadIdentity();
	SetupViewingTransform();
	glutPostRedisplay();
}
int SetupLighting() //setup lighting and materials, will be explained later
{
	GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f }; //brass material
	GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
	GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f, 1.0f };
	GLfloat mat_shininess = { 27.8974f };
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0, 10.0, -20.0, 0.0 }; //light position

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	return 1;
}


void DrawBorder(void) //draw viewing volume
{
	glPushMatrix();
	//glColor3f( 0.0f, 0.0f, 1.0f );
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
	glPopMatrix();
}

void teapod(void) 
{
	glPushMatrix();
	glPolygonMode(GL_FRONT, GL_FILL);
	glTranslatef(tx, ty, tz);
	glutSolidTeapot(1.5);
	glPopMatrix();
}

void OnResizeWindow(int cx, int cy)
{

	GLdouble aspect_ratio; // width-height ratio

	if (0 >= cx || 0 >= cy)
	{
		return;
	}

	SetupViewport(cx, cy);

	aspect_ratio = (GLdouble)cx / (GLdouble)cy;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	SetupPerspectiveViewing(aspect_ratio);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	SetupViewingTransform();
}


void init(void)
{

	SetupLighting();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)

}
void idle() {
	switch (tstate) {
	case 1:
		if (tx <= 5.0) {
			tx += speed;
		}
		else {
			tstate = 2;
		}
		break;
	case 2:
		if (tx >= -5) {
			tx -= speed;
		}
		else {
			tstate = 3;
		}
		break;
	case 3:
		if (tx <= 0) {
			tx += speed;
		}
		else {
			tstate = 4;
		}
		break;
	case 4:
		if (ty <= 5) {
			ty += speed;
		}
		else {
			tstate = 5;
		}
		break;
	case 5:
		if (ty >= -5) {
			ty -= speed;
		}
		else {
			tstate = 6;
		}
		break;
	case 6:
		if (ty <= 0) {
			ty += speed;
		}
		else {
			tstate = 7;
		}
		break;
	case 7:
		if (tz <= 5) {
			tz += speed;
		}
		else {
			tstate = 8;
		}
		break;
	case 8:
		if (tz >= -5) {
			tz -= speed;
		}
		else {
			tstate = 9;
		}
		break;
	case 9:
		if (tz <= 0) {
			tz += speed;
		}
		else {
			tstate = 1;
		}
		break;
	}
	glLoadIdentity();
	SetupViewingTransform();
	glutPostRedisplay();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawBorder();
	teapod();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	int mode = GLUT_DOUBLE | GLUT_RGBA;

	glutInit(&argc, argv);
	glutInitDisplayMode(mode);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 150);
	glutCreateWindow("Soal2 UTS - Desi & Iddad");

	init();
	glutSpecialFunc(arrowInput);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(OnResizeWindow);
	glutKeyboardFunc(keyboardInput);
	glutMainLoop();

	return 0;
}