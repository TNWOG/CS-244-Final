// GemMine.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "GemMineGame.h"
#include "GemIdentifier.h"

using namespace std;


GemMineGame::GemMineGame()
{
	loadMine();
}


void GemMineGame::loadMine()
{
	//fixed instead of randomly generated to make easier to correct
	Gem* g1 = GemIdentifier::identifyGem("Diamond",10,10);
	mGemMine.loadMine("A7", g1);
	Gem* g2 = GemIdentifier::identifyGem("Diamond",2,8);
	mGemMine.loadMine("B3", g2);
	Gem* g3 = GemIdentifier::identifyGem("Diamond",4,7);
	mGemMine.loadMine("C1", g3);
	Gem* g4 = GemIdentifier::identifyGem("Diamond",1,9);
	mGemMine.loadMine("D5", g4);
	Gem* g5 = GemIdentifier::identifyGem("Diamond",1,5);
	mGemMine.loadMine("E9", g5);
	Gem* g6 = GemIdentifier::identifyGem("Diamond",1,10);
	mGemMine.loadMine("F1", g6);
	Gem* g7 = GemIdentifier::identifyGem("Diamond",1,10);
	mGemMine.loadMine("G3", g7);
	Gem* g8 = GemIdentifier::identifyGem("Sapphire",10,10);
	mGemMine.loadMine("A6", g8);
	Gem* g9 = GemIdentifier::identifyGem("Sapphire",2,8);
	mGemMine.loadMine("B2", g9);
	Gem* g10 = GemIdentifier::identifyGem("Sapphire",4,7);
	mGemMine.loadMine("C0", g10);
	Gem* g11 = GemIdentifier::identifyGem("Sapphire",1,9);
	mGemMine.loadMine("D4", g11);
	Gem* g12 = GemIdentifier::identifyGem("Sapphire",1,5);
	mGemMine.loadMine("E8", g12);
	Gem* g13 = GemIdentifier::identifyGem("Sapphire",1,10);
	mGemMine.loadMine("F2", g13);
	Gem* g14 = GemIdentifier::identifyGem("Sapphire",1,10);
	mGemMine.loadMine("G4", g14);
	Gem* g15 = GemIdentifier::identifyGem("Ruby", 10, 10);
	mGemMine.loadMine("H6", g15);
	Gem* g16 = GemIdentifier::identifyGem("Ruby", 2, 8);
	mGemMine.loadMine("I2", g16);
	Gem* g17 = GemIdentifier::identifyGem("Ruby", 4, 7);
	mGemMine.loadMine("J0", g17);
	Gem* g18 = GemIdentifier::identifyGem("Ruby", 1, 9);
	mGemMine.loadMine("H4", g18);
	Gem* g19 = GemIdentifier::identifyGem("Ruby", 1, 5);
	mGemMine.loadMine("I8", g19);
	Gem* g20 = GemIdentifier::identifyGem("Ruby", 1, 10);
	mGemMine.loadMine("J2", g20);

}

void GemMineGame::playerSetup() {
	cout << "How many players what to mine for Gems?" << endl;
	int nbrOfPlayers = 0;

	readFromStandardIOAndValidateInput<int>(nbrOfPlayers);
	while (nbrOfPlayers < 1 || nbrOfPlayers > 10) {
		cout << "There must be at least one player, but not more than 10.";
		cout << "How many players what to mine for Gems?" << endl;
		readFromStandardIOAndValidateInput<int>(nbrOfPlayers);
	}

	string playerName;
	for (int i = 1; i <= nbrOfPlayers; i++) {
		cout << "Enter the name of player #" << i << endl;
		readFromStandardIOAndValidateInput<string>(playerName);
		mPlayers.insert(make_pair(playerName, GemBag()));
	}
};

double GemMineGame::dig(unordered_map<string, GemBag>::iterator player) {
	cout << player->first << ", where do you want to dig?"<<endl;  
	cout<<"Enter a coordinate from A0 to J9" << endl;
	string inputCoordinates;
	readFromStandardIOAndValidateInput<string>(inputCoordinates);
	Gem* foundGem = mGemMine.dig(inputCoordinates);
	if (foundGem) {
		cout << "You found a ";
		foundGem->print();
		cout << endl;
		cout << "It has a value of " << foundGem->CalculateValue() << endl;
		player->second.putInBag(foundGem);
	}
	else {
		cout << "Sorry, you didn't find anything." << endl;
	}
	cout << endl << "You current have the following gems in your bag:" << endl;
	(player->second).print();

	double value = (player->second).CalculateTotal();
	cout << "You have a value of "<< value <<" gems in your bag." << endl << endl;
	return value;

}

pair<string, GemBag> GemMineGame::takeTurns() {

	cout << "Are you ready to dig for gems?" << endl;
	cout << "The first player to 500 wins!" << endl << endl;
	cout << "You are searching in a grid from A thru J and 0 thru 9." << endl;
	cout << "Choose your coordinate by typing in a letter followed by a number." << endl;
	cout << "  For example:  C2" << endl;
	cout << "(If you enter a coordinate outside the grid, you won't find anything.)" << endl;
	cout << endl<<endl;
	while (true) {
		for (unordered_map<string, GemBag>::iterator player = mPlayers.begin(); player != mPlayers.end(); ++player) {
			double gemBagValue = dig(player);
			if (gemBagValue >= 500.0) {
				//return the winner
				return *player;
			}
		}
	}
}


void GemMineGame::playGame()
{
	playerSetup();
	cout << endl;
	for (pair<string, GemBag> player : mPlayers) {
		cout << player.first << "! ";
	}

	pair<string, GemBag> winner = takeTurns();
	cout << "Congratulations " << winner.first << "!  You are the champion!" << std::endl;

}

