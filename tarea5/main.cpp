/*
 * Semestre 2018-2
 * Alumno: Cabrera López Oscar Emilio
 */
#include <GL/glut.h>
#include <cstdio>
#include <cstring>

float tranZ = -5.0f;
int screenW = 0;
int screenH = 0;
int dedo = 0;
int falange = 0;
double ang[6][3] = {
        {0.0,    0.0,   0.0},
        {0.0,    0.0,   0.0},
        {0.0,    0.0,   0.0},
        {0.0,    0.0,   0.0},
        {0.0,    0.0,   0.0},
        {0.0,    0.0,   90.0},
};


void initGL()     // Inicializamos parametros
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);               // Negro de fondo
    glClearDepth(1.0f);                                 // Configuramos Depth Buffer
    glEnable(GL_DEPTH_TEST);                            // Habilitamos Depth Testing
    glDepthFunc(GL_LEQUAL);                             // Tipo de Depth Testing a realizar
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma() {
    GLfloat vertice[8][3] = {
            {0.5f,  -0.5f, 0.5f},    //Coordenadas Vértice 0 V0
            {-0.5f, -0.5f, 0.5f},    //Coordenadas Vértice 1 V1
            {-0.5f, -0.5f, -0.5f},    //Coordenadas Vértice 2 V2
            {0.5f,  -0.5f, -0.5f},    //Coordenadas Vértice 3 V3
            {0.5f,  0.5f,  0.5f},    //Coordenadas Vértice 4 V4
            {0.5f,  0.5f,  -0.5f},    //Coordenadas Vértice 5 V5
            {-0.5f, 0.5f,  -0.5f},    //Coordenadas Vértice 6 V6
            {-0.5f, 0.5f,  0.5f},    //Coordenadas Vértice 7 V7
    };

    //glPolygonMode(GL_FRONT, GL_FILL);
    //glPolygonMode(GL_BACK, GL_LINE);

    glBegin(GL_POLYGON);    //Front
    glColor3f(1.0, 0.0, 0.0);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[4]);
    glVertex3fv(vertice[7]);
    glVertex3fv(vertice[1]);
    glEnd();

    glBegin(GL_POLYGON);    //Right
    glColor3f(0.0, 0.0, 1.0);
    //glNormal3f(1.0,0.0,0.0);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[3]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[4]);
    glEnd();

    glBegin(GL_POLYGON);    //Back
    glColor3f(0.0, 1.0, 0.0);
    //glNormal3f(0.0,0.0,-1.0);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[3]);
    glVertex3fv(vertice[2]);
    glEnd();

    glBegin(GL_POLYGON);  //Left
    glColor3f(1.0, 1.0, 1.0);
    //glNormal3f(-1.0,0.0,0.0);
    glVertex3fv(vertice[1]);
    glVertex3fv(vertice[7]);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[2]);
    glEnd();

    glBegin(GL_POLYGON);  //Bottom
    glColor3f(0.4, 0.2, 0.6);
    //glNormal3f(0.0,-1.0,0.0);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[1]);
    glVertex3fv(vertice[2]);
    glVertex3fv(vertice[3]);
    glEnd();

    glBegin(GL_POLYGON);  //Top
    glColor3f(0.8, 0.2, 0.4);
    //glNormal3f(0.0,1.0,0.0);
    glVertex3fv(vertice[4]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[7]);
    glEnd();
}

