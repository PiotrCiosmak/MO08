#include <iostream>
#include <fstream>
#include "functions.hpp"

using namespace std;

template<typename T>
void saveToFile(const vector<vector<T>> &differences)
{
    fstream fowardDifference2Center("fowardDifference2Center.txt", ios::out);
    fstream centralDifference2Center("centralDifference2Center.txt", ios::out);
    fstream backwardDifference2Center("backwardDifference2Center.txt", ios::out);
    fstream backwardDifference2End("backwardDifference2End.txt", ios::out);
    fstream backwardDifference3End("backwardDifference3End.txt", ios::out);

    for (int i = 0; i < differences.size(); ++i)
    {
        fowardDifference2Center << log10(differences.at(i).at(0)) << ";";
        centralDifference2Center << log10(differences.at(i).at(1)) << ";";
        backwardDifference2Center << log10(differences.at(i).at(2)) << ";";
        backwardDifference2End << log10(differences.at(i).at(3)) << ";";
        backwardDifference3End << log10(differences.at(i).at(4)) << ";";
    }

    fowardDifference2Center.close();
    centralDifference2Center.close();
    backwardDifference2Center.close();
    backwardDifference2End.close();
    backwardDifference3End.close();
}

int main()
{
    vector<vector<double>> results;
    vector<vector<double>> differences;
    constexpr double begin{0};
    constexpr double end{M_PI / 2};
    double h{1};
    constexpr double epsilon{1e-10};
    calculate(results, begin, end, h, epsilon);
    difference(results, differences, begin, end);
    saveToFile(differences);
}
