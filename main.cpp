#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Class to represent a Criminal
class Criminal {
public:
    // Constructor with default values
    Criminal(const string& name = "Unknown", int age = 0, double height = 0.0, int criminalRecords = 0, const string& crimeType = "Unknown")
        : name(name), age(age), height(height), criminalRecords(criminalRecords), crimeType(crimeType) {}

    // Accessor methods
    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getHeight() const {
        return height;
    }

    int getCriminalRecords() const {
        return criminalRecords;
    }

    const string& getCrimeType() const {
        return crimeType;
    }

    // Setter methods
    void setName(const string& name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setHeight(double height) {
        this->height = height;
    }

    void setCriminalRecords(int criminalRecords) {
        this->criminalRecords = criminalRecords;
    }

    void setCrimeType(const string& crimeType) {
        this->crimeType = crimeType;
    }

private:
    // Member variables
    string name;
    int age;
    double height;
    int criminalRecords;
    string crimeType;
};

// Class to represent a node in a LinkedList
class Node {
public:
    Criminal data;
    Node* next;

    Node(const Criminal& criminal) : data(criminal), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    // Function to add a criminal to the linked list
    void addCriminal(const Criminal& criminal) {
        Node* newNode = new Node(criminal);
        newNode->next = head;
        head = newNode;
    }

    // Function to print all criminals in the linked list
    void printCriminals() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->data.getName() << ", Age: " << current->data.getAge()
                << ", Height: " << current->data.getHeight()
                << ", Criminal Records: " << current->data.getCriminalRecords()
                << ", Crime Type: " << current->data.getCrimeType() << endl;
            current = current->next;
        }
        cout << endl;
    }

    // Function to clear the linked list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Getter for head pointer (useful for accessing nodes)
    Node* getHead() const {
        return head;
    }
};

// Class to manage the database of criminals
class Database {
private:
    LinkedList criminalList;

public:
    void addCriminal(const Criminal& criminal) {
        criminalList.addCriminal(criminal);
        cout << "Criminal added successfully." << endl;
    }

    void printCriminals() const {
        cout << "Printing Criminals in the Database:" << endl;
        criminalList.printCriminals();
    }

    void clearDatabase() {
        criminalList.clear();
        cout << "Database cleared." << endl;
    }

    LinkedList* getCriminalList() {
        return &criminalList;
    }
};

// Comparator functions for sorting using LinkedList
bool compareByName(Node* a, Node* b) {
    return a->data.getName() < b->data.getName();
}

bool compareByAge(Node* a, Node* b) {
    return a->data.getAge() < b->data.getAge();
}

bool compareByHeight(Node* a, Node* b) {
    return a->data.getHeight() < b->data.getHeight();
}

bool compareByCriminalRecords(Node* a, Node* b) {
    return a->data.getCriminalRecords() < b->data.getCriminalRecords();
}

// Function to input data for a criminal
Criminal inputCriminalData() {
    string name;
    int age;
    double height;
    int criminalRecords;
    string crimeType;

    cout << "Enter name of the criminal: ";
    getline(cin >> ws, name); // Use getline to handle spaces in name

    //Age
    while (true) {
        cout << "Enter age of the criminal: ";
        cin >> age;

        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Try Again" << endl;
        } else if(age<=10||age>=140) {
            cout << "Try again "<<endl;
        }
        else {
            break; // input is valid, exit the loop
        }
    }

    //Height
    while (true) {
        cout << "Enter height of the criminal (in cm): ";
        cin >> height;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Try Again" << endl;
        } else if(height<=90||height>=300) {
            cout << "Try again "<<endl;
        }
        else {
            break; 
        }
    }

    //Criminal Records
    while (true) {
        cout << "Enter number of criminal records: ";
        cin >> criminalRecords;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Try Again" << endl;
        } else if(criminalRecords<=0) {
            cout << "Try again "<<endl;
        }
        else {
            break; 
        }
    }

    cin.ignore(); // Clear input buffer

    cout << "Enter type of crime committed: ";
    getline(cin >> ws, crimeType);

    // Create a Criminal object with the input data
    Criminal newCriminal(name, age, height, criminalRecords, crimeType);
    return newCriminal;
}

