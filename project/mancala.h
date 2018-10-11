/****************************************************************
	Joseph Ricker	CS 2401   Spring 2018
	Project 6 Phase 3

	This is the header file for the mancala class. For this
	phase, all functions are implemented
****************************************************************/

#ifndef MANCALA_H
#define	MANCALA_H

#include "game.h"
#include "colors.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

using namespace main_savitch_14;
using namespace std;

class Mancala: public game{
	public:
		Mancala();
		void display_status( ) const;
		bool is_legal(const std::string& move) const;
		void make_move(const std::string& move);
		void restart( );
		bool is_game_over( ) const;
		who winning( ) const;
		game* clone( ) const;
		void compute_moves(std::queue<std::string>& moves) const;
		int evaluate( ) const;

    	
	private:
		int board[14];
};

#endif
