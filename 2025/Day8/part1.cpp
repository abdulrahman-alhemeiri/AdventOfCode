#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <cmath>

auto const ProblemSize = 1000;

std::vector<std::string> splitStringBySubstr(std::string str, std::string const& delimiter) {
    std::vector<std::string> tokens;
    size_t pos{0};
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);
    return tokens;
}

struct Point
{
    long long x{0};
    long long y{0};
    long long z{0};
    
    bool operator<(const Point& other) const {
        return x < other.x;
    }
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

double distance(Point const& p1, Point const& p2)
{
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}

namespace std {
    template <>
    struct hash<Point> {
        std::size_t operator()(const Point& other) const noexcept {
            std::size_t h1 = std::hash<int>{}(other.x);
            std::size_t h2 = std::hash<int>{}(other.y);
            std::size_t h3 = std::hash<int>{}(other.z);
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
}

int main() {
    std::string line;
    std::vector<Point> points;
    std::vector<std::tuple<double, Point, Point>> distances;
    std::unordered_map<Point, std::unordered_map<Point, bool>> isConnected;
    std::unordered_map<Point, bool> visited;
    std::unordered_map<Point, std::vector<Point>> neighbors;
    
    while (std::getline(std::cin, line))
    {
        auto point = splitStringBySubstr(line, ",");
        Point p{std::stoi(point[0]), std::stoi(point[1]), std::stoi(point[2])};
        for (Point point : points)
        {
            auto newDistance = std::make_tuple<double, Point, Point>(distance(p, point), std::move(p), std::move(point));
            distances.push_back(newDistance);
            isConnected[point][p] = false;
            isConnected[p][point] = false;
        }
        visited[p] = false;
        points.push_back(p);
    }
    std::sort(distances.begin(), distances.end());

    for (int i = 0; i < ProblemSize; ++i)
    {
        double distance = std::get<0>(distances[i]);
        Point p1 = std::get<1>(distances[i]);
        Point p2 = std::get<2>(distances[i]);
        isConnected[p1][p2] = true;
        isConnected[p2][p1] = true;
        neighbors[p1].push_back(p2);
        neighbors[p2].push_back(p1);
    }
    
    std::vector<int> clusterSizes;
    for (auto const& point : points)
    {
        if (!visited[point])
        {
            std::vector<Point> dfs;
            dfs.push_back(point);
            auto count = 0;
            while (!dfs.empty())
            {
                Point currentPoint = dfs.back();
                dfs.pop_back();
                if (!visited[currentPoint])
                {
                    visited[currentPoint] = true;
                    ++count;
                }
                for (auto const& neighbor : neighbors[currentPoint])
                {
                    if (!visited[neighbor])
                    {
                        dfs.push_back(neighbor);
                    }
                }
            }
            clusterSizes.push_back(count);
        }
    }
    std::sort(clusterSizes.begin(), clusterSizes.end());
    std::reverse(clusterSizes.begin(), clusterSizes.end());

    for (auto const& clusterSize : clusterSizes)
    {
        std::cout << clusterSize << ", ";
    }
    std::cout << "\n\n" << (clusterSizes[0] * clusterSizes[1] * clusterSizes[2]) << "\n";
}
