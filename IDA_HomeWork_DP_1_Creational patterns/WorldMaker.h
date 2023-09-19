#pragma once
#include "World.h"


enum class WorldMaker_Strategies { AppleOnly, PearOnly, tundra, end_of_enum };


class WorldMaker
{
	WorldMaker_Strategies _strategy;
	WorldMaker* _current_world_maker = nullptr;
public:

	virtual ~WorldMaker() = default;	
	
	//////////////////////////////////////////////////////////////
	/// Все что ниже - не работает!!! Оставил здесь как памятник потраченному времени
	//////////////////////////////////////////////////////////////

	// Выбрал вот такой вариант полиморфной обработки разных стратегий через наследников WorldMaker
	// Получается для добавления новой стратегии надо:
		// 1) Создать новый класс-наследник от WorldMaker
		// 2) Возможно добавить еще конструктор в TreeLoaction, если существующие не смогут удовлетворить специфику новой статегии создания локации
		// 3) Внести запись в enum class WorldMaker_Strategies
		// 4) Внести запись в switch по обработке стратегии в WorldMaker::SetStrategy

	/*void SetStrategy(WorldMaker_Strategies current_strategy)
	{
		_strategy = current_strategy;
		switch (_strategy)
		{
		//case WorldMaker_Strategies::AppleOnly: _current_world_maker = new WorldMaker_AppleOnly; break;
		case WorldMaker_Strategies::AppleOnly: _current_world_maker = dynamic_cast<WorldMaker*>(new WorldMaker_AppleOnly); break;
		case WorldMaker_Strategies::PearOnly: _current_world_maker = new WorldMaker_Pear_and_Raspberry; break;
		case WorldMaker_Strategies::tundra: _current_world_maker = new WorldMaker_tundra; break;
		}
	}*/

	/* Альтернативный вариант работы с полиформизмом через указатели на наследников, 
	// но в вызывающем методе придется использовать конструкцию типа
	// WorldMaker* world_maker = world_maker->SetStrategy(new_strategie);
	// что как-то тяжеловато выглядит
	WorldMaker* SetStrategy(WorldMaker_Strategies current_strategy, WorldMaker*& world_maker)
	{
		_strategy = current_strategy;
		switch (_strategy)
		{
			case WorldMaker_Strategies::AppleOnly: world_maker = new WorldMaker_AppleOnly; break;
			case WorldMaker_Strategies::PearOnly: world_maker = new WorldMaker_Pear_and_Raspberry; break;
			case WorldMaker_Strategies::tundra: world_maker = new WorldMaker_tundra; break;
		}
	}//*/

	//virtual World* makeWorld() = 0;

	virtual World* makeWorld()
	{
		return _current_world_maker->makeWorld();
	}



};

