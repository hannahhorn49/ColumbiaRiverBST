#include "BST_tree.hpp"
#include <iostream>
#include <iomanip>

// this is our constructor that will create a classic_Node, tributaray or dam struct based on type parameter
Node::Node(std::string name, std::string type)
{
    this->data = new classic_Node(name);
    this->type = type;
}

// implement getters here
Node *&Node::goLeft()
{
    return data->left;
}

Node *&Node::goRight()
{
    return data->right;
}

Node *&Node::getParent()
{
    return data->parent;
}

void Node::setParent(Node *ptr)
{
    data->parent = ptr;
}

// NOTE: I think we need to fix this here
Node::~Node()
{
    if (data)
    {
        delete data;
        data = nullptr;
    }
}

BST_class::BST_class()
{
    mouth = nullptr;
}

// this looks like it only deletes one node -- not the whole tree
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

void BST_class::insert_node(std::string type, std::string name)
{
    // based on the type string (call insert branch, insert dam or tributary)
    if (type == "branch")
    {
        insert_branch(mouth, name);
    }
    else if (type == "tributary")
    {
        insert_tributary(mouth, name);
    }
    else if (type == "dam")
    {
        insert_dam(mouth, name);
    }
    else
    {
        std::cout << "Unknown node type.\n";
    }
}

void BST_class::insert_branch(Node *&node, std::string name)
{
    // if node == nullptr, make new node with type branch?
    // otherwise keep going left

    if (node == nullptr)
    {
        node = new Node(name, "branch");
        return;
    }
    insert_branch(node->goLeft(), name); // we want to recurse down the left
    // creates the left heavy backbone --> represents the river
}

void BST_class::insert_tributary(Node *&node, std::string name)
{
    // always goes to the right child of the branch node
    if (node == nullptr)
    {
        std::cout << "Cannot insert tributary: no branch to attach to.\n";
        return;
    }

    if (node->goRight() == nullptr)
    {
        node->goRight() = new Node(name, "tributary");
        node->goRight()->getParent() = node;
    }
    else
    {
        insert_tributary(node->goLeft(), name); // recurse to find next branch
        // basically want to try and insert a tributary on the right of the first avilable branch node
        // if the current node's right child is full, recurse left to next branch
    }
}

void BST_class::insert_dam(Node *&node, std::string name)
{
    // traverse and insert on the left or under an existing branch node
    if (node == nullptr)
    {
        std::cout << "Cannot insert dam: no node found.\n";
        return;
    }

    if (node->goLeft() == nullptr)
    {
        node->goLeft() = new Node(name, "dam");
        node->goLeft()->getParent() = node;
    }
    else
    {
        insert_dam(node->goLeft(), name); // keep going down the left
        // same logic as branches
    }
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
