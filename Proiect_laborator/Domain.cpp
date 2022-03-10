#include "Domain.h"
#include <exception>

int Apartament::get_apartament() const noexcept
{
	return apartament;
}

string Apartament::get_nume() const
{
	return nume_proprietar;
}

double Apartament::get_suprafata() const noexcept
{
	return suprafata;
}

string Apartament::get_tip() const
{
	return tip;
}

void Apartament::set_apartament(const int other) noexcept
{
	apartament = other;
}

void Apartament::set_nume(const string other)
{
	nume_proprietar = other;
}

void Apartament::set_suprafata(const double other) noexcept
{
	suprafata = other;
}

void Apartament::set_tip(const string other)
{
	tip = other;
}

void Apartament::print_apartament() const
{
	std::cout << apartament << ": " << nume_proprietar << ", " << suprafata << ", " << tip << '\n';
}

bool Apartament::operator==(const Apartament& a1) const noexcept
{
	return a1.get_apartament() == apartament;
}

bool Apartament::operator!=(const Apartament& a) const noexcept
{
	return a.get_apartament() != apartament;
}

Apartament& Apartament::operator=(const Apartament& ot)
{
	this->apartament = ot.apartament;
	this->nume_proprietar = ot.nume_proprietar;
	this->suprafata = ot.suprafata;
	this->tip = ot.tip;
	return *this;
}

