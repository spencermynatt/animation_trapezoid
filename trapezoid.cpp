

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
void handleKeyPress(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
	{
		exit(0);
	}
	}
}
void initRendering(){
		glEnable(GL_DEPTH_TEST);
};
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
float angle = 30.0f;
float camera_angle = 0.0f;
void draw_scene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 2.0f, -5.0f);
	glPushMatrix();
	
	glTranslatef(-1.0f, -1.0f, 0.0f);
	glRotatef(angle, 0.0f, 2.0f, -1.0f);
	

	glBegin(GL_QUADS);
	glVertex3f(-0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.4f, 0.5f, 0.0f);
	glVertex3f(-0.4f, 0.5f, 0.0f);
	glEnd();
	glutSwapBuffers();
}


void update(int value) {
	angle = angle + 2.0;
	if (angle > 360) {
		angle = angle - 360;
	}
	glutPostRedisplay(); //display changed
	glutTimerFunc(25, update, 0); //put update again in 25 miliseconds
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("hi");
	initRendering();
	glutDisplayFunc(draw_scene);
	glutKeyboardFunc(handleKeyPress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;

}
