/**
* Vivianne Yee
* 300118867
**/

#include <iostream>
#include <cstddef>

using namespace std;

/**
* add a new player and score
**/
void addplayer(string player, int score, string players[], int scores[]) {
  // iterate thru the player array
  // if any entry is null then add player
  // if not tell user that list is full
  for (int i = 0; i < 10; i++) {
    // if there is an empty space in the list
    if (players[i].compare("") == 0) {
      players[i] = player;
      scores[i] = score;
      cout << "\nPlayer successfully added to List.\n";
      break;
    }
    // if the list is full
    if (i == 9 && players[i].compare("") != 0) {
      cout << "\nList is full. Cannot add player.\n";
    }
  }
}

/**
* print all players abd their score to the screen
**/
void printplayers(string players[], int scores[]) {
  int ctr = 1;
  for (int i = 0; i <= 9; i++) {
    if (players[i].compare("") != 0) {
      cout << ctr << ". " << players[i] << " score: " << scores[i] << "\n";
      ctr++;
    }
  }
}

/**
* allow the user to enter a player name and output the player's
* score or a message if the player's name has not been entered
**/
void showscore(string player, string players[], int scores[]) {
  for (int i = 0; i <= 9; i++) {
    if (players[i].compare(player) == 0) {
      cout << "\n" << player << "'s score is " << scores[i] << "\n";
      break;
    } else if (i == 9) {
      cout << "Player not found.";
    }
  }
}

/**
* allow the user to enter a player name and remove the player from
* the list
**/
void removeplayer(string player, string players[], int scores[]) {
  for (int i = 0; i <= 9; i++) {
    if (players[i].compare(player) == 0) {
      players[i] = "";
      scores[i] = 0;
      cout << "\n" << player << " was sucessfully removed.\n";
      break;
    } else if (i == 9) {
      cout << "Player not found.";
    }
  }
}

int main() {
  // initialize arrays with capacity 10
  string players[10];
  int scores[10];

  // ask user what they want to do
  char choice;
  bool flag = true;
  string player;
  int score;
  while (true) {
    cout << "\nEnter 'a' to add a new player\nEnter 'b' to print all players and their scores\nEnter 'c' to see a certain player's score\nEnter 'd' to remove a player\nEnter 'q' to quit\n";
    cin >> choice;
    switch(choice) {
      case 'a':
        cout << "enter player name: ";
        cin >> player;
        cout << "enter their score: ";
        cin >> score;
        addplayer(player, score, players, scores);
        break;
      case 'b':
        printplayers(players, scores);
        break;
      case 'c':
        cout << "enter player name: ";
        cin >> player;
        showscore(player, players, scores);
        break;
      case 'd':
        cout << "enter player name: ";
        cin >> player;
        removeplayer(player, players, scores);
        break;
      case 'q':
        return 0;
        break;
      default:
        cout << "invalid selection\n";
        break;
    }
  }
}
