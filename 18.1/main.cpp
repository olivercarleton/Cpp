//HW18 Oliver Carleton April 21, 2024
//“I affirm that I do not give or receive any unauthorized help on this homework and tha all work is my own”
#include <iostream>
#include <string>

namespace OliverCarleton {

class Plant {
public:
    // Constructors
    Plant();
    Plant(std::string theName);

    // Accessors
    std::string getName() const;

    // Mutators
    void setName(std::string newName);

    // Growth behavior
    void grow() const;

private:
    std::string name;
};

Plant::Plant() : name("NA") {}

Plant::Plant(std::string theName) : name(theName) {}

std::string Plant::getName() const {
    return name;
}

void Plant::setName(std::string newName) {
    name = newName;
}

void Plant::grow() const {
    std::cout << "This plant is growing in a general way." << std::endl;
}

class Flower : public Plant {
public:
    // Constructors
    Flower();
    Flower(std::string theName);

    // Growth behavior specific to Flower
    void grow() const;
};

Flower::Flower() {}

Flower::Flower(std::string theName) : Plant(theName) {}

void Flower::grow() const {
    std::cout << "The flower has vibrant colors." << std::endl;
}

class Tree : public Plant {
public:
    // Constructors
    Tree();
    Tree(std::string theName);

    // Growth behavior specific to Tree
    void grow() const;
};

Tree::Tree() {}

Tree::Tree(std::string theName) : Plant(theName) {}

void Tree::grow() const {
    std::cout << "The tree grows tall." << std::endl;
}

} // namespace OliverCarleton

int main() {
    OliverCarleton::Flower myFlower("Daisy");
    OliverCarleton::Tree myTree("Oak");

    std::cout << "My flower's name is " << myFlower.getName() << std::endl;
    myFlower.grow();

    std::cout << "My tree's name is " << myTree.getName() << std::endl;
    myTree.grow();

    return 0;
}

