#include <GL/glut.h>


void RenderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.5f, 0.5f, 0.5f);
	//规过1
		/*
		glBegin(GL_TRIANGLES);

		glVertex3f(0, 0, 0);
		glVertex3f(0.25, 0.25, 0);
		glVertex3f(0.25, -0.25, 0);


		glVertex3f(0, 0, 0);
		glVertex3f(-0.25, 0.25, 0);
		glVertex3f(-0.25, -0.25, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(-0.25, 0.25, 0);
		glVertex3f(0.25, 0.25, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(-0.25, -0.25, 0);
		glVertex3f(0.25, -0.25, 0);


		glVertex3f(0.25, 0.25, 0);
		glVertex3f(0.25, -0.25, 0);
		glVertex3f(0.5, 0, 0);

		glEnd();
		*/


		//规过 2
			/*
			GLfloat vertices[] = { 0, 0, 0,
								   0.25f,0.25f,0 ,
								   0.25f, -0.25f, 0,
								   0, 0, 0,
								   0.25f,0.25f,0,
								   -0.25f, 0.25f, 0,
								   0, 0, 0,
								   -0.25f, 0.25f, 0,
									-0.25f,-0.25f, 0,
								   0,0,0,
								   -0.25f,-0.25f, 0,
								   0.25f, -0.25f, 0,
								   0.25f,0.25f,0,
								   0.25f, -0.25f, 0,
								   0.5f, 0, 0};
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3,GL_FLOAT,0,vertices);

			glDrawArrays(GL_TRIANGLES,  0  ,  15);
			glDisableClientState(GL_VERTEX_ARRAY);
			*/


			//规过3
				/*
				GLfloat vertices[] = { 0, 0, 0,
									   0.25f,0.25f,0 ,
									   0.25f, -0.25f, 0,
									   -0.25f,-0.25f, 0,
									   -0.25f, 0.25f, 0,
									   0.5f, 0, 0
			};
				GLubyte indices[] = { 0,1,2, 0,2,3, 0,3,4, 0,1,4, 1,2,5 };
				glEnableClientState(GL_VERTEX_ARRAY);
				glVertexPointer(3,GL_FLOAT,0,vertices);

				glDrawElements(GL_TRIANGLES,15,GL_UNSIGNED_BYTE,indices);

				glDisableClientState(GL_VERTEX_ARRAY);




				*/



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
	glutCreateWindow("Lec 02");

	glutDisplayFunc(RenderScene);

	SetupRC();
	glutMainLoop();
	return 0;



}