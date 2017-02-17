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
// GemMineGame.h
//
// GemMineGame is the driver to play the game.
//
// Instructor: Jocelyn Richardt
// Assignment: Gem Mine Game
// Author: Jocelyn Richardt
// Date: 12/5/2016
//
// ---------------------------------------------------------------------------
#ifndef GEM_MINE_GAME_H
#define GEM_MINE_GAME_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <utility>

#include "stdafx.h"
#include "GemMine.h"
#include "GemBag.h"

using namespace std;

class GemMineGame {

public:
	GemMineGame();
	~GemMineGame() {};

	void playGame();

private:
	GemMine mGemMine;
	unordered_map<string, GemBag> mPlayers;


	//helper methods
	template <class TYPE>
	bool readFromStandardIOAndValidateInput(TYPE& input);

	void loadMine();
	void playerSetup();
	pair<string, GemBag> takeTurns();
	double dig(unordered_map<string, GemBag>::iterator player);
		

};


template <class TYPE>
bool GemMineGame::readFromStandardIOAndValidateInput(TYPE& input) {
	//executes loop if the input fails (e.g., no characters were read)
	int maxInvalidInput = 5;
	while (!(std::cin >> input) && maxInvalidInput) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input; please re-enter.\n";
		maxInvalidInput--;
	}
	if (maxInvalidInput == 0) {
		std::cout << "Please learn your numbers from your letters and try again later.\n";
		exit(0);
	}
	return true;
};
#endif
