#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream inFile("input.txt");
    std::string line;
    int answer = 0;
    while (std::getline(inFile, line))
    {
        const int lineLength = line.size();
        int max = 0;
        for (int i = 0; i < lineLength - 1; ++i)
        {
            for (int j = i + 1; j < lineLength; ++j)
            {
                const int left = line[i] - '0';
                const int right = line[j] - '0';
                const int potential = left * 10 + right;
                if (potential > max)
                {
                    max = potential;
                }
            }
        }
        answer += max;
    }
    std::cout << answer << "\n";
    return 0;
}