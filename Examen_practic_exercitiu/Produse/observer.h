#pragma once
#include <vector>
using std::vector;

class Observer
{
public:
	virtual void update() = 0;
};

class Observable 
{
private:
	vector<Observer*> interesati;
protected:
	void notify();
public:
	void add_observer(Observer* ob);
	void remove_observer(Observer* ob);
};

