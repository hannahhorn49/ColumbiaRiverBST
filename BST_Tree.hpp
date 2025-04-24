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

class BST {
public:
    BST();
    ~BST();
    void insert(int val);
    bool search(int val);
    void in_order_traversal();
    void pre_order_traversal();
    void post_order_traversal();
    void print_tree();
    Node *get_root(){return root;} //for testing 

private:
    Node* root;
    void insert(Node*& node, int val);
    bool search(Node* node, int val);
    void in_order_traversal(Node* node);
    void pre_order_traversal(Node* node);
    void post_order_traversal(Node* node);

    void print_tree(Node* node, int space);
};

#endif