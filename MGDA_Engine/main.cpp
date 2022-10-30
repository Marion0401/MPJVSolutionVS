#include <GLFW/glfw3.h>
#include <time.h>
#include <iostream>

#include "./Game/SimpleShooter/Bullet.h"
#include "./Game/SimpleShooter/Cannonball.h"
#include "./Game/SimpleShooter/Fireball.h"
#include "./Game/SimpleShooter/Lazer.h"
#include "./Game/SimpleShooter/GameEnvironment.h"
#include "./Engine/Graphics/EngineGFX.h" 
#include "./Engine/Graphics/ShaderS.h"

// settings
unsigned int scrWidth = 1920;
unsigned int scrHeight = 1080;
const char* title = "Simple Shooter";
GLuint shaderProgram;

/*
	Main Loop Functions 
*/

// callback for window size change
void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	scrWidth = width;
	scrHeight = height;

	// update projection matrix
	EngineGFX.setOrthographicProjection(shaderProgram, 0, width, 0, height, 0.0f, 1.0f);
}


void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	GameEnvironment* env = reinterpret_cast<GameEnvironment*>(glfwGetWindowUserPointer(window));
	if (env)
	{
		//Update Mouvement de la Balle
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
			env->isShot = true;
	}
}

void processInput(GLFWwindow* window)
{
	GameEnvironment* environment = reinterpret_cast<GameEnvironment*>(glfwGetWindowUserPointer(window));
	if (!environment)
	{
		return;
	}

	// Keyboard
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// Changement de projectile
		// 1 Fireball
		// 2 Bullet
		// 3 Cannonbullet
		// 4 Lazer
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		environment->projCurrent = Fireball(Vector3D(0, 0, 0), Vector3D(-1, 0, 0), Vector3D(0, 0, 0));
		environment->projCurrent.setVelocity(Vector3D(-fireball_velocity, 0, 0));
		ball.setFillColor(Color::Red);
		//nom_Proj.setString("Fireball");
		//info_projectile.setString("Velocity = " + std::to_string(environment->projCurrent.getVelocity().getNorm()) + "\n"
		//	"Mass = " + std::to_string(environment->projCurrent.getMass()) + "\n"
		//	"Radius = " + std::to_string(environment->projCurrent.getRadius()) + "\n");

		ball.setRadius(environment->projCurrent.getRadius() * CONST_GRAPHIQUE);
		ball.setPosition(start_ball, 0);
		environment->isShot = false;

	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		environment->projCurrent = Bullet(Vector3D(0, 0, 0), Vector3D(-1, 0, 0), Vector3D(0, 0, 0));
		environment->projCurrent.setVelocity(Vector3D(-bullet_velocity, 0, 0));
		ball.setFillColor(Color::Green);
		//nom_Proj.setString("Bullet");
		//info_projectile.setString("Velocity = " + std::to_string(environment->projCurrent.getVelocity().getNorm()) + "\n"
		//	"Mass = " + std::to_string(environment->projCurrent.getMass()) + "\n"
		//	"Radius = " + std::to_string(environment->projCurrent.getRadius()) + "\n");

		ball.setRadius(environment->projCurrent.getRadius() * CONST_GRAPHIQUE);
		ball.setPosition(start_ball, 0);
		environment->isShot = false;

	}
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		environment->projCurrent = Cannonball(Vector3D(0, 0, 0), Vector3D(-1, 0, 0), Vector3D(0, 0, 0));
		environment->projCurrent.setVelocity(Vector3D(-cannonball_velocity, 0, 0));
		ball.setFillColor(Color::Blue);
		//nom_Proj.setString("Cannonball");
		//info_projectile.setString("Velocity = " + std::to_string(environment->projCurrent.getVelocity().getNorm()) + "\n"
		//	"Mass = " + std::to_string(environment->projCurrent.getMass()) + "\n"
		//	"Radius = " + std::to_string(environment->projCurrent.getRadius()) + "\n");

		ball.setRadius(environment->projCurrent.getRadius() * CONST_GRAPHIQUE);
		ball.setPosition(start_ball, 0);
		environment->isShot = false;

	}
	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		environment->projCurrent = Lazer(Vector3D(0, 0, 0), Vector3D(-1, 0, 0), Vector3D(0, 0, 0));
		environment->projCurrent.setVelocity(Vector3D(-lazer_velocity, 0, 0));
		ball.setFillColor(Color::Yellow);
		//nom_Proj.setString("Lazer");
		//info_projectile.setString("Velocity = " + std::to_string(environment->projCurrent.getVelocity().getNorm()) + "\n"
		//	"Mass = " + std::to_string(environment->projCurrent.getMass()) + "\n"
		//	"Radius = " + std::to_string(environment->projCurrent.getRadius()) + "\n");

		ball.setRadius(environment->projCurrent.getRadius() * CONST_GRAPHIQUE);
		ball.setPosition(start_ball, 0);
		environment->isShot = false;

	}

}

/*
	Main loop
*/

