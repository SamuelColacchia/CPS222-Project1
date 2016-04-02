//TODO a comment

#include <iostream>
using namespace std;

class GameOfLife
{
public:

        static const int activeRows = 18;
        static const int activeCols = 50;
        static const int totalRows  = activeRows + 2;
        static const int totalCols  = activeCols + 2;
        static const char ESC        = 27;

        enum Organism
        {
                NONE, GESTATING, LIVING, DYING, BORDER
        };
        Organism _board[totalRows][totalCols] =
        {
                NONE
        };



        class Board
        {
public:
                int printboard(Organism _board[totalRows][totalCols]);
                void createBoarder(Organism _board[totalRows][totalCols])


        };

        class Logic
        {
public:
                int countOrganisms(Organism _board[totalRows][totalCols], int rows, int cols)

                void changeState(Organism _board[totalRows][totalCols])

                void cleanup(Organism _board[totalRows][totalCols])


        };
};
