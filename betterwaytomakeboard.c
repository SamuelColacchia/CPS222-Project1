#include <iostream>
using namespace std;
int main()
{
  enum Organism { NONE, GESTATING, LIVING, DYING };
  Organism _board[10][10];
  int j = 0;
  static const char ESC = 27;
  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

  //old method to build a board
  //will keep around, may be useful in the future
  // for (int i=1; i <= (sizeof(_board)/sizeof(int)) ; i++) {
  //   if (i % 10 == 1) {
  //     cout << "start";
  //   }
  //   cout << i;
  //   if (i % 10 == 0 && i != 0) {
  //     cout << "end of row"<< j++ << endl;
  //
  //   }
  // }

  //Better way to get board information.
  for (int x = 0; x <= 10; x++){
    for (int y = 0; y < 10; y++){
      cout << x << ":" << y << endl;
    }
  }
  cout << (sizeof(_board)/sizeof(int)) << endl;
  cout << "Press RETURN to continue";
  while (cin.get() != '\n') ; // NOTE THE SEMICOLON!


}
