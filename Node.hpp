#ifndef NODE_HPP
#define NODE_HPP

#include <string> // needed for std::string name

class Node
{
private:
    std::string name;
    Node *left;
    Node *right;
    Node *parent;
    std::string type;

public:
    Node(const std::string &name, const std::string &type);

    Node *&goLeft();
    Node *&goRight();
    Node *&getParent();

    std::string getName() const;
    std::string getType() const;

    // we should use a virtual destructor here
    // (correct destructor for derived class is called when object is deleted through a base class pointer)
    virtual ~Node();
};

class Dam : public Node
{
private:
    double tempWater;
    int capacity;
    double height;

public:
    Dam(const std::string &name, double tempWater, int capacity, double height);

    double getTempWater() const;
    int getCapacity() const;
    double getHeight() const;
};

class Tributary : public Node
{
private:
    double length;
    double basinSize;
    double averageDischarge;

public:
    Tributary(const std::string &name, double length, double basinSize, double discharge);

    double getLength() const;
    double getBasinSize() const;
    double getAverageDischarge() const;
};

#endif