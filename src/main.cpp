#include "converter.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

const int EXIT_CHOICE = 0;

void printMenu() {
    cout << "\nUnit Converter" << endl << endl;
    cout << "1. Inches to centimeters" << endl;
    cout << "2. Centimeters to inches" << endl;
    cout << "3. Pounds to kilograms" << endl;
    cout << "4. Kilograms to pounds" << endl;
    cout << "5. Fahrenheit to Celsius" << endl;
    cout << "6. Celsius to Fahrenheit" << endl;
    cout << "0. Exit" << endl << endl;
    cout << "Enter choice: ";
}

bool isValidMenuChoice(int choice) {
    return (choice >= 1 && choice <= 6) || choice == EXIT_CHOICE;
}

bool isValidValueForChoice(int choice, double value) {
    if (choice >= 1 && choice <= 4) {
        return value >= 0;
    }
    return true;
}

int main() {
    int choice = -1;
    double value = 0.0;
    double result = 0.0;

    cout << fixed << setprecision(2);

    while (true) {
        printMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (choice == EXIT_CHOICE) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (!isValidMenuChoice(choice)) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        cout << "Enter value: ";
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid value for this conversion. Please try again." << endl;
            continue;
        }

        if (!isValidValueForChoice(choice, value)) {
            cout << "Invalid value for this conversion. Please try again." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                result = inchesToCentimeters(value);
                cout << value << " inches is " << result << " centimeters" << endl;
                break;
            case 2:
                result = centimetersToInches(value);
                cout << value << " centimeters is " << result << " inches" << endl;
                break;
            case 3:
                result = poundsToKilograms(value);
                cout << value << " pounds is " << result << " kilograms" << endl;
                break;
            case 4:
                result = kilogramsToPounds(value);
                cout << value << " kilograms is " << result << " pounds" << endl;
                break;
            case 5:
                result = fahrenheitToCelsius(value);
                cout << value << " Fahrenheit is " << result << " Celsius" << endl;
                break;
            case 6:
                result = celsiusToFahrenheit(value);
                cout << value << " Celsius is " << result << " Fahrenheit" << endl;
                break;
        }
    }

    return 0;
}
