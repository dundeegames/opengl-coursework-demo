#include"light.h"


Light::Light(int id_)
{
	id = id_;
}


Light::~Light()
{


}


void Light::init(GLfloat aR, GLfloat aG, GLfloat aB, GLfloat aA,  GLfloat dR, GLfloat dG, GLfloat dB, GLfloat dA, GLfloat x, GLfloat y, GLfloat z, GLfloat t)
{
	Ambient[0] = aR;
	Ambient[1] = aG;
	Ambient[2] = aB;
	Ambient[3] = aA;

	Diffuse[0] = dR;
	Diffuse[1] = dG;
	Diffuse[2] = dB;
	Diffuse[3] = dA;

	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	Position[3] = t;

}


void Light::render()
{
	glLightfv(id, GL_AMBIENT,  Ambient);
	glLightfv(id, GL_DIFFUSE,  Diffuse);
	glLightfv(id, GL_POSITION, Position);
	glEnable(id);
}

