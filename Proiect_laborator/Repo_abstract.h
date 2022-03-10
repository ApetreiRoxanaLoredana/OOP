#pragma once
#include "Domain.h"
#include <vector>


class Repo_abs
{
public:


	virtual ~Repo_abs() = default;

	virtual int get_dim() const = 0;

	virtual void add(const Apartament& a) = 0;

	virtual const std::vector<Apartament>& get_list() = 0;

	virtual void update(const Apartament& a) = 0;

	virtual void remove(const Apartament& a) = 0;

	virtual const Apartament search(const Apartament& a) const = 0;


};

