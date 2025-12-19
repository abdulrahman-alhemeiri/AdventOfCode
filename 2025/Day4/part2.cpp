#include <iostream>
#include <string>
#include <array>

int main()
{
    std::string line;
    auto const GridSize = 136;
    std::array<std::array<char, GridSize>, GridSize> grid;
    int currentInputRow = 0;
    while (std::getline(std::cin, line))
    {
        for (int i = 0; i < GridSize; ++i)
        {
            grid[currentInputRow][i] = line[i];
        }
        ++currentInputRow;
    }
    
    auto answer = 0;
    bool removeableExists = true;
    while(removeableExists)
    {
        removeableExists = false;
        for (int i = 0; i < GridSize; ++i)
        {
            for (int j = 0; j < GridSize; ++j)
            {
                if (grid[i][j] == '@')
                {
                    int adjacentRolls = 0;
                    for (int row = i - 1; row <= i + 1; row++)
                    {
                        for (int column = j - 1; column <= j + 1; column++)
                        {
                            if (row >= 0 && row < GridSize && 
                                column >= 0 && column < GridSize && 
                                !(row == i && column == j))
                            {
                                if (grid[row][column] == '@')
                                {
                                    ++adjacentRolls;
                                }
                            }
                        }
                    }
                    
                    if (adjacentRolls < 4)
                    {
                        grid[i][j] = '.';
                        removeableExists = true;
                        ++answer;
                    }
                }
            }
        }
    }
    std::cout << answer << "\n";
}