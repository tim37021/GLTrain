/*
	OpenGL Training by YU-LUN HSU
	Chapter Four - Rounding Error

	Purpose:
		1. Explain the behave of the program.
		2. Read http://www.songho.ca/opengl/gl_transform.html
*/
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

float z=0.0f;
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS) return;

    switch(key){
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, GL_TRUE); break;
	case 65:
        	glMatrixMode(GL_MODELVIEW);
        	glTranslatef(0.0f, 0.0f, 0.3f);
		z+=0.3f;
		break;
	case 66:
		glMatrixMode(GL_MODELVIEW);
        	glTranslatef(0.0f, 0.0f, -0.3f);
		z-=0.3f;
		break;
    }  
    char buf[100];
    sprintf(buf, "Chapter Four - Rounding Error %f", z);
    glfwSetWindowTitle(window, buf);

}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Chapter Four - Rounding Error", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
  
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    while (!glfwWindowShouldClose(window))
    {
	glClear(GL_COLOR_BUFFER_BIT);	
	const float ratio = 640.0f/480;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1, 1, 0.8, 999);
	glViewport(0, 0, 640, 480);
	

        //glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-ratio, -1.0f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(ratio, -1.0f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 1.0f, 0.f);
        glEnd();
        
	glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
