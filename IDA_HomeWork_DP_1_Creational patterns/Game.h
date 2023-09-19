#pragma once
//#include "WorldMaker.h"
#include "WorldMaker_AppleOnly.h"
#include "WorldMaker_Pear_and_Raspberry.h"
#include "WorldMaker_tundra.h"
#include "Player.h"


class Game
{
	World* _game_world = nullptr;
	Player* _player = nullptr;
	bool _is_game_already_exist = false;
	// Вот здесь я считаю реализован паттерн типа Абстрактной фабрики
	void makeWorld()
	{
		WorldMaker* world_maker = nullptr;

		// точка управления стратегиями создания миров

		//////// Пытался спрятать это блок в классе WorldMaker - но возникали перекрестные include

		WorldMaker_Strategies new_strategie = static_cast<WorldMaker_Strategies>(Get_Random(0, int(WorldMaker_Strategies::end_of_enum)));
					
			switch (new_strategie)
			{
			case WorldMaker_Strategies::AppleOnly: world_maker = dynamic_cast<WorldMaker*>(new WorldMaker_AppleOnly); break;
			case WorldMaker_Strategies::PearOnly: world_maker = new WorldMaker_Pear_and_Raspberry; break;
			case WorldMaker_Strategies::tundra: world_maker = new WorldMaker_tundra; break;
			}

		// установка стратегии внутри world_maker приводит к созданию полиморфного указателя 
		// на соотвтетсвующего стратегии наслденика WorldMaker
		//world_maker->SetStrategy(new_strategie);
		//////////////////////////

		_game_world = world_maker->makeWorld();
	}
	void makePlayer()
	{
		_player = new Player("Player_One");
		_player->SetBackPack();
	}

	void GetStarted()
	{
		std::cout << "\nGame: FruitHarvester\n\n";
		std::cout << "Goal:\n1) Harvest fruits from trees\n2) Sell fruits (comming)\n";
		_getch();
		User_Actions_Handle();
	}
	void User_Actions_Handle()
	{
		do
		{
			system("cls");
			std::cout << "\n\nActions available:\n1) Get 1 fruit\n2)Get N-amount of fruits with strategy: finding Apple\n3)Check BackPack\naction: ";
			switch (Get_Int_Positive(1, 3, "error"))
			{
			case 1: Collect_1_fruit(); break;
			case 2: Collect_N_fruit(); break;
			case 3: Check_BackPack(); break;
			}

			std::cout << "\n\nEsc - exit | any key to continue";
		} while (_getch() != 27);

	}
	void Check_BackPack()
	{
		_player->GetBackPack()->Info();
	}
	void Collect_1_fruit()
	{
		Location_Player_Interface* choosen_location = nullptr;
		while (true)
		{
			_game_world->ShowInfo();
			choosen_location = _game_world->chooseLocation();
			if (choosen_location)  choosen_location->ShowTrees();
			else break;

			while (true)
			{
				int choosen_tree = choosen_location->chooseTree();
				if (choosen_tree) 
					choosen_location->Get_fruit(choosen_tree - 1, _player->GetBackPack());
				else 
					break;
			}

		}
	}
	void Collect_N_fruit()
	{
		std::cout << "\nfruits_to_collect -> ";
		int fruits_to_collect = Get_Int_Positive(1, 1e3, " too much ");
		Location_Player_Interface* choosen_location = nullptr;
		while (true)
		{
			_game_world->ShowInfo();
			choosen_location = _game_world->chooseLocation();
			if (choosen_location) 
			_player->CollectFruit(CollectionStrategy_Types::Apple, dynamic_cast<TreeLocation*>(choosen_location), fruits_to_collect);
			else 
				break;		
		}
	}	

public:
	// А это у меня солитон - экземпляр игры только один
	Game()
	{
		if (_is_game_already_exist) throw std::exception("Game already exist");
		_is_game_already_exist = true;
	}

	void Initialize()
	{
		makeWorld();
		makePlayer();
		GetStarted();
	}






};

