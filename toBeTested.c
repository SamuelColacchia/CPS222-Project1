#include <iostream>
using namespace std;
int main()
{
  static const int activeRows = 18;
  static const int activeCols = 50;
  static const int totalRows = activeRows + 2;
  static const int totalCols = activeCols + 2;

  enum Organism { NONE, GESTATING, LIVING, DYING };
  Organism _board[totalRows][totalCols];

cout<<"number of starting organisms: "<<endl;
while (cin.get() != '\n') ;
int numOFOrganisms = cin.get();

cout<<"number of starting generations: ";
while (cin.get() != '\n');
int numOfGenrations = cin.get();

//more of a idea
int board = arr[totalRows][totalCols];
CreateBoard(totalCols,totalRows);

cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
while(numOfGenrations>0){
  cout << ESC << "[H" << "Generation " << numOfGenrations << ":" << endl;
  generation(totalCols,totalRows);
  numOfGenrations--;
}

}

int generation(cols, rows){
for(int x = 0; x<= rows; x++){
  for(int y = 0; y<= cols; y++){

    if(Organism _board[x][y] == DYING){
        Organism _board[x][y] = NONE;
        coutt<<"*";}

    if(Organism _board[x][y] == living){
      if(countOrganisms(x,y)<2)
        Organism _board[x][y] = DYING;
      else if(countOrganisms(x,y)>3)
        Organism _board[x][y] = DYING;
      coutt<<"*";}

    if(Organism _board[x][y] == GESTATING){
      Organism _board[x][y] = LIVING;
      cout<<" ";}

    }

    }
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

int createBoard(cols,rows){
  for (int x = 0; x<= cols; x++){
    for(int y = 0; y<= rows; y++){

       if (x == 0 || x == cols || y == 0 || y == rows){
         if (x == 0  && y ==0)
           cout<<"+";
          else if (x == cols  && y == rows)
            cout<<"+";
          else if (x == 0  || x == cols)
            cout<<"|";
         else
            cout<<"-"
       }
}}
}
