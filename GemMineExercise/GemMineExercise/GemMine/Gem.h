
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
// Gem.h
//
// Header and Implementation for Gem class
//
// Instructor: Jocelyn Richardt
// Assignment: GemMine
// Author: Ryan Vanden Boomen
// Date: 12/12/16
//
// ---------------------------------------------------------------------------

#include "stdafx.h"
#include <string>
#include <iostream>

#ifndef GEM_H
#define GEM_H
class Gem {
public:
	//initializes object using necessary data element
	Gem(std::string gemType, int nbrOfCarats, int clarityRating) :mGemType(gemType), mNbrOfCarats(nbrOfCarats), mClarityRating(clarityRating) {};
	~Gem();
	//calculates value of gem object
	inline double CalculateValue()
	{
		return mNbrOfCarats*GetMultiplier()*(0.1*mClarityRating);
	};
	//polymorpically returns multiplier of object
	virtual int GetMultiplier() = 0;
	//prints object according to data members
	void print()
	{
		std::cout << mGemType << ": Carats :" << mNbrOfCarats << " Clarity: " << mClarityRating << std::endl;
	};
	//overrides out operator
	friend std::ostream& operator<<(std::ostream& out, const Gem* gem)
	{
		out << gem->mGemType << ": Carats :" << gem->mNbrOfCarats << " Clarity: " << gem->mClarityRating << std::endl;
		return out;
	};
	//overrides comparison operators to compare based on value of object
	friend bool Gem::operator==(Gem& a, Gem& b)
	{
		if (a.CalculateValue() == b.CalculateValue())
		{
			return true;
		}
		return false;
	}
	friend bool Gem::operator>(Gem& a, Gem& b)
	{
		if (a.CalculateValue() > b.CalculateValue())
		{
			return true;
		}
		return false;
	}
	friend bool Gem::operator>=(Gem& a, Gem& b)
	{
		if (a.CalculateValue() >= b.CalculateValue())
		{
			return true;
		}
		return false;
	}
	friend bool Gem::operator<=(Gem& a, Gem& b)
	{
		if (a.CalculateValue() <= b.CalculateValue())
		{
			return true;
		}
		return false;
	}
private:
	//basic data members of object
	std::string mGemType;
	int mNbrOfCarats;
	int mClarityRating;
};
#endif