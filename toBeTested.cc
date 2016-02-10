#include <iostream>


using namespace std;
enum Organism { NONE, GESTATING, LIVING, DYING };

static const int activeRows = 18;
static const int activeCols = 50;
static const int totalRows = activeRows + 2;
static const int totalCols = activeCols + 2;
static const char ESC = 27;

int countOrganisms (Organism _board[][totalCols], int rows, int cols){

int count = 0;
  if(_board[rows+1][cols] == LIVING || _board[rows+1][cols] == DYING)
    count++;
  if(_board[rows][cols+1] == LIVING || _board[rows][cols+1] == DYING)
    count++;
  if(_board[rows+1][cols+1] == LIVING || _board[rows+1][cols+1] == DYING)
    count++;
  if(_board[rows-1][cols] == LIVING || _board[rows-1][cols] == DYING)
    count++;
  if(_board[rows][cols-1] == LIVING || _board[rows][cols-1] == DYING)
    count++;
  if(_board[rows-1][cols-1] == LIVING || _board[rows-1][cols-1] == DYING)
    count++;
  if(_board[rows-1][cols+1] == LIVING || _board[rows-1][cols+1] == DYING)
    count++;
  if(_board[rows+1][cols-1] == LIVING || _board[rows+1][cols-1] == DYING)
    count++;
  return (count);
}


int main()
{

  Organism _board[totalRows][totalCols];


  cout<<"number of starting organisms: ";
  int numOFOrganisms;
  std::cin>>numOFOrganisms;
  while (cin.get() != '\n');

  cout<<"number of starting generations: ";
  int numOfGenrations;
  std::cin>>numOfGenrations;
  while (cin.get() != '\n');

  for(int rows = 0; rows<totalRows; rows++){
    for(int cols = 0; cols<totalCols; cols++){
      _board[rows][cols] = NONE;

    }
  }

  cout<<"organisms coordinates: ";
  int a,b;
  for(int i=0; i<numOFOrganisms; i++){
    std::cin>>a;
    std::cin>>b;
    _board[a][b] = LIVING;
  }
  while (cin.get() != '\n') ;

  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

  for(int gen = 0; gen < numOfGenrations + 1; gen++){


    for(int rows = 0; rows< totalRows; rows++){
      for(int cols = 0; cols< totalCols; cols++){

	if( _board[rows][cols] == LIVING){
	  if(countOrganisms(_board,rows,cols)<2 || countOrganisms(_board,rows,cols)>3)
	    _board[rows][cols] = DYING;
	}

	else if(_board[rows][cols] == NONE){

	  if(countOrganisms(_board,rows,cols)==2 || countOrganisms(_board,rows,cols)==3)
	    _board[rows][cols] = GESTATING;

	}


	if (rows == 0  && cols ==0)
	  cout<<"+";

	else if (rows == totalRows-1  && cols == 0)
	  cout<<"+";
	else if (rows == 0  && cols == totalCols-1)
	  cout<<"+"<<endl;
	else if (rows == totalRows-1  && cols == totalCols-1)
	  cout<<"+"<<endl;

	else if (rows == 0  || rows == totalRows-1)
	  cout<<"-";

	else if(cols == 0  || cols == totalCols-1){
	  if(cols == 0)
	    cout<<"|";
	  else
	    cout<<"|"<<endl;
	}

	else if(_board[rows][cols] == LIVING || _board[rows][cols] == DYING)
	  cout<<"*";

	else if(_board[rows][cols] == NONE)
	  cout<<" ";
	else if(_board[rows][cols] == GESTATING)
	  cout<<" ";

      }

    }

    for(int rows = 0; rows< totalRows; rows++){
      for(int cols = 0; cols< totalCols; cols++){

        if(_board[rows][cols] == DYING)
          _board[rows][cols] = NONE;


	else if(_board[rows][cols] == GESTATING)
          _board[rows][cols] = LIVING;

      }
    }
	cout<<"press enter for next genration"<<endl;
  	while (cin.get() != '\n');
	cout << ESC << "[H" << "Generation " << gen << ":" << endl;
  }

}
