#include "BST_Tree.hpp"
#include <iostream>

bool testInsertMouth()
{
    // should we test inserting mouth of the river as the root?

    // set up
    BST_class river;

    // execution (add a single node)
    river.insert_node();

    // validation
    Node *mouth = river.get_mouth();
    if (mouth == nullptr)
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
    river.insert_node(); // insert the "root" first
    Node *mouth = river.get_mouth();
    river.insert_tributary(mouth, "Tributary1");

    // validation

    // clean up
    return true;
}

bool testInsertDam()
{
    // testing adding a dam to the river
    // set up

    // execution

    // validation

    // clean up
}

bool testTraverseExplore()
{
    // somehow we need to test navigating through the river system
    // should we try all direction? e.g. going up, down, right, left

    // set up

    // execution

    // validation

    // clean up
}

// for testing printing, I'm not sure how we would validate it besides manually checking
// but it seems like something we should test?

bool testGetInfo()
{
    // test getting info from different node types -- dam and tributary
    // set up

    // execution

    // validation

    // clean up
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
