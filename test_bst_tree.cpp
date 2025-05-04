#include "BST_Tree.hpp"
#include <iostream>
#include <fstream>

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

bool testInsertTributary()
{
    // set up
    BST_class river;

    // execution
    river.insert_branch("MainRiver");
    river.insert_tributary("Cowlitz", "right", 169, 6698, 286.6);
    river.insert_branch("Columbia River");
    river.insert_tributary("Willamette", "right", 187, 29800, 302.0);

    river.print_tree(); // optional debugging

    Node *root = river.get_mouth();  // MainRiver
    Node *cowlitz = root->goRight(); // Should be Cowlitz
    Node *columbia = root->goLeft(); // Should be Columbia River
    Node *willamette = columbia ? columbia->goRight() : nullptr;

    // validation
    if (!cowlitz || cowlitz->getName() != "Cowlitz")
    {
        std::cout << "Test failed: Cowlitz not inserted correctly.\n";
        return false;
    }

    if (!columbia || columbia->getName() != "Columbia River")
    {
        std::cout << "Test failed: Columbia River branch not inserted correctly.\n";
        return false;
    }

    if (!willamette || willamette->getName() != "Willamette")
    {
        std::cout << "Test failed: Willamette not inserted correctly.\n";
        return false;
    }

    std::cout << "Test passed: All branches and tributaries inserted correctly.\n";

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

bool testStoreInFile()
{
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
    river.store_in_file();
    std::ifstream file_to_open("river_system.bin", std::ios::binary);
    std::ofstream file_to_write("river_system.txt");
    float value;
    if (file_to_open.is_open())
    {
        while (!file_to_open.eof())
        {
            file_to_open.read((char *)&value, sizeof(float));
            file_to_write << value;
        }
    }
    // clean up

    return true;
}

// call functions here
bool testInsertMouth();
bool testInsertTributary();
bool testInsertDam();
bool testTraverseExplore();
bool testSetInfo();
bool testStoreInFile();

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
    if (testStoreInFile())
    {
        std::cout << "Storing in file passed!!\n";
    }
    else
    {
        std::cout << "Storing in file failed.\n";
    }
    return 0;
}
