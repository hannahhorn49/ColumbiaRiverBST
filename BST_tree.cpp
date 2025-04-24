#include "BST_tree.hpp"
#include <iostream>
#include <iomanip>
// #include <algorithm>

Node::Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
}

Node::~Node() {
    if (left != nullptr){
        delete left;
        left = nullptr;
    }
    if (right != nullptr){
        delete right;
        right = nullptr;
    }
}

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    if (root != nullptr) {
        delete root;
        root = nullptr;
    }
}

void BST::insert(int val) {
    insert(root, val);
}

bool BST::search(int val) {
    return search(root, val);
}

void BST::print_tree() {
    print_tree(root, 0);
}

void BST::insert(Node*& node, int val) { //passing the Node by reference (not modifying pointer itself unless the root)
    //two cases: empty tree and non empty tree 
    //empty tree case 
    if (node == nullptr) {
        //place that we are at does not exist (because node is root)
        Node* new_node = new Node(val);
        node = new_node;
        return;
    }
    //case where there is a value
    else if (val < node->data){
        insert(node->left, val); //no need to check if there is something in that spot 
    }
    else{
        //if entering here: value is greater 
        insert(node->right, val);

    }
    
    
    return;
}

bool BST::search(Node* node, int val) {
    if(node == nullptr)
    {
        //indicates that it is not in the tree 
        return false;
    }
    else if (node->data == val)
    {
        return true;
    }
    else if (node->data > val)
    {
        return search(node->left, val);
    }
    else
    {
        return search(node->right, val);
    }

}

void BST::print_tree(Node* node, int space) {
    if (node == nullptr) {
        return;
    }
    space += 5;
    print_tree(node->right, space);
    std::cout << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << " /"<< std::setw(2)<< " " << "Right: " << std::setw(14) << node->right << " |" << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << "|" << std::setw(3) << node->data << " at " << std::setw(17) << node << " |" << std::endl;
     for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << " \\"<< std::setw(2)<< " " << "Left : " << std::setw(14) << node->left << " |" << std::endl;
    print_tree(node->left, space);
}

