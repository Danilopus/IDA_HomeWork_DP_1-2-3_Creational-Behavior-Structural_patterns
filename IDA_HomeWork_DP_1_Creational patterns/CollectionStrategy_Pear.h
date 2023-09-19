#pragma once
#include "CollectionStrategy.h"

class CollectionStrategy_Pear   : public CollectionStrategy
{
public:

	std::string UseStrategy() override
	{
		return "PearTree";
	}
};

