#include "conway.h"

Conway::Conway(int row, int col, float density, unsigned int seed)
{
    srand(seed);

    height = col;
    width = row;
    display = new int* [row];
    
    for (int i = 0; i < row; i++)
    {
        display[i] = new int [col];
    }
    
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            int num = rand() % 100;    
            if (num < (density * 100))
            {
                display[j][k] = 1;
            }   
            else
            {
                display[j][k] = 0;
            }
        }
    }
}

Conway::Conway(int row, int col, float density)
{
    srand(time(NULL));
   
    height = col;
    width = row;
    display = new int* [row];
   
    for (int i = 0; i < row; i++)
    {
        display[i] = new int [col];
    }
    
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            int num = rand() % 100;    
            if (num < (density * 100))
            {
                display[j][k] = 1;
            }   
            else
            {
                display[j][k] = 0;
            }
        }
    }
}

Conway::~Conway()
{
    for (int i = 0; i < width; i++)
    {
        delete display[i];
    }
    delete display;
}
// friend_array = friend();
//for i = 0 i < row i ++
//for j = 0 j < col j++
//live = display[i][j];
//if friend_array[i][j] == 2 || 3 && live == 1
//display[i][j] = 1
//else if friend_array[i][j] == 3 && live == 0
//display[i][j] = 1
//else
//display[i][j] = 0
void Conway::update()
{
    int** friend_array = friendz();
    for (int i =0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int live = display[i][j];
            int friendz = friend_array[i][j];
            if ((friendz == 2 || friendz == 3 && live == 1) || (friendz == 3 && live == 0))
            {
                display[i][j] = 1;
            }
            else
            {
                display[i][j] = 0;
            }

        }
    }
    for (int k = 0; k < width; k++)
    {
        delete friend_array[k];
    }
    delete friend_array;
}

int** Conway::friendz()
{
    int** friend_array = new int* [width];
    for (int k = 0; k < width; k++)
    {
        friend_array[k] = new int [height]; 
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            friend_array[i][j] = near(i, j);
        }
    }
    return friend_array;
}

int Conway::near(int row, int col)
{
    int friendz = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i != row && j != col)
            {
                if (i >= 0 && j >= 0 && i < width && j < height)
                {
                    friendz += display[i][j];
                }
            }
        }
    }
    return friendz;
}
