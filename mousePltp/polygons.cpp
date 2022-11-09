/*
    Fecha: 11-09-22
    Alumno: Renet de Jesús Pérez Gómez
    Matricula: A01640555
*/
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <random>

const double TWO_PI = 6.2831853;

using namespace std;

/* Initial display-window size. */
GLsizei winWidth = 400, winHeight = 400;
GLuint regHex;

/*Vertex*/
int numVertex = 5;

class screenPt
{
private:
    GLint x, y;
public:
    /* Default Constructor: initializes coordinate position to (0, 0).*/
    screenPt ( ) {
	x = y = 0;
    }
    void setCoords (GLint xCoord, GLint yCoord) {
	x = xCoord;
	y = yCoord;
    }
    GLint getx ( ) const {
	return x;
    }
    GLint gety ( ) const {
	return y;
    }
};


static void init (void)
{
    screenPt hexVertex, circCtr;
    GLdouble theta;
    GLint k;
    /* Set circle center coordinates. */
    circCtr.setCoords (winWidth / 2, winHeight / 2);
    glClearColor (1.0, 1.0, 1.0, 0.0); //    Display-window color = white.
    /* Set up a display list for a red regular hexagon.
     * Vertices for the hexagon are six equally spaced
     * points around the circumference of a circle.
     */
    regHex = glGenLists (1); // Get an identifier for the display list.
    glNewList (regHex, GL_COMPILE);

    float c1 = static_cast<float> (rand()) / static_cast <float> (RAND_MAX);
    float c2 = static_cast<float> (rand()) / static_cast <float> (RAND_MAX);
    float c3 = static_cast<float> (rand()) / static_cast <float> (RAND_MAX);
    glColor3f (c1, c2, c3);  // Set fill color for hexagon to red.
    glBegin (GL_POLYGON);
    for (k = 0; k < numVertex; k++) {
	theta = TWO_PI * k / numVertex;
	hexVertex.setCoords (circCtr.getx ( ) + 150 * cos (theta),
			     circCtr.gety ( ) + 150 * sin (theta));
	glVertex2i (hexVertex.getx ( ), hexVertex.gety ( ));
    }
    glEnd ( );
    glEndList ( );
}



void regHexagon (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glCallList (regHex);
    glFlush ( );
}

void winReshapeFcn (int newWidth, int newHeight)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ( );
    gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
    glClear (GL_COLOR_BUFFER_BIT);
}

void mousePtPlot (GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
        if(numVertex>11)
            numVertex=5;
        else numVertex++;
        init( );
        regHexagon( );
    }
    glFlush ( );
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Reshape-Function & Display-List Example");
    init ( );
    glutMouseFunc (mousePtPlot);
    glutDisplayFunc (regHexagon);
    glutReshapeFunc (winReshapeFcn);
    glutMainLoop ( );
    return 0;
}