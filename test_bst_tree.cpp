#include "BST_Tree.hpp"
#include <iostream>

bool testInsertMouth()
{
    // should we test inserting mouth of the river as the root?

    // set up
    BST_class river;

    // execution (add a single node)
    river.insert_branch("MainRiver");

    // validation
    Node *mouth = river.get_mouth();
    if (mouth == nullptr || mouth->getName() != "MainRiver")
    {
        std::cout << "test failed, mouth not inserted.\n";
        return false;
    }

    river.print_tree(); // for debuggin purposees

    // clean up
    return true;
}

bool testInsertTributary()
{
    // testing adding a tributary to the river
    // set up
    BST_class river;

    // execution
    river.insert_branch("MainRiver");
    river.insert_tributary("Cowlitz", "right", 169, 6698, 286.6);

    Node *mouth = river.get_mouth();
    Node *trib = mouth->goRight();

    river.print_tree(); // for debuggin purposees

    // validation
    if (trib == nullptr || trib->getName() != "Cowlitz")
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
    river.insert_branch("MainRiver");
    river.insert_dam("Bonneville", 197, 1190, 1937, "Lake Bonneville");

    // validation
    Node *mouth = river.get_mouth();
    Node *dam = mouth->goLeft();

    river.print_tree(); // for debuggin purposees

    if (dam == nullptr || dam->getName() != "Bonneville")
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
    river.insert_branch("MainRiver");
    river.insert_branch("Branch1");                                   // goes left of MainRiver
    river.insert_dam("McNary", 183, 1133, 1954, "Lake Wallula");      // goes left of Branch1
    river.insert_tributary("Willamette", "Left", 301, 28949, 1098.7); // goes right of MainRiver

    // validation
    Node *mouth = river.get_mouth();
    Node *branch1 = mouth->goLeft(); // this will be the second "node"
    Node *dam1 = branch1->goLeft();  // the dam will be the third "node" on the left
    Node *trib1 = mouth->goRight();  // this tributary will be to the right of mouth

    river.print_tree(); // for debuggin purposees

    if (!branch1 || branch1->getName() != "Branch1")
        return false;
    if (!dam1 || dam1->getName() != "McNary")
        return false;
    if (!trib1 || trib1->getName() != "Willamette")
        return false;

    // clean up
    return true;
}

// for testing printing, I'm not sure how we would validate it besides manually checking
// but it seems like something we should test?

bool testSetInfo()
{
    // TO DO HERE:
    // set up
    BST_class river;

    // execution
    river.insert_branch("MainRiver");
    river.insert_dam("Priest Rapids", 178, 955, 1961, "Priest Rapids Lake");
    river.insert_tributary("Snake River", "Left", 1735, 160938, 1755.6);

    // validation
    river.print_tree();

    // clean up
    return true;
}

// call functions here
bool testInsertMouth();
bool testInsertTributary();
bool testInsertDam();
bool testTraverseExplore();
bool testSetInfo();

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

    if (testSetInfo())
    {
        std::cout << "Getting Info Test passed!!\n";
    }
    else
    {
        std::cout << "Getting Info Test failed.\n";
    }

    return 0;
}
