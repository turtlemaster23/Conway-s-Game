#include "algorithm.h"

#ifndef CONWAY_H_INCLUDE_
#define CONWAY_H_INCLUDE

class Conway: public Algorithm
{
    public:
        //row is the row count of the matrix
        //col is the column count of the matrix
        //density is approximitly how many tiles will be alive; 1 being 100% and 0 being 0%
        Conway(int row, int col, float density, unsigned int seed); 
        Conway(int row, int col, float density);
        ~Conway();
        void update() override;
    private:
        //returns a stack allocated matrix with the number of neighbors each square has
        int** friendz();
        // returns the number of neighbors a square has
        int near(int row, int col);
};
#endif
