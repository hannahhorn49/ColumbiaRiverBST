#include "BST_tree.hpp"
#include <iostream>
#include <iomanip>

// for our node constructor do we want to pass in a name to it (tributary, dam)
Node::Node(std::string name)
{
    name = name;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::~Node()
{
    if (left != nullptr)
    {
        delete left;
        left = nullptr;
    }
    if (right != nullptr)
    {
        delete right;
        right = nullptr;
    }
}

BST_class::BST_class()
{
    mouth = nullptr;
}

BST_class::~BST_class()
{
    if (mouth != nullptr)
    {
        delete mouth;
        mouth = nullptr;
    }
}

void BST_class::insert_node()
{
    // this is the main function that kicks off adding any kind of node
    // 1. prompt the user: "What kind of node do you want to insert? (branch / tributary / dam)"
    // 2. get the input string
    // 3. call make_node(input_string)
}

void BST_class::make_node(std::string class_pick)
{
    // takes the user input and decides which function to call
    if (class_pick == "branch")
    {
        make_branch();
    }
    else if (class_pick == "tributary")
    {
        make_tributary();
    }
    else if (class_pick == "dam")
    {
        make_dam();
    }
    else
    {
        std::cout << "Unknown type.\n";
    }
}

void BST_class::make_branch()
{
    // call insert_branch(node)
}

void BST_class::make_dam()
{
    // 1. ask user: "Enter name for dam:"
    // 2. also ask: "Enter tempWater, fish_passage rating, and dam height:"
    // 3. get data
    // 4. call insert_dam(mouth, name)
}

void BST_class::make_tributary()
{
    // 1. ask user: "Enter name for tributary:"
    // 2. also ask: "Enter tributary's length, basin size, and avg water discharge:"
    // 3. get data
    // 4. call insert_tributary(mouth, name)
}

void BST_class::insert_branch(Node *&node)
{
    // if node == nullptr -> create new branch node here
    // else we need to traverse??
    // how do we figure out where a branch gets inserted
}

void BST_class::insert_tributary(Node *&node, std::string name)
{
    // if node == nullptr -> create new tributary node
    // else need to recurse left or right??
}

void BST_class::insert_dam(Node *&node, std::string name)
{
    // if node == nullptr -> create new dam node
    // else need to recurse left or right??
}

void BST_class::print_tree()
{
    print_tree(mouth, 0); // this is what the user would call
}

void BST::print_tree(Node *node, int space)
{
    // note: might need to change implementation, recursive print
    if (node == nullptr)
    {
        return;
    }
    space += 5;
    print_tree(node->right, space);
    std::cout << std::endl;
    for (int i = 5; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << " /" << std::setw(2) << " " << "Right: " << std::setw(14) << node->right << " |" << std::endl;
    for (int i = 5; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << "|" << std::setw(3) << node->data << " at " << std::setw(17) << node << " |" << std::endl;
    for (int i = 5; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << " \\" << std::setw(2) << " " << "Left : " << std::setw(14) << node->left << " |" << std::endl;
    print_tree(node->left, space);
}

void BST_class::store_in_file()
{
    // open a file that we will write to (output file)
    // prob need to recursively traverse the tree
    // at each node, need to write its type and any associated data
}
