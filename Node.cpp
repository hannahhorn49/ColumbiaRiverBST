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

Dam::Dam(const std::string &name, int height, int capacity, int year_completed, std::string reservoir_formed)
    : Node(name, "Dam")
{
    this->year_completed = year_completed;
    this->reservoir_formed = reservoir_formed;
    this->capacity = capacity;
    this->height = height;
}

// accessor methods for Dam-specific attributes
int Dam::getCapacity() const
{
    return capacity;
}

int Dam::getHeight() const
{
    return height;
}

int Dam::getYear() const
{
    return year_completed;
}

std::string Dam::getReservoir() const
{
    return reservoir_formed;
}

Tributary::Tributary(const std::string &name, std::string direction, int length, double basinSize, double averageDischarge)
    : Node(name, "Tributary") // initialize base class first
{
    this->direction = direction;
    this->length = length;
    this->basinSize = basinSize;
    this->averageDischarge = averageDischarge;
}

// Accessor methods for Tributary-specific attributes
int Tributary::getLength() const
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

std::string Tributary::getDirection() const
{
    return direction;
}