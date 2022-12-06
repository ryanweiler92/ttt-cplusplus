#include <iostream>
#include <vector>
#include <string>
#include "ttt_declarations.hpp"
#include <algorithm>
using namespace std;


int main() {

  vector<string> game_board = {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "};
  vector<string> game_board_selections = { "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
  int player_turn = 1;
  bool game_resolved = false;
  int turn = 1;
  string winner;

  welcome();

  while(!game_resolved && turn < 10){
	draw_board(game_board);
	string player_selection = player_turn_handler(player_turn, game_board_selections, game_board);
	game_board_selections = update_selections(player_selection, game_board_selections);
	game_board = update_game_board(player_selection, game_board, player_turn);
	player_turn = player_turn == 1 ? 0 : 1;
	game_resolved = check_game_resolved(game_resolved, game_board);
	turn++;
	cout << "Turn : " << turn << "\n";
}

 winner = declare_winner(turn, game_resolved, winner);
 draw_board(game_board);
 cout << winner << "\n";
 
}