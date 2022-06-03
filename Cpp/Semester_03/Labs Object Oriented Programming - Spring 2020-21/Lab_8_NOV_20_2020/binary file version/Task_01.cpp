/*

Construct a class Player which contains the player name, player number, number of matches, highest scores of all
matches, no of 100s, no of 50s. Implement the following functionalities:
 A parametrized constructor that initialize all the data members
 Stream Insertion operator for player class <<

Construct another class Team that contains 11 players and team’s total scores and wickets. Implement the
following functionalities in it:
 readPlayers function to read the data of all the players and assign them accordingly
 Highest Scorer will return the Player having height scores
 Most 100s returns the player with most 100s if two players have same highest 100s than compare 50s
Construct a class MATCH having any no of teams greater than five
 Compare among the teams having highest scores and least wicket and call it winner
Instructions about file handling(Choose any Name of the file):
 You will store updated array into file in binary form at the time of program’s termination and at the start
of the program you need to read data from file in binary form and updates array.
Perform This task with both weak/strong aggregations.

*/
#include <iostream>
#include <iomanip>
#include <string.h>


using namespace std;

class Player{
	char Playername[20];
	int numberofmathches,scoremax,centuries,fifties,playernumber;
public:
	Player(char Playername[]="",int numberofmathches=0,int scoremax=0,int centuries=0,int fifties=0,int playernumber=0){
		strcpy(this->Playername, Playername);
		this->numberofmathches = numberofmathches;
		this->scoremax = scoremax;
		this->centuries = centuries;
		this->playernumber = playernumber;
	}
	
    friend ostream& operator << (ostream &out, const Player &s);
    friend class Team;

};
ostream& operator << (ostream &out, const Player &s){
	out << "Player Number: "<<s.playernumber<<'\n';
    out << "Player Name: "<<s.Playername<<'\n';
    out << "Higest Score: "<<s.scoremax<<'\n';
    out << "Number of Matches: "<<s.numberofmathches<<'\n';
    out << "Number of Centuries: "<<s.centuries<<'\n';
    out << "Number of Fifties: "<<s.fifties<<"\n\n";
	return out;
}
