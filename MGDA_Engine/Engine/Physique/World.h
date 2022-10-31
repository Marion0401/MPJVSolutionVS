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

	// Générer les forces sur les particules
	// Effectue la tâche d'intégration sur chacunes des particules
	// Détecter et gérer les collisions
	void runPhysics(float duration);

};
#endif