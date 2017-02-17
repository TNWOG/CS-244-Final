
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
// Ruby.h
//
// Header and Implementation for Ruby class
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "Gem.h"
#include "stdafx.h"

#ifndef RUBY_H
#define RUBY_H
class Ruby
	: public Gem {
public:
	//polymorpically creates ruby object using parent's data
	Ruby(std::string gemType, int nbrOfCarats, int clarityRating) : Gem(gemType, nbrOfCarats, clarityRating) {};
	~Ruby();
	//returns multiplier
	int GetMultiplier()
	{
		return RUBY_VALUE_MULTIPLIER;
	}
private:
	//multiplier of ruby
	const int RUBY_VALUE_MULTIPLIER = 50;
};
#endif