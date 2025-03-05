#include <windows.h>
#include <glut.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <cstring>

#define FIX		0.02

using namespace std;

float degree = 0;
float x_take = 0, y_take = 0, z_take = 0;
float progress = 0.05, back = 0.05;
int window_width = 1500, window_height = 600;
static float value = 0;
static float instant = 0;
GLfloat scrolling_text_loc = -10.0;
float view = 20.0;
char text[6][80];
int text_count = 0;


void House(void) 
{
	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(-0.5, 1.0, 0.5);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(0.5, 1.0, 0.5);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(-0.5, 1.0, -0.5);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(-0.5, 1.0, 0.5);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(0.5, 1.0, 0.5);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(0.5, 1.0, -0.5);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(0.5, 1.0, -0.5);
	glVertex3f(0.0, 1.8, 0.0);
	glVertex3f(-0.5, 1.0, -0.5);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, 0.3, 0.5);
	glVertex3f(0.5, 1.0, 0.5);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, 1.0, 0.5);
	glVertex3f(0.5, 1.0, 0.5);
	glVertex3f(-0.5, 0.3, 0.5);
	glVertex3f(0.5, 0.3, 0.5);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, 0.3, 0.5);
	glVertex3f(-0.5, 0.0, 0.5);
	glVertex3f(-0.2, 0.3, 0.5);
	glVertex3f(-0.2, 0.0, 0.5);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.2, 0.3, 0.5);
	glVertex3f(0.2, 0.0, 0.5);
	glVertex3f(0.5, 0.3, 0.5);
	glVertex3f(0.5, 0.0, 0.5);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, 1.0, -0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glVertex3f(-0.5, 1.0, 0.5);
	glVertex3f(-0.5, 0.0, 0.5);
	glEnd();

	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.5, 1.0, 0.5);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.5, 1.0, -0.5);
	glVertex3f(0.5, 0.0, -0.5);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.5, 1.0, -0.5);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(-0.5, 1.0, -0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glEnd();

	glPopMatrix();
}

void Sky(void) 
{
	glColor3f(0, 1, 1);
	glPushMatrix();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, -500.0);
	glVertex3f(-500.0, 0.0, -400.0);
	glVertex3f(500.0, 0, -400);
	glVertex3f(500.0, 0, -500.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, -400.0);
	glVertex3f(-500.0, 0.0, -300.0);
	glVertex3f(500.0, 0, -300.0);
	glVertex3f(500.0, 0, -400);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, -300.0);
	glVertex3f(-500.0, 0.0, -200.0);
	glVertex3f(500.0, 0, -200);
	glVertex3f(500.0, 0, -300.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, -200.0);
	glVertex3f(-500.0, 0.0, -100.0);
	glVertex3f(500.0, 0, -100.0);
	glVertex3f(500.0, 0, -200);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, -100.0);
	glVertex3f(-500.0, 0.0, 0.0);
	glVertex3f(500.0, 0, 0);
	glVertex3f(500.0, 0, -100.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, 0.0);
	glVertex3f(-500.0, 0.0, 100.0);
	glVertex3f(500.0, 0, 100.0);
	glVertex3f(500.0, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, 100.0);
	glVertex3f(-500.0, 0.0, 200.0);
	glVertex3f(500.0, 0, 200);
	glVertex3f(500.0, 0, 100.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, 200.0);
	glVertex3f(-500.0, 0.0, 300.0);
	glVertex3f(500.0, 0, 300.0);
	glVertex3f(500.0, 0, 200);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, 100.0);
	glVertex3f(-500.0, 0.0, 200.0);
	glVertex3f(500.0, 0, 200);
	glVertex3f(500.0, 0, 100.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, 400.0);
	glVertex3f(500.0, 0, 400);
	glVertex3f(-500.0, 0.0, 600.0);
	glVertex3f(500.0, 0, 300.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-500.0, 0.0, 500.0);
	glVertex3f(-500.0, 0.0, 600.0);
	glVertex3f(500.0, 0, 600);
	glVertex3f(500.0, 0, 500.0);
	glEnd();

	glPopMatrix();
}

void Object(void) 
{
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.6, 0.2, 0.06);
	glutSolidSphere(0.5, 3.75, 3.75);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6, 0.4, 0.12);
	glutSolidCube(0.5);
	glPopMatrix();

	glPopMatrix();
}

