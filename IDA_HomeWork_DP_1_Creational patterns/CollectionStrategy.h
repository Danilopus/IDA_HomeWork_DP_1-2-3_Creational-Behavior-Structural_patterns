#pragma once
#include <string>

enum class CollectionStrategy_Types {Apple, Pear, end_of_enum};

class CollectionStrategy
{

public:
	virtual ~CollectionStrategy() = default;

	/*static CollectionStrategy* SetStrategy(CollectionStrategy_Types current_strategy)
	{		
		switch (current_strategy)
		{
		case CollectionStrategy_Types::Apple: return new CollectionStrategy_Apple;
		case CollectionStrategy_Types::Pear: return new CollectionStrategy_Pear;
		}
	}*/

	virtual std::string UseStrategy() = 0;
	
};

