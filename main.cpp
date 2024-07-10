
#include <iostream>
#include "Class.h"
using namespace std;

int main() {
    CrimeManagementSystem system;

    CrimeDatabase cityA;
    cityA.addReport(CrimeReport("Theft", 3, "Downtown"));
    cityA.addReport(CrimeReport("Assault", 5, "Suburbs"));
    cityA.addReport(CrimeReport("Fraud", 2, "Business District"));

    CrimeDatabase cityB;
    cityB.addReport(CrimeReport("Burglary", 4, "Residential Area"));
    cityB.addReport(CrimeReport("Vandalism", 1, "City Park"));
    cityB.addReport(CrimeReport("Arson", 6, "Industrial Area"));

    system.addDatabase(cityA);
    system.addDatabase(cityB);

    cout << "Before Sorting:\n";
    system.displayAllDatabases();

    system.sortAllDatabases();

    cout << "\nAfter Sorting:\n";
    system.displayAllDatabases();

    return 0;
}
