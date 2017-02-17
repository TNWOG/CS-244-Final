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
// GemIdentifier.h
//
// GemIdentifier take a type of gem and returns an instance of that gem
//
// Instructor: Jocelyn Richardt
// Assignment: Gem Mine Game
// Author: Jocelyn Richardt
// Date: 12/5/2016
//
// ---------------------------------------------------------------------------
#ifndef GEM_IDENTIFIER_H
#define GEM_IDENTIFIER_H

#include <string>

#include "Gem.h"
#include "Diamond.h"
#include "Ruby.h"
#include "Sapphire.h"


class GemIdentifier
{
public:
	
	static const string DIAMOND;
	static const string SAPPHIRE;
	static const string RUBY;

private:
	//do not allow GemIdentifier's to be constructed
	GemIdentifier() {};

public:
	~GemIdentifier() {};

public:
	static Gem* identifyGem(string gemType, int nbrOfCarats, int clarityRating) 
	{
		if (gemType == DIAMOND)	return new Diamond(DIAMOND, nbrOfCarats, clarityRating);
		else if (gemType == RUBY) return new Ruby(RUBY, nbrOfCarats, clarityRating);
		else if (gemType == SAPPHIRE) return new Sapphire(SAPPHIRE, nbrOfCarats, clarityRating);

		return NULL;
	};

};


const string GemIdentifier::DIAMOND = "Diamond";
const string GemIdentifier::SAPPHIRE = "Sapphire";
const string GemIdentifier::RUBY = "Ruby";

#endif
