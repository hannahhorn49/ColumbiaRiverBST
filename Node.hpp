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

    virtual std::string getInfo() const
    {
        return getName() + " (" + getType() + ")";
    }

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

    // this will override the getInfo method in node class (right function called based on object type)
    virtual std::string getInfo() const override
    {
        return "Dam: " + getName() + " | Height: " + std::to_string(height) +
               " | Capacity: " + std::to_string(capacity) +
               " | Flow: " + std::to_string(tempWater);
    }

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

    // this will override the getInfo method in node class (right function called based on object type)
    virtual std::string getInfo() const override
    {
        return "Tributary: " + getName() + " | Length: " + std::to_string(length) +
               " | Area: " + std::to_string(basinSize) +
               " | Avg Flow: " + std::to_string(averageDischarge);
    }

    double getLength() const;
    double getBasinSize() const;
    double getAverageDischarge() const;
};

#endif