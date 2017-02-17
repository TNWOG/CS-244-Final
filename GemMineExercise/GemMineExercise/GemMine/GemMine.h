
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
// GemMine.h
//
// Header for GemMine container class
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "Gem.h"
#include <unordered_map>


#ifndef GEMMINE_H
#define GEMMINE_H
class GemMine {
public:
	GemMine();
	//~GemMine();
	//inserts gem into mine
	void loadMine(std::string coord, Gem* gem);
	//returns gem at coordinate
	Gem* dig(std::string coord);

private:
	//container of gems and string key
	std::unordered_map<std::string, Gem*> mMineGrid;

};
#endif