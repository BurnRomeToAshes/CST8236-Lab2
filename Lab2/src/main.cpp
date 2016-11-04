
#include <SFML/Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include "Cube.h"
#include "main.h"

using namespace sf;

int main(int argc, char *argv)
{

  GLenum mode = GL_TRIANGLES; // by default it's triangles
  
  sf::RenderWindow window(sf::VideoMode(400, 400), "Lab 2 - DRAW MODE: GL_TRIANGLES ", sf::Style::Titlebar | sf::Style::Close);
  glEnable(GL_TEXTURE_2D);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  glDepthFunc(GL_LESS);
  
  glEnable(GL_CULL_FACE);

  glFrontFace(GL_CW);

  float positionZ = 0.5f;
  float angle = 0.0f;
  
  sf::Event evt;
  sf::Clock appTimer;

  Cube cube(NULL);
  cube.loadTextures();

  while (window.isOpen()) {
    float deltaTime = appTimer.restart().asSeconds();

    while (window.pollEvent(evt)) {
      if (evt.type == sf::Event::Closed) {
        window.close();
      }

	  if (evt.type == sf::Event::KeyPressed) {
		  switch (evt.key.code) {

		  case Keyboard::Num1: mode = GL_TRIANGLES; window.setTitle("Lab 2 - DRAW MODE: GL_TRIANGLES"); break;

		  case Keyboard::Num2: mode = GL_TRIANGLE_STRIP; window.setTitle("Lab 2 - DRAW MODE: GL_TRIANGLE_STRIP"); break;

		  case Keyboard::Num3: mode = GL_QUADS; window.setTitle("Lab 2 - DRAW MODE: GL_QUADS"); break;

		  case Keyboard::Num4: mode = GL_QUAD_STRIP; window.setTitle("Lab 2 - DRAW MODE: GL_QUAD_STRIP"); break;

		  case Keyboard::Up: cube.hAngle = 0.0f; cube.vAngle = 90.0f; cube.rotate(deltaTime); break;

		  case Keyboard::Down: cube.hAngle = 0.0f; cube.vAngle = -90.0f; cube.rotate(deltaTime); break;

		  case Keyboard::Left: cube.hAngle = -90.0f; cube.vAngle = 0.0f; cube.rotate(deltaTime); break;

		  case Keyboard::Right: cube.hAngle = 90.0f; cube.vAngle = 0.0f; cube.rotate(deltaTime); break;

		  default: break;
		  }
	  }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLenum error = glGetError();

    float offset = 0.25f;
    angle += 90.0f * deltaTime;

    
    GLfloat position[] = { 1, -0.1, 2,  0.0f };
    glLightfv(GL_LIGHTING, GL_POSITION, position);
  
	cube.Draw(mode);
	cube.Update(deltaTime);
	
    window.display();
  }

  return 0;
}