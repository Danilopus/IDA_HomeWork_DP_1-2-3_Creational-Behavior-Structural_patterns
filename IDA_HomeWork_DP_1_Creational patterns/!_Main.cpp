// HomeWork template project v 6.0 // 27.06.2023 //

/*

Паттерны проектирования - Порождающие паттерны

Задание

Для реализованных семейств классов Растений/Плодов/Локаций/Рюкзаков 
реализовать генерацию новых объектов с помощью порождающих паттернов:

абстрактная фабрика (abstract factory);
строитель (builder);
фабричный метод (factory method);
ленивая инициализация (lazy initialization);
объектный пул (object pool);
прототип (prototype);
одиночка (singleton);
пул одиночек (Multiton).

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
//#include "Location.h"
//#include "BackPack.h"
#include "Game.h"



// Homework DP 1 ----------------------------------------------------	


//Task 1 TheGame with DesignPatterns
void Task_1(std::string name_of_task)
{	
	Game new_game;
	new_game.Initialize();
	
	
	/*do
	{		
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";					
	
		

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);*/
}

//Task 2 BackPack
void Task_2(std::string name_of_task)

{
	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
				
		BackPack main_back_pack;
		
		//Создадим несколько деревьев, чтобы собрать с них фрукты в рюкзак
		std::vector<MotherPlant*> trees_vec = { new AppleTree(2, Color::white, 50), new Raspberry_bush(1, Color::green, 70), new PearTree(2, Color::brown, 30) };
		
		//соберем в рюкзак по 5 разных фруктов
		std::cout << "\n\n--- Harvesting 5 Apples, 5 Pears, 5 Raspberrys:\n";
		for ( int tree = trees_vec.size(); tree; --tree)
			for (int i = 0; i < 5; ++i)		
				main_back_pack.AddItem(trees_vec[tree-1]->Get_fruit());
						
		// Еще есть такой вариант метода положить в рюкзак
		Fruit& new_fruit = *new Apple(0.2, Color::green);
		main_back_pack << new_fruit;

		std::cout << "\n\n--- ShortInfo():\n";
		main_back_pack.ShortInfo();
		//Перебор элементов Способ 1 []
		std::cout << "\n\n--- iterating through the elements []:\n";
		for (int i = 0; i < main_back_pack.size(); ++i)
		{
			//std::cout << "\nItem " << i + 1;
			//main_back_pack[i]->Info();
			std::cout << i + 1 <<":" << main_back_pack[i]->Get_name() <<" | ";
		}

		// удаление 1-го элемента
		std::cout << "\n\n\n--- DeleteItem(1):\n";
		main_back_pack.DeleteItem(1); 
		
		std::cout << "\n\n--- ShortInfo():\n";
		main_back_pack.ShortInfo();
		//Перебор элементов Способ 2 at()
		std::cout << "\n\n--- iterating through the at():\n";
		for (int i = 0; i < main_back_pack.size(); ++i)
		{
			//std::cout << "\nItem " << i + 1;
			//main_back_pack.at(i).Info();
			std::cout << i + 1 << ":" << main_back_pack.at(i).Get_name() << " | ";

		}
				
		// удаление элементов в диапазоне
		std::cout << "\n\n\n--- DeleteItem(3,5):\n";
		main_back_pack.DeleteItem(3,5); 
		
		std::cout << "\n\n--- ShortInfo():\n";
		main_back_pack.ShortInfo();
		//Перебор элементов Способ 3 iterator
		std::cout << "\n\n--- iterating through the iterator:\n";
		int i=0;
		for (auto iter : main_back_pack)			
			std::cout << ++i << ":" << iter.Get_name() << " | ";


		//Удаление всех плодов одного типа
		std::cout << "\n\n\n--- Delete all Apples:\n";
		main_back_pack.DeleteItem(Fruit::fruitTypes::Apple);

		std::cout << "\n\n--- ShortInfo():\n";
		main_back_pack.ShortInfo();



		std::cout << "\n\n\nGet ready to watch full BackPack info:";
		_getch();
		main_back_pack.Info();

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("Design Patterns. Home Work 1: Creational patterns in My_Game_App (Plant, Fruit, BackPack, Loacation class world)");	// Homework name
	MainMenu.AddElement("Game: FruitHarvester (include AbstractFabric, Strategy design patterns");

	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

