/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "Subject.h"



Subject::Subject()
{}


Subject::~Subject()
{
	for (vector<Observer*>::iterator currentObserver = listObservers.begin();
	currentObserver != listObservers.end(); ++currentObserver) {
		delete (*currentObserver);
		(*currentObserver) = nullptr;
	}
}
