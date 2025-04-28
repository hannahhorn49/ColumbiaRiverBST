#ifndef BST_TREE_HPP
#define BST_TREE_HPP

class Node {
private:
    struct classic_Node 
    {
        std::string name;
        Node* left;
        Node* right;
        Node* parent;

    };
    struct Tributary : public classic_Node {
        double length;
        double basin_size;
        double average_water_discharge;
    };
    //struct Branch : public classic_Node {
        
    //};
    struct Dam : public classic_Node {
        double tempWater;
        int fish_passage;
        double height;
    };

    public: 
        Node(int val);
        ~Node();
    
};

//might create three different classes for Branch Node, Dam Node, Tributary
//structu would not be a bad idea 


class BST_class {
public:
    BST_class();
    ~BST_class();


    void insert_node(); //should these take anything in??
    void insert_branch();
    void insert_dam();

    void make_branch();
    void make_tributary();
    void make_dam();

    // calls make node and insert node

    //COULD ALSO DO THIS::
    void make_node(std::string class_pick);

    void print_tree();
    Node *get_root(){return mouth;} //for testing
    //instantiate a get_mouth

    //somehow puts it in a workable file
    void store_in_file();


private:
    Node* mouth;

    void insert_node(Node*& node);
    void insert_tributary(Node*& node, std::string name);
    void insert_dam(Node*& node, std::string name);
    void print_tree(Node* node, int space);
};

class BST_program {

    public: 
        void print_tree();
        void insert_node(int val);
        void get_info(); //prints info in table like fashion
        void explore_river(std::string direction);

        //should these be the same? as the class features?
        void insert_node(); //should these take anything in??
        void insert_branch();
        void insert_dam();

        void make_branch();
        void make_tributary();
        void make_dam();

    private:
        void get_info(Node* node);
        
        
        void print_tree(Node* node, int space);
        
        void insert_node(Node*& node);
        void insert_tributary(Node*& node, std::string name);
        void insert_dam(Node*& node, std::string name);

        void explore_river(Node *node, std::string direction);
}

#endif