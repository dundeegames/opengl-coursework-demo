#include "planets.h"


void Planets::init()
{
	rotation = 0;
	rotation2 = 0;
	rotation3 = 0;
	speed = 15.0;
}

// ------------------------------------------------------------------------------

void Planets::update(float dt)
{
	rotation += (speed*3) * dt;
	rotation2 += (speed*2) * dt;
	rotation3 += speed * dt;
}

// ------------------------------------------------------------------------------

void Planets::render()
{
	// rotate matrix
		glTranslatef(-1.0f, 0.0f, 0.0f);
		//tilt our solar system slightly so it isn’t on the eye plane
		glRotatef(20, 1, 0, 0);
		glPushMatrix();	// Remember where we are.  THE SUN

			// render the sun
			glColor3f(1.0f, 0.9f, 0.0f);
			gluSphere(gluNewQuadric(), 0.40f, 40, 40);

			glPushMatrix();
				//render planet 1
				
				glRotatef(rotation, 0.0f, 0.5f, 0.5f);
				glTranslatef(1.0f, 0.0f, 0.0f);
				glScalef(0.1f, 0.1f, 0.1f);
				glColor3f(0.8f, 0.1f, 0.1f);
				gluSphere(gluNewQuadric(), 0.40, 40,40);
			glPopMatrix();//GO BACK TO SUN

			// Notice the indentation, this helps keep track of all the pushes and pops

			glPushMatrix(); // REMEMBER WHERE WE ARE
				// render planet 2
				glRotatef(rotation2,0.0f, 0.0f, 1.0f);
				glTranslatef(1.5f, 0.0f, 0.0f);
				glScalef(0.3f, 0.3f, 0.3f);
				glColor3f(0.1f, 0.3f, 1.0f);
				gluSphere(gluNewQuadric(), 0.40f, 40, 40);
				glPushMatrix(); // REMEMBER WHERE WE ARE
					// Render a moon around planet 2
					glRotatef((rotation2*2.0f),0.0f, 1.0f, 0.0f);
					glTranslatef(1.5f, 0.0f, 0.0f);
					glScalef(0.3f, 0.3f, 0.3f);
					glColor3f(0.8f, 0.8f, 0.8f);
					gluSphere(gluNewQuadric(), 0.40f, 40, 40);
				glPopMatrix();
			glPopMatrix();//GO BACK TO SUN

			// going for a new planet and moons
			glPushMatrix(); // REMEMBER WHERE WE ARE
				// render planet 3
				glRotatef(rotation3, 0.0f, 1.0f, 0.0f);
				glTranslatef(3.5f, 0.0f, 0.0f);
				glScalef(0.5f, 0.5f, 0.5f);
				glColor3f(0.3f, 0.3f, 1.0f);
				gluSphere(gluNewQuadric(), 0.40f, 40, 40);
				glPushMatrix(); // REMEMBER WHERE WE ARE
					// Render a moon1 around planet 3
					glRotatef((rotation3*3.0f), 0.0f, 1.0f, 0.0f);
					glTranslatef(1.5f, 0.0f, 0.0f);
					glScalef(0.3f, 0.3f, 0.3f);
					glColor3f(0.8f, 0.8f, 0.8f);
					gluSphere(gluNewQuadric(), 0.40f, 40, 40);
				glPopMatrix();	// GO BACK TO PLANET 3
				glPushMatrix(); // REMEMBER WHERE WE ARE
					// Render a moon2 around planet 3
					glRotatef((rotation3*(-5.0f)), 0.0f, 1.0f, 0.0f);
					glTranslatef(2.5f, 0.0f, 0.0f);
					glScalef(0.4f, 0.4f, 0.4f);
					glColor3f(0.3f, 0.3f, 0.3f);
					gluSphere(gluNewQuadric(), 0.40f, 40, 40);
					glPushMatrix(); // REMEMBER WHERE WE ARE
						// Render a moon3 around moon2
						glRotatef((rotation3*12.0f), 0.0f, 1.0f, 0.0f);
						glTranslatef(1.5f, 0.0f, 0.0f);
						glScalef(0.4f, 0.4f, 0.4f);
						glColor3f(0.5f, 1.0f, 0.5f);
						gluSphere(gluNewQuadric(), 0.40f, 40, 40);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();//GO BACK TO SUN

		glPopMatrix();

	// reset colour
	glColor3f(1.0f, 1.0f, 1.0f);

}