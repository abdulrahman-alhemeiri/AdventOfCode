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
    std::vector<std::string> nums;
    std::vector<std::string> operations;
    while (std::getline(std::cin, line))
    {
        if (line[0] == '+' || line[0] == '*')
        {
            operations = splitByWhitespace(line);
            break;
        }
        nums.push_back(line);
    }
    
    long long rows = nums.size();
    long long columns = nums[0].size();

    long long finalAnswer = 0;
    long long currentProblemTotal = 0;
    bool isNewProblem = true;
    char currentOperation = '_';
    long long currentOperationIndex = 0;
    for (long long j = 0; j < columns; ++j)
    {
        std::string column = "0";
        for (long long i = 0; i < rows; ++i)
        {
            if (nums[i][j] != ' ')
            {
                column += nums[i][j];
            }
        }
        
        long long currentNum = std::stoll(column);
        
        if (currentNum == 0 || j == columns - 1)
        {
            if (currentOperation == '+')
            {
                currentProblemTotal += currentNum;
            }
            else if (currentOperation == '*')
            {
                if (currentNum != 0)
                {
                    currentProblemTotal *= currentNum;
                }
            }
            finalAnswer += currentProblemTotal;
            currentProblemTotal = 0;
            isNewProblem = true;
            continue;
        }
        
        if (isNewProblem) 
        {
            currentProblemTotal = currentNum;
            isNewProblem = false;
            currentOperation = operations[currentOperationIndex++][0];
            continue;
        }
        
        if (currentOperation == '+')
        {
            currentProblemTotal += currentNum;
        }
        else if (currentOperation == '*')
        {
            currentProblemTotal *= currentNum;
        }
    }
    
    std::cout << finalAnswer << "\n";
}
