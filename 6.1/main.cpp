#include <iostream>
#include <vector>
#include <limits>

//structure for pizza info
struct Pizza {
    double diameter;
    double cost;
// (cost/in^2)
    double unitPrice;
};
//declaration(prototype)
double calculateUnitPrice(double diameter, double cost);

int main() {
    std::vector<Pizza> pizzas;
    char more = 'y';
    std::cout << "Pizza Value Calculator:" << std::endl;

//loop min of 2 times for size and cost
    do {
        Pizza pizza;

        std::cout << "Enter the diameter of the pizza (in inches): ";
        std::cin >> pizza.diameter;

        std::cout << "Enter the cost of the pizza: $";
        std::cin >> pizza.cost;

//take calculated unit price and store it in a vector
        pizza.unitPrice = calculateUnitPrice(pizza.diameter, pizza.cost);
        pizzas.push_back(pizza);

        if (pizzas.size() >= 2) {
            std::cout << "Do you want to input more pizza info? (y/n): ";
            std::cin >> more;
        }

//ignore extra input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (more == 'y' | more == 'Y');

//determines best pizza to buy
    Pizza bestBuy = pizzas[0];
    for (const auto& pizza : pizzas) {
        if (pizza.unitPrice < bestBuy.unitPrice ||
            (pizza.unitPrice == bestBuy.unitPrice && pizza.diameter < bestBuy.diameter)) {
            bestBuy = pizza;
        }
    }
//output of best pizza size and price
    std::cout << "The best buy is the " << bestBuy.diameter << " inch pizza at $"
              << bestBuy.unitPrice << " per square inch.\n";

    return 0;
}
//definition(implementation)
double calculateUnitPrice(double diameter, double cost) {
    double radius = diameter / 2;
    double area = 3.14159 * radius * radius;
    //cost per in^2
    return cost / area;
}

