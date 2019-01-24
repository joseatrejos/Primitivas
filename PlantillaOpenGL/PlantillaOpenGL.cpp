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
void dibujarFiguras();
void dibujarPuntos();
void dibujarLineas();
void dibujarLineaContinua();
void dibujarTrianguloContinuo();

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
	
	// dibujarFiguras();
	// dibujarPuntos();
	// dibujarLineas();
	// DibujarLineaContinua();
	dibujarTrianguloContinuo();
}

void actualizar()
{

}


// Funciones de Dibujo

void dibujarFiguras()
{
	// Color Morado = 138,43,226
	glColor3f(138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f);

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
		glVertex3f(-.75, -.8, 0.0);
		glColor3f(.2, .5, .8);
		glVertex3f(-.50, -.3, 0.0);
		glVertex3f(-.55, -.7, 0.0);
	glEnd();
}

void dibujarPuntos()
{
	glBegin(GL_POINTS);
		glColor3f(1, 1, 1);
		glVertex3f(-0.4f, 0.1f, 0);
		glVertex3f(0, 0.3f, 0);
		glVertex3f(0.1f, 0.4f, 0);
		glVertex3f(0.2f, 0.1f, 0);
		glVertex3f(0.3f, 0.8f, 0);
		glVertex3f(0.4f, 0.9f, 0);
		glVertex3f(0.5f, 0.4f, 0);
		glVertex3f(0.6f, 0.2f, 0);
		glVertex3f(0.7f, 0.1f, 0);
		glVertex3f(0.8f, 0.6f, 0);
		glVertex3f(0.9f, 0.5f, 0);
	glEnd();
}

void dibujarLineas()
{
	glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex3f(-0.4f, 0.1f, 0);
		glVertex3f(0, 0.3f, 0);
		glVertex3f(0.1f, 0.4f, 0);
		glVertex3f(0.2f, 0.1f, 0);
		glVertex3f(0.3f, 0.8f, 0);
		glVertex3f(0.4f, 0.9f, 0);
		glVertex3f(0.5f, 0.4f, 0);
		glVertex3f(0.6f, 0.2f, 0);
		glVertex3f(0.7f, 0.1f, 0);
		glVertex3f(0.8f, 0.6f, 0);
		glVertex3f(0.9f, 0.5f, 0);
	glEnd();
}

void dibujarLineaContinua()
{
	glBegin(GL_LINE_STRIP);
		glColor3f(1, 1, 1);
		glVertex3f(-.25, -.25f, 0);
		glVertex3f(-.25, .25f, 0);
		glVertex3f(.25f, 0.25f, 0);
		glVertex3f(.25f, -0.25f, 0);
		glVertex3f(-.25, -.25f, 0);
	glEnd();
}

void dibujarTrianguloContinuo()
{
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(.25F, .25f, 0);
		glVertex3f(.25f, 0, 0);
		// A partir del 3er vértice, los nuevos vértices harán un nuevo triángulo con los dos vértices anteriores a éste.
		glVertex3f(.6f, -0.3, 0);
		glVertex3f(-.4f, 0.5, 0);
	glEnd();
}