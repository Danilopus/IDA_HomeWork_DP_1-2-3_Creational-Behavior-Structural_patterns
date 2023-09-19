#pragma once
#include "BackPack.h"
//#include "CollectionStrategy.h"
//#include <conio.h>
#include "CollectionStrategy_Apple.h"
#include "CollectionStrategy_Pear.h"

class Player
{
	std::string _name;
	BackPack_Player_Interface* _back_pack;
	double _gold = 0;

public:
	Player(std::string name) : _name(name) {}
	void SetBackPack()
	{
		_back_pack = new BackPack;
	}
	BackPack_Player_Interface* GetBackPack() { return _back_pack; }
	
	void CollectFruit(CollectionStrategy_Types current_strategy, TreeLocation* current_location, int fruits_to_collect)
	{
		
		//CollectionStrategy* current_collection_strategy = CollectionStrategy::SetStrategy(current_strategy);

		//// Пытлася спрятать это блок в классе CollectionStrategy - но возникали перекрестные include
		CollectionStrategy* current_collection_strategy = nullptr;
		switch (current_strategy)
			{
		case CollectionStrategy_Types::Apple: current_collection_strategy = new CollectionStrategy_Apple; break;
		case CollectionStrategy_Types::Pear: current_collection_strategy = new CollectionStrategy_Pear; break;
			}		
		///////////////////////////////////////


		int fruits_collected = 0;

		// Алгоритм сбора плодов в соответствии со стратегией. Стратегия при использовании метода UseStrategy возращает строку
		// для поиска определенного типа деревьев для сбора определенного вида плодов
		for (int tree_index = 0; tree_index < current_location->size(); tree_index++)
			{
				if ((current_location->Get_plants_list())[tree_index]->Get_Name() == current_collection_strategy->UseStrategy())
				{
					while (current_location->Get_plants_list()[tree_index]->Get_fruits_remain()&&fruits_collected < fruits_to_collect)
						{
							current_location->Get_fruit(tree_index, _back_pack);
							fruits_collected++;
						}
					if (fruits_collected >= fruits_to_collect) return;						
				}
			}
		std::cout << "\nNot enough " << current_collection_strategy->UseStrategy() << " fruits on this Location\nTry another\n\n";
		_getch();

	}
};

