#include <SFML/Graphics.hpp>
#include "./src/Headers/Bullet.h"
#include "./src/Headers/Cannonball.h"
#include "./src/Headers/Fireball.h"
#include "./src/Headers/Lazer.h"
#include <iostream>

#define CONST_GRAPHIQUE 10
#define LEN_CIBLE 200

using namespace sf;
#include <time.h>

int main()
{

	RenderWindow window(VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Game");
	time_t t1, t2;
	float deltatime = 0;

    // Setup du projectile
    Projectile projCurrent = Fireball(Vector3D(0,0,0), Vector3D(-1, 0, 0), Vector3D(0,0,0));

    //Setup balle qui représente le projectile
	CircleShape ball;
	bool isShot = false;
	ball.setRadius(projCurrent.getRadius() * CONST_GRAPHIQUE);
	ball.setFillColor(Color::Red);
	ball.setPosition(window.getSize().x - (projCurrent.getRadius() * CONST_GRAPHIQUE)*2, 0);

	//Setup target
	RectangleShape cible(sf::Vector2f(20, 100));
	int dir = 0;
	cible.setFillColor(Color::Red);
	cible.setPosition(10, LEN_CIBLE);

    // Interface du jeu
    sf::Font font;
	if (!font.loadFromFile("./resources/Font/Optien.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		return -1;
	}

	//Nom du projectile
    sf::Text nom_Proj;
    nom_Proj.setFont(font);
    nom_Proj.setString("Fireball");
    nom_Proj.setCharacterSize(50);
    nom_Proj.setFillColor(sf::Color::White);
    nom_Proj.setStyle(sf::Text::Bold | sf::Text::Underlined);
    nom_Proj.setPosition(40,0);

    //Informations du jeu
    sf::Text info_jeu;
    info_jeu.setFont(font);
    info_jeu.setString("Press 1 Fireball - 2 pts\n"
    		"Press 2 Bullet - 10 pts\n"
    		"Press 3 Cannonball - 5 pts\n"
    		"Press 4 Lazer - 1 pts");
    info_jeu.setCharacterSize(20);
    info_jeu.setPosition(50,60);
    info_jeu.setFillColor(sf::Color::White);

    // Informations du projectile
    sf::Text info_projectile;
    info_projectile.setFont(font);
    info_projectile.setString("Velocity = " + std::to_string(projCurrent.getVelocity().getNorm()) + "\n"
								"Mass = " + std::to_string(projCurrent.getMass()) + "\n"
								"Radius = " + std::to_string(projCurrent.getRadius()) + "\n");
    info_projectile.setCharacterSize(20);
    info_projectile.setPosition(350,60);
    info_projectile.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
    	//calcul du temps d'une frame
    	t1 = time(nullptr);


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    	// Offset_y du nouveau projectile quand on le change
    	int start_ball = window.getSize().x - (projCurrent.getRadius() * CONST_GRAPHIQUE)*2;

        // Changement de projectile
        // 1 Fireball
        // 2 Bullet
        // 3 Cannonbullet
        // 4 Lazer
        if(Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			projCurrent = Fireball(Vector3D(0,0,0), Vector3D(-1, 0, 0), Vector3D(0,0,0));
			projCurrent.setVelocity(Vector3D(-fireball_velocity, 0, 0));
			ball.setFillColor(Color::Red);
			nom_Proj.setString("Fireball");
			info_projectile.setString("Velocity = " + std::to_string(projCurrent.getVelocity().getNorm()) + "\n"
										"Mass = " + std::to_string(projCurrent.getMass()) + "\n"
										"Radius = " + std::to_string(projCurrent.getRadius()) + "\n");

			ball.setRadius(projCurrent.getRadius() * CONST_GRAPHIQUE);
			ball.setPosition(start_ball , 0);
			isShot = false;

		} else if(Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			projCurrent = Bullet(Vector3D(0,0,0), Vector3D(-1, 0, 0), Vector3D(0,0,0));
			projCurrent.setVelocity(Vector3D(-bullet_velocity, 0, 0));
			ball.setFillColor(Color::Green);
			nom_Proj.setString("Bullet");
			info_projectile.setString("Velocity = " + std::to_string(projCurrent.getVelocity().getNorm()) + "\n"
										"Mass = " + std::to_string(projCurrent.getMass()) + "\n"
										"Radius = " + std::to_string(projCurrent.getRadius()) + "\n");

			ball.setRadius(projCurrent.getRadius() * CONST_GRAPHIQUE);
			ball.setPosition(start_ball , 0);
			isShot = false;

		} else if(Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			projCurrent = Cannonball(Vector3D(0,0,0), Vector3D(-1, 0, 0), Vector3D(0,0,0));
			projCurrent.setVelocity(Vector3D(-cannonball_velocity, 0, 0));
			ball.setFillColor(Color::Blue);
			nom_Proj.setString("Cannonball");
			info_projectile.setString("Velocity = " + std::to_string(projCurrent.getVelocity().getNorm()) + "\n"
										"Mass = " + std::to_string(projCurrent.getMass()) + "\n"
										"Radius = " + std::to_string(projCurrent.getRadius()) + "\n");

			ball.setRadius(projCurrent.getRadius() * CONST_GRAPHIQUE);
			ball.setPosition(start_ball , 0);
			isShot = false;

		} else if(Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
			projCurrent = Lazer(Vector3D(0,0,0), Vector3D(-1, 0, 0), Vector3D(0,0,0));
			projCurrent.setVelocity(Vector3D(-lazer_velocity, 0, 0));
			ball.setFillColor(Color::Yellow);
			nom_Proj.setString("Lazer");
			info_projectile.setString("Velocity = " + std::to_string(projCurrent.getVelocity().getNorm()) + "\n"
										"Mass = " + std::to_string(projCurrent.getMass()) + "\n"
										"Radius = " + std::to_string(projCurrent.getRadius()) + "\n");

			ball.setRadius(projCurrent.getRadius() * CONST_GRAPHIQUE);
			ball.setPosition(start_ball , 0);
			isShot = false;

		}

        //Update Mouvement de la Balle
        if(Mouse::isButtonPressed(Mouse::Left))
			isShot = true;

        if (!isShot)
        {
        	ball.setPosition(ball.getPosition().x, Mouse::getPosition(window).y);
        	projCurrent.setX(ball.getPosition().x);
        	projCurrent.setY(Mouse::getPosition(window).y);

        } else {
        	//std::cout << projCurrent.getVelocity() << std::endl;

        	// TODO corriger pb deltatime = 0
        	projCurrent.integrer(0.05);
        	ball.setPosition(projCurrent.getX(), projCurrent.getY());

        	//ball.move(projCurrent.getVelocity().getX(), projCurrent.getVelocity().getY());

        }

        if(ball.getPosition().x <= 0)
		{
			isShot = false;
		    ball.setPosition(Vector2f(window.getSize().x - ball.getRadius()*3, ball.getPosition().y));
		}

        //Update Mouvement de la Cible
		if (cible.getPosition().y <= 0)
			dir = 1;
		else if (cible.getPosition().y + LEN_CIBLE/2 >= window.getSize().y)
			dir = 0;

		if (dir == 0)
		{
			cible.move(0, -1.f);
		}
		else
		{
			cible.move(0, 1.f);
		}

        window.clear(Color::Black);

        //Draw
        window.draw(cible);
        window.draw(ball);
        window.draw(nom_Proj);
        window.draw(info_jeu);
        window.draw(info_projectile);

        window.display();

        //calcul delta d'une frame
        t2 = time(nullptr);
		deltatime = difftime(t2, t1);
		//std::cout << deltatime << std::endl;

    }

    return 0;
}

