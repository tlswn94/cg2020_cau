#include <GL/glut.h>
#include <math.h>


void RenderScene(void)
{
	#define PI 3.141692
	float x = 0.25;
	float y = 0.8;
	float z = 0.0;

	float x1 = 0.25;
	float y1 = 0.8;
	float z1 = 0.0;

	glClear(GL_COLOR_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex3f(x, y, z);
	glEnd();




	for (int i = 0; i < 105; i++)
	{	
		x1 =x * cos(30*i * PI / 180) - z * sin(30*i * PI / 180);
		y1 = y1 - 0.05;
		z1 = x * sin(30 *i * PI / 180) + z * cos(30 *i* PI / 180);


		
		glBegin(GL_POINTS);
		glVertex3f(x1, y1, z1);
		glEnd();
		

	}

	glPopMatrix();


	glFlush();

}

void SetupRC(void)
{


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}

int main(int argc, char * argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Lec 03");

	glutDisplayFunc(RenderScene);

	SetupRC();
	glutMainLoop();
	return 0;



}