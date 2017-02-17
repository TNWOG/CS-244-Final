
// ---------------------------------------------------------------------------
//    
//                   University of Wisconsin-Stout
//            Mathematics, Statistics & Computer Science
//                 CS-244 Data Structures - Fall 2016
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2016
//
// Sapphire.h
//
// Header and Implementation for Sapphire class
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "Gem.h"
#include "stdafx.h"

#ifndef SAPPHIRE_H
#define SAPPHIRE_H
class Sapphire
	: public Gem {
public:
	//polymorpically creates sapphire object using parent's data
	Sapphire(std::string gemType, int nbrOfCarats, int clarityRating) : Gem(gemType, nbrOfCarats, clarityRating){};
	~Sapphire();
	//returns multiplier
	int GetMultiplier() 
	{
		return SAPPHIRE_VALUE_MULTIPLIER;
	}
private:
	//sapphire multiplier
	const int SAPPHIRE_VALUE_MULTIPLIER = 25;
};
#endif