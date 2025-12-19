#include <iostream>
#include <string>
#include <fstream>
#include <array>

const int NumberOfDigits = 12;

long long joltage(std::array<int, NumberOfDigits>& indexes, std::string& line)
{
    std::string joltDigits = "";
    for (const auto& index : indexes)
    {
        joltDigits += line[index];
    }
    long long joltValue = std::stoll(joltDigits);
    return joltValue;
}

int main()
{
    std::string line;
    long long answer = 0;

    while (std::getline(std::cin, line))
    {
        std::array<int, NumberOfDigits> indexes;
        for (int i = 0; i < NumberOfDigits; ++i)
        {
            indexes[i] = i;
        }

        for (int i = 1; i < line.size(); ++i)
        {
            for (int j = 0; j < NumberOfDigits && indexes[j] < i; ++j)
            {
                if ((line[i] - '0') > (line[indexes[j]] - '0'))
                {
                    if (i <= line.size() - (NumberOfDigits - j))
                    {
                        for (int k = i; j < NumberOfDigits; ++k)
                        {
                            indexes[j++] = k;
                        }
                        break;
                    }
                }
            }
            
        }
        const auto lineJoltage = joltage(indexes, line);
        answer += lineJoltage;
    }
    std::cout << answer << "\n";
    return 0;
}