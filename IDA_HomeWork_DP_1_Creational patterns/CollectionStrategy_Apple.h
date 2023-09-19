#pragma once
#include "CollectionStrategy.h"


class CollectionStrategy_Apple :    public CollectionStrategy
{
public:

	std::string UseStrategy() override
	{
		return "AppleTree";
	}

};

