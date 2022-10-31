#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "../Objects/Disc.h"

class World {

protected:
	std::vector<Disc> blobList;

public:

	void addBlob(Disc blob);
	void removeBlob(Disc blob);
	void clearWorld();

	// G�n�rer les forces sur les particules
	// Effectue la t�che d'int�gration sur chacunes des particules
	// D�tecter et g�rer les collisions
	void runPhysics(float duration);

};
#endif