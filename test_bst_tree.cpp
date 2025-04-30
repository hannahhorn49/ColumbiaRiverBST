#include "BST_Tree.hpp"
#include <iostream>

bool testInsertMouth()
{
    // should we test inserting mouth of the river as the root?

    // set up
    BST_class river;

    // execution (add a single node)
    river.insert_node("branch", "MainRiver");

    // validation
    Node *mouth = river.get_mouth();
    if (mouth == nullptr || mouth->getName() != "MainRiver" || mouth->getType() != "branch")
    {
        std::cout << "test failed, mouth not inserted.\n";
        return false;
    }

    // clean up
    return true;
}

bool testInsertTributary()
{
    // testing adding a tributary to the river
    // set up
    BST_class river;

    // execution
    river.insert_node("branch", "MainRiver"); // insert the "root" first
    river.insert_node("tributary", "Tributary1");

    Node *mouth = river.get_mouth();
    Node *trib = mouth->goRight();

    // validation
    if (trib == nullptr || trib->getName() != "Tributary1" || trib->getType() != "tributary")
    {
        std::cout << "test failed, tributary not correctly added.\n";
        return false;
    }

    // clean up
    return true;
}

bool testInsertDam()
{
    // testing adding a dam to the river
    // set up
    BST_class river;

    // execution
    river.insert_node("branch", "MainRiver");
    river.insert_node("dam", "Dam1");

    // validation
    Node *mouth = river.get_mouth();
    Node *dam = mouth->goLeft();

    if (dam == nullptr || dam->getName() != "Dam1" || dam->getType() != "dam")
    {
        std::cout << "test failed, dam not not correctly added.\n";
        return false;
    }

    // clean up
    return true;
}

bool testTraverseExplore()
{
    // somehow we need to test navigating through the river system
    // should we try all direction? e.g. going up, down, right, left

    // set up
    BST_class river;

    // execution
    river.insert_node("branch", "MainRiver");
    river.insert_node("branch", "Branch1");
    river.insert_node("dam", "Dam1");
    river.insert_node("tributary", "Trib1");

    // validation
    Node *mouth = river.get_mouth();
    Node *branch1 = mouth->goLeft(); // this will be the second "node"
    Node *dam1 = branch1->goLeft();  // the dam will be the third "node" on the left
    Node *trib1 = mouth->goRight();  // this tributary will be to the right of mouth

    if (!branch1 || branch1->getName() != "Branch1")
        return false;
    if (!dam1 || dam1->getName() != "Dam1")
        return false;
    if (!trib1 || trib1->getName() != "Trib1")
        return false;

    // clean up
    return true;
}

// for testing printing, I'm not sure how we would validate it besides manually checking
// but it seems like something we should test?

bool testGetInfo()
{
    // test getting info from different node types -- dam and tributary
    // set up
    BST_class river;

    // execution
    river.insert_node("branch", "MainRiver");
    river.insert_node("dam", "Dam1");
    river.insert_node("tributary", "Trib1");

    // validation
    Node *mouth = river.get_mouth();
    Node *dam = mouth->goLeft();
    Node *trib = mouth->goRight();

    if (dam->getType() != "dam" || trib->getType() != "tributary")
    {
        std::cout << "test failed,  Node types incorrect.\n";
        return false;
    }

    // clean up
    return true;
}

// call functions here
bool testInsertMouth();
bool testInsertTributary();
bool testInsertDam();
bool testTraverseExplore();
bool testGetInfo();

int main()
{
    std::cout << "Running River Tests..\n";

    if (testInsertMouth())
    {
        std::cout << "Inserting at Mouth Test passed!!\n";
    }
    else
    {
        std::cout << "Inserting at Mouth Test failed.\n";
    }

    if (testInsertTributary())
    {
        std::cout << "Inserting a Tributary Test passed!!\n";
    }
    else
    {
        std::cout << "Inserting a Tributary Test failed.\n";
    }

    if (testInsertDam())
    {
        std::cout << "Inserting a Dam Test passed!!\n";
    }
    else
    {
        std::cout << "Inserting a Dam Test failed.\n";
    }

    if (testTraverseExplore())
    {
        std::cout << "Traversing Tree Test passed!!\n";
    }
    else
    {
        std::cout << "Traversing Tree Test failed.\n";
    }

    if (testGetInfo())
    {
        std::cout << "Getting Info Test passed!!\n";
    }
    else
    {
        std::cout << "Getting Info Test failed.\n";
    }

    return 0;
}
