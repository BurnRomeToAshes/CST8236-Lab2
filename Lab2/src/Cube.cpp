#include "Cube.h"

Cube::Cube(GLuint textureID) : _horizontalAngle(0), _verticalAngle(0), _textureID(textureID)
{
  _textureOffset = 0.0f;
  hAngle = 90.0f;
  vAngle = 0.0f;
}

void Cube::Update(float dt)
{
  _textureOffset += 0.1f * dt;
  if (_textureOffset > 0.611) {
	  _textureOffset -= 0.611;
  }
}

void Cube::Draw(GLenum mode)
{
  float offset = 0.25;
  
  float leftS = _textureOffset;
  float rightS = leftS + 0.4f;
  float topT = 0.25f;
  float bottomT = 0.75f;


  GLenum error = glGetError();

  glPushMatrix();
  error = glGetError();
  
   // Front

   glBindTexture(GL_TEXTURE_2D, texturesID[0]);

   glBegin(mode);

   glColor3f(1.0f, 0.0f, 0.0f);
   glTexCoord2f(leftS, bottomT);
   glNormal3f(0.0f, 0.0f, 1.0f);
   glVertex3f(-offset, -offset, offset);

   glTexCoord2f(leftS, topT);
   glNormal3f(0.0f, 0.0f, 1.0f);
   glVertex3f(-offset, offset, offset);

   glTexCoord2f(rightS, topT);
   glNormal3f(0.0f, 0.0f, 1.0f);
   glVertex3f(offset, offset, offset);

   glTexCoord2f(rightS, bottomT);
   glNormal3f(0.0f, 0.0f, 1.0f);
   glVertex3f(offset, -offset, offset);
   glEnd();

   // Right

   glBindTexture(GL_TEXTURE_2D, texturesID[1]);

   glBegin(mode);
   glColor3f(0.0f, 1.0f, 0.0f);
   glTexCoord2f(leftS, bottomT);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glVertex3f(offset, -offset, offset);

   glTexCoord2f(leftS, topT);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glVertex3f(offset, offset, offset);

   glTexCoord2f(rightS, topT);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glVertex3f(offset, offset, -offset);

   glTexCoord2f(rightS, bottomT);
   glNormal3f(1.0f, 0.0f, 0.0f);
   glVertex3f(offset, -offset, -offset);
   glEnd();


   // Left

   glBindTexture(GL_TEXTURE_2D, texturesID[2]);

   glBegin(mode);
   glColor3f(0.0f, 0.0f, 1.0f);
   glTexCoord2f(leftS, bottomT);
   glNormal3f(-1.0f, 0.0f, 0.0f);
   glVertex3f(-offset, -offset, -offset);

   glTexCoord2f(leftS, topT);
   glNormal3f(-1.0f, 0.0f, 0.0f);
   glVertex3f(-offset, offset, -offset);

   glTexCoord2f(rightS, topT);
   glNormal3f(-1.0f, 0.0f, 0.0f);
   glVertex3f(-offset, offset, offset);

   glTexCoord2f(rightS, bottomT);
   glNormal3f(-1.0f, 0.0f, 0.0f);
   glVertex3f(-offset, -offset, offset);
   glEnd();
   // Back

   glBindTexture(GL_TEXTURE_2D, texturesID[3]);

   glBegin(mode);
   glColor3f(0.0f, 1.0f, 1.0f);
   glTexCoord2f(leftS, bottomT);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glVertex3f(offset, -offset, -offset);

   glTexCoord2f(leftS, topT);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glVertex3f(offset, offset, -offset);

   glTexCoord2f(rightS, topT);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glVertex3f(-offset, offset, -offset);

   glTexCoord2f(rightS, bottomT);
   glNormal3f(0.0f, 0.0f, -1.0f);
   glVertex3f(-offset, -offset, -offset);
   glEnd();

   // Top

   glBindTexture(GL_TEXTURE_2D, texturesID[4]);

   glBegin(mode);
   glColor3f(1.0f, 0.0f, 1.0f);
   glTexCoord2f(leftS, bottomT);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-offset, offset, offset);

   glTexCoord2f(leftS, topT);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-offset, offset, -offset);

   glTexCoord2f(rightS, topT);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glVertex3f(offset, offset, -offset);

   glTexCoord2f(rightS, bottomT);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glVertex3f(offset, offset, offset);
   glEnd();

   // Bottom

   glBindTexture(GL_TEXTURE_2D, texturesID[5]);

   glBegin(mode);
   glColor3f(1.0f, 1.0f, 1.0f);
   glTexCoord2f(leftS, bottomT);
   glNormal3f(0.0f, -1.0f, 0.0f);
   glVertex3f(-offset, -offset, -offset);

   glTexCoord2f(leftS, topT);
   glNormal3f(0.0f, -1.0f, 0.0f);
   glVertex3f(-offset, -offset, offset);

   glTexCoord2f(rightS, topT);
   glNormal3f(0.0f, -1.0f, 0.0f);
   glVertex3f(offset, -offset, offset);

   glTexCoord2f(rightS, bottomT);
   glNormal3f(0.0f, -1.0f, 0.0f);
   glVertex3f(offset, -offset, -offset);

   // End our drawing block.
   glEnd();
  
  glPopMatrix();
}

void Cube::loadTextures() {

	sf::Image images[2];
	images[0].loadFromFile("res/doge.jpg");
	images[1].loadFromFile("res/polar.jpg");


	glGenTextures(6, texturesID);


	for (int i = 0; i < 6; i++) {

		glBindTexture(GL_TEXTURE_2D, texturesID[i]);
		glTexImage2D(GL_TEXTURE_2D, // specifies that we're working on the active texture.
			0, // ignore.
			GL_RGBA, // specifies that making a texture that has RGBA data.
			images[i % 2].getSize().x, // specify the width of the texture.
			images[i % 2].getSize().y, // specify the height of the texture.
			0, // no border
			GL_RGBA, // specifies that we're working with an image that has RGBA data.
			GL_UNSIGNED_BYTE, // specifies the format of the RGBA data (in this case, everything is 0-255)
			images[i % 2].getPixelsPtr() // specifies the actual image data.
		);
		
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
}

void Cube::rotate(float dt) {
	_horizontalAngle = 20 * hAngle * dt;
	_verticalAngle = 20 * vAngle * dt;
	glRotatef(_horizontalAngle, 0.0f, 1.0f, 0.0f); // rotate at 90 degrees/second on the X axis. 
	glRotatef(_verticalAngle, 1.0f, 0.0f, 0.0f); //rotate 20 degrees on the Y axis
}