int main() {
    Database criminalDatabase; // Database object to manage criminals

    int choice;

    do {
        // Prompt user for choice
        cout << "Choose an option to access the Criminal Database:" << endl;
        cout << "1. Add a criminal" << endl;
        cout << "2. Print all criminals" << endl;
        cout << "3. Sort by Name" << endl;
        cout << "4. Sort by Age" << endl;
        cout << "5. Sort by Height" << endl;
        cout << "6. Sort by Criminal Records" << endl;
        cout << "7. Clear Database" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: {
                // Input data for a new criminal
                Criminal newCriminal = inputCriminalData();
                criminalDatabase.addCriminal(newCriminal);
                break;
            }
            case 2:
                criminalDatabase.printCriminals();
                break;
            case 3: {
                // Sorting by Name
                LinkedList* list = criminalDatabase.getCriminalList();
                vector<Node*> tempVec;
                Node* current = list->getHead();
                while (current != nullptr) {
                    tempVec.push_back(current);
                    current = current->next;
                }
                sort(tempVec.begin(), tempVec.end(), compareByName);
                cout << "Sorted by Name:" << endl;
                for (Node* node : tempVec) {
                    cout << "Name: " << node->data.getName() << ", Age: " << node->data.getAge()
                         << ", Height: " << node->data.getHeight()
                         << ", Criminal Records: " << node->data.getCriminalRecords()
                         << ", Crime Type: " << node->data.getCrimeType() << endl;
                }
                cout << endl;
                break;
            }
            case 4: {
                // Sorting by Age
                LinkedList* list = criminalDatabase.getCriminalList();
                vector<Node*> tempVec;
                Node* current = list->getHead();
                while (current != nullptr) {
                    tempVec.push_back(current);
                    current = current->next;
                }
                sort(tempVec.begin(), tempVec.end(), compareByAge);
                cout << "Sorted by Age:" << endl;
                for (Node* node : tempVec) {
                    cout << "Name: " << node->data.getName() << ", Age: " << node->data.getAge()
                         << ", Height: " << node->data.getHeight()
                         << ", Criminal Records: " << node->data.getCriminalRecords()
                         << ", Crime Type: " << node->data.getCrimeType() << endl;
                }
                cout << endl;
                break;
            }
            case 5: {
                // Sorting by Height
                LinkedList* list = criminalDatabase.getCriminalList();
                vector<Node*> tempVec;
                Node* current = list->getHead();
                while (current != nullptr) {
                    tempVec.push_back(current);
                    current = current->next;
                }
                sort(tempVec.begin(), tempVec.end(), compareByHeight);
                cout << "Sorted by Height:" << endl;
                for (Node* node : tempVec) {
                    cout << "Name: " << node->data.getName() << ", Age: " << node->data.getAge()
                         << ", Height: " << node->data.getHeight()
                         << ", Criminal Records: " << node->data.getCriminalRecords()
                         << ", Crime Type: " << node->data.getCrimeType() << endl;
                }
                cout << endl;
                break;
            }
            case 6: {
                // Sorting by Criminal Records
                LinkedList* list = criminalDatabase.getCriminalList();
                vector<Node*> tempVec;
                Node* current = list->getHead();
                while (current != nullptr) {
                    tempVec.push_back(current);
                    current = current->next;
                }
                sort(tempVec.begin(), tempVec.end(), compareByCriminalRecords);
                cout << "Sorted by Criminal Records:" << endl;
                for (Node* node : tempVec) {
                    cout << "Name: " << node->data.getName() << ", Age: " << node->data.getAge()
                         << ", Height: " << node->data.getHeight()
                         << ", Criminal Records: " << node->data.getCriminalRecords()
                         << ", Crime Type: " << node->data.getCrimeType() << endl;
                }
                cout << endl;
                break;
            }
            case 7:
                criminalDatabase.clearDatabase();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
