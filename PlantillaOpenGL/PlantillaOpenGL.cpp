// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

void dibujar();
void actualizar();

int main()
{
	// Creamos una ventana
	GLFWwindow *window;

	// Si no se puede inicializar glfw, finalizamos la ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// Si se pudo iniciar GLFW, entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	
	// Si no podemos iniciar la ventana, terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto, activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL << std::endl;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(.23, 0.3, 0.3, 1);

		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

void dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Color Morado = 138,43,226
	glColor3f(138.0f/255.0f, 43.0f/255.0f, 226.0f/255.0f);

	glBegin(GL_TRIANGLES);
		glVertex3f(1, 1, 0.0);
		glVertex3f(1, -1, 0.0);
		glVertex3f(-1, -1, 0.0);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
		glVertex3f(.25, .25, 0.0);
		glVertex3f(.25, -.25, 0.0);
		glVertex3f(-.25, -.25, 0.0);
		glVertex3f(-.25, .25, 0.0);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		glVertex3f(-.75, -1, 0.0);
		glVertex3f(-.7, -.9, 0.0);
		glColor3f(.2, .3, .8);
		glVertex3f(-.50, -.5, 0.0);
		glVertex3f(-.55, -.9, 0.0);
	glEnd();
}

void actualizar()
{

}