void Car(void) 
{
	glColor3f(0, 0, 1);
	glPushMatrix();

	glPushMatrix();
	glScalef(2, .5, 1);
	glutSolidCube(.5);
	glPopMatrix();
	glTranslatef(0, 0, .25);

	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glColor3f(0, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);
	glTranslatef(.8, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);
	glPopMatrix();
	glTranslatef(0, 0, -.5);

	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glColor3f(0, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);
	glTranslatef(.8, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);
	glPopMatrix();

	glPopMatrix();
}

void Tunnel(void) 
{
	glPushMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0, 0.5);
	glEnd();

	glPopMatrix();
}

void Wall(void) 
{
	glColor3f(0.25, 0.25, 0.25);
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.5, 0.3, 0.5);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.5, 0.3, -15.5);
	glVertex3f(0.5, 0.0, -15.5);
	glEnd();
	glPopMatrix();
}

void BackWall(void) 
{
	glColor3f(0.25, 0.25, 0.25);
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(5.0, 0.3, -0.5);
	glVertex3f(5.0, 0.0, -0.5);
	glVertex3f(-4.0, 0.3, -0.5);
	glVertex3f(-4.0, 0.0, -0.5);
	glEnd();
	glPopMatrix();
}

void Sun(void) 
{
	glColor3f(1, 1, 0);
	glPushMatrix();

	glBegin(GL_POLYGON);
	for (double i = 0; i < 2 * 3.141; i += 3.141 / 6)
		glVertex3f(cos(i) * 0.75, sin(i) * 0.75, 0.0);
	glEnd();

	glPopMatrix();
}

void OpenCone(void) 
{
	glColor3f(1, 0, 1);
	glPushMatrix();
	glutSolidCone(0.5, 1, 4, 45);
	glPopMatrix();
}

void Walk(void) 
{
	glLoadIdentity();

	static int b = 1;
	if (b == 1)
		value++;

	if (value >= 15)
		b = 2;

	if (b == 2)
		value--;

	if (value < -15)
		b = 1;
}

void TakeForward(void) 
{
	x_take -= (float) sin(degree * FIX) * progress;
	z_take -= (float) cos(degree * FIX) * progress;
}

void TakeBack(void) 
{
	x_take += (float) sin(degree * FIX) * back;
	z_take += (float) cos(degree * FIX) * back;
}

void TakeRight(void) 
{
	degree -= 1.0;
	if (degree <= -270)
		degree = 90;
}

void TakeLeft(void) 
{
	degree += 1.0;
	if (degree >= 270)
		degree = -90;
}

