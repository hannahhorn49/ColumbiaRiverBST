#ifndef BST_Tree_HPP
#define BST_Tree_HPP

#include <string> // needed for std::string name
#include "Node.hpp"

class BST_class // this class represents the actual binary search tree (river system)
{
public:
    BST_class();
    ~BST_class();

    // tree operations here (simplified for public use)
    void insert_branch(const std::string &name);
    void insert_dam(const std::string name, int height, int capacity, int year_completed, std::string reservoir_formed);
    void insert_tributary(const std::string name, std::string direction, int length, double basinSize, double averageDischarge);

    void print_tree();                  // prints the river system visually
    Node *get_mouth() { return mouth; } // for testing

    // somehow puts it in a workable file
    void store_in_file();

    // function to load trib and dam data from our csv files
    void loadDamData(const std::string &filename);
    void loadTribData(const std::string &filename);

private:
    Node *mouth;                            // river's starting point (aka the root)
    void print_tree(Node *node, int space); // recursive helper to print the tree
    void destroy_tree(Node *node);

    // recursive insert helpers
    void recursive_branch_insert(Node *&node, std::string name);
    void recursive_dam_insert(Node *&node, std::string name, int height, int capacity, int year_completed, std::string reservoir_formed);
    bool recursive_trib_insert(Node *&node, const std::string name, std::string direction, int length, double basinSize, double averageDischarge);
};

class BST_program
{

public:
    void showMenu(); // this shows user the main menu (e.g. add node, explore river, print, exit)

    void add_node(); // will prompt user for a node type (branch, dam, tributary) + any extra info
    // this calls bst.insert_node(type, name)
    void explore_river(); // display options "go up/down/right/view info"
    // this will be based on direction
    void print_river();

private:
    Node *current_location; // pointer to where the user is in the river //DO NOT KNOW if we need this if we jsut keep updating node 
    // function to update the current location
    BST_class river;
    void print_node_info(Node *node); 
    void explore_river(Node *node);
};

#endif