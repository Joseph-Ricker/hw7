/**************************************************************
	Joseph Ricker	CS 2401   Spring 2018
	Project 6
	
	This the implementation file for the mancala class
	functions
**************************************************************/

#include "mancala.h"

#include <string>

using namespace std;
using namespace main_savitch_14;

Mancala::Mancala(){
	board[0] = 0; // computer mancala

	board[1] = 4;
	board[2] = 4;
	board[3] = 4;
	board[4] = 4;
	board[5] = 4;
	board[6] = 4;
	
	// human's bins

	board[7] = 0; // human mancala

	board[8] = 4;
	board[9] = 4;
	board[10] = 4;
	board[11] = 4;
	board[12] = 4;
	board[13] = 4;

	// computer's bins

}

void Mancala:: display_status( ) const{
	cout << B_YELLOW << setfill(' ') << setw(121) << ' ' << B_WHITE << endl;
	cout << B_YELLOW << setfill(' ') << setw(121) << ' ' << B_WHITE << endl;
	cout << B_YELLOW << setfill(' ') << setw(121) << ' ' << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "                                                         Player 2                                                        " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "                     CUP 13         CUP 12         CUP 11         CUP 10         CUP 9          CUP 8                    " << B_WHITE << endl;  
	cout << B_YELLOW << BLACK << "     *******        *******        *******        *******        *******        *******        *******        *******    " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "   **       **    **       **    **       **    **       **    **       **    **       **    **       **    **       **  " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **  **         **  **         **  **         **  **         **  **         **  **         **  **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **  **    " << board[13] << "    **  **    " << board[12] << "    **  **    " << board[11] << "    **  **    " << board[10] << "    **  **    " << board[9] << "    **  **    " << board[8] << "    **  **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **  **         **  **         **  **         **  **         **  **         **  **         **  **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **   **       **    **       **    **       **    **       **    **       **    **       **   **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **     *******        *******        *******        *******        *******        *******     **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **                                                                                            **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **    " << board[0] << "    **                                                                                            **    " << board[7] <<"    ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **                                                                                            **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **     *******        *******        *******        *******        *******        *******     **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **   **       **    **       **    **       **    **       **    **       **    **       **   **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **  **         **  **         **  **         **  **         **  **         **  **         **  **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **  **    " << board[1] << "    **  **    " << board[2] << "    **  **    " << board[3] << "    **  **    " << board[4] << "    **  **    " << board[5] << "    **  **    " << board[6] << "    **  **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "  **         **  **         **  **         **  **         **  **         **  **         **  **         **  **         ** " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "   **       **    **       **    **       **    **       **    **       **    **       **    **       **    **       **  " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "     *******        *******        *******        *******        *******        *******        *******        *******    " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "                     CUP 1          CUP 2          CUP 3          CUP 4          CUP 5          CUP 6                    " << B_WHITE << endl;
	cout << B_YELLOW << BLACK << "                                                         Player 1                                                        " << B_WHITE << endl;
	cout << B_YELLOW << setfill(' ') << setw(121) << ' ' << B_WHITE << endl;	
	cout << B_YELLOW << setfill(' ') << setw(121) << ' ' << B_WHITE << endl;
	cout << B_YELLOW << setfill(' ') << setw(121) << ' ' << B_WHITE << endl;

	cout << B_WHITE << endl;
	cout << endl;
}

bool Mancala:: is_legal(const std::string& move) const{
	stringstream bin(move); // converts a sting to an integer
	
	int bin_number = 0;
	
	bin >> bin_number; // reads the value from the stringstream into the integer variable bin_number
	
	if(bin_number > 0 && bin_number < 7 && board[bin_number] != 0 && game:: next_mover() == HUMAN){
		return true;
	}
	
	else if(bin_number > 7 && bin_number < 14 && board[bin_number] != 0 && game:: next_mover() ==  COMPUTER){
		return true;
	}

	else if(bin_number == 0){
		return false;
	}
		
	else if(bin_number == 7){
		return false;
	}
	
	else{
		return false;
	}
}

