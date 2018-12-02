#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(10)
{
	index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == Event::KeyPressed)
			{
				if (sf::Keyboard::Escape == event.key.code)
				{
					isRunning = false;
				}

				if (sf::Keyboard::A == event.key.code)
				{
					rotating = true;
					rotationAngle += 0.005f;
				}
				if (sf::Keyboard::D == event.key.code)
				{
					rotating = true;
					rotationAngle -= 0.005f;
				}

				if (sf::Keyboard::W == event.key.code)
				{
					scaling = true;
					scaleScalar += 0.001f;
				}
				if (sf::Keyboard::S == event.key.code)
				{
					scaling = true;
					scaleScalar -= 0.001f;
				}

				if (sf::Keyboard::Up == event.key.code)
				{
					translating = true;
					translateScalarY += 0.001f;
				}
				if (sf::Keyboard::Down == event.key.code)
				{
					translating = true;
					translateScalarY -= 0.001f;
				}
				if (sf::Keyboard::Left == event.key.code)
				{
					translating = true;
					translateScalarX -= 0.001f;
				}
				if (sf::Keyboard::Right == event.key.code)
				{
					translating = true;
					translateScalarX += 0.001f;
				}
			}
			if (event.type == Event::KeyReleased)
			{
				if (sf::Keyboard::A == event.key.code)
				{
					rotating = false;
					rotationAngle = 0.0f;
				}
				if (sf::Keyboard::D == event.key.code)
				{
					rotating = false;
					rotationAngle = 0.0f;
				}
				if (sf::Keyboard::W == event.key.code)
				{
					scaling = false;
					scaleScalar = 1.0f;
				}
				if (sf::Keyboard::S == event.key.code)
				{
					scaling = false;
					scaleScalar = 1.0f;
				}
				if (sf::Keyboard::Up == event.key.code)
				{
					translating = false;
					translateScalarY = 0.0f;
				}
				if (sf::Keyboard::Down == event.key.code)
				{
					translating = false;
					translateScalarY = 0.0f;
				}
				if (sf::Keyboard::Left == event.key.code)
				{
					translating = false;
					translateScalarX = 0.0f;
				}
				if (sf::Keyboard::Right == event.key.code)
				{
					translating = false;
					translateScalarX = 0.0f;
				}
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glNewList(index, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(-0.25, 1.0, -5.0);
		glVertex3f(-1.0, -0.5, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
		glVertex3f(1.0, -0.5, -5.0);
		glVertex3f(0.25, 1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(-0.25, 1.0, -5.0);
		glVertex3f(-1.0, -0.5, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
		glVertex3f(1.0, -0.5, -5.0);
		glVertex3f(0.25, 1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(-0.25, 1.0, -5.0);
		glVertex3f(-1.0, -0.5, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
		glVertex3f(1.0, -0.5, -5.0);
		glVertex3f(0.25, 1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(-2.0, 1.0, -5.0);
		glVertex3f(-1.0, -0.0, -5.0);
		glVertex3f(-2.0, -1.0, -5.0);
		glColor3f(100.0f, 100.0f, 0.0f);
		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(-1.0, -0.0, -5.0);
		glVertex3f(-2.0, -1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(100.0f, 0.0f, 0.0f);
		glVertex3f(-2.0, 1.0, -5.0);
		glVertex3f(-1.0, -0.0, -5.0);
		glVertex3f(-2.0, -1.0, -5.0);
		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(-1.0, -0.0, -5.0);
		glVertex3f(-2.0, -1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(0.0, -1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(-1.0, 1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(-1.0, 1.0, -5.0);
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(0.0, -1.0, -5.0);
		glColor3f(100.0f, 0.0f, 0.0f);
		glVertex3f(-0.3, -1.0, -5.0);
		glVertex3f(0.3, -1.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 0.9, -5.0);
		glVertex3f(0.6, 0.2, -5.0);
		glVertex3f(0.3, -0.8, -5.0);
		glVertex3f(-0.3, -0.8, -5.0);
		glVertex3f(-0.6, 0.2, -5.0);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	if (rotating)
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	}

	if (scaling)
	{
		glScalef(scaleScalar, scaleScalar, 1.0f);
	}

	if (translating)
	{
		glTranslatef(translateScalarX, translateScalarY, 0.0f);
	}

	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Primative " << current << endl;
	glCallList(current);

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
