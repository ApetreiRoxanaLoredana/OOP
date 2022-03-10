#pragma once
#include <vector>
using std::vector;

class Observer
{
public:
	virtual void update() = 0;
};

class Observable {
private:
	vector<Observer*> interesati;

protected:
	void notify() {
		for (auto obs : interesati)
			obs->update();
	}

public:

	void add_observer(Observer* ob) {
		interesati.push_back(ob);
	}

	void remove_observer(Observer* ob) {
		interesati.erase(std::remove(interesati.begin(), interesati.end(), ob), interesati.end());
	}
};

