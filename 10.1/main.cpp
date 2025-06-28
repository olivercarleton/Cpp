//HW10 Mar 13,2024 Oliver Carleton
//Users/olivercarleton/Documents/cpp/HW10/HW10/NOLA2024.txt
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

const int INVALID_DATA = -999;
const int MONTHS_IN_YEAR = 12;
const std::string INPUT_FILE = "/Users/olivercarleton/Documents/cpp/HW10/HW10/NOLA2024.txt";
const std::string OUTPUT_FILE = "/Users/olivercarleton/Documents/cpp/HW10/HW10/ProcessedData.txt"; // Change to desired output path

void processMonthlyData(std::istream& inFile, int year, std::vector<double>& monthlyPrecip, std::vector<double>& monthlyMaxTemp, std::vector<double>& monthlyMinTemp);
void exportMonthlyData(std::ostream& out, const std::vector<double>& monthlyPrecip, const std::vector<double>& monthlyMaxTemp, const std::vector<double>& monthlyMinTemp, int year);

int main() {
    int year;
    char outputPreference;
    std::cout << "Enter the year for which you want to process data: ";
    std::cin >> year;
    std::cout << "Do you want to export data to a file [F] or display on screen [S]? ";
    std::cin >> outputPreference;

    std::ifstream inFile(INPUT_FILE);
    if (!inFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::vector<double> monthlyPrecip(MONTHS_IN_YEAR, 0), monthlyMaxTemp(MONTHS_IN_YEAR, 0), monthlyMinTemp(MONTHS_IN_YEAR, 0);
    
    processMonthlyData(inFile, year, monthlyPrecip, monthlyMaxTemp, monthlyMinTemp);
    inFile.close();

    if (outputPreference == 'F' || outputPreference == 'f') {
        std::ofstream outFile(OUTPUT_FILE);
        if (!outFile) {
            std::cerr << "Error: Unable to open output file." << std::endl;
            return 1;
        }
        exportMonthlyData(outFile, monthlyPrecip, monthlyMaxTemp, monthlyMinTemp, year);
        outFile.close();
    } else {
        exportMonthlyData(std::cout, monthlyPrecip, monthlyMaxTemp, monthlyMinTemp, year);
    }

    return 0;
}

void processMonthlyData(std::istream& inFile, int year, std::vector<double>& monthlyPrecip, std::vector<double>& monthlyMaxTemp, std::vector<double>& monthlyMinTemp) {
    int date;
    double precip, maxTemp, minTemp;
    int dayCount[MONTHS_IN_YEAR] = {0};
    
    while (inFile >> date >> precip >> maxTemp >> minTemp) {
       
        if (date / 10000 != year) continue;
        
        int month = (date % 10000) / 100 - 1;


        if (precip != INVALID_DATA) {
            monthlyPrecip[month] += precip;
        }
        
        if (maxTemp != INVALID_DATA) {
            monthlyMaxTemp[month] += maxTemp;
            dayCount[month]++;
        }
        
        if (minTemp != INVALID_DATA) {
            monthlyMinTemp[month] += minTemp;
        }
    }

    for (int i = 0; i < MONTHS_IN_YEAR; ++i) {
        if (dayCount[i] > 0) {
            monthlyMaxTemp[i] /= dayCount[i];
            monthlyMinTemp[i] /= dayCount[i];
        } else {
            monthlyPrecip[i] = INVALID_DATA;
            monthlyMaxTemp[i] = INVALID_DATA;
            monthlyMinTemp[i] = INVALID_DATA;
        }
    }
}

void exportMonthlyData(std::ostream& out, const std::vector<double>& monthlyPrecip, const std::vector<double>& monthlyMaxTemp, const std::vector<double>& monthlyMinTemp, int year) {
    out << "Year: " << year << "\n";
    out << "Month | Total Precipitation | Avg Max Temp | Avg Min Temp" << std::endl;
    out << "---------------------------------------------------------" << std::endl;

    for (int i = 0; i < MONTHS_IN_YEAR; ++i) {
        out << std::setw(5) << i + 1 << " | ";
        if (monthlyPrecip[i] != INVALID_DATA) {
            out << std::setw(19) << std::fixed << std::setprecision(2) << monthlyPrecip[i] << " | ";
        } else {
            out << std::setw(19) << "-999" << " | ";
        }
        if (monthlyMaxTemp[i] != INVALID_DATA) {
            out << std::setw(12) << std::fixed << std::setprecision(1) << monthlyMaxTemp[i] << " | ";
        } else {
            out << std::setw(12) << "-999" << " | ";
        }
        if (monthlyMinTemp[i] != INVALID_DATA) {
            out << std::setw(12) << std::fixed << std::setprecision(1) << monthlyMinTemp[i] << std::endl;
        } else {
            out << std::setw(12) << "-999" << std::endl;
        }
    }
}
