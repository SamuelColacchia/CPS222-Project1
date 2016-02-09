#include <iostream>
using namespace std;
int main(int activeRows,int activeCols)
{
  std::cout << "Hello World!";

//more of a idea
int arr[activeRows][activeCols]

}


//implementation notes:
static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows = activeRows + 2;
static const int totalCols = activeCols + 2;

enum Organism { NONE, GESTATING, LIVING, DYING };
Organism _board[totalRows][totalCols];

// The following code should be used to flush the input buffer after reading input from the user.
// Immediately after reading all the input values from the user at startup

while (cin.get() != '\n') ; // NOTE THE SEMICOLON!

//The following code can be used to clear the screen before the initial board is displayed:
//At toplevel near the start of the file
static const char ESC = 27;

//Just before displaying the initial board:
cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

//The following code can be used to position the cursor to the top of the screen, so that each
//board overwrites the previous one, giving the appearance of animation.
//Just before starting to display the board each time after the first
//cout << ESC << "[H" << "Generation " << some variable << ":" << endl;

//The following code can be used to prompt the user to press Return after each generation and
//wait for the user to do so.
// After each board has been displayed:
cout << ESC << "[23;1H" << ESC << "[K"
 << "Press RETURN to continue";
while (cin.get() != '\n') ; // NOTE THE SEMICOLON!

//examle of initiating a 2d array
int arr[2][5] = {{1,8,12,20,25}, {5,9,13,24,26}};
