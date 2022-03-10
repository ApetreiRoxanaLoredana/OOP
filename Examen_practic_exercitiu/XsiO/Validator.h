#pragma once
#include "MyException.h"
#include "Domain.h"
#include <string>
using std::string;

class Validator
{
public:
	Validator() {};

	void valideaza(const Joc& j) const;
};

