#include <iostream>
using namespace std;
int main()
{
   for (int x = -1; x < 2; x++)
   {
      for (int y = -1; y < 2; y++)
      {
        if ((x == 0) && (y == 0))
        {
           cout << x << ":" << y << endl;
        }

      }
   }
   cout << "Press RETURN to continue";
   while (cin.get() != '\n')
   {
   }
   return 0;
}
