#include "Plate.h"

Plate::Plate(Vertex3D* position, GLfloat size, TgaTexture* texture)
	: DrawableObjectBase(position, texture), size(size)
{
	this->vertexCount = 4;
	this->type = GL_QUADS;
}

Plate::~Plate()
{
	delete this->cornerA;
	delete this->cornerB;
	delete this->cornerC;
	delete this->cornerD;

	delete this->position;
	delete this->vertices;
}

void Plate::generate()
{
	this->cornerA = new Vertex3D(0, 0, size);
	this->cornerB = new Vertex3D(size, 0, size);
	this->cornerC = new Vertex3D(size, 0, 0);
	this->cornerD = new Vertex3D(0, 0, 0);

	texCoords = new TexCoords *[this->vertexCount];
	vertices = new Vertex3D *[this->vertexCount];

	texCoords[0] = new TexCoords(0.0f, 0.0f);
	texCoords[1] = new TexCoords(size, 0.0f);
	texCoords[2] = new TexCoords(size, size);
	texCoords[3] = new TexCoords(0.0f, size);

	// bottom plate
	vertices[0] = cornerA;
	vertices[1] = cornerB;
	vertices[2] = cornerC;
	vertices[3] = cornerD;
}