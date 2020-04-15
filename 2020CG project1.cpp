#include <GL/glut.h>
#include <math.h>

GLfloat rotate_var = 0.0f;
GLfloat scale_var = 1.0f;
GLfloat temp = 0.0f;
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

	
	
	glMatrixMode(GL_MODELVIEW);
	rotate_var += g_velocityx * (GLfloat)g_timedelta / 1.f;
	scale_var += g_velocityx * (GLfloat)g_timedelta / 30.f;
	if (fmod(scale_var, 5) > 2.5)
	{

		temp = 5 - fmod(scale_var, 5);


	}
	else {

		temp = fmod(scale_var,5);
	}
	
	


	glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(0.5f, 0.5f, 0.0f);
		glRotatef(rotate_var, 0, 0, 1);
		glScalef(0.1f, 0.1f, 0.1f);
		
		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);





		glLoadIdentity();


		glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(-0.5f, -0.5f, 0.0f);
		glRotatef(rotate_var, 0, 0, 1);
		glTranslatef(-0.2f, -0.2f, 0.0f);
		
		glScalef(0.1f, 0.1f, 0.1f);

		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);






		glLoadIdentity();


		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(0.5f, -0.5f, 0.0f);
		glScalef(temp, temp, temp);
		glScalef(0.1f, 0.1f, 0.1f);

		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);


	glPopMatrix();
	

	glDisableClientState(GL_VERTEX_ARRAY);
	glutSwapBuffers();

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

int main(int argc, char * argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("20140661 Ω≈¡÷»Ø 2020 CG Project 1");

	glutDisplayFunc(RenderScene);
	glutIdleFunc(idle);
	SetupRC();
	glutMainLoop();
	return 0;



}