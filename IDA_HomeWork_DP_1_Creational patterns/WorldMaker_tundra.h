#pragma once
#include "WorldMaker.h"

class WorldMaker_tundra :  public WorldMaker
{
	World* makeWorld()
	{
		World* new_world = new World; 

		// Определяем параметры создания конкретного мира: мир из new_world->Get_Location_Quantity() локаций, 
		// состоящих только из деревьев plant_size = smalll
		MotherPlant::plant_size plant_size = MotherPlant::plant_size::smalll;

		for (int i = 0; i < new_world->Get_Location_Quantity(); i++)
			new_world->Location_list.push_back(new TreeLocation(plant_size));

		return new_world;
	}
};