void Mancala:: make_move(const std::string& move){
	stringstream bin(move);
	
	int bin_number = 0;
	
	bin >> bin_number;

	int stones = board[bin_number]; // variable for the number of stones in the bin the user has selected
	
	int cup = bin_number + 1; // variable for the next bin after the user's choice to move

	if(bin_number == 0){
		if(board[13] != 0)
			bin_number = 13;
		else if(board[12] != 0)
			bin_number = 12;
		else if(board[11] != 0)
			bin_number = 11;
		else if(board[10] != 0)
			bin_number = 10;
		else if(board[9] != 0)			
			bin_number = 9;
		else if(board[8] != 0)
			bin_number = 8;
	}

	if(bin_number == 13){
		cup = 0;
	}
	

	board[bin_number] = 0; // empties the bin that the user chose

	for(int i = stones; i != 0; i --){
		if(bin_number > 0 && bin_number < 7){
			if(cup == 13){
				board[cup]++;
				cup = 1;
			}
		
			else{
				board[cup]++;
				cup++;
			}
		
			
		}
		else{
			if(cup == 6){
				board[cup]++;
				cup = 8;
			}
			
			else if(cup == 13){
				board[cup]++;
				cup = 0;
			}

			else{
				board[cup]++;
				cup++;
			}
		}
	
	}

	if(game:: next_mover() == HUMAN && cup - 1 == 7){ // human ends in their mancala

		display_status( );

		cout << "Player 1 gets another turn!" << endl;

		string move;

		move = get_user_move( );
		while (!is_legal(move))
		{
	   		display_message("Illegal move.\n");
	   		move = get_user_move( );
       		}

		make_move(move);
		game:: make_move(move);
	}

	else if(game:: next_mover() == COMPUTER && cup - 1 == 0){ // computer ends in their mancala

		display_status( );

		string move;
		stringstream ss;

		int move_num;
		
	
		move_num = rand()%((14 - 8) + 1) + 8;

		ss << move_num;

		move = ss.str();
		while(!is_legal(move)){
			move_num = rand()%((14 - 8) + 1) + 8;
			ss << move_num;
			move = ss.str();
		}
		make_move(move);
		game:: make_move(move);
	}

	// scenarios for each player ending in an empty cup on their own side and stealing the stones from the opposite cup

	else if(game:: next_mover() == HUMAN && cup - 1  == 1 && board[1] == 1){
		board[7] = board[7] + board[1] + board[13];
		board[1] = 0;
		board[13] = 0;
	}

	else if(game:: next_mover() == HUMAN && cup - 1  == 2 && board[2] == 1){
		board[7] = board[7] + board[2] + board[12];
		board[2] = 0;
		board[12] = 0;
	}

	else if(game:: next_mover() == HUMAN && cup - 1  == 3 && board[3] == 1){
		board[7] = board[7] + board[3] + board[11];
		board[3] = 0;
		board[11] = 0;
	}

	else if(game:: next_mover() == HUMAN && cup - 1  == 4 && board[4] == 1){
		board[7] = board[7] + board[4] + board[10];
		board[4] = 0;
		board[10] = 0;
	}

	else if(game:: next_mover() == HUMAN && cup - 1  == 5 && board[5] == 1){
		board[7] = board[7] + board[5] + board[9];
		board[5] = 0;
		board[9] = 0;
	}

	else if(game:: next_mover() == HUMAN && cup - 1  == 6 && board[6] == 1){
		board[7] = board[7] + board[6] + board[8];
		board[6] = 0;
		board[8] = 0;
	}

	else if(game:: next_mover() == COMPUTER && cup == 0 && board[13] == 1){
		board[0] = board[0] + board[13] + board[1];
		board[13] = 0;
		board[1] = 0;
	}

	else if(game:: next_mover() == COMPUTER && cup - 1  == 12 && board[12] == 1){
		board[0] = board[0] + board[12] + board[2];
		board[12] = 0;
		board[2] = 0;
	}

	else if(game:: next_mover() == COMPUTER && cup - 1  == 11 && board[11] == 1){
		board[0] = board[0] + board[11] + board[3];
		board[11] = 0;
		board[3] = 0;
	}
	
	else if(game:: next_mover() == COMPUTER && cup - 1  == 10 && board[10] == 1){
		board[0] = board[0] + board[10] + board[4];
		board[10] = 0;
		board[4] = 0;
	}

	else if(game:: next_mover() == COMPUTER && cup - 1  == 9 && board[9] == 1){
		board[0] = board[0] + board[9] + board[5];
		board[9] = 0;
		board[5] = 0;
	}

	else if(game:: next_mover() == COMPUTER && cup - 1  == 8 && board[8] == 1){
		board[0] = board[0] + board[8] + board[6];
		board[8] = 0;
		board[6] = 0;
	}

	game:: make_move(move);

}

void Mancala:: restart( ){
	Mancala();
	game:: restart();
}

bool Mancala:: is_game_over( ) const{
	if(board[1] == 0 && board[2] == 0 && board[3] == 0 && board[4] == 0 && board[5] == 0 && board[6] == 0){
		return true;
	}

	else if(board[8] == 0 && board[9] == 0 && board[10] == 0 && board[11] == 0 && board[12] == 0 && board[13] == 0){
		return true;
	}

	else{
		return false;
	}
}

main_savitch_14:: game:: who Mancala:: winning( ) const{
	if(board[7] > board[0]){
		return HUMAN;
	}

	else if(board[0] > board[7]){
		return COMPUTER;
	}

	else{
		return NEUTRAL;
	}
}

game * Mancala:: clone( ) const{
	return new Mancala(*this);
}

void Mancala:: compute_moves(std::queue<std::string>& moves) const{
	stringstream ss;
	string temp_move;

	for(int i = 8; i <= 13; i++){
		ss << i;

		temp_move = ss.str();
	
		if(is_legal(temp_move)){
			moves.push(temp_move);
		}
	}
}

int Mancala:: evaluate( ) const{
	return board[0] - board[7];
}

