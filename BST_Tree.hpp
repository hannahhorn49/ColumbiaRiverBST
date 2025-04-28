#ifndef BST_TREE_HPP
#define BST_TREE_HPP

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val);
    ~Node();

};

//might create three different classes for Branch Node, Dam Node, Tributary
//structu would not be a bad idea 


class BST {
public:
    BST();
    ~BST();
    void insert(int val);

    void make_node(std::string class_pick);

    void print_tree();
    Node *get_root(){return root;} //for testing
    
    

private:
    Node* root;
    void insert(Node*& node, int val);



    void print_tree(Node* node, int space);
};

#endif