void display()   // Creamos la función donde se dibuja
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiamos pantalla y Depth Buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        glTranslatef(0.0f, 0.0f, tranZ);
        glRotated(90, 0.0, 0.0, 1.0);
        glRotated(ang[4][2], 1.0, 0.0, 0.0);
        // Palma
        glPushMatrix();                     // Stack palma
            glTranslatef(-1.0f, 0.0f, 0.0f);  // Traslación para la palma
            glScalef(2, 4, 1);
            prisma();                           // Dibujar palma
        glPopMatrix();                      // Sale del stack de la palma

        // indice
        glPushMatrix();
            glTranslatef(0.0f, 1.5f, 0.0f);

            glPushMatrix(); // articulación
                glRotated(ang[0][0], 0.0, 1.0, 0.0);
                glTranslatef(0.7f, 0.0, 0.0);

                glPushMatrix(); //Falange
                    glScalef(1.4, 0.75, 1.0);
                    glRotatef(90, 1, 0, 0);
                    prisma();
                glPopMatrix(); // Sale del stack de la falange

                glPushMatrix();
                    glTranslatef(0.7, 0.0, 0.0);

                    glPushMatrix(); // articulación
                        glRotated(ang[0][1], 0.0, 1.0, 0.0);
                        glTranslatef(0.5f, 0.0f, 0.0f);

                        glPushMatrix(); //Falangina
                            glScalef(1.0, 0.65, 1.0);
                            glRotatef(90, 1, 0, 0);
                            prisma();
                        glPopMatrix(); // Sale del stack de la falangina

                        glPushMatrix();
                            glTranslatef(0.5f, 0.0f, 0.0f);

                            glPushMatrix(); // articulación
                                glRotated(ang[0][2], 0.0, 1.0, 0.0);
                                glTranslatef(0.4f, 0.0f, 0.0);

                                glPushMatrix(); //Falangeta
                                    glScalef(0.80, 0.55, 1.0);
                                    glRotatef(90, 1, 0, 0);
                                    prisma();
                                glPopMatrix(); // Sale del stack de la falangeta
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        //medio
        glPushMatrix();
            glTranslatef(0.0f, 0.5f, 0.0f);

            glPushMatrix(); // articulación
                glRotated(ang[1][0], 0.0, 1.0, 0.0);
                glTranslatef(0.75, 0.0, 0.0);

                glPushMatrix(); //Falange
                    glScalef(1.5, 0.75, 1.0);
                    glRotatef(-90, 1, 0, 0);
                    glRotatef(90, 0, 1, 0);
                    prisma();
                glPopMatrix(); // Sale del stack de la falange

                glPushMatrix();
                    glTranslatef(0.75, 0.0, 0.0);

                    glPushMatrix(); // articulación
                        glRotated(ang[1][1], 0.0, 1.0, 0.0);
                        glTranslatef(0.6, 0.0, 0.0);

                        glPushMatrix(); //Falangina
                            glScalef(1.2, 0.65, 1.0);
                            glRotatef(-90, 1, 0, 0);
                            glRotatef(90, 0, 1, 0);
                            prisma();
                        glPopMatrix(); // Sale del stack de la falangina

                        glPushMatrix();
                            glTranslatef(0.6, 0.0, 0.0);

                            glPushMatrix(); // articulación
                                glRotated(ang[1][2], 0.0, 1.0, 0.0);
                                glTranslatef(0.5, 0.0, 0.0);

                                glPushMatrix(); //Falangeta
                                    glScalef(1.0, 0.55, 1.0);
                                    glRotatef(-90, 1, 0, 0);
                                    glRotatef(90, 0, 1, 0);
                                    prisma();
                                glPopMatrix(); // Sale del stack de la falangeta
                            glPopMatrix(); // articulación
                        glPopMatrix();
                    glPopMatrix(); // articulación
                glPopMatrix();
            glPopMatrix(); // articulación
        glPopMatrix();



        //anular
        glPushMatrix();
            glTranslatef(0.0f, -0.5f, 0.0f);

            glPushMatrix(); // articulación
                glRotated(ang[2][0], 0.0, 1.0, 0.0);
                glTranslatef(0.7, 0.0, 0.0);

                glPushMatrix(); //Falange
                    glScalef(1.4, 0.75, 1.0);
                    glRotatef(90, 0, 1, 0);
                    prisma();
                glPopMatrix(); // Sale del stack de la falange

                glPushMatrix();
                    glTranslatef(0.70f, 0.0, 0.0);

                    glPushMatrix(); // articulación
                        glRotated(ang[2][1], 0.0, 1.0, 0.0);
                        glTranslatef(0.5, 0.0, 0.0);

                        glPushMatrix(); //Falangina
                            glScalef(1.0, 0.65, 1.0);
                            glRotatef(90, 0, 1, 0);
                            prisma();
                        glPopMatrix(); // Sale del stack de la falangina

                        glPushMatrix();
                            glTranslatef(0.5f, 0.0, 0.0);

                            glPushMatrix(); // articulación
                                glRotated(ang[2][2], 0.0, 1.0, 0.0);
                                glTranslatef(0.4, 0.0, 0.0);

                                glPushMatrix(); //Falangeta
                                    glScalef(0.80, 0.55, 1.0);
                                    glRotatef(90, 0, 1, 0);
                                    prisma();
                                glPopMatrix(); // Sale del stack de la falangeta
                            glPopMatrix(); // articulación
                        glPopMatrix();
                    glPopMatrix(); // articulación
                glPopMatrix();
            glPopMatrix(); // articulación
        glPopMatrix();



        // meñique
        glPushMatrix();
            glTranslatef(0.0, -1.5f, 0.0f);

            glPushMatrix(); // articulación
                glRotated(ang[3][0], 0.0, 1.0, 0.0);
                glTranslatef(0.5, 0.0, 0.0);

                glPushMatrix(); //Falange
                    glScalef(1.0, 0.75, 1.0);
                    glRotatef(-90, 0, 1, 0);
                    glRotatef(-90, 0, 1, 0);
                    prisma();
                glPopMatrix(); // Sale del stack de la falange

                glPushMatrix();
                    glTranslatef(0.5f, 0.0, 0.0);

                    glPushMatrix(); // articulación
                        glRotated(ang[3][1], 0.0, 1.0, 0.0);
                        glTranslatef(0.5, 0.0, 0.0);

                        glPushMatrix(); //Falangina
                            glScalef(1.0, 0.65, 1.0);
                            glRotatef(-90, 0, 1, 0);
                            glRotatef(-90, 0, 1, 0);
                            prisma();
                        glPopMatrix(); // Sale del stack de la falangina

                        glPushMatrix();
                            glTranslatef(0.5f, 0.0f, 0.0f);

                            glPushMatrix(); // articulación
                                glRotated(ang[3][2], 0.0, 1.0, 0.0);
                                glTranslatef(0.4, 0.0, 0.0);

                                glPushMatrix(); //Falangeta
                                    glScalef(0.8, 0.55, 1.0);
                                    glRotatef(-90, 0, 1, 0);
                                    glRotatef(-90, 0, 1, 0);
                                    prisma();
                                glPopMatrix(); // Sale del stack de la falangeta
                            glPopMatrix(); // articulación
                        glPopMatrix();
                    glPopMatrix(); // articulación
                glPopMatrix();
            glPopMatrix(); // articulación
        glPopMatrix();

        // Pulgar
        glPushMatrix(); // Pulgar
            glTranslatef(-1.0f, 2.0f, 0.0f);
            glRotated(ang[5][0], 1.0f, 0.0f, 0.0);
            glRotated(ang[5][2], 0.0f, 0.0f, 1.0);

            glPushMatrix();
                //glTranslatef(-0.30f, 0.0, 0.0);

                glPushMatrix(); // articulación
                    glRotated(ang[4][0], 0.0, 1.0, 0.0);
                    glTranslatef(0.7, 0.0, 0.0);

                    glPushMatrix(); //Falange
                        glScalef(1.4, 0.75, 1.0);
                        glRotatef(-90, 0, 1, 0);
                        prisma();
                    glPopMatrix(); // Sale del stack de la falange

                    glPushMatrix();
                        glTranslatef(0.70f, 0.0, 0.0);

                        glPushMatrix(); // articulación
                            glRotated(ang[4][1], 0.0, 1.0, 0.0);
                            glTranslatef(0.5, 0.0, 0.0);

                            glPushMatrix(); //Falangina
                                glScalef(1.0, 0.65, 1.0);
                                glRotatef(-90, 0, 1, 0);
                                prisma();
                            glPopMatrix(); // Sale del stack de la falangina
                        glPopMatrix(); // articulación
                    glPopMatrix();
                glPopMatrix(); // articulación
            glPopMatrix();
        glPopMatrix(); // Sale del stack del pulgar

    glPopMatrix();


    glutSwapBuffers();
    // glFlush();
    // Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
    if (height == 0)                                        // Prevenir division entre cero
    {
        height = 1;
    }

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);                        // Seleccionamos Projection Matrix
    glLoadIdentity();

    // Tipo de Vista
    //glOrtho(-5,5,-5,5,0.2,20);
    glFrustum(-0.01, 0.01, -0.01, 0.01, 0.01, 100.0);

    glMatrixMode(GL_MODELVIEW);                         // Seleccionamos Modelview Matrix
    //glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
    switch (key) {
        case 'w':
        case 'W':
            tranZ += 0.3f;
            break;
        case 's':
        case 'S':
            tranZ -= 0.3f;
            break;
        case 'e':
        case 'E':
            dedo = 0;
            break;
        case 'r':
        case 'R':
            dedo = 1;
            break;
        case 't':
        case 'T':
            dedo = 2;
            break;
        case 'y':
        case 'Y':
            dedo = 3;
            break;
        case 'u':
        case 'U':
            dedo = 4;
            break;
        case 'i':
        case 'I':
            falange = 0;
            break;
        case 'o':
        case 'O':
            falange = 1;
            break;
        case 'p':
        case 'P':
            falange = 2;
            break;
        case 'q':
        case 'Q':
            dedo = 4; falange = 2;
            break;
        case 'z':
        case 'Z':
            dedo = 5; falange = 0;
            break;
        case 'x':
        case 'X':
            dedo = 4; falange = 0;
            break;
        case 'c':
        case 'C':
            dedo = 5; falange = 2;
            break;
        case 'a':
        case 'A':
            ang[dedo][falange] += 3.0;
            break;
        case 'd':
        case 'D':
            ang[dedo][falange] -= 3.0;
            break;
        case 'm':
        case 'M':
            memset(ang, 0, sizeof(ang));
            ang[5][2] = 90.0;
            break;
        case 27:        // Cuando Esc es presionado...
            exit(0);    // Salimos del programa
        default:        // Cualquier otra
            break;
    }
    printf("dedo: %d, falange: %d, angulo: %2.1f, tranZ: %2.1f \n", dedo, falange, ang[dedo][falange], tranZ);
    glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Función para manejo de teclas especiales (arrow keys)
{
    switch (a_keys) {
        case GLUT_KEY_UP:       // Presionamos tecla ARRIBA...
            break;
        case GLUT_KEY_DOWN:     // Presionamos tecla ABAJO...
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        default:
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char **argv)   // Main Function
{
    glutInit(&argc, argv); // Inicializamos OpenGL
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    screenW = glutGet(GLUT_SCREEN_WIDTH);
    screenH = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(500, 500);   // Tamaño de la Ventana
    glutInitWindowPosition(0, 0);   // Posicion de la Ventana
    glutCreateWindow("Practica 5"); // Nombre de la Ventana
    printf("Resolution H: %i \n", screenW);
    printf("Resolution V: %i \n", screenH);
    initGL();                   // Parametros iniciales de la aplicacion
    glutDisplayFunc(display);   // Indicamos a Glut función de dibujo
    glutReshapeFunc(reshape);   // Indicamos a Glut función en caso de cambio de tamano
    glutKeyboardFunc(keyboard); // Indicamos a Glut función de manejo de teclado
    glutSpecialFunc(arrow_keys);// Otras
    glutMainLoop();

    return 0;
}
