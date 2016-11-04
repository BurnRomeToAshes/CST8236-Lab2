#ifndef _CUBE_H_
#define _CUBE_H_
#include <SFML/Graphics.hpp>
#include <SFML\OpenGL.hpp>

class Cube
{
public:
  Cube(GLuint textureID);
  float hAngle;
  float vAngle;

  void Update(float dt);
  void Draw(GLenum mode);
  void loadTextures();
  void rotate(float dt);

private:
  float _horizontalAngle;
  float _verticalAngle;
  
  GLuint _textureID;
  float _textureOffset;
  GLuint texturesID[6];
};

#endif //_CUBE_H_