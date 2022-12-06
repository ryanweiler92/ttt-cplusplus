#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void welcome();
void draw_board(vector<string> game_board);
string player_turn_handler(int player_turn, vector<string> game_board_selections, vector<string> game_board);
vector<string> update_selections(string selection, vector<string> game_board_selections);
vector<string> update_game_board(string selection, vector<string> game_board, int player_turn);
bool check_game_resolved(bool game_resolved, vector<string> game_board);
string declare_winner(int turn, bool game_resolved, string winner);