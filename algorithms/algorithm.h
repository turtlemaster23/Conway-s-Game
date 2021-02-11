#include<iostream>

#ifndef ALGORITHM_H_INCLUDE_
#define ALGORITHM_H_INCLUDE_

class Algorithm
{
    public:
        // virtual funcions for algorithms
        virtual void update() = 0;
        void debug_print()
        {
            for(int i = 0; i < width; i++)
            {
                for(int j = 0; j < height; j++)
                {
                    std::cout << display[i] [j] << " "; 
                }
                std::cout << std::endl;
            }
        }
    protected:
        //instince variables for algorithms
        
        //height = colunms; width = rows
        int height;
        int width;
        
        // 2 dimentional list with height and width
        int **display;
};
#endif
