#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> splitByWhitespace(const std::string& input) {
    std::istringstream buffer(input);
    std::vector<std::string> words;
    std::string temp;

    while (buffer >> temp) {
        words.push_back(temp);
    }

    return words;
}

int main() {
    
    std::string line;
    std::vector<std::vector<long long>> nums;
    std::vector<std::string> operations;
    while (std::getline(std::cin, line))
    {
        std::vector<std::string> row = splitByWhitespace(line);
        if (line[0] == '+' || line[0] == '*')
        {
            operations = splitByWhitespace(line);
            break;
        }
        
        std::vector<long long> rowNums;
        for (auto const& num : row)
        {
            rowNums.push_back(std::stoll(num));
        }
        nums.push_back(rowNums);
    }
    
    int rows = nums.size();
    int columns = nums[0].size();
    long long answer = 0;

    for (int j = 0; j < columns; ++j)
    {
        char operation = operations[j][0];
        long long columnAnswer = nums[0][j];
        for (int i = 1; i < rows; ++i)
        {
            if (operation == '+')
            {
                columnAnswer += nums[i][j];
            }
            else if (operation == '*')
            {
                columnAnswer *= nums[i][j];
            }
        }
        answer += columnAnswer;
    }
    
    std::cout << answer << "\n";
}
