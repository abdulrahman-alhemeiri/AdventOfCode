#include <iostream>
#include <string>
#include <fstream>

int main()
{
    int current = 50;
    std::ifstream inFile("input.txt");
    std::string line;
    int answer = 0;
    int lineCount = 1;
    while (std::getline(inFile, line))
    {
        const bool isLeft = line[0] == 'L';
        auto move = std::stoi(line.substr(1, line.size() - 1));
 
        if (move >= 100)
        {
            const int fullRotations = move / 100;
            answer += fullRotations;
            move = move % 100;
        }
        
        if (move == 0)
        {
            continue;
        }
        
        if (isLeft)
        {
            current -= move;
            if (current <= 0) {
                current = (current + 100) % 100;
                if ((100 - current) != move)
                {
                    ++answer;
                }
            }
        }
        else
        {
            current += move;
            if (current >= 100) {
                ++answer;
            }
            current %= 100;
        }
    }
    std::cout << answer << "\n";
    return 0;
}