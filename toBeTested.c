#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main()
{
  static const int activeRows = 18;
  static const int activeCols = 50;
  static const int totalRows = activeRows + 2;
  static const int totalCols = activeCols + 2;

  enum Organism { NONE, GESTATING, LIVING, DYING };
  Organism _board[totalRows][totalCols];

int board = arr[totalRows][totalCols];

cout<<"number of starting organisms: "<<endl;
int numOFOrganisms = getline(cin, input);
while (cin.get() != '\n') ;

cout<<"number of starting generations: "
int numOfGenrations = getline(cin, input);
while (cin.get() != '\n');


cout<<"organisms coordinates: (x,y)"


cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
while(numOfGenrations>0){
  cout << ESC << "[H" << "Generation " << numOfGenrations << ":" << endl;

  for(int x = 0; x<= totalCols; x++){
    for(int y = 0; y<= totalRows; y++){
      if (x == 0 || x == totalCols || y == 0 || y == totalRows){
        if (x == 0  && y ==0)
          cout<<"+";
        else if (x == cols  && y == totalRows)
          cout<<"+";
        else if (x == 0  || x == totalCols)
          if (x == cols)
          cout<<"|\n";
          else
          cout<<"|";
        else if ( y == 0  || y == totalRows)
          cout<<"-"
           }
    else{
        if(countOrganisms(x,y)<2 && Organism _board[x][y] == LIVING){
            Organism _board[x][y] = DYING;
            cout<<"*";}
        else if(countOrganisms(x,y)>3 && Organism _board[x][y] == LIVING){
          Organism _board[x][y] = DYING;
          cout<<"*";}
        else if(Organism _board[x][y] == DYING){
          Organism _board[x][y] = NONE;
          cout<<" ";}
       else if(Organism _board[x][y] == GESTATING){
         Organism _board[x][y] = LIVING;
         cout<<"*";}
        else if(Organism _board[x][y] == LIVING){
        Organism _board[x][y] = LIVING;
        cout<<"*";}
        else
          cout<<" ";}
  numOfGenrations--;
}
}}
}


int countOrganisms ( int x, int y){
  int count = 0;
  if(Organism[x+1][y] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x][y+1] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x+1][y+1] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x-1][y] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x][y-1] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x-1][y-1] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x-1][y+1] == Living || Organism[x][y] == DYING)
    count++;
  if(Organism[x+1][y-1] == Living || Organism[x][y] == DYING)
    count++;
  return (count);
}
