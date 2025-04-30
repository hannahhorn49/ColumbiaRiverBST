#ifndef BST_Tree_HPP
#define BST_Tree_HPP

#include <string> // needed for std::string name
#include "Node.hpp"

class BST_class // this class represents the actual binary search tree (river system)
{
public:
    BST_class();
    ~BST_class();

    void insert_node(std::string type, std::string name);

    // tree operations here
    void insert_branch(Node *&node, std::string name);    // insert a branch node specifically
    void insert_dam(Node *&node, std::string name);       // insert a dam
    void insert_tributary(Node *&node, std::string name); // insert a tributary

    void print_tree();                  // prints the river system visually
    Node *get_mouth() { return mouth; } // for testing

    // somehow puts it in a workable file
    void store_in_file();

private:
    Node *mouth;                            // river's starting point (aka the root)
    void print_tree(Node *node, int space); // recursive helper to print the tree
    void destroy_tree(Node *node);
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
    Node *current_location; // pointer to where the user is in the river
    // function to update the current location
    void print_node_info(Node *node);
};

#endif