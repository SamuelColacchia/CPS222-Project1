#include <iostream>
using namespace std;
int main()
{
        int numOFOrganisms, numOfGenrations, initLocations;

        //Get the starting orgonisms then clear the input buffer just to be safe
        cout<<"Number of starting organisms: ";
        cin >> numOFOrganisms;
        while (cin.get() != '\n');

        cout<<"Locations: ";
        cin >> initLocations;


        //Get the number of generations then clear the input buffer just to be safe
        cout << "Number of generations: ";
        cin >> numOfGenrations;
        while (cin.get() != '\n') ;


        //         char name2[50];
        // cin >> name2;
        // cout << name;
        // cout << name2;
        enum Organism { NONE, GESTATING, LIVING, DYING, BORDER };
      //  Organism _board[10][10] = {NONE};
      //  int j = 0;
        // static const char ESC = 27;
        // cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

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
        // for (int x = 0; x <= 10; x++){
        //   for (int y = 0; y < 10; y++){
        //     Organism _board[x][y]=LIVING;
        //   }
        // }
        // for (int x = 0; x < 10; x++) {
        //         cout << "|" << "-";
        //         for (int y = 0; y < 10; y++) {
        //                 _board[x][y] = LIVING;
        //                 if (_board[x][y] == LIVING) {
        //                         cout << "#" << "-";
        //                 }
        //         }
        //         cout << "|" << endl;
        // }
        // cout << (sizeof(_board)/sizeof(int)) << endl;
        cout << "Press RETURN to continue";
        while (cin.get() != '\n');  // NOTE THE SEMICOLON!


}
