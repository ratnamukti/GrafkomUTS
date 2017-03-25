/**
* UTS Nomor 2
* Desi Ratna Mukti Umpuan & Muhammad Iddad Izzatul Ummah
* 1306397904 & 1306381603
**/

// Disable Console for Executable File
// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <stdio.h>
#include <glut.h>

//cube volume
GLfloat vertices[] =
{ -10.0, -10.0, -10.0, 10.0, -10.0, -10.0,
10.0, 10.0, -10.0, -10.0, 10.0, -10.0,
-10.0, -10.0, 10.0, 10.0, -10.0, 10.0,
10.0, 10.0, 10.0, -10.0, 10.0, 10.0 };

// cube index
GLubyte cubeIndices[] = { 0, 3, 2, 1, 2, 3, 7, 6, 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4 };

// camera parameter
GLfloat eyex = 0.0, eyey = 0.0, eyez = 10.0,
centerx = 0.0, centery = 0.0, centerz = 0.0,
upx = 0.0, upy = 1.0, upz = 0.0;

// position
GLfloat teapotPos[] = { 0,0,0 };
GLint camPos[] = { 0,0,1 };

// state
GLint teapotState = 1;
GLfloat teapotSpeed = 0.005;
GLfloat teapotMaxPos = 3;
bool teapotStop = false;

int SetupViewport(int cx, int cy)
{
	glViewport(0, 0, cx, cy);
	return 1;
}

int SetupPerspectiveViewing(GLdouble aspect_ratio)
{
	gluPerspective(60.0f, aspect_ratio, 1.0f, 256.0f);
	return 1;
}

int SetupViewingTransform()
{
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	return 1;
}


int SetupLighting()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess = { 100.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 10.0, 10.0, -10.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	return 1;
}

void idle() {
	glLoadIdentity();
	// teapot animation states
	if (teapotState == 1) {
		if (teapotPos[2] < teapotMaxPos) {
			teapotPos[2] += teapotSpeed;
		}
		else {
			teapotState = 2;
		}
	}
	if (teapotState == 2) {
		if (teapotPos[2] > 0) {
			teapotPos[2] -= teapotSpeed;
		}
		else {
			teapotState = 3;
		}
	}
	if (teapotState == 3) {
		if (teapotPos[2] > -teapotMaxPos) {
			teapotPos[2] -= teapotSpeed;
		}
		else {
			teapotState = 4;
		}
	}
	if (teapotState == 4) {
		if (teapotPos[2] < 0) {
			teapotPos[2] += teapotSpeed;
		}
		else {
			teapotState = 5;
		}
	}
	if (teapotState == 5) {
		if (teapotPos[0] < teapotMaxPos) {
			teapotPos[0] += teapotSpeed;
		}
		else {
			teapotState = 6;
		}
	}
	if (teapotState == 6) {
		if (teapotPos[0] > 0) {
			teapotPos[0] -= teapotSpeed;
		}
		else {
			teapotState = 7;
		}
	}
	if (teapotState == 7) {
		if (teapotPos[0] > -teapotMaxPos) {
			teapotPos[0] -= teapotSpeed;
		}
		else {
			teapotState = 8;
		}
	}
	if (teapotState == 8) {
		if (teapotPos[0] < 0) {
			teapotPos[0] += teapotSpeed;
		}
		else {
			teapotState = 9;
		}
	}
	if (teapotState == 9) {
		if (teapotPos[1] < teapotMaxPos) {
			teapotPos[1] += teapotSpeed;
		}
		else {
			teapotState = 10;
		}
	}
	if (teapotState == 10) {
		if (teapotPos[1] > 0) {
			teapotPos[1] -= teapotSpeed;
		}
		else {
			teapotState = 11;
		}
	}
	if (teapotState == 11) {
		if (teapotPos[1] > -teapotMaxPos) {
			teapotPos[1] -= teapotSpeed;
		}
		else {
			teapotState = 12;
		}
	}
	if (teapotState == 12) {
		if (teapotPos[1] < 0) {
			teapotPos[1] += teapotSpeed;
		}
		else {
			teapotState = 1;
		}
	}
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's': // play animation
		if (teapotStop) {
			teapotSpeed = 0.005;
			teapotStop = false;
		}
		else { // stop animation
			teapotSpeed = 0;
			teapotStop = true;
		}
		break;
	}
}

void special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		glLoadIdentity();
		// check camera position state
		// and move the camera based on that state
		if (camPos[0] == 1) {
			if (camPos[2] == 1) {
				camPos[2] -= 1;
				eyez -= 10;
			}
			else if (camPos[2] == 0) {
				camPos[2] -= 1;
				eyez -= 10;
			}
			else {
				camPos[0] -= 1;
				eyex -= 10;
			}
		}
		else if (camPos[0] == 0) {
			if (camPos[2] == 1) {
				camPos[0] += 1;
				eyex += 10;
			}
			else if (camPos[2] == 0) {
				camPos[0] -= 1;
				eyex -= 10;
			}
			else {
				camPos[0] -= 1;
				eyex -= 10;
			}
		}
		else {
			if (camPos[2] == 1) {
				camPos[0] += 1;
				eyex += 10;
			}
			else if (camPos[2] == 0) {
				camPos[2] += 1;
				eyez += 10;
			}
			else {
				camPos[2] += 1;
				eyez += 10;
			}
		}
		gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		glLoadIdentity();
		// check camera position state
		// and move the camera based on that state
		if (camPos[0] == 1) {
			if (camPos[2] == 1) {
				camPos[0] -= 1;
				eyex -= 10;
			}
			else if (camPos[2] == 0) {
				camPos[2] += 1;
				eyez += 10;
			}
			else {
				camPos[2] += 1;
				eyez += 10;
			}
		}
		else if (camPos[0] == 0) {
			if (camPos[2] == 1) {
				camPos[0] -= 1;
				eyex -= 10;
			}
			else if (camPos[2] == 0) {
				camPos[2] += 1;
				eyez += 10;
			}
			else {
				camPos[0] += 1;
				eyex += 10;
			}
		}
		else {
			if (camPos[2] == 1) {
				camPos[2] -= 1;
				eyez -= 10;
			}
			else if (camPos[2] == 0) {
				camPos[2] -= 1;
				eyez -= 10;
			}
			else {
				camPos[0] += 1;
				eyex += 10;
			}
		}
		gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		glLoadIdentity();
		// check camera position state
		// and move the camera based on that state
		if (camPos[1] < 1) {
			camPos[1] += 1;
			eyey += 10;
		}
		gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		glLoadIdentity();
		// check camera position state
		// and move the camera based on that state
		if (camPos[1] > -1) {
			camPos[1] -= 1;
			eyey -= 10;
		}
		gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
		glutPostRedisplay();
		break;
	}
}

void reshape(int cx, int cy)
{
	GLdouble aspect_ratio;
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
}

void displayDraw() {
	// draw border and teapot
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
	glPopMatrix();
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glTranslatef(teapotPos[0], teapotPos[1], teapotPos[2]);
	glutSolidTeapot(1);
	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	displayDraw();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	int mode = GLUT_DOUBLE | GLUT_RGBA;
	glutInit(&argc, argv);
	glutInitDisplayMode(mode);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Soal2 - Desi & Iddad");

	init();
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}