void Snake(void) 
{
	glRotatef(-degree, 0, 2, 0);
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(5, 0.0, 10);

	glScalef(0.075, 0.075, 0.075);
	glutSolidSphere(0.3, 0.6, 0.6);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, 0.0, 6.0);

	glScalef(0.128, 0.16, 0.16);
	glutSolidCone(12, 12, 24, 24);
	glColor3f(0, 0, 0);
	glTranslatef(-4.0, 10.0, 0.0);

	glScalef(0.3, 0.3, 0.3);
	glutSolidSphere(10, 20, 20);
	glTranslatef(32.0, 0.0, 0.0);

	glutSolidSphere(10, 20, 20);
	glTranslatef(-18, -35.0, -25);

	glColor3f(1.0, 1.0, 0.6);
	glScalef(4.5, 4.5, 4.5);
	glutSolidSphere(10, 20, 20);
	glTranslatef(0, 4.0, -12);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-5, 0.5, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-5, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-2, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(0, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(0, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(2, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(3, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(4, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(5, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(6, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(4, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(2, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(1, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(0, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(0, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-1, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-2, 0.0, -10);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-2, 0.0, -8);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(0.8, 0.8, 0.8);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-2, 0.0, -6);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(0.8, 0.8, 0.8);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-2, 0.0, -6);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(0.8, 0.8, 0.8);
	glutSolidSphere(7, 20, 20);
	glTranslatef(-2, 0.0, -6);

	glColor3f(0.82, 0.0, 0.0);
	glScalef(0.8, 0.8, 0.8);
	glutSolidSphere(7, 20, 20);
	glPopMatrix();
}

void DogsEyes(void) 
{
	glColor3f(0.8, 0.8, 0.8);
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glutSolidCube(0.1);
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, 0.43);
	glutSolidCube(0.1);
}

void DogsHead() 
{
	glColor3f(0.2, 0.2, 0.2);
	glutSolidCube(0.5);
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.4, -0.1, 0.0);
	glutSolidCube(0.3);
	glTranslatef(-0.53, 0.40, -0.2);
	DogsEyes();
}

void DogsHindLegs1(void)
{
	glColor3f(0.6, 0.6, 0.6);
	glutSolidCube(0.3);
}

void DogsHindLegs2(void) 
{
	glPushMatrix();
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(0.3);
	glPopMatrix();
}

void DogsHindLegs()
{
	glScalef(1.0, 3.0, 1.0);
	DogsHindLegs1();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.0, -0.3, 0.0);
	DogsHindLegs2();
}

void DogsFrontLegs1A(void) 
{
	glColor3f(0.6, 0.6, 0.6);
	glutSolidCube(0.3);
}

void DogsFrontLegs1B(void)
{
	glPushMatrix();
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(0.3);
	glPopMatrix();
}

void DogsFrontLegs1(void)
{
	glScalef(1.0, 3.0, 1.0);
	DogsFrontLegs1A();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.0, -0.3, 0.0);
	DogsFrontLegs1B();
}

void DogsHindLegs1A(void) 
{
	glColor3f(0.6, 0.6, 0.6);
	glutSolidCube(0.3);
}

void DogsHindLegs1B(void)
{
	glPushMatrix();
	glColor3f(0.4, 0.4, 0.4);
	glutSolidCube(0.3);
	glPopMatrix();
}

void DogsHindLegs1C(void)
{
	glScalef(1.0, 3.0, 1.0);
	DogsHindLegs1A();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.0, -0.3, 0.0);
	DogsHindLegs1B();
}

void DogsTail(void) 
{
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glScalef(1.0, 5.0, 1.0);
	glutSolidCube(0.1);
	glPopMatrix();
}

void DogsBody(void) 
{
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.5, 1.0, 1.0);
	glutSolidCube(1.0);
	glTranslatef(-0.45, 0.7, 0.0);
	DogsTail();
}

void EntireDog(void) 
{
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.87, 0.0, 0.2);
	DogsFrontLegs1();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(0.9, 0.0, -0.68);
	DogsHindLegs();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(-0.53, 0.0, -0.68);
	DogsFrontLegs1();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);
	glTranslatef(-0.53, 0.0, 0.2);
	DogsHindLegs1C();
	glPopMatrix();
}

void DogsComplete(void) 
{
	glPushMatrix();
	glTranslatef(1.0, 1.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
	DogsBody();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.85, 0.5, 1.2);
	glScalef(0.8, 0.8, 0.8);
	EntireDog();
	glPopMatrix();
}

void DogsFunc(void) 
{
	glPushMatrix();
	glTranslatef(1.0, 1.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
	DogsComplete();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, 2.2, 1.8);
	glScalef(1.5, 1.0, 1.5);
	DogsHead();
	glPopMatrix();
}

void DogsFunction(void) 
{
	glPushMatrix();
	glScalef(0.25, 0.25, 0.25);
	DogsFunc();
	glPopMatrix();
}

void Earth(void) 
{
	glLoadIdentity();
	glColor3f(0, 1, 0);
	gluLookAt(0.0, 1.5, 5.5, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
	glRotatef(-degree, 0, 0.1, 0);
	glTranslatef(-x_take, -y_take, -z_take);

	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(-5000.0, 0.0, -5000.0);
	glVertex3f(-5000.0, 0.0, 5000.0);
	glVertex3f(5000.0, 0.0, 5000.0);
	glVertex3f(1000.0, 0.0, -5000.0);
	glEnd();

	glPushMatrix();
	glTranslatef(-2.5, 0.0, -3);
	OpenCone();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.0, -6);
	Tunnel();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.35, -10);
	Car();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.0, -14);
	House();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 0.35, -2);
	DogsFunction();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 0.0, -6);
	House();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 0.5, -10);
	Object();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 0.0, -14);
	Car();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 0.0, -2);
	Wall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, 0.0, -2);
	Wall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -17);
	BackWall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, 0.0, -2);
	House();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, 0.0, -6);
	Tunnel();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, 0.35, -10);
	Car();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, 0.0, -14);
	House();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.5, 0.35, -2);
	Car();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.5, 0.0, -6);
	House();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.5, 0.5, -10);
	Object();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 0.0, -10);
	Snake();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.5, 0.0, -2);
	Wall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.0, 0.0, -17);
	BackWall();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 5.0, 0.0);
	Sky();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.0, 4.0, -30.0);
	Sun();;
	glPopMatrix();

	glPopMatrix();
}

