#pragma once
#include "Location.h"
#include "World_Player_Interface.h"



class World : public World_Player_Interface
{
	int _location_quantity = 3;
	bool _is_world_already_exist = false;

public:
	std::vector <TreeLocation*> Location_list;

	// Это у меня солитон - экземпляр игры только один
	World(int location_quantity = 3): _location_quantity(location_quantity)	
	{
		if (_is_world_already_exist) throw std::exception("World already exist");
		_is_world_already_exist = true;
	}
	int Get_Location_Quantity() { return _location_quantity; }

	//int chooseLocation() override
	TreeLocation* chooseLocation() override
	{
		std::cout << "\nChoose location [0 - exit]\n";
		int choosen_location = Get_Int_Positive(0, Location_list.size(), " Location number out of range\n");
		if (!choosen_location) return nullptr;
		return Location_list[choosen_location-1];
	}
	void ShowInfo() override
	{
		std::cout << "\nWorld Info:\n\n";
		int i = 1;
		for (auto item : this->Location_list)
		{
			std::cout << "Location [" << i++ << "]\n";
			item->Info_categorized();
		}
	}
};

