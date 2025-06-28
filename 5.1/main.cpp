//HW05 Oliver Carleton Feb 5, 2024
#include <iostream>
#include <string>
using namespace std;
string grade(double score) {
    if (score >= 93) return "A";
    if (score >= 90) return "A-";
    if (score >= 87) return "B+";
    if (score >= 83) return "B";
    if (score >= 80) return "B-";
    if (score >= 77) return "C+";
    if (score >= 73) return "C";
    if (score >= 70) return "C-";
    if (score >= 67) return "D+";
    if (score >= 63) return "D";
    if (score >= 60) return "D-";
    return "F";
}
int main() {
    double score = 0;
    while (true) {
        cout << "Enter a score; (-) value to terminate: ";
        cin >> score;
        
        if (score < 0) {
            break;
        }
        if (score > 100) {
            std::cout << "Invalid score; enter value x<=100." << endl;
            continue;
        }
        cout << "Student's Grade: " << grade(score) << endl;
    }
    cout << "Terminated." << endl;
    return 0;
}

