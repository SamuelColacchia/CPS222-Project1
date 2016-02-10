//Import statement

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
static const char ESC = 27;


//Function to count around a given position
//Takes a board and the current x and y then loops around it
int countOrganisms(Organism _board[totalRows][totalCols], int rows, int cols)
{
   int count = 0;
   //Nested for loop working around a given value
   for (int x = -1; x < 2; x++)
   {
      for (int y = -1; y < 2; y++)
      {
        //If state to check what we want while also ensuring that what we are counting is not a brorder
         if (((_board[rows + x][cols + y] == DYING) || (_board[rows + x][cols + y] == LIVING)) && (_board[rows + x][cols + y] != BORDER))
         {
           //If statement to check to ensure we do not count our starting cell
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
  //Declaring local vars
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
   cout << "Locations: ";
   for (int i = 0; i < numOFOrganisms; i++)
   {
      int a;
      int b;

      cin >> a;
      cin >> b;
      _board[a][b] = LIVING;
      // while (cin.get() != '\n')
      // {
      // }
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
   cout <<
   // Commented out because causing errors
   //ESC <<
   "Initial:" << endl;
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

   cout << "Press RETURN to continue";
   while (cin.get() != '\n')
   {
   }



   //The main loop

   //Generations loop
   for (int g = 0; g < numOfGenrations; g++)
   {
      //Copy the board before we make any changes
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
      //Change DYING and GESTATING to there final form before leaving this generation
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

      //Loop through the board and draw it
      cout <<
      //ESC <<
      //Commented out causeing errors
       "Generation " << g << ":" << endl;

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

      cout << "Press RETURN to continue";
      while (cin.get() != '\n')
      {
      }
   }
}
