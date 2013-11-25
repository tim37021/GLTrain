/*
	OpenGL Training by YU-LUN HSU
	Chapter Three - Understanding projection matrix

	Purpose: 
		Customerlizing coordinate system so that point at the upper left of the window is (0, 0) and that at the bottom right is (windowWidth, windowHeight)
		HINT: use glViewport and glOrtho
	Bonus:
		Explain why glRotatef behave differently.
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
    window = glfwCreateWindow(640, 480, "Chapter Three - Projection Matrix", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0, 640, 480);

        glClear(GL_COLOR_BUFFER_BIT);

	/*******HINT*******/
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
	glOrtho(0, 640, 480, 0, -100, 100);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	/******************/

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(320.0f, 0.0f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.0f, 480.0f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(640.0f, 480.0f, 0.f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
