#include <iostream>
using namespace std;
int main()
{
  enum Organism { NONE, GESTATING, LIVING, DYING };
  Organism _board[10][10];
  int j = 0;
  static const char ESC = 27;
  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
  for (int i=0; i < sizeof(_board); i++) {
  
  }




}
