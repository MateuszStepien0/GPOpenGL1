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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		isRunning = false;
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
		{
			flip = false;
		}
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
	//cout << "Draw up" << endl;
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
