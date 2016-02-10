#include <iostream>
using namespace std;
int main()
{
   int numOFOrganisms, numOfGenrations;
   enum Organism
   {
      NONE, GESTATING, LIVING, DYING, BORDER
   };
   static const int activeRows = 18;
   static const int activeCols = 50;
   static const int totalRows  = activeRows + 2;
   static const int totalCols  = activeCols + 2;

   // TODO Known Bugs
   // 1: Does not handle user input thing well.

   // Get the starting orgonisms then clear the input buffer just to be safe
   cout << "Number of starting organisms: ";
   cin >> numOFOrganisms;
   while (cin.get() != '\n')
   {
   }

   // Get the starting locations store them and asign them to a var,
   // TODO may consider changing and improving the way of input
   int initLocations[numOFOrganisms];

   for (int i = 0; i < numOFOrganisms; i++)
   {
		 	char input[50];
      cout << "Locations: ";
      initLocations[i]cin.getline(input, sizeof(input));

      {
      }
   }
   for (int i = 0; i < numOFOrganisms; i++)
   {
		 cout << initLocations[i] <<endl;
   }

   // while (cin.get() != '\n');

   // Get the number of generations then clear the input buffer just to be safe
   // cout << "Number of generations: ";
   // cin >> numOfGenrations;
   // while (cin.get() != '\n');

   // Create Board
   Organism _board[totalRows][totalCols] =
   {
      NONE
   };

   // Asign Border cells to value Border
   for (int x = 0; x < totalRows; x++)
   {
      for (int y = 0; y < totalCols; y++)
      {
         if ((x == 0) || (y == 0) || (y == totalCols - 1) || (x ==
                                                              totalRows - 1))
         {
            _board[x][y] = BORDER;
         }
      }
   }
   for (int x = 0; x < activeRows; x++)
   {
      for (int y = 0; y < activeCols; y++)
      {
      }
   }
   // Display board as is ##TESTING PUPOSE##

   // for (int x = 0; x < totalRows; x++)
   // {
   // cout << "|";
   // for (int y = 0; y < totalCols; y++)
   // {
   // if (_board[x][y] == NONE)
   // {
   // cout << " ";
   // }
   // else if (_board[x][y] == BORDER)
   // {
   // cout << "@";
   // }
   // }
   // cout << "|" << endl;
   // }
   // for (int i = 0; i < numOfGenrations; i++) {
   //
   // }

   // char name2[50];
   // cin >> name2;
   // cout << name;
   // cout << name2;

   // Organism _board[10][10] = {NONE};
   // int j = 0;
   // static const char ESC = 27;
   // cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

   // old method to build a board
   // will keep around, may be useful in the future
   // for (int i=1; i <= (sizeof(_board)/sizeof(int)) ; i++) {
   // if (i % 10 == 1) {
   // cout << "start";
   // }
   // cout << i;
   // if (i % 10 == 0 && i != 0) {
   // cout << "end of row"<< j++ << endl;
   //
   // }
   // }

   // Better way to get board information.
   // for (int x = 0; x <= 10; x++){
   // for (int y = 0; y < 10; y++){
   // Organism _board[x][y]=LIVING;
   // }
   // }
   // for (int x = 0; x < 10; x++) {
   // cout << "|" << "-";
   // for (int y = 0; y < 10; y++) {
   // _board[x][y] = LIVING;
   // if (_board[x][y] == LIVING) {
   // cout << "#" << "-";
   // }
   // }
   // cout << "|" << endl;
   // }
   // cout << (sizeof(_board)/sizeof(int)) << endl;
   cout << "Press RETURN to continue";
   while (cin.get() != '\n')
   {
      // NOTE THE SEMICOLON!
   }
}
