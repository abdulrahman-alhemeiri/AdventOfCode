#include <iostream>
#include <string>
#include <fstream>

int main()
{
    int current = 50;
    std::ifstream inFile("input.txt");
    std::string line;
    int answer = 0;
    while (std::getline(inFile, line))
    {
        const bool isLeft = line[0] == 'L';
        auto move = std::stoi(line.substr(1, line.size() - 1));
        if (isLeft)
        {
            move *= -1;
        }
        current = (current - move) % 100;
        if (isLeft)
        {
            current %= 100;
        }
        if (current == 0)
        {
            ++answer;
        }
    }
    std::cout << answer << "\n";
    return 0;
}
