#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void welcome(){
  cout << "Welcome to Tic-Tac-Toe\n";
}

void draw_board(std::vector<std::string> game_board){
  cout << "    1    2    3\n";
  cout << "  ================\n";
  cout << "A | " << game_board[0] << " | " << game_board[1] << " | " << game_board[2] << " |\n";
  cout << "  ================\n";
  cout << "B | " << game_board[3] << " | " << game_board[4] << " | " << game_board[5] << " |\n";
  cout << "  ================\n";
  cout << "C | " << game_board[6] << " | " << game_board[7] << " | " << game_board[8] << " |\n";
  cout << "  ================\n";
}

bool valid_selection(string player_selection, vector<std::string> game_board_selections){
  bool valid_selection = false;
  for(int i = 0; i < game_board_selections.size(); i++){
      if(game_board_selections[i] == player_selection){
        valid_selection = true;
    }
  }
  return valid_selection;
}

string player_turn_handler(int player_turn, vector<string> game_board_selections, vector<string> game_board){
  string player_id = player_turn == 1 ? "Player 1" : "Player 2";

  string player_selection;

  cout << player_id << " please make a selection.\n";
  for(int i = 0; i < game_board_selections.size(); i++){
    cout << game_board_selections[i] << " ";
  }
  cout << "\n";
  cin >> player_selection;
  cout << "\n";

  bool is_valid_selection = valid_selection( player_selection, game_board_selections);

   while(!is_valid_selection){
     cout << "Invalid selection. Please try again.\n";
     cin >> player_selection;
     cout << "\n";
     if(valid_selection(player_selection, game_board_selections)){
       is_valid_selection = true;
     }
   }
  cout << player_id << " selects " << player_selection << "\n";

  return player_selection;
}

// function to remove the chosen selection from the vector
vector<string> update_selections(string selection, vector<string> game_board_selections){
  vector<string>::iterator remove_item;
  remove_item = remove(game_board_selections.begin(), game_board_selections.end(), selection);

  return game_board_selections;
}

int find_index (string selection){
  int index;
    if(selection == "A1"){
    index = 0;
  } else if (selection == "A2"){
    index = 1;
  } else if (selection == "A3"){
    index = 2;
  } else if (selection == "B1"){
    index = 3;
  } else if (selection == "B2"){
    index = 4;
  } else if (selection == "B3"){
    index = 5;
  } else if (selection == "C1"){
    index = 6;
  } else if (selection == "C2"){
    index = 7;
  } else if (selection == "C3"){
    index = 8;
  }
  
  return index;
}

vector<string> update_game_board(string selection, vector<string> game_board, int player_turn){
  // identify player game piece & name of current turn;
  char game_piece = (player_turn == 1) ? 'X' : 'O';

  int index = find_index(selection);

  game_board[index] = game_piece;

  return game_board;
}

bool check_game_resolved(bool game_resolved, vector<string> game_board){
    if(game_board[0] == "X" && game_board[1] == "X" && game_board[2] == "X"){
        game_resolved = true;
    } else if (game_board[0] == "O" && game_board[1] == "O" && game_board[2] == "O"){
        game_resolved = true;
    } else if (game_board[0] == "X" && game_board[3] == "X" && game_board[6] == "X"){
        game_resolved = true;
    } else if (game_board[0] == "O" && game_board[3] == "O" && game_board[6] == "O"){
        game_resolved = true;
    } else if (game_board[0] == "X" && game_board[4] == "X" && game_board[9] == "X"){
        game_resolved = true;
    } else if (game_board[0] == "O" && game_board[4] == "O" && game_board[9] == "O"){
        game_resolved = true;
    } else if (game_board[3] == "X" && game_board[4] == "X" && game_board[5] == "X"){
        game_resolved = true;
    } else if (game_board[3] == "O" && game_board[4] == "O" && game_board[5] == "O"){
        game_resolved = true;
    } else if (game_board[7] == "X" && game_board[8] == "X" && game_board[9] == "X"){
        game_resolved = true;
    } else if (game_board[7] == "O" && game_board[8] == "O" && game_board[9] == "O"){
        game_resolved = true;
    } else if (game_board[7] == "X" && game_board[4] == "X" && game_board[2] == "X"){
        game_resolved = true;
    } else if (game_board[7] == "O" && game_board[4] == "O" && game_board[2] == "O"){
        game_resolved = true;
    } else if (game_board[1] == "X" && game_board[4] == "X" && game_board[7] == "X"){
        game_resolved = true;
    } else if (game_board[1] == "O" && game_board[4] == "O" && game_board[7] == "O"){
        game_resolved = true;
    } else if (game_board[2] == "X" && game_board[5] == "X" && game_board[8] == "X"){
        game_resolved = true;
    } else if (game_board[2] == "O" && game_board[5] == "O" && game_board[8] == "O"){
        game_resolved = true;
    }

    return game_resolved;
}

string declare_winner(int turn, bool game_resolved, string winner){
    if(!game_resolved){
        winner = "It's a tie!";
        return winner;
    } 

    if(turn % 2 == 0){
        winner = "Player 2 wins!";
    } else {
        winner = "Player 1 wins!";
    }

    return winner;

    
}
