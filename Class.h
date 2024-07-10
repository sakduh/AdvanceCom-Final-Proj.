#ifndef CLASS_H
#define CLASS_H

#include <string>

// Class to represent a Criminal
class Criminal {
public:
    // Constructor with default values
    Criminal(const std::string& name = "Unknown", int age = 0, double height = 0.0,
             int criminalRecords = 0, const std::string& crimeType = "Unknown");

    // Accessor methods
    const std::string& getName() const;
    int getAge() const;
    double getHeight() const;
    int getCriminalRecords() const;
    const std::string& getCrimeType() const;

    // Setter methods
    void setName(const std::string& name);
    void setAge(int age);
    void setHeight(double height);
    void setCriminalRecords(int criminalRecords);
    void setCrimeType(const std::string& crimeType);

private:
    // Member variables
    std::string name;
    int age;
    double height;
    int criminalRecords;
    std::string crimeType;  // New member variable for type of crime committed
};

// Class to represent a node in a LinkedList
class Node {
public:
    Criminal data;
    Node* next;

    Node(const Criminal& criminal);
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    // Function to add a criminal to the linked list
    void addCriminal(const Criminal& criminal);

    // Function to print all criminals in the linked list
    void printCriminals() const;

    // Function to clear the linked list
    void clear();

    // Getter for head pointer (useful for accessing nodes)
    Node* getHead() const;
};

// Class to manage the database of criminals
class Database {
private:
    LinkedList criminalList;

public:
    void addCriminal(const Criminal& criminal);
    void printCriminals() const;
    void clearDatabase();
    LinkedList* getCriminalList();
};

// Comparator functions for sorting using LinkedList
bool compareByName(Node* a, Node* b);
bool compareByAge(Node* a, Node* b);
bool compareByHeight(Node* a, Node* b);
bool compareByCriminalRecords(Node* a, Node* b);

// Function to input data for a criminal
Criminal inputCriminalData();

#endif // CLASS_H
