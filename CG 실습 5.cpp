#include <GL/glut.h>
#include <math.h>

GLfloat moving_var = 0.0f;
int g_timedelta = 0, g_prevTime = 0;
GLfloat g_velocityx = 0.05f;
GLfloat vertices[] = { -0.8f, -0.8f ,-0.8f,
						0.8f, -0.8f, -0.8f,
						0.8f, 0.8f, -0.8f,
						-0.8f, 0.8f, -0.8f,
						-0.8f, -0.8f,0.8f,
						0.8f, -0.8f, 0.8f,
						0.8f, 0.8f, 0.8f,
						-0.8f,0.8f,0.8f
};
GLubyte indices[] = { 7, 5, 6,
				7, 4 ,5,
				3, 2, 1,
				3, 1, 0,
				2, 6, 5,
				2, 5, 1,
				3, 7, 6,
				3, 6, 2,
				0, 4, 7,
				0, 7, 3,
				1, 5, 4,
				1, 4, 0 };

void RenderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	moving_var += g_velocityx * (GLfloat)g_timedelta / 5.f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(moving_var, 0.f, -80.f, moving_var, 0.f, 0.f, 0.f, 1.f, 0.f);

	glPushMatrix();

	glScaled(20.f, 20.f, 1.f);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
	glPopMatrix();



	glFlush();

}

void SetupRC(void)
{


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}
void idle()
{

	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	g_timedelta = currentTime - g_prevTime;
	g_prevTime = currentTime;
	glutPostRedisplay();
}

void ChangeSize(GLsizei w, GLsizei h)
{


	GLfloat aspectRatio;

	if (h == 0)
	{
		h = 1;

	}

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;

	if (w <= h)
		glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 100.0, -100.0);

	else
		glOrtho(-100.0*aspectRatio, 100.0 *aspectRatio, -100.0, 100.0, 100.0, -100.0);

}

int main(int argc, char * argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("20140661 신주환 2020 CG 실습5");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(idle);
	SetupRC();
	glutMainLoop();
	return 0;



}