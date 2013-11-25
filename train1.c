/*
	OpenGL Training by YU-LUN HSU
	Chapter One - Your first GLFW window

	Purpose:
		1. Learn how to read tutorial and reference
	Bonus:
		1. Display the position of the mouse on the title of the window
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

/* Bonus 1 */
static void mousepos_callback(GLFWwindow *window, double x, double y){
	char buf[50];
	sprintf(buf, "Chapter One - Your First Window (%.2f, %.2f)", x, y);
	glfwSetWindowTitle(window, buf);
}
/**********/
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Chapter One - Your First Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    /* Bonus 1 */
    glfwSetCursorPosCallback(window, mousepos_callback);
    /***********/

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
	glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
