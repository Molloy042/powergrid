/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#pragma once
#include <iostream>
#include "Observer.h"
#include <vector>
#include <algorithm>

using std::vector;

class Subject
{
	vector <Observer*> listObservers;
public:
	inline void	attach(Observer *newObserver)
	{
		listObservers.push_back(newObserver);
	}
	inline void detach(Observer *existingObserver)
	{
		listObservers.erase(std::remove(listObservers.begin(), listObservers.end(), existingObserver), listObservers.end());
	}
	inline void notify()
	{
		for (vector<Observer*>::const_iterator currentObserver = listObservers.begin();
		currentObserver != listObservers.end(); ++currentObserver) {
			(*currentObserver)->update();
		}
	}

	Subject();
	~Subject();
};

	