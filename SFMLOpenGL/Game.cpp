#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
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
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	isRunning = true;
}

void Game::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		isRunning = false;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		input = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		input = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		input = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		input = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		input = 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		input = 6;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		input = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		input = 8;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		input = 9;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		input = 0;
	}
	

}

void Game::draw()
{
	switch (input)
	{
	case 1:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
		glLoadIdentity();
		std::cout << "points" << std::endl;
		glBegin(GL_POINTS);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		break;
	case 2:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "lines" << std::endl;
		glBegin(GL_LINES);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(-0.5, 2.0, -5.0);
			glVertex3f(-2.0, -1.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(2.0, -1.0, -5.0);
			glVertex3f(0.5, 2.0, -5.0);
		}
		break;
	case 3:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "line strip" << std::endl;
		glBegin(GL_LINE_STRIP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(-0.5, 2.0, -5.0);
			glVertex3f(-2.0, -1.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(2.0, -1.0, -5.0);
			glVertex3f(0.5, 2.0, -5.0);
		}
		break;
	case 4:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "line loop" << std::endl;
		glBegin(GL_LINE_LOOP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(-0.5, 2.0, -5.0);
			glVertex3f(-2.0, -1.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(2.0, -1.0, -5.0);
			glVertex3f(0.5, 2.0, -5.0);
		}
		break;
	case 5:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "triangles" << std::endl;
		glBegin(GL_TRIANGLES);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		break;
	case 6:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "triangle strip" << std::endl;
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
		break;
	case 7:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "triangle fan" << std::endl;
		glBegin(GL_TRIANGLE_FAN);
		{
			glColor3f(100.0f, 0.0f, 0.0f);
			glVertex3f(-2.0, 1.0, -5.0);
			glVertex3f(-1.0, -0.0, -5.0);
			glVertex3f(-2.0, -1.0, -5.0);
			glColor3f(0.0f, 100.0f, 100.0f);
			glVertex3f(0.0, -1.0, -5.0);
			glVertex3f(-1.0, -0.0, -5.0);
			glVertex3f(-2.0, -1.0, -5.0);
		}
		break;
	case 8:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "quads" << std::endl;
		glScalef(2.0f, 2.0f, 2.0f);
		glBegin(GL_QUADS);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(0.0, -1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(-1.0, 1.0, -5.0);
		}
		break;
	case 9:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "quads strip" << std::endl;
		glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_QUAD_STRIP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -5.0);
			glVertex3f(0.0, 0.5, -5.0);
			glVertex3f(-0.5, -0.5, -5.0);
			glVertex3f(0.0, -0.5, -5.0);
			glColor3f(100.0f, 0.0f, 0.0f);
			glVertex3f(-0.3, -1.0, -5.0);
			glVertex3f(0.3, -1.0, -5.0);
		}
		break;
	case 0:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		std::cout << "polygon" << std::endl;
		glTranslatef(1.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 0.9, -5.0);
			glVertex3f(0.6, 0.2, -5.0);
			glVertex3f(0.3, -0.8, -5.0);
			glVertex3f(-0.3, -0.8, -5.0);
			glVertex3f(-0.6, 0.2, -5.0);
		}
		break;
	}
	glEnd();
	//cout << "Draw up" << endl;
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
