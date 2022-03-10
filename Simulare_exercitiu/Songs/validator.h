#pragma once
#include <string>
#include "domain.h"
using std::string;

class Validator
{
public:
	Validator() {};

	void valideaza(const Melodie& mel) const;
};

