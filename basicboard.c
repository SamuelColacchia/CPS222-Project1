#include <iostream>
using namespace std;
int main()
{
  enum Organism { NONE, GESTATING, LIVING, DYING };
  Organism _board[10][10];
  int j = 0;
  static const char ESC = 27;
  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

  //code to display the board
  for (int i=0; i <= (sizeof(_board)/sizeof(int)) ; i++) {
    if (i % 10 == 1) {
      cout << "start";
    }
    cout << i;
    if (i % 10 == 0) {
      cout << "end of row"<< j++ << endl;

    }
  }
  cout << (sizeof(_board)/sizeof(int)) << endl;
  cout << "Press RETURN to continue";
  while (cin.get() != '\n') ; // NOTE THE SEMICOLON!


}
