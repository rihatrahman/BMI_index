#include <iostream>
#include "Person.h"
#include <vector>

using namespace std;

double pounds_to_kilograms(double pounds) { return pounds * 0.453592; }

double inches_to_meter(double inches) { return inches * 0.0254; }

double calculate_bmi(double mass, double height) { return mass / (height * height); }

double getPositiveNumberInput() {

    float input; 
    cin >> input;

    while (!cin || input <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    return input;
}


double getMassFromUser() {

    double mass;
    char mass_unit;
    string input;
    
    cout << "Select body mass unit (k for Kilograms or p for Pounds): ";
    cin >> input;
    mass_unit = toupper(input[0]);

    while (((mass_unit != 'K') && (mass_unit != 'P')) || (input.length() != 1)) {

        cout << "Invalid value. Please enter 'k' or 'p': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
        mass_unit = toupper(input[0]);
    }

    if (mass_unit == 'P') {
        cout << "Enter body mass in Pounds: ";
        mass = getPositiveNumberInput();
        mass = pounds_to_kilograms(mass);
    }

    else if (mass_unit == 'K') {
        cout << "Enter body mass in Kilograms: ";
        mass = getPositiveNumberInput();
    } 

    return mass;
}



double getHeightFromUser() {

    double height;
    char height_unit;
    string input;

    cout << "Select height unit (m for Meters or f for feet/inches): ";
    cin >> input;
    height_unit = toupper(input[0]);


    while (((height_unit != 'M') && (height_unit != 'F')) || (input.length() != 1)) {

        cout << "Invalid value. Please enter 'm' or 'f': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
        height_unit = toupper(input[0]);
    }

    if (height_unit == 'M') {

        cout << "Enter height in Meters: ";
        cin >> height;
    }

    else if (height_unit == 'F') {

        double feet, inches;
        cout << "Enter Feet: ";
        cin >> feet;
        cout << "Enter Inches: ";
        cin >> inches;
        height = inches_to_meter(feet * 12 + inches);
    }

    return height;
}



int menu() {

    int option;
    cout << "Menu\nCalculate BMI:\t1\nShow History:\t2\nExit:\t\t3\n\nEnter an option: ";
    cin >> option;
    
    while (option != 1 && option != 2 && option != 3) {

        cout << "Invalid input. Please enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> option;
    }

    cout << "\n";
    return option;
}


Person new_bmi() {

    string name;
    cout << "Enter Name: ";
    cin >> name;
    double mass = getMassFromUser();
    double height = getHeightFromUser();
    double bmi = calculate_bmi(mass, height);
    cout << "\nBody Mass Index(BMI): "<< bmi << "\n\n\n\n";
    
    Person newPerson (name, mass, height, bmi);
    return newPerson;
}


void show_history(vector<Person> listOfPeople) {

    
    cout << "Name\tMass (Kilograms)\tHeight\tBody Mass Index (BMI)\n";

    for (int i = 0; i < listOfPeople.size(); i++) {

        cout << listOfPeople[i].getName() << "\t" << listOfPeople[i].getMass() << "\t\t\t" 
            << listOfPeople[i].getHeight() << "\t" << listOfPeople[i].getBMI() << "\n";
    }

    cout << "\n\n\n";
}


int main()
{
    cout << "##################################################################\n";
    cout << "#                           BMI Index                            #\n";
    cout << "##################################################################\n\n\n";

    int option;
    vector<Person> listoOfPeople;

    do {

        option = menu();

        switch (option) {

        case 1:
            listoOfPeople.push_back(new_bmi());
            break;

        case 2:
            show_history(listoOfPeople);
            break;

        case 3:
            return 0;
        }

    } while (option != 3);
}