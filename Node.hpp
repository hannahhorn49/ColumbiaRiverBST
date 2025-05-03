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

    Node *&goLeft() { return left; }
    Node *&goRight() { return right; }
    Node *&getParent();

    std::string getName() const;
    std::string getType() const;

    void setLeft(Node *newLeft) { left = newLeft; }
    void setRight(Node *newRight) { right = newRight; }
    void setParent(Node *newParent) { parent = newParent; }

    // we should use a virtual destructor here
    // (correct destructor for derived class is called when object is deleted through a base class pointer)
    virtual ~Node();
};

class Dam : public Node
{
private:
    int year_completed;
    int capacity;
    int height;
    std::string reservoir_formed;

public:
    Dam(const std::string &name, int height, int capacity, int year_completed, std::string reservoir_formed);

    // this will override the getInfo method in node class (right function called based on object type)
    virtual std::string getInfo() const override
    {
        return "Dam: " + getName() + " | Height: " + std::to_string(height) +
               " | Capacity: " + std::to_string(capacity) +
               " | Year Completed: " + std::to_string(year_completed) +
               " | Reservoir Formed: " + reservoir_formed;
    }

    int getCapacity() const;
    int getHeight() const;
    int getYear() const;
    std::string getReservoir() const;
};

class Tributary : public Node
{
private:
    int length;
    double basinSize;
    double averageDischarge;
    std::string direction;

public:
    Tributary(const std::string &name, std::string direction, int length, double basinSize, double averageDischarge);

    // this will override the getInfo method in node class (right function called based on object type)
    virtual std::string getInfo() const override
    {
        return "Tributary: " + getName() + " | Direction: " + direction +
               " | Length: " + std::to_string(length) +
               " | Basin Size: " + std::to_string(basinSize) +
               " | Avg Discharge: " + std::to_string(averageDischarge);
    }

    int getLength() const;
    double getBasinSize() const;
    double getAverageDischarge() const;
    std::string getDirection() const;
};

#endif