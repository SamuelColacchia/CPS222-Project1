#include <iostream>
using namespace std;

enum Organism
{
   NONE, GESTATING, LIVING, DYING, BORDER
};
static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows  = activeRows + 2;
static const int totalCols  = activeCols + 2;

int countOrganisms(Organism _board[totalRows][totalCols], int rows, int cols)
{
   int count = 0;

   for (int x = -1; x < 2; x++)
   {
      for (int y = -1; y < 2; y++)
      {
         if (((_board[rows + x][cols + y] == DYING) || (_board[rows + x][cols + y] == LIVING)) && (_board[rows + x][cols + y] != BORDER))
         {
            if ((x != 0) || (y != 0))
            {
               count++;
            }
         }
      }
   }

   //  if ((_board[rows + 1][cols] == LIVING) || (_board[rows + 1][cols] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows][cols + 1] == LIVING) || (_board[rows][cols + 1] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows + 1][cols + 1] == LIVING) || (_board[rows + 1][cols + 1] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows - 1][cols] == LIVING) || (_board[rows - 1][cols] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows][cols - 1] == LIVING) || (_board[rows][cols - 1] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows - 1][cols - 1] == LIVING) || (_board[rows - 1][cols - 1] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows - 1][cols + 1] == LIVING) || (_board[rows - 1][cols + 1] == DYING))
   //  {
   //     count++;
   //  }
   //  if ((_board[rows + 1][cols - 1] == LIVING) || (_board[rows + 1][cols - 1] == DYING))
   //  {
   //     count++;
   //  }
   return(count);
}


int main()
{
   int numOFOrganisms, numOfGenrations;

   // Create Board
   Organism _board[totalRows][totalCols] =
   {
      NONE
   };
   Organism _oldboard[totalRows][totalCols] =
   {
      NONE
   };

   // TODO Known Bugs
   // 1: Does not handle user input thing well.

   // Get the starting orgonisms then clear the input buffer just to be safe
   cout << "Number of starting organisms: ";
   cin >> numOFOrganisms;
   while (cin.get() != '\n')
   {
   }


   // Get the starting locations store them and asign them to a var,

   for (int i = 0; i < numOFOrganisms; i++)
   {
      int a;
      int b;
      cout << "Locations: ";
      cin >> a;
      cin >> b;
      _board[a][b] = LIVING;
      while (cin.get() != '\n')
      {
      }
   }


   // while (cin.get() != '\n');

   //Get the number of generations then clear the input buffer just to be safe
   cout << "Number of generations: ";
   cin >> numOfGenrations;
   while (cin.get() != '\n')
   {
   }



   // Asign Border cells to value Border
   for (int x = 0; x < totalRows; x++)
   {
      for (int y = 0; y < totalCols; y++)
      {
         if ((x == 0) || (y == 0) || (y == totalCols - 1) || (x == totalRows - 1))
         {
            _board[x][y] = BORDER;
         }
      }
   }

   //Copy


   //The main loop
   for (int g = 0; g < numOfGenrations; g++)
   {
      for (int x = 0; x < totalRows; x++)
      {
         cout << "|";
         for (int y = 0; y < totalCols; y++)
         {
            if (_board[x][y] == NONE)
            {
               cout << " ";
            }
            else if (_board[x][y] == LIVING)
            {
               cout << "#";
            }
            else if (_board[x][y] == BORDER)
            {
               cout << "@";
            }
            else if (_board[x][y] == GESTATING)
            {
               cout << "G";
            }
            else if (_board[x][y] == DYING)
            {
               cout << "D";
            }
         }
         cout << "|" << endl;
      }

      for (int x = 0; x < totalRows; x++)
      {
         for (int y = 0; y < totalCols; y++)
         {
            _oldboard[x][y] = _board[x][y];
         }
      }

      //Logic for the game
      for (int x = 0; x < totalRows; x++)
      {
         for (int y = 0; y < totalCols; y++)
         {
            if (_oldboard[x][y] == LIVING)
            {
               if ((countOrganisms(_oldboard, x, y) < 2) || (countOrganisms(_oldboard, x, y) > 3))
               {

                  _board[x][y] = DYING;
               }
            }
            else if (_oldboard[x][y] == NONE)
            {
               if (countOrganisms(_oldboard, x, y) == 3)
               {
                   
                  _board[x][y] = GESTATING;
               }
            }
         }
      }

      for (int x = 1; x < activeRows; x++)
      {
         for (int y = 1; y < activeCols; y++)
         {
            if (_board[x][y] == DYING)
            {
               _board[x][y] = NONE;
            }
            else if (_board[x][y] == GESTATING)
            {
               _board[x][y] = LIVING;
            }
         }
      }

      cout << "Press RETURN to continue";
      while (cin.get() != '\n')
      {
      }
   }
// Display board as is ##TESTING PUPOSE##


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
}
