/*
	OpenGL Training by YU-LUN HSU
	Chapter Two - Your first triangle

	Purpose:
		1. Understanding the default coordinate used by OpenGL is [-1, -1]x[1, 1], and the origin is in the mid of the window.
		2. Understanding the MODEL_VIEW matrix in OpenGL
		3. OpenGL IS A STATE MACHINE

	Bonus: 
		1. Use glRotatef to rotate the triangle by the origin (0, 0)
		2. Use glTranslate to move the triangle by (+0.5, 0)
		HINT: Use glLoadIdentity(); to reset MODEL_VIEW matrix
*/

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(600, 600, "Chapter Two - Your first Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
	glClear(GL_COLOR_BUFFER_BIT);	

	glViewport(0, 0, 600, 600);
	
	glMatrixMode(GL_MODELVIEW);
	//glRotatef(.1f, 0, 0, 1);

	/* Bonus 2 */
	//glLoadIdentity();
	//glTranslatef(0.5f, 0.f, 0.f);
	/***********/

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-1.0f, -1.0f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(1.0f, -1.0f, 0.f);
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
