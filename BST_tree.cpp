#include "BST_Tree.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

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

void BST_class::insert_dam(const std::string name, int height, int capacity, int year_completed, std::string reservoir_formed)
{
    recursive_dam_insert(mouth, name, height, capacity, year_completed, reservoir_formed);
}

void BST_class::insert_tributary(std::string name, std::string direction, int length, double basinSize, double averageDischarge)
{
    recursive_trib_insert(mouth, name, direction, length, basinSize, averageDischarge);
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

void BST_class::recursive_dam_insert(Node *&node, std::string name, int height, int capacity, int year_completed, std::string reservoir_formed)
{
    if (node == nullptr)
    {
        std::cout << "Cannot insert dam: no node found.\n";
        return;
    }

    // if the left child is null, insert the new dam here
    if (node->goLeft() == nullptr)
    {
        node->goLeft() = new Dam(name, height, capacity, year_completed, reservoir_formed);
        node->goLeft()->getParent() = node;
    }
    else
    {
        // recursive part, if there's already a node in the left position
        recursive_dam_insert(node->goLeft(), name, height, capacity, year_completed, reservoir_formed);
    }
}

bool BST_class::recursive_trib_insert(Node *&node, const std::string name, std::string direction, int length, double basinSize, double averageDischarge)
{
    if (node == nullptr)
        return false;

    // check if this node is a branch and has space for a tributary
    if (node->getType() == "branch" && node->goRight() == nullptr)
    {
        std::cout<< name << std::endl;
        node->goRight() = new Tributary(name, direction, length, basinSize, averageDischarge);
        node->goRight()->getParent() = node;
        return true;
    }

    // want to try left subtree first
    if (recursive_trib_insert(node->goLeft(), name, direction, length, basinSize, averageDischarge))
        return true;

    // then try right subtree
    return recursive_trib_insert(node->goRight(), name, direction, length, basinSize, averageDischarge);
}

void BST_class::loadDamData(const std::string &filename)
{
    std::ifstream file(filename); // opens file passed in
    std::string line;             // stores each line read from file

    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::getline(file, line); // don't need to read the header row

    while (std::getline(file, line)) // loop through each row in the table
    {
        std::stringstream ss(line);
        std::string name, reservoir;
        std::string heightStr, capacityStr, yearCompletedStr;
        int height = 0, capacity = 0, year_completed = 0;

        // actually values from CSV
        std::getline(ss, name, ',');
        std::getline(ss, heightStr, ',');
        height = (heightStr == "NA") ? 0 : std::stoi(heightStr);

        std::getline(ss, capacityStr, ',');
        capacity = (capacityStr == "NA") ? 0 : std::stoi(capacityStr);

        std::getline(ss, yearCompletedStr, ',');
        year_completed = (yearCompletedStr == "NA") ? 0 : std::stoi(yearCompletedStr);

        std::getline(ss, reservoir, ',');
        if (reservoir == "NA")
            reservoir = "Unknown";

        insert_dam(name, height, capacity, year_completed, reservoir); // insert into tree
    }

    file.close();
}

void BST_class::loadTribData(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::getline(file, line); // don't need to read the header row

    while (std::getline(file, line)) // loop through each data row
    {
        std::stringstream ss(line);
        std::string name, direction;
        std::string lengthStr, basinSizeStr, avgDischargeStr;
        int length = 0;
        double basinSize = 0.0, average_discharge = 0.0;

        // actually read values from CSV
        std::getline(ss, name, ',');
        std::getline(ss, direction, ',');

        std::getline(ss, lengthStr, ',');
        length = (lengthStr == "NA") ? 0 : std::stoi(lengthStr);

        std::getline(ss, basinSizeStr, ',');
        basinSize = (basinSizeStr == "NA") ? 0.0 : std::stod(basinSizeStr);

        std::getline(ss, avgDischargeStr, ',');
        average_discharge = (avgDischargeStr == "NA") ? 0.0 : std::stod(avgDischargeStr);

        insert_tributary(name, direction, length, basinSize, average_discharge); // insert into tree
    }

    file.close();
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

// sotre_in_file helper function
void BST_class::store_node(std::ofstream &out, Node *node){
    if (!node){
        return;
    }

    // Writes the length of the string and then writes it into characters
    std::string nodeType = node->getType();
    size_t typeLength = nodeType.length();
    out.write(reinterpret_cast<const char *>(&typeLength), sizeof(typeLength));
    out.write(nodeType.c_str(), typeLength);

    // Same but with the name
    std::string nodeName = node->getName();
    size_t nameLength = nodeType.length();
    out.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
    out.write(nodeName.c_str(), nameLength);

    // Stores tributary specific data
    if (nodeType == "Tributary"){
        Tributary *tri = dynamic_cast<Tributary *>(node);
        int length = tri->getLength();
        double basin = tri->getBasinSize();
        double discharge = tri->getAverageDischarge();
        std::string direction = tri->getDirection();
        out.write(reinterpret_cast<const char *>(&length), sizeof(length));
        out.write(reinterpret_cast<const char *>(&basin), sizeof(basin));
        out.write(reinterpret_cast<const char *>(&discharge), sizeof(discharge));
        size_t directionLength = direction.length();
        out.write(reinterpret_cast<const char *>(&directionLength), sizeof(directionLength));
        out.write(direction.c_str(), directionLength);
    }

    // Stores dam specific data
    else if(nodeType == "Dam"){
        Dam *dam = dynamic_cast<Dam *>(node);
        int capacity = dam->getCapacity();
        double height = dam->getHeight();
        double year = dam->getYear();
        std::string resevoir = dam->getReservoir();
        out.write(reinterpret_cast<const char *>(&capacity), sizeof(capacity));
        out.write(reinterpret_cast<const char *>(&height), sizeof(height));
        out.write(reinterpret_cast<const char *>(&year), sizeof(year));
        size_t resevoirLength = resevoir.length();
        out.write(reinterpret_cast<const char *>(&resevoirLength), sizeof(resevoirLength));
        out.write(resevoir.c_str(), resevoirLength);
    }
    store_node(out,node->goLeft());
    store_node(out,node->goRight());
}

void BST_class::store_in_file()
{
    std::ofstream out("river_system.bin", std::ios::binary);
    store_node(out,mouth);
    out.close();
}

void BST_program::loadDamData(const std::string &filename)
{
    river.loadDamData(filename);
}

void BST_program::loadTribData(const std::string &filename)
{
    river.loadTribData(filename);
}

void BST_program::setupRiver()
{
    river.insert_branch("Columbia River");
    loadDamData("Dams.csv");
    loadTribData("Tributaries.csv");
    river.print_tree();
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
    std::string reservoir_formed;
    std::string direction;
    // attributes for dam and tributaries
    int capacity, height, year_completed;
    double length, basinSize, averageDischarge;

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
        std::cout << "Enter the year completed: ";
        std::cin >> year_completed;
        std::cout << "Enter the reservoir formed: ";
        std::cin >> reservoir_formed;
        std::cout << "Enter the dams capacity: ";
        std::cin >> capacity;
        std::cout << "Enter the dam height: ";
        std::cin >> height;
        river.insert_dam(name, height, capacity, year_completed, reservoir_formed);
        break;
    case 3:
        std::cout << "Enter the direction of the tributary: ";
        std::cin >> direction;
        std::cout << "Enter the tributary length: ";
        std::cin >> length;
        std::cout << "Enter the basin size: ";
        std::cin >> basinSize;
        std::cout << "Enter the avg discharge: ";
        std::cin >> averageDischarge;
        river.insert_tributary(name, direction, length, basinSize, averageDischarge);
        break;
    default:
        std::cout << "Invalid node type.\n";
    }
}

void BST_program::explore_river()
{
    // calls the helper function starting at the mouth of the river
    Node *start = river.get_mouth();
    // check to make sure there is a "river" to explore
    if (start == nullptr)
    {
        std::cout << "The river is currently empty. Please add a node first to be able to explore.\n";
        return;
    }

    explore_river(start);
}

void BST_program::explore_river(Node *node)
{
    std::string choiceExplore;

    while (true) // keeps user in explore mode until they choose to exit
    {
        std::cout << "Let us explore the river!" << std::endl;
        std::cout << "Please pick an option below that describes what you would like to do: " << std::endl;
        std::cout << "You are currently at: " << node->getName() << std::endl;

        if (node->goLeft() != nullptr)
        {
            std::cout << "L) You can go left to: " << node->goLeft()->getName() << "\n";
        }
        if (node->goRight() != nullptr)
        {
            std::cout << "R) You can go right to: " << node->goRight()->getName() << "\n";
        }
        if (node->getParent() != nullptr)
        {
            std::cout << "B) You can go backwards to: " << node->getParent()->getName() << "\n";
        }

        std::cout << "I) Find out more about this location\n";
        std::cout << "E) Exit to Main Menu\n";
        std::cout << "====================================\n";
        std::cout << "Your choice: ";
        std::cin >> choiceExplore;

        if (choiceExplore == "L" || choiceExplore == "l")
        {
            if (node->goLeft() != nullptr)
                node = node->goLeft();
            else
                std::cout << "No left path from here.\n";
        }
        else if (choiceExplore == "R" || choiceExplore == "r")
        {
            if (node->goRight() != nullptr)
                node = node->goRight();
            else
                std::cout << "No right path from here.\n";
        }
        else if (choiceExplore == "B" || choiceExplore == "b")
        {
            if (node->getParent() != nullptr)
                node = node->getParent();
            else
                std::cout << "No parent node to go back to.\n";
        }
        else if ((choiceExplore == "I" || choiceExplore == "i"))
        {
            print_node_info(node);
        }
        else if (choiceExplore == "E" || choiceExplore == "e")
        {
            break; // exit explore loop and return to menu
        }
        else
        {
            std::cout << "Invalid option. Please try again.\n";
        }

        std::cout << std::endl; // space before next loop
    }

    showMenu(); // return to menu after exit
}

void BST_program::print_node_info(Node *node)
{
    std::cout << "--------------------------------Selected Node Information: ----------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << node->getInfo() << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
}

void BST_program::print_river()
{
    std::cout << "\n========= The Columbia River System =========\n";
    river.print_tree();
    std::cout << "=============================================\n";
}
