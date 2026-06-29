#include "converter.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

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
            case INCHES_TO_CENTIMETERS:
                result = inchesToCentimeters(value);
                cout << value << " inches is " << result << " centimeters" << endl;
                break;
            case CENTIMETERS_TO_INCHES:
                result = centimetersToInches(value);
                cout << value << " centimeters is " << result << " inches" << endl;
                break;
            case POUNDS_TO_KILOGRAMS:
                result = poundsToKilograms(value);
                cout << value << " pounds is " << result << " kilograms" << endl;
                break;
            case KILOGRAMS_TO_POUNDS:
                result = kilogramsToPounds(value);
                cout << value << " kilograms is " << result << " pounds" << endl;
                break;
            case FAHRENHEIT_TO_CELSIUS:
                result = fahrenheitToCelsius(value);
                cout << value << " Fahrenheit is " << result << " Celsius" << endl;
                break;
            case CELSIUS_TO_FAHRENHEIT:
                result = celsiusToFahrenheit(value);
                cout << value << " Celsius is " << result << " Fahrenheit" << endl;
                break;
        }
    }

    return 0;
}
