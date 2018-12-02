#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	int input;
	
	const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed{ sf::seconds(0) };

	bool rotating{ false };
	float rotationAngle = 0.0f;

	bool scaling{ false };
	float scaleScalar = 1.0f;

	bool translating{ false };
	float translateScalarX = 0.0f;
	float translateScalarY = 0.0f;
};