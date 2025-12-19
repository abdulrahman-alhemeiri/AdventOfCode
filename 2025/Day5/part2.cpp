#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

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
    
    std::sort(ranges.begin(), ranges.end());
    
    for (int i = 0; i < ranges.size() - 1; ++i)
    {
        if (ranges[i + 1].second <= ranges[i].second)
        {
            ranges.erase(ranges.begin() + (i + 1));
            --i;
        }
        else if (ranges[i].second >= ranges[i + 1].first)
        {
            if (ranges[i + 1].first - 1 >= ranges[i].first)
            {
                ranges[i].second = ranges[i + 1].first - 1;
            }
            else
            {
                ranges.erase(ranges.begin() + i);
                --i;
            }
        }
    }
    
    long long answer = 0;
    for (auto const& [start, end] : ranges)
    {
        answer += (end - start + 1);
    }
    std::cout << answer << "\n";
}