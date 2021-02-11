#include "algorithms/conway.h"

int main()
{
    Conway* grid = new Conway(12, 8, 0.8, 2656489);
    for (int i =0; i < 10; i++)
    {
        grid -> debug_print();
        grid -> update();
        std::cout<<std::endl;
    }
    grid -> debug_print();
    delete grid;
}
