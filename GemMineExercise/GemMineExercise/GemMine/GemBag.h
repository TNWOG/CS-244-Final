
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
// GemBag.h
//
// Header for GemBag container of Gem objects
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "AVLPointerTree.h"
#include "Gem.h"

#ifndef GEMBAG_H
#define GEMBAG_H
class GemBag {
public:
	GemBag();
	//~GemBag();
	//calculates total value of the bag
	double CalculateTotal();
	//inserts gem into bag
	void putInBag(Gem* gem);
	//prints entire bag
	void print() { mBag.inorderTraversal(); };
private:
	//helper function for calculating total for bag
	static void sum(Gem* gem);
	//number calculating total of bag
	static double mCurrentTotal;
	//tree containing gems
	AVLPointerTree<Gem*> mBag;
};
#endif