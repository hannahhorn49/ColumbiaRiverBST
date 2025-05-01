#include "Node.hpp"

// constructor implementation
Node::Node(const std::string &name, const std::string &type)
{
    this->name = name;
    this->type = type;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

// river navigation methods here
Node *&Node::goLeft()
{
    return left;
}

Node *&Node::goRight()
{
    return right;
}

Node *&Node::getParent()
{
    return parent;
}

// getters
std::string Node::getName() const
{
    return name;
}

std::string Node::getType() const
{
    return type;
}

Node::~Node()
{
    // don't think we need to do anything here since memory handled with virtual destructor?
}

Dam::Dam(const std::string &name, double temp, int cap, double h)
    : Node(name, "Dam")
{
    tempWater = temp;
    capacity = cap;
    height = h;
}

// Accessor methods for Dam-specific attributes
double Dam::getTempWater() const
{
    return tempWater;
}

int Dam::getCapacity() const
{
    return capacity;
}

double Dam::getHeight() const
{
    return height;
}

Tributary::Tributary(const std::string &name, double len, double basin, double discharge)
    : Node(name, "Tributary") // initialize base class first
{
    length = len;
    basinSize = basin;
    averageDischarge = discharge;
}

// Accessor methods for Tributary-specific attributes
double Tributary::getLength() const
{
    return length;
}

double Tributary::getBasinSize() const
{
    return basinSize;
}

double Tributary::getAverageDischarge() const
{
    return averageDischarge;
}