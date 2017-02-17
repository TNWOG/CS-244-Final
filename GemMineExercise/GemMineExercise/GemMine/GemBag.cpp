
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
// GemBag.cpp
//
// Implementation for GemBag container
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "stdafx.h"
#include "GemBag.h"

double GemBag::mCurrentTotal = 0;

GemBag::GemBag() 
{
	mCurrentTotal = 0;
}

double GemBag::CalculateTotal() 
{
	mCurrentTotal = 0;
	//uses AVLTree method to inorder traverse the tree and apply the sum method to each object
	mBag.functionTraverse(sum);
	//returns value of total after traversal
	return mCurrentTotal;
}
void GemBag::putInBag(Gem* gem)
{
	//inserts object into bag
	mBag.insert(gem);
}
void GemBag::sum(Gem* e)
{
	//increases total by value of gem
	mCurrentTotal += e->CalculateValue();
}