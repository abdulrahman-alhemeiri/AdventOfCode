#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    
    std::string line = "";
    std::vector<std::string> grid;
    while (std::getline(std::cin, line))
    {
        grid.push_back(line);
    }
    
    auto rows = grid.size();
    auto columns = grid[0].size();
    std::unordered_set<int> currentBeamIndexes;
    auto answer = 0;

    for (int j = 0; j < columns; ++j)
    {
        if (grid[0][j] == 'S')
        {
            currentBeamIndexes.insert(j);
            break;
        }
    }
    
    for (int i = 1; i < rows; ++i)
    {
        std::unordered_set<int> newBeamIndexes;
        for (auto const& index : currentBeamIndexes)
        {
            if (grid[i][index] == '^')
            {
                newBeamIndexes.insert(index - 1);
                newBeamIndexes.insert(index + 1);
                ++answer;
            }
            else
            {
                newBeamIndexes.insert(index);
            }
        }
        currentBeamIndexes = newBeamIndexes;
    }
    
    std::cout << answer << "\n";
}
