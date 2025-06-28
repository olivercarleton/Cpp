//HW12 Oliver Carleton
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// class definition for Pizza
class Pizza {
private:
    char size; // holds the size of the pizza
    int numberOfToppings; // holds the number of toppings on the pizza

public:
    // public member functions
    char getSize() const; // returns the pizza size
    int getNumberOfToppings() const; // returns the number of toppings
    void setPizza(char newSize, int newNumTops); // sets the pizza's size and number of toppings
    Pizza pizzaOrder(); // handles ordering process
};

// implementation of getSize() - returns size of the pizza
char Pizza::getSize() const {
    return size;
}

// implementation of getNumberOfToppings() - returns number of toppings
int Pizza::getNumberOfToppings() const {
    return numberOfToppings;
}

// implementation of setPizza() - sets the size and number of toppings of the pizza
void Pizza::setPizza(char newSize, int newNumTops) {
    size = newSize;
    numberOfToppings = newNumTops;
}

// pizzaOrder() - facilitates the process of ordering a pizza, ensuring valid inputs for size and toppings
Pizza Pizza::pizzaOrder() {
    const int MAX_TOPPINGS_S_M_L = 3; // max toppings for sizes S, M, L
    const int MAX_TOPPINGS_G = 4; // max toppings for size G
    Pizza order;

    // prompt for and validate pizza size input
    cout << "Enter pizza size (S, M, L, G): ";
    while (true) {
        cin >> order.size;
        order.size = toupper(order.size); // convert to uppercase for consistency
        // check for valid size input
        if (order.size == 'S' || order.size == 'M' || order.size == 'L' || order.size == 'G') {
            break; // valid size entered
        } else {
            cout << "Invalid size. Please enter S, M, L, or G: ";
        }
    }

    // determine max toppings based on pizza size and prompt for valid number of toppings
    int maxToppings = (order.size == 'G') ? MAX_TOPPINGS_G : MAX_TOPPINGS_S_M_L;
    cout << "Enter number of toppings (0 to " << maxToppings << "): ";
    while (true) {
        cin >> order.numberOfToppings;
        // check for valid number of toppings input
        if (order.numberOfToppings >= 0 && order.numberOfToppings <= maxToppings) {
            break; // valid number entered
        } else {
            cout << "Invalid number of toppings. Please enter a value between 0 and " << maxToppings << ": ";
        }
    }

    return order; // return the ordered pizza
}

// calculatePizzaPrice() - calculates the price of the ordered pizza based on its size and toppings
double calculatePizzaPrice(const Pizza& order) {
    // arrays holding base prices and topping prices for different sizes
    const double BASE_PRICES[] = {2.75, 8.95, 11.95, 14.75};
    const double TOPPING_PRICES[] = {0.50, 1.75, 2.25, 2.75};
    // determine the index for price arrays based on pizza size
    int sizeIndex = (order.getSize() == 'S') ? 0 : (order.getSize() == 'M') ? 1 : (order.getSize() == 'L') ? 2 : 3;
    // calculate and return the total price
    return BASE_PRICES[sizeIndex] + order.getNumberOfToppings() * TOPPING_PRICES[sizeIndex];
}

// displayPizzaPrice() - displays the total price of the pizza order
void displayPizzaPrice(const Pizza& order, double price) {
    cout << fixed << setprecision(2); // set the output to show two decimal places
    cout << "Total price for a " << order.getSize() << " pizza with " << order.getNumberOfToppings()
         << " toppings is: $" << price << endl;
}

// askYesNo() - prompts the user to decide whether to calculate another pizza
bool askYesNo() {
    string input;
    cout << "Do you want to calculate another pizza? (Y/N): ";
    cin >> input;
    return (toupper(input[0]) == 'Y' || toupper(input[0]) == 'y'); // returns true for 'y' or 'Y'
}

int main() {
    do {
        Pizza p;
        p = p.pizzaOrder();
        double price = calculatePizzaPrice(p);
        displayPizzaPrice(p, price);
    } while (askYesNo());

    return 0;
}
//HW12
