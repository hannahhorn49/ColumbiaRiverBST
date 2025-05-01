#include "BST_Tree.hpp"
#include <iostream>
#include <iomanip>

BST_class::BST_class()
{
    mouth = nullptr;
}

BST_class::~BST_class()
{
    destroy_tree(mouth); // recursively deletes tree
    mouth = nullptr;
}

// recursive helper here
void BST_class::destroy_tree(Node *node)
{
    if (node == nullptr)
        return;

    destroy_tree(node->goLeft());
    destroy_tree(node->goRight());

    delete node;
}

void BST_class::insert_branch(const std::string &name)
{
    recursive_branch_insert(mouth, name);
}

void BST_class::insert_dam(std::string name, double tempWater, int capacity, double height)
{
    recursive_dam_insert(mouth, name, tempWater, capacity, height);
}

void BST_class::insert_tributary(std::string name, double length, double basinSize, double discharge)
{
    recursive_trib_insert(mouth, name, length, basinSize, discharge);
}

void BST_class::recursive_branch_insert(Node *&node, std::string name)
{
    if (node == nullptr)
    {
        node = new Node(name, "branch");
        return;
    }
    recursive_branch_insert(node->goLeft(), name); // recurse down the left
}

void BST_class::recursive_dam_insert(Node *&node, const std::string name, double tempWater, int capacity, double height)
{
    if (node == nullptr)
    {
        std::cout << "Cannot insert dam: no node found.\n";
        return;
    }

    // if the left child is null, insert the new dam here
    if (node->goLeft() == nullptr)
    {
        node->goLeft() = new Dam(name, tempWater, capacity, height);
        node->goLeft()->getParent() = node;
    }
    else
    {
        // recursive part, if there's already a node in the left position
        recursive_dam_insert(node->goLeft(), name, tempWater, capacity, height);
    }
}

void BST_class::recursive_trib_insert(Node *&node, const std::string name, double length, double basinSize, double discharge)
{
    if (node == nullptr)
    {
        std::cout << "Cannot insert tributary: no branch to attach to.\n";
        return;
    }

    if (node->getType() == "branch" && node->goRight() == nullptr)
    {
        node->goRight() = new Tributary(name, length, basinSize, discharge);
        node->goRight()->getParent() = node;
    }
    else
    {
        recursive_trib_insert(node->goLeft(), name, length, basinSize, discharge);
    }
}

void BST_class::print_tree()
{
    print_tree(mouth, 0); // this is what the user would call
}

void BST_class::print_tree(Node *node, int space)
{
    // want a constant horizontal spacing between levels
    const int INDENT = 7;
    // note: might need to change implementation, recursive print
    if (node == nullptr)
    {
        return;
    }

    space += INDENT;

    // a way we could print it out is tributaries processed first (so printed higher than the node they are a child of?)
    // can def change later
    print_tree(node->goRight(), space);

    // then print the current node (first pass would be root)
    std::cout << std::endl;
    for (int i = INDENT; i < space; i++)
    {
        std::cout << " ";
    }

    std::cout << node->getInfo() << std::endl;

    // then process left child
    print_tree(node->goLeft(), space);
}

void BST_class::store_in_file()
{
    // open a file that we will write to (output file)
    // prob need to recursively traverse the tree
    // at each node, need to write its type and any associated data
    // prob need a helper function for this??
}

void BST_program::showMenu()
{
    // display the menu (do while loop?)
    // can do a switch case block here?

    int choice;

    do
    {
        std::cout << "\n------Welcome to the Columbia River!!------\n";
        std::cout << "1. Add a node (e.g. branch, dam, tributary)\n";
        std::cout << "2. Explore the river\n";
        std::cout << "3. Print out the river\n";
        std::cout << "4. Exit\n";
        std::cout << "Please choose an option (1-4): ";
        std::cin >> choice; // store the user input in choice

        switch (choice)
        {
        case 1:
            add_node();
            break;
        case 2:
            explore_river();
            break;
        case 3:
            print_river();
            break;
        case 4:
            std::cout << "You have chosen to exit the program. Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 4);
}

void BST_program::add_node()
{
    // prompts user for type and name, then call correct insert function
    int nodeType;
    std::string name;
    // attributes for dam and tributaries
    int capacity;
    double tempWater, height, length, basinSize, averageDischarge;

    std::cout << "\nSelect the type of node you would like to add:\n";
    std::cout << "1. Branch\n";
    std::cout << "2. Dam\n";
    std::cout << "3. Tributary\n";
    std::cout << "Please choose an option (1-3): ";
    std::cin >> nodeType;

    std::cout << "Enter the name of the node: ";
    std::cin.ignore(); // clears input buffer
    std::getline(std::cin, name);

    switch (nodeType)
    {
    case 1:
        river.insert_branch(name);
        break;
    case 2:
        std::cout << "Enter the water temperature: ";
        std::cin >> tempWater;
        std::cout << "Enter the dams capacity: ";
        std::cin >> capacity;
        std::cout << "Enter the dam height: ";
        std::cin >> height;
        river.insert_dam(name, tempWater, capacity, height);
        break;
    case 3:
        std::cout << "Enter the tributary length: ";
        std::cin >> length;
        std::cout << "Enter the basin size: ";
        std::cin >> basinSize;
        std::cout << "Enter the avg discharge: ";
        std::cin >> averageDischarge;
        river.insert_tributary(name, length, basinSize, averageDischarge);
        break;
    default:
        std::cout << "Invalid node type.\n";
    }
}

void BST_program::explore_river()
{
    // navigate
}

void BST_program::print_river()
{
    // call print tree function here?
}
