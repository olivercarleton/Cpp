//HW09 FEB 29,2024 Oliver Carleton
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//function declaration (prototype)
//preconditions: input file, output to either open file or cout in terminal
//postconditions: dates with temps below freezing are written to the selected output
void exportFreezingDays(std::istream& in, std::ostream& out);

int main(int argc, char *argv[]) {
    std::ifstream ifile;
    ifile.open("/Users/olivercarleton/Documents/cpp/HW09/HW09/NOLA2024.txt");
    if (ifile.fail()){
        std::cout << "File not found\n";
        return 1;
    }

    std::cout << "Output Data to Screen [S] or File [F]? ";
    char sorf;
    std::cin >> sorf;
    std::cin.ignore();//ignore the newline when user types
    if (sorf == 'F' || sorf == 'f'){
        std::ofstream ofile;
        //assuming the file path is correct and replaced with "FreezingDays2024.txt" for simplicity
        ofile.open("/Users/olivercarleton/Documents/cpp/HW09/HW09/FreezingDays2024.txt");
        if (!ofile) {
            std::cerr << "Error opening output file." << std::endl;
            return 1; //return sign put as 1
        }
        //process the data and write to the file
        exportFreezingDays(ifile, ofile);
        //close the output file
        ofile.close();
    }
    else {
        //process the data and write to the screen
        exportFreezingDays(ifile, std::cout);
    }
    //close input file
ifile.close();
    return 0;
}
void exportFreezingDays(std::istream& in, std::ostream& out) {
    std::string date;
    double precipitation;
    int maxTemp, minTemp;

    while (in >> date >> precipitation >> maxTemp >> minTemp) {
        //skip entries with placeholder values for precipitation, maxTemp, or minTemp
        if (minTemp == -999 || maxTemp == -999 || precipitation == -999) {
            continue; //skip iteration and proceed next task in while
        }
        if (minTemp < 32) {  //check min temperature below 32F degrees
        out << date << " " << precipitation << " " << maxTemp << " " << minTemp << std::endl;
        }
    }
}






