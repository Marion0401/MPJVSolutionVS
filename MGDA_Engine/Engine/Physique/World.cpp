#include "World.h"

void World::addBlob(Disc blob) 
{
	blobList.push_back(blob);
}

void World::removeBlob(Disc blob)
{
	std::vector<Disc>::iterator iter;
	int count = 0;

	// use iterator with for loop
	for (iter = blobList.begin(); iter != blobList.end(); ++count) {
		if (blobList.at(count) == blob)
		{
			blobList.erase(blobList.begin() + count);
		}
	}
}

void World::clearWorld()
{
	blobList.clear();
}

void World::runPhysics(float duration)
{

	std::vector<Disc>::iterator iter, iter2;
	int count = 0, count2 = 0;

	for (iter = blobList.begin(); iter != blobList.end(); ++count) {

		Disc blobActuel = blobList.at(count);
	
		// Générer les forces sur les particules
		// Effectue la tâche d'intégration sur chacunes des particules
		blobActuel.update(duration);

		// Détecter et gérer les collisions
		for (iter2 = blobList.begin(); iter2 != blobList.end(); ++count2) {
			Disc blobNext = blobList.at(count2);

			if (!(blobActuel == blobNext))
			{
				if (blobActuel.intersects(blobNext))
				{
					//add collision
					Collision c = Collision(blobActuel, blobNext, 0);
					blobActuel.addCollision(c);
					blobNext.addCollision(c);

					//resolve collision
					c.resolveCollision();
				}
			}
		}

	}

}