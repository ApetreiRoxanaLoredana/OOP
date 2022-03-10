#include "observer.h"

void Observable::notify()
{
	for (auto obs : interesati)
		obs->update();
}

void Observable::add_observer(Observer* ob)
{
	interesati.push_back(ob);
}

void Observable::remove_observer(Observer* ob)
{
	interesati.erase(std::remove(interesati.begin(), interesati.end(), ob), interesati.end());
}
