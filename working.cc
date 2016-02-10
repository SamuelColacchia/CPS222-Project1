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
   return(count);
}


int main()
{
   int numOFOrganisms, numOfGenrations;

   // Create Boards
   Organism _board[totalRows][totalCols] =
   {
      NONE
   };
   Organism _oldboard[totalRows][totalCols] =
   {
      NONE
   };


   // Get the starting orgonisms then clear the input buffer just to be safe
   cout << "Number of starting organisms: ";
   cin >> numOFOrganisms;
   while (cin.get() != '\n')
   {
   }


   // Get and set starting locations
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
}
