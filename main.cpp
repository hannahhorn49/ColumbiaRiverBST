#include <iostream>
#include "BST_Tree.hpp"

int main()
{
    std::cout << "Testing if the tree with full data is loaded...\n";
    BST_class river;

    // need an initial branch to build upon
    river.insert_branch("Columbia River");

    river.loadDamData("Dams.csv");
    river.loadTribData("Tributaries.csv");

    river.print_tree();

    // BST_program program; // Create an instance of your interface class
    // program.showMenu();  // Start the user interaction loop
    return 0;
}