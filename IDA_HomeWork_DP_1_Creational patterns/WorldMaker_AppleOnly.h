#pragma once
#include "WorldMaker.h"

//extern class WorldMaker;

class WorldMaker_AppleOnly :  public WorldMaker 
{
public:
	WorldMaker_AppleOnly() = default;
    World* makeWorld() override
	{
        World* new_world = new World;

		// Определяем параметры создания конкретного мира: мир из new_world->Get_Location_Quantity() локаций, состоящих только из AppleTree
		
		// универсальный интерфейс для передачи списка вида деревьев, которые должны быть на локациях
		// В данном случае только один вид: AppleTree
		MotherPlant::treeTypes type_1 = MotherPlant::treeTypes::AppleTree;
		std::vector<MotherPlant::treeTypes> trees_list{ type_1 };
		
		for (int i = 0; i < new_world->Get_Location_Quantity(); i++)
			new_world->Location_list.push_back(new TreeLocation(trees_list));

		return new_world;
    }
};

