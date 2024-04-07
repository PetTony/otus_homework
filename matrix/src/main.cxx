#include "matrix.h"
#include <iostream>

int main(void)
{
    Matrix<int, 0, 2> matrix;

    for(int i = 0; i < 10; ++i)
    {
        matrix[i][i] = i;
        matrix[i][9 - i] = 9 - i;
    }

    for(int i = 1; i < 9; ++i)
    {
        for(int j = 1; j < 9; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    for(const auto &[pos, value] : matrix)
    {
        for(size_t i = 0; i < pos.size(); ++i)
        {
            std::cout << '[' << pos[i] << ']';
        }
        std::cout << " - " << value << std::endl;
    }

    std::cout << "Matrix size: " << matrix.size() << std::endl;

    return 0;
}