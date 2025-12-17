#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ranges>
#include <string_view>

std::vector<std::string> splitStringBySubstr(std::string str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        // Erase the found token and delimiter from the original string
        str.erase(0, pos + delimiter.length());
    }
    // Add the last part of the string
    tokens.push_back(str);
    return tokens;
}

int main()
{
    std::ifstream inFile("input.txt");
    std::string line;
    std::getline(inFile, line);
    auto const ranges = splitStringBySubstr(line, ",");
    long long answer = 0;
    for (auto& range : ranges)
    {
        auto const ends = splitStringBySubstr(range, "-");
        auto const start = std::stoll(ends[0]);
        auto const end = std::stoll(ends[1]);
        for (auto i = start; i <= end; ++i)
        {
            auto const id = std::to_string(i);
            auto const length = id.size();
            if (length % 2) {
                continue;
            }
            const auto halfLength = length / 2;
            auto const firstHalf = id.substr(0, length / 2);
            auto const secondHalf = id.substr(length / 2);
            if (firstHalf == secondHalf)
            {
                std::cout << firstHalf << " " << secondHalf << "\n";
                answer += i;
            }
        }
    }
    std::cout << answer;
}