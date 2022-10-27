#pragma once
#include <GLFW/glfw3.h>
#include "./Projectile.h"

class GameEnvironment
{
	public:

		bool isShot;
		Projectile projCurrent;

		GameEnvironment();

};

