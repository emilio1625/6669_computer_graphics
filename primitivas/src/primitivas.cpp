//
// Created by emilio1625 on 24/03/18.
//

#include <cmath>
#include <GL/glut.h>
#include "primitivas.h"

void prisma() {
    GLfloat vertice[8][3] = {
            {0.5f,  -0.5f,  0.5f},    //Coordenadas Vértice 0 V0
            {-0.5f, -0.5f,  0.5f},    //Coordenadas Vértice 1 V1
            {-0.5f, -0.5f, -0.5f},    //Coordenadas Vértice 2 V2
            { 0.5f, -0.5f, -0.5f},    //Coordenadas Vértice 3 V3
            { 0.5f,  0.5f,  0.5f},    //Coordenadas Vértice 4 V4
            { 0.5f,  0.5f, -0.5f},    //Coordenadas Vértice 5 V5
            {-0.5f,  0.5f, -0.5f},    //Coordenadas Vértice 6 V6
            {-0.5f,  0.5f,  0.5f},    //Coordenadas Vértice 7 V7
    };

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


void drawEsfera(GLdouble radio, int paralelos, int meridianos) {
    double v1[] = {0.0, 0.0, 0.0};
    double v2[] = {0.0, 0.0, 0.0};
    double v3[] = {0.0, 0.0, 0.0};
    double v4[] = {0.0, 0.0, 0.0};
    double angm, angp;

    angp = M_PI / paralelos;
    angm = 2 * M_PI / meridianos;

    for (int i = 0; i < meridianos; i++) {
        for (int j = 0; j < paralelos; j++) {
            v1[0] = radio * cos(angm * i) * sin(angp * j);
            v1[1] = radio * cos(angp * j);
            v1[2] = radio * sin(angm * i) * sin(angp * j);

            v2[0] = radio * cos(angm * i) * sin(angp * (j + 1));
            v2[1] = radio * cos(angp * (j + 1));
            v2[2] = radio * sin(angm * i) * sin(angp * (j + 1));

            v3[0] = radio * cos(angm * (i + 1)) * sin(angp * (j + 1));
            v3[1] = radio * cos(angp * (j + 1));
            v3[2] = radio * sin(angm * (i + 1)) * sin(angp * (j + 1));

            v4[0] = radio * cos(angm * (i + 1)) * sin(angp * j);
            v4[1] = radio * cos(angp * j);
            v4[2] = radio * sin(angm * (i + 1)) * sin(angp * j);

            glBegin(GL_POLYGON);
            glNormal3dv(v1);
            glVertex3dv(v1);
            glNormal3dv(v2);
            glVertex3dv(v2);
            glNormal3dv(v3);
            glVertex3dv(v3);
            glNormal3dv(v4);
            glVertex3dv(v4);
            glEnd();
        }
    }
}

void drawCono(GLdouble altura, GLdouble radio, int segmentos) {
    double v1[] = {0.0, 0.0, 0.0};
    double v2[] = {0.0, 0.0, 0.0};
    double angulo = 2 * M_PI / segmentos;

    for (int i = 0; i < segmentos; i++) {

        v1[0] = radio * cos(angulo * i);
        v1[1] = 0;
        v1[2] = radio * sin(angulo * i);

        v2[0] = radio * cos(angulo * (i + 1));
        v2[1] = 0;
        v2[2] = radio * sin(angulo * (i + 1));

        //glBegin(GL_LINE_LOOP);
        glBegin(GL_POLYGON); //Construye Base
        glNormal3d(0.0, -1.0, 0.0);
        glVertex3d(0.0,  0.0, 0.0);
        glVertex3dv(v1);
        glVertex3dv(v2);
        glEnd();


        glBegin(GL_TRIANGLES);
        glNormal3d(v1[0], 0.0f, v1[2]);
        glVertex3dv(v1);
        glVertex3dv(v2);
        glVertex3d(0.0, altura, 0.0);
        glEnd();
    }
}

void drawSemiCono(GLdouble altura, GLdouble radio, int segmentos) {
    double v1[] = {0.0, 0.0, 0.0};
    double v2[] = {0.0, 0.0, 0.0};
    double angulo = 2 * M_PI / (2 * segmentos);

    for (int i = 0; i < segmentos; i++) {

        v1[0] = radio * cos(angulo * i);
        v1[1] = 0;
        v1[2] = radio * sin(angulo * i);

        v2[0] = radio * cos(angulo * (i + 1));
        v2[1] = 0;
        v2[2] = radio * sin(angulo * (i + 1));

        //glBegin(GL_LINE_LOOP);
        glBegin(GL_POLYGON); //Construye Base
        glNormal3d(0.0, -1.0, 0.0);
        glVertex3d(0.0,  0.0, 0.0);
        glVertex3dv(v1);
        glVertex3dv(v2);
        glEnd();


        glBegin(GL_TRIANGLES);
        glNormal3d(v1[0], 0.0f, v1[2]);
        glVertex3dv(v1);
        glVertex3dv(v2);
        glVertex3d(0.0, altura, 0.0);
        glEnd();
    }
}
