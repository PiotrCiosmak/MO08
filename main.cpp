#include <iostream>
#include <fstream>
#include "functions.hpp"

using namespace std;

template<typename T>
void saveToFile(const vector<vector<T>> &differences, const vector<T> &archivesH)
{
    fstream fowardDifference2Begin("fowardDifference2Begin.txt", ios::out);
    fstream fowardDifference3Begin("fowardDifference3Begin.txt", ios::out);
    fstream fowardDifference2Center("fowardDifference2Center.txt", ios::out);
    fstream centralDifference2Center("centralDifference2Center.txt", ios::out);
    fstream backwardDifference2Center("backwardDifference2Center.txt", ios::out);
    fstream backwardDifference2End("backwardDifference2End.txt", ios::out);
    fstream backwardDifference3End("backwardDifference3End.txt", ios::out);

    for (int i = 0; i < differences.size(); ++i)
    {
        fowardDifference2Begin << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(0)) << "\n";
        fowardDifference3Begin << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(1)) << "\n";
        fowardDifference2Center << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(2)) << "\n";
        centralDifference2Center << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(3)) << "\n";
        backwardDifference2Center << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(4)) << "\n";
        backwardDifference2End << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(5)) << "\n";
        backwardDifference3End << log10(archivesH.at(i)) << " " << log10(differences.at(i).at(6)) << "\n";
    }

    fowardDifference2Begin.close();
    fowardDifference3Begin.close();
    fowardDifference2Center.close();
    centralDifference2Center.close();
    backwardDifference2Center.close();
    backwardDifference2End.close();
    backwardDifference3End.close();
}

int main()
{
    vector<vector<float>> results;
    vector<vector<float>> differences;
    vector<float> archivesH;
    constexpr float begin{0};
    constexpr float end{M_PI / 2};
    float h{100};
    constexpr float epsilon{1e-10};
    calculate(results, archivesH, begin, end, h, epsilon);
    difference(results, differences, begin, end);
    saveToFile(differences, archivesH);
}
