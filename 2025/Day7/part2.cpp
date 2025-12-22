#include <iostream>
#include <string>
#include <vector>

int main() {
    
    std::string line = "";
    std::vector<std::string> grid;
    while (std::getline(std::cin, line))
    {
        grid.push_back(line);
    }
    
    auto rows = grid.size();
    auto columns = grid[0].size();
    
    auto startColumn = -1;
    for (int j = 0; j < columns; ++j)
    {
        if (grid[0][j] == 'S')
        {
            startColumn = j;
            break;
        }
    }

    std::vector<long long> values(columns, 0);

    for (int i = rows - 1; i >= 1; --i)
    {
        std::vector<long long> newValues(values);
        for (int j = 0; j < columns; ++j)
        {
            if (grid[i][j] == '^')
            {
                int numberOfNeighbors = 0;
                if (values[j] != 0)
                {
                    newValues[j] = 0;
                }
                if (values[j - 1] != 0)
                {
                    newValues[j] += values[j - 1];
                    ++numberOfNeighbors;
                }
                if (values[j + 1] != 0)
                {
                    newValues[j] += values[j + 1];
                    ++numberOfNeighbors;
                }
                
                newValues[j] += (2 - numberOfNeighbors);
            }
        }
        values = newValues;
    }
    
    std::cout << values[startColumn] << "\n";
}
