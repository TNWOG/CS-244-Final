
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
// GemMine.cpp
//
// Implementation for GemMine container
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "stdafx.h"
#include "GemMine.h"

GemMine::GemMine()
{

}

void GemMine::loadMine(std::string coord, Gem* gem)
{
	//inserts gem and key into grid map
	mMineGrid.insert({ coord, gem });
}

Gem* GemMine::dig(std::string coord)
{
	//if the object exists
	if (mMineGrid[coord])
	{
		//return object
		return mMineGrid[coord];
	}
	return NULL;
}