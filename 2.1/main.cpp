//HW 2 Oliver Carleton 1/26/24.
#include <iostream>
#include <iomanip>
int main() {
    int score;
    int totalScores = 0;
    int count = 0;
    double average = 0;
    std::cout << "Enter student scores, input negative value to output average:\n";
    while (1) {
        std::cout << "Enter student score:";
        std::cin >> score;
        if (score < 0) {
            break;
        }
        if (score >= 0) {
            totalScores += score;
            count++;
        }
    }
    if (count > 0) {
        average = static_cast<double>(totalScores) / count;
        std::cout << "Average score: " << std::fixed << std::setprecision(1) << average << std::endl;
    } else {
        std::cout << "No valid scores entered.\n";
    }
    return 0;
}


