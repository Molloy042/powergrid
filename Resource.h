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
#include "Utility.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

class Resource
{
public:
	//CONSTRUCTORS
	Resource(void);

	//DESTRUCTORS
	~Resource(void);

	//GETTERS
	virtual ResourceType getResourceType() = 0;
protected:
	ResourceType resourceType;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & boostArchive, const unsigned int version)
	{
		boostArchive & resourceType;
	}

	
};

