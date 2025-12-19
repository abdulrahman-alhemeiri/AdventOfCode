#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <vector>

std::vector<std::string> splitStringBySubstr(std::string str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);
    return tokens;
}

int main()
{
    std::string line;
    std::vector<std::pair<long long, long long>> ranges;
    while (std::getline(std::cin, line))
    {
        if (line == "")
        {
            break;
        }
        
        auto range = splitStringBySubstr(line, "-");
        std::pair<long long, long long> rangePair{std::stoll(range[0]), std::stoll(range[1])};
        ranges.push_back(rangePair);
    }
    
    auto answer = 0;
    
    while (std::getline(std::cin, line))
    {
        long long id = std::stoll(line);
        for (const auto& [start, end] : ranges)
        {
            if (start <= id && id <= end)
            {
                ++answer;
                break;
            }
        }
    }
    
    std::cout << answer << "\n";
}