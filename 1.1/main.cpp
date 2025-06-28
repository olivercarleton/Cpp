//HW1 Jan 24/2024 - Oliver Carleton
#include <iostream>
int main() {
//varibles defined
    double priceP;
    int numP;
//user inputs price
    std::cout << "Enter the price of a pen: $";
    std::cin >> priceP;
//user inputs quantity
    std::cout << "Enter the number of pens: ";
    std::cin >> numP;
//calculation of total
    double totalP = priceP * numP;
    std:: cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
//total price output
    std::cout << "The total price for " << numP << " pens is: $" << totalP << std::endl;
//end of code
    return 0;
}