int main(void)
{
	GLFWwindow* window;
	GameEnvironment* environment = new GameEnvironment();

	// glfw: initialize and configure
	// ------------------------------
	EngineGFX::initGLFW(3, 3);

	// glfw window creation
	// --------------------
	GLFWwindow* window;
	EngineGFX::createWindow(window, title, scrWidth, scrHeight, framebuffer_size_callback);
	glfwSetWindowUserPointer(window, reinterpret_cast<void*>(environment));

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	EngineGFX::loadGlad();

	glViewport(0, 0, scrWidth, scrHeight);

	// build and compile our shader program
	// ------------------------------------
	shaderProgram = ShaderS::genShaderProgram("./Engine/Shaders/main.vs", "./Engine/Shaders/main.fs");
	ShaderS::setOrthographicProjection(shaderProgram, 0, scrWidth, 0, scrHeight, 0.0f, 1.0f);

	// uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Mouse
	glfwSetMouseButtonCallback(window,mouse_button_callback);

	time_t t1, t2;
	float deltatime = 0;

    // Setup du projectile
    environment->projCurrent = Fireball(Vector3D(0,0,0), Vector3D(-1, 0, 0), Vector3D(0,0,0));

    //Setup balle qui représente le projectile
	CircleShape ball;
	bool environment->isShot = false;
	ball.setRadius(environment->projCurrent.getRadius() * CONST_GRAPHIQUE);
	ball.setFillColor(Color::Red);
	ball.setPosition(window.getSize().x - (environment->projCurrent.getRadius() * CONST_GRAPHIQUE)*2, 0);

	//Setup target
	RectangleShape cible(sf::Vector2f(20, 100));
	int dir = 0;
	cible.setFillColor(Color::Red);
	cible.setPosition(10, LEN_CIBLE);

    // Interface du jeu
    //sf::Font font;
	//if (!font.loadFromFile("./resources/Font/Optien.ttf"))
	//{
	//	std::cerr << ".Error while loading font" << std::endl;
	//	return -1;
	//}

	//Nom du projectile
    //sf::Text nom_Proj;
    //nom_Proj.setFont(font);
    //nom_Proj.setString("Fireball");
    //nom_Proj.setCharacterSize(50);
    //nom_Proj.setFillColor(sf::Color::White);
    //nom_Proj.setStyle(sf::Text::Bold | sf::Text::Underlined);
    //nom_Proj.setPosition(40,0);

    //Informations du jeu
    //sf::Text info_jeu;
    //info_jeu.setFont(font);
    //info_jeu.setString("Press 1 Fireball - 2 pts\n"
    //		"Press 2 Bullet - 10 pts\n"
    //		"Press 3 Cannonball - 5 pts\n"
    //		"Press 4 Lazer - 1 pts");
    //info_jeu.setCharacterSize(20);
    //info_jeu.setPosition(50,60);
    //info_jeu.setFillColor(sf::Color::White);

    // Informations du projectile
    //sf::Text info_projectile;
    //info_projectile.setFont(font);
    //info_projectile.setString("Velocity = " + std::to_string(environment->projCurrent.getVelocity().getNorm()) + "\n"
	//							"Mass = " + std::to_string(environment->projCurrent.getMass()) + "\n"
	//							"Radius = " + std::to_string(environment->projCurrent.getRadius()) + "\n");
    //info_projectile.setCharacterSize(20);
    //info_projectile.setPosition(350,60);
    //info_projectile.setFillColor(sf::Color::White);

    while (!glfwWindowShouldClose(window))
    {
		//Input
		processInput(window);

    	//calcul du temps d'une frame
    	t1 = time(nullptr);

    	// Offset_y du nouveau projectile quand on le change
    	int start_ball = W_WIDTH - (environment->projCurrent.getRadius() * CONST_GRAPHIQUE)*2;

        if (!environment->isShot)
        {
        	ball.setPosition(ball.getPosition().x, Mouse::getPosition(window).y);
        	environment->projCurrent.setX(ball.getPosition().x);
        	environment->projCurrent.setY(Mouse::getPosition(window).y);

        } else {
        	//std::cout << environment->projCurrent.getVelocity() << std::endl;

        	// TODO corriger pb deltatime = 0
        	environment->projCurrent.integrer(0.05);
        	ball.setPosition(environment->projCurrent.getX(), environment->projCurrent.getY());

        	//ball.move(environment->projCurrent.getVelocity().getX(), environment->projCurrent.getVelocity().getY());

        }

        if(ball.getPosition().x <= 0)
		{
			environment->isShot = false;
		    ball.setPosition(Vector2f(W_WIDTH - ball.getRadius()*3, ball.getPosition().y));
		}

        //Update Mouvement de la Cible
		if (cible.getPosition().y <= 0)
			dir = 1;
		else if (cible.getPosition().y + LEN_CIBLE/2 >= W_HEIGHT)
			dir = 0;

		if (dir == 0)
		{
			cible.move(0, -1.f);
		}
		else
		{
			cible.move(0, 1.f);
		}

		/* Draw */
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();

        //calcul delta d'une frame
        t2 = time(nullptr);
		deltatime = difftime(t2, t1);
		//std::cout << deltatime << std::endl;

    }

	glfwTerminate();
	return 0;
}

