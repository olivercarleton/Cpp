#include <iostream>
#include <string>
#include <cctype> //toupper function
#include <iomanip> //setprecision
using namespace std;

//function prototypes
//preconditions: none
//postcondition: pizzaSize will contain
void pizzaOrder(char &pizzaSize, int &numberOfToppings);
//preconditions: pizzaSize must be one of 'S', 'M', 'L', or 'G';
//postcondition: returns the calculated price of the pizza
double calculatePizzaPrice(char pizzaSize, int numberOfToppings);
//precondition: pizzaSize must be one of 'S', 'M', 'L', or 'G';
//postcondition: outputs the total price of the pizza order to the console.
void displayPizzaPrice(char pizzaSize, int numberOfToppings, double pizzaPrice);
//preconditions: none
//postconditions: returns true if the user wants to repeat the operation, false otherwise
bool askYesNo();

int main() {
    char pizzaSize;
    int numberOfToppings;
    double pizzaPrice;

    do {
        //get pizza order
        pizzaOrder(pizzaSize, numberOfToppings);

        //calculate price
        pizzaPrice = calculatePizzaPrice(pizzaSize, numberOfToppings);

        //display price
        displayPizzaPrice(pizzaSize, numberOfToppings, pizzaPrice);

        cout << "Repeat? [Y/N]";
    } while (askYesNo());

    cout << "Bye\n";
    return 0;
}

//function to get the pizza size and number of toppings
void pizzaOrder(char &size, int &toppings) {
    const int MAX_TOPPINGS_S_M_L = 3;
    const int MAX_TOPPINGS_G = 4;

    cout << "Enter pizza size (S, M, L, G): ";
while (true) {
        cin >> size;
        size = toupper(size); //uppercase converter
        if (size == 'S' || size == 'M' || size == 'L' || size == 'G') {
            break;
        } else {
            cout << "Invalid size. Please enter S, M, L, or G: ";
        }
    }
int maxToppings = (size == 'G') ? MAX_TOPPINGS_G : MAX_TOPPINGS_S_M_L;
    cout << "Enter number of toppings (0 to " << maxToppings << "): ";
    while (true) {
        cin >> toppings;
        if (toppings >= 0 && toppings <= maxToppings) {
            break;
        } else {
            cout << "Invalid number of toppings. Please enter a value between 0 and " << maxToppings << ": ";
        }
    }
}
//function to calculate pizza price
double calculatePizzaPrice(char pizzaSize, int numberOfToppings) {
    const double BASE_PRICES[] = {2.75, 8.95, 11.95, 14.75};
    const double TOPPING_PRICES[] = {0.50, 1.75, 2.25, 2.75}; 
    int sizeIndex = (pizzaSize == 'S') ? 0 : (pizzaSize == 'M') ? 1 : (pizzaSize == 'L') ? 2 : 3;
    return BASE_PRICES[sizeIndex] + numberOfToppings * TOPPING_PRICES[sizeIndex];
}
//function to display the price
void displayPizzaPrice(char pizzaSize, int numberOfToppings, double pizzaPrice) {
    cout << fixed << setprecision(2);
    cout << "Total price for a " << pizzaSize << " pizza with " << numberOfToppings
         << " toppings is: $" << pizzaPrice << endl;
}
//function for user to continue
bool askYesNo() {
    string input;
    cout << " Do you want to calculate another pizza? (Y/N): ";
    cin >> input;
    return (toupper(input[0]) == 'Y');
}

