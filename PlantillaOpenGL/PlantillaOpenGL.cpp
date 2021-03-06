// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <math.h>

using namespace std;

void dibujar();
void actualizar();
void dibujarPoligonos();
void dibujarPuntos();
void dibujarLineas();
void dibujarLineaContinua();
void dibujarTrianguloContinuo();
void dibujarCuadrado();
void dibujarCuadradoContinuo();
void dibujarPaisaje();
void dibujarSol();
void dibujarCasa();
void dibujarFondo();
void dibujarArbol();

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
	
	// dibujarPoligonos();
	// dibujarPuntos();
	// dibujarLineas();
	// DibujarLineaContinua();
	// dibujarTrianguloContinuo();
	// dibujarCuadrado();
	// dibujarCuadradoContinuo();
	dibujarPaisaje();
}

void actualizar()
{

}

// Funciones de Dibujo Primitivas
void dibujarPoligonos()
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
void dibujarCuadrado()
{
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(.25F, .0f, 0);
		glVertex3f(.25f, .25f, 0);
		glVertex3f(0, .25f, 0);
	glEnd();
}
void dibujarCuadradoContinuo()
{
	glBegin(GL_QUAD_STRIP);
		glColor3f(.2, .32, .8);
		glVertex3f(0, 0, 0);
		glVertex3f(-.25F, .0f, 0);
		glVertex3f(-.25f, -.25f, 0);
		glVertex3f(0, -.25f, 0);
		glVertex3f(0, -.75, 0);
		glVertex3f(-.25, -.75, 0);
	glEnd();
}

// DIBUJOS DE LA CASA
void dibujarPaisaje()
{
	dibujarFondo(); 
	dibujarSol();
	dibujarCasa();
	dibujarArbol();
}
void dibujarSol()
{
	glBegin(GL_POLYGON);
		glColor3f(1, .8, 0);
		for (int i = 0; i < 360; i++)
		{
			glVertex3f(0.2*cos((double)i*(3.1416 / 180)) - 0.95, 0.2*sin((double)i*(3.14159 / 180.0)) + 0.95, 0.4);
		}
	glEnd();
}
void dibujarCasa()
{
	// Casa
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(.2f, -.5f, 0);
		glVertex3f(.5f, -.5f, 0);
		glVertex3f(.5f, -.15f, 0);
		glVertex3f(.2f, -.15f, 0);
	glEnd();

	// Techo
	glBegin(GL_TRIANGLES);
		glColor3d(.4f, .1f, .1f);
		glVertex3d(.15f, -.15f, 0);
		glVertex3d(.55f, -.15f, 0);
		glVertex3d(.35f, -.02f, 0);
	glEnd();

	// Puerta
	glBegin(GL_QUADS);
		glColor3f(.2578, .128, 0);
		glVertex3f(.39f, -.5f, 0);
		glVertex3f(.31f, -.5f, 0);
		glVertex3f(.31f, -.37f, 0);
		glVertex3f(.39f, -.37f, 0);
	glEnd();

	// Ventana 1
	glBegin(GL_QUADS);
		glColor3f(.23f, .31f, .8f);
		glVertex3f(.23f, -.2f, 0);
		glVertex3f(.32f, -.2f, 0);
		glVertex3f(.32f, -.32f, 0);
		glVertex3f(.23f, -.32f, 0);
	glEnd();

	// Ventana 2
	glBegin(GL_QUADS);
		glColor3d(.23f, .31f, .8f);
		glVertex3f(.38f, -.2f, 0);
		glVertex3d(.47f, -.2f, 0);
		glVertex3d(.47f, -.32f, 0);
		glVertex3d(.38f, -.32f, 0);
	glEnd();
}
void dibujarArbol()
{
	// Tronco
	glBegin(GL_QUADS);
	glColor3f(.2578, .128, 0);
		glVertex3f(-.3f, -.5f, 0);
		glVertex3f(-.3f, -.05f, 0);
		glVertex3f(-.48f, -.05f, 0);
		glVertex3f(-.48f, -.5f, 0);
	glEnd();

	// Hojas
	glBegin(GL_POLYGON);
		glColor3f(.12f, .75f, .35f);
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.5, 0.1*sin((double)i*3.14159 / 180.0), 0);
		}
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.45, 0.1*sin((double)i*3.14159 / 180.0), 0);
		}
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.4, 0.1*sin((double)i*3.14159 / 180.0), 0);
		}
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.3, 0.1*sin((double)i*3.14159 / 180.0), 0);
		}
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.34, 0.1*sin((double)i*3.14159 / 180.0) + .12, 0);
		}
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.45, 0.1*sin((double)i*3.14159 / 180.0) + .12, 0);
		}
	glEnd();

	
}
void dibujarFondo()
{
	// Cielo
	glBegin(GL_QUADS);
		glColor3f(.23f, .3f, .65f);
		glVertex3f(1, 1, 0);
		glVertex3f(1, -.5, 0);
		glVertex3f(-1, -.5, 0);
		glColor3f(1, .8, 0);
		glVertex3f(-1, 1, 0);
	glEnd();

	// Suelo
	glBegin(GL_QUADS);
		glColor3f(.1f, .7f, .3f);
		glVertex3f(-1, -.5, 0);
		glVertex3f(1, -.5, 0);
		glVertex3f(1, -1, 0);
		glVertex3f(-1, -1, 0);
	glEnd();

	//  Nube Izquierda Parte 1
	glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.15, 0.1*sin((double)i*3.14159 / 180.0) + 0.69, 0);
		}
	glEnd();

	// Nube Izquierda Parte 2
	glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) - 0.04, 0.1*sin((double)i*3.14159 / 180.0) + 0.69, 0);
		}
	glEnd();

	// Nube Derecha Parte 1
	glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.45, 0.1*sin((double)i*3.14159 / 180.0) + 0.8, 0);
		}
	glEnd();

	// Nube Derecha Parte 2
	glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		for (int i = 0; i < 360; i++) {
			glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.55, 0.1*sin((double)i*3.14159 / 180.0) + 0.8, 0);
		}
	glEnd();
}