void SpiderRightFoot(void) 
{
	glPushMatrix();
	glLineWidth(1.0);
	glRotatef(value, -1, -1, 0);

	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0.1, 0, 0);
	glVertex3f(0.1, 0, 0);
	glVertex3f(0.1, -0.15, 0);
	glEnd();

	glPopMatrix();
}

void SpiderLeftAntenna(void) 
{
	glPushMatrix();
	glRotatef(instant, 1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.1, 0);
	glEnd();
	glPopMatrix();
}

void SpiderRightAntenna(void) 
{
	glPushMatrix();
	glRotatef(instant, 1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.1, 0);
	glEnd();
	glPopMatrix();
}

void SpiderLeftFoot(void) 
{
	glPushMatrix();
	glLineWidth(1.0);
	glRotatef(value, 1, 1, 0);

	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(-0.1, 0, 0);
	glVertex3f(-0.1, 0, 0);
	glVertex3f(-0.1, -0.15, 0);
	glEnd();

	glPopMatrix();
}

void Spider(void) 
{
	glLoadIdentity();
	gluLookAt(0.0, 2.5, 5.5, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
	glColor3f(0.6, 0.4, 0.12);

	glPushMatrix();
	glTranslatef(0, 0.05, 0);

	glPushMatrix();
	glColor3f(0.6, 0.4, 0.12);
	glutSolidSphere(0.04, 40, 40);

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.01, 0, -0.01);
	glRotatef(20, 0, 0, 1);
	SpiderLeftAntenna();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.01, 0, -0.01);
	glRotatef(-20, 0, 0, 1);
	SpiderRightAntenna();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.01, 0, -0.01);
	glRotatef(-20, 0, 1, 0);
	SpiderLeftFoot();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.01, 0, 0);
	SpiderLeftFoot();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.01, 0, 0.01);
	glRotatef(20, 0, 1, 0);
	SpiderLeftFoot();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.01, 0, -0.01);
	glRotatef(20, 0, 1, 0);
	SpiderRightFoot();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.01, 0, 0);
	SpiderRightFoot();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.01, 0, 0.01);
	glRotatef(-20, 0, 1, 0);
	SpiderRightFoot();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void Timer(void)
{
	if (scrolling_text_loc < -600)
		view -= 0.000011;

	if (view < 0) { 
		view = 20; 
		scrolling_text_loc = -10.0; 
	}

	scrolling_text_loc -= 0.015;
	glutPostRedisplay();
}

void TextPlayer(void)
{
	glTranslatef(0.0, -1, scrolling_text_loc);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.01, 0.01, 0.01);

	for (int i = 0; i < text_count; i++) {
		int text_length = (int)strlen(text[i]);
		glPushMatrix();
		glTranslatef(-(text_length * 37), -(i * 200), 0.0);

		for (int j = 0; j < text_length; j++) {
			glColor3f(0, 0, 0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i][j]);
		}

		glPopMatrix();
	}
}

void Start(void) 
{
	glClearColor(1.000, 1.000, 1.000, 1.000);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_VERTEX_ARRAY);
}

void Keyboard(int key, int x, int y) 
{
	switch (key) {
		case GLUT_KEY_LEFT:
			TakeLeft(); 
			Walk(); 
			break;
		case GLUT_KEY_RIGHT:
			TakeRight(); 
			Walk(); 
			break;
		case GLUT_KEY_UP:
			TakeForward(); 
			Walk(); 
			break;
		case GLUT_KEY_DOWN:
			TakeBack(); 
			Walk(); 
			break;
		default:
			break;
	}

	glutPostRedisplay();
}

void DrawingPlace(void) 
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0.0, 3.5, 5.5, 0.0, 0.0, 2.0, 0.0, 1.0, 0.0);

	Earth();
	Spider();
	TextPlayer();

	glutPostRedisplay();
	glutSwapBuffers();
}

void Resize(int width, int height) 
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, (float)width / (float)height, 1, 20000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) 
{
	strcpy_s(text[0], "OpenGL Game Programming");
	strcpy_s(text[1], "Code Design");
	strcpy_s(text[2], "Esen EYRIBAS");
	strcpy_s(text[3], "Spider Game");
	text_count = 4;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Spider Game");

	glLineWidth(3);
	Start();
	glutReshapeFunc(Resize);
	glutDisplayFunc(DrawingPlace);
	glutSpecialFunc(Keyboard);
	glutIdleFunc(Timer);

	glutMainLoop();
	
	return 0;
}