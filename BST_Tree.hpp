#ifndef BST_TREE_HPP
#define BST_TREE_HPP

#include <string> // needed for std::string name

class Node // represents each individual "thing" in river (e.g. branch, tributary, dam)
{
private:
    struct classic_Node // will be our basic node
    {
        std::string name;
        Node *left;
        Node *right;
        Node *parent;
    };
    struct Tributary : public classic_Node // inherits from classic node
    {
        double length;
        double basin_size;
        double average_water_discharge;
    };

    struct Dam : public classic_Node // also inherits from classic node
    {
        double tempWater;
        int fish_passage;
        double height;
    };

public:
    Node(std::string name);
    ~Node();
};

// might create three different classes for Branch Node, Dam Node, Tributary
// struct would not be a bad idea

class BST_class // this class represents the actual binary search tree (river system)
{
public:
    BST_class();
    ~BST_class();

    void insert_node();                     // will call make_node() to create new node based on type?
    void make_node(std::string class_pick); // decided which kind of node to make

    void make_branch();    // prompt user for branch data
    void make_tributary(); // prompt user for tributary data
    void make_dam();       // prompt user for dam data

    void insert_branch(Node *&node);                      // insert a branch node specifically
    void insert_dam(Node *&node, std::string name);       // insert a dam
    void insert_tributary(Node *&node, std::string name); // insert a tributary

    void print_tree();                  // prints the river system visually
    Node *get_mouth() { return mouth; } // for testing

    // somehow puts it in a workable file
    void store_in_file();

private:
    Node *mouth;                            // river's starting point (aka the root)
    void print_tree(Node *node, int space); // recursive helper to print the tree
};

// class BST_program
// {

// public:
//     void print_tree();
//     void insert_node(int val);
//     void get_info(); // prints info in table like fashion
//     void explore_river(std::string direction);

//     // should these be the same? as the class features?
//     void insert_node(); // should these take anything in??
//     void insert_branch();
//     void insert_dam();

//     void make_branch();
//     void make_tributary();
//     void make_dam();

// private:
//     void get_info(Node *node);

//     void print_tree(Node *node, int space);

//     void insert_node(Node *&node);
//     void insert_tributary(Node *&node, std::string name);
//     void insert_dam(Node *&node, std::string name);

//     void explore_river(Node *node, std::string direction);
// };

#endif