/*
    Fecha: 08-11-22
    Alumno: Renet de Jesús Pérez Gómez
    Matricula: A01640555
*/
#include <GL/glut.h>

struct Point {
    int x=0;
    int y=0;
};


void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);    // Set display-window color to white.
    glMatrixMode (GL_PROJECTION);         // Set projection parameters.
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void myLine (void)
{
    Point points[] = 
    {
        {1,2}, {100, 20},
        {10,200}, {50,10},
        {300,300}, {10,10},
        {200,300}, {250,50}, 
        {350,350},{100,300}
    };
    glClear (GL_COLOR_BUFFER_BIT);        // Clear display window.

    glColor3f (0.0, 0.4, 0.2);            // Set line segment color to green.
    glBegin (GL_LINES);

    int n = sizeof(points)/sizeof(points[0]);
    
    for(int i = 0; i <= n; i++){
        glVertex2i (points[i].x, points[i].y);
        glVertex2i (points[i+1].x, points[i+1].y);
        i++;
    }
    glEnd ( );
    glFlush ( );                          // Process all OpenGL routines as quickly as possible.
}

void points (void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin (GL_POINTS);
    for (int i = 0; i<400; i++)
      glVertex2i (i, i);
    glEnd ();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);    // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);    // Set display mode.
    glutInitWindowPosition (50, 100);    // Set top-left display-window position.
    glutInitWindowSize (400, 400);    // Set display-window width and height.
    glutCreateWindow ("An Example OpenGL Program"); // Create display window.
    init ( ); // Execute initialization procedure.
    glutDisplayFunc (myLine);    // Send graphics to display window.
    //glutDisplayFunc (points);
    glutMainLoop ( );    // Display everything and wait.
    return 0;
}