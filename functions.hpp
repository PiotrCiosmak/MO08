#include <cmath>
#include <vector>

constexpr int numberOfIterations{1000};

template<typename T>
T function(T x)
{
    return sin(x);
}

template<typename T>
T derivative(T x)
{
    return cos(x);
}

template<typename T>
T fowardDifference2(T x, T h)
{
    return (function(x + h) - function(x)) / h;
}

template<typename T>
T centralDifference2(T x, T h)
{
    return (function(x + h) - function(x - h)) / (2 * h);
}

template<typename T>
T backwardDifference2(T x, T h)
{
    return (function(x) - function(x - h)) / h;
}

template<typename T>
T fowardDifference3(T x, T h)
{
    return (-3 / 2.0 * function(x) + 2 * function(x + h) - 0.5 * function(x + 2 * h)) / h;
}

template<typename T>
T backwardDifference3(T x, T h)
{
    return (3 / 2.0 * function(x) - 2 * function(x - h) + 0.5 * function(x - 2 * h)) / h;
}

template<typename T>
void calculate(std::vector<std::vector<T>> &results, std::vector<T> &archivesH, const T &begin, const T &end, T &h,
               const T &epsilon)
{
    T center = (begin - end) / 2;

    for (int i = 0; i < numberOfIterations; ++i)
    {
        if (h < epsilon)
            break;
        results.push_back(std::vector<T>{0, 0, 0, 0, 0, 0, 0});
        results.at(i).at(0) = fowardDifference2(begin, h);
        results.at(i).at(1) = fowardDifference3(begin, h);
        results.at(i).at(2) = fowardDifference2(center, h);
        results.at(i).at(3) = centralDifference2(center, h);
        results.at(i).at(4) = backwardDifference2(center, h);
        results.at(i).at(5) = backwardDifference2(end, h);
        results.at(i).at(6) = backwardDifference3(end, h);
        archivesH.push_back(h);
        h /= 1.05;
    }
}

template<typename T>
void difference(const std::vector<std::vector<T>> &results, std::vector<std::vector<T>> &differences, const T &begin,
                const T &end)
{
    T center = (begin - end) / 2;
    for (int i = 0; i < results.size(); ++i)
    {
        differences.push_back(std::vector<T>{0, 0, 0, 0, 0, 0, 0});
        differences.at(i).at(0) = fabs(results.at(i).at(0) - derivative(begin));
        differences.at(i).at(1) = fabs(results.at(i).at(1) - derivative(begin));
        differences.at(i).at(2) = fabs(results.at(i).at(2) - derivative(center));
        differences.at(i).at(3) = fabs(results.at(i).at(3) - derivative(center));
        differences.at(i).at(4) = fabs(results.at(i).at(4) - derivative(center));
        differences.at(i).at(5) = fabs(results.at(i).at(5) - derivative(end));
        differences.at(i).at(6) = fabs(results.at(i).at(6) - derivative(end));
    }
}