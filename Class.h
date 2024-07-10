#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Class representing a crime report
class CrimeReport {
public:
    string type;
    int severity;
    string location;

    CrimeReport(string t, int s, string l) : type(t), severity(s), location(l) {}
};

// Class representing a node in the linked list
struct Node {
    CrimeReport report;
    Node* next;
    Node(CrimeReport r) : report(r), next(nullptr) {}
};

// Class representing a crime database that contains multiple reports
class CrimeDatabase {
private:
    Node* head;

public:
    CrimeDatabase() : head(nullptr) {}
    void addReport(CrimeReport report);
    void sortReportsBubble();
    void sortReportsInsertion();
    void sortReportsSelection();
    void displayReports();
};

// Method to add a report to the linked list
void CrimeDatabase::addReport(CrimeReport report) {
    Node* newNode = new Node(report);
    newNode->next = head;
    head = newNode;
}

// Method to display reports in the linked list
void CrimeDatabase::displayReports() {
    Node* current = head;
    while (current != nullptr) {
        cout << "Type: " << current->report.type << ", Severity: " << current->report.severity << ", Location: " << current->report.location << endl;
        current = current->next;
    }
}

// Sorting algorithms implementations

void CrimeDatabase::sortReportsBubble() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (current->report.severity > current->next->report.severity) {
                swap(current->report, current->next->report);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void CrimeDatabase::sortReportsInsertion() {
    if (!head || !head->next) return;
    Node* sorted = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        if (!sorted || sorted->report.severity >= current->report.severity) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->report.severity < current->report.severity) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

void CrimeDatabase::sortReportsSelection() {
    if (!head || !head->next) return;
    for (Node* i = head; i && i->next; i = i->next) {
        Node* min = i;
        for (Node* j = i->next; j; j = j->next) {
            if (j->report.severity < min->report.severity) {
                min = j;
            }
        }
        swap(i->report, min->report);
    }
}

// Class representing the crime management system
class CrimeManagementSystem {
private:
    queue<CrimeDatabase> databases;

public:
    void addDatabase(CrimeDatabase database);
    void sortAllDatabases();
    void displayAllDatabases();
};

// Method to add a database to the system
void CrimeManagementSystem::addDatabase(CrimeDatabase database) {
    databases.push(database);
}

// Method to sort all reports in all databases
void CrimeManagementSystem::sortAllDatabases() {
    queue<CrimeDatabase> tempQueue;
    while (!databases.empty()) {
        CrimeDatabase database = databases.front();
        databases.pop();
        database.sortReportsBubble();  // Example: using bubble sort
        tempQueue.push(database);
    }
    databases = tempQueue;
}

// Method to display all reports in all databases
void CrimeManagementSystem::displayAllDatabases() {
    queue<CrimeDatabase> tempQueue = databases;
    while (!tempQueue.empty()) {
        CrimeDatabase database = tempQueue.front();
        tempQueue.pop();
        database.displayReports();
    }
}
