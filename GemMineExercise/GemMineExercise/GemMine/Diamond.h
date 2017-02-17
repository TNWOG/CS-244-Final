
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
// Diamond.h
//
// Header and Implementation for Diamond class
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "Gem.h"
#include "stdafx.h"

#ifndef DIAMOND_H
#define DIAMOND_H
class Diamond
	: public Gem {
public:
	//polymorpically creates object based on parent
	Diamond(std::string gemType, int nbrOfCarats, int clarityRating) : Gem(gemType, nbrOfCarats, clarityRating) {};
	~Diamond();
	//returns multiplier
	int GetMultiplier()
	{
		return DIAMOND_VALUE_MULTIPLIER;
	}

private:
	//multiplier of object
	const int DIAMOND_VALUE_MULTIPLIER = 100;
};
#endif