#pragma once
#include "Location.h"

class World_Player_Interface
{
public:
	virtual ~World_Player_Interface() = default;

	virtual TreeLocation* chooseLocation() = 0;
	virtual void ShowInfo() = 0;
};

