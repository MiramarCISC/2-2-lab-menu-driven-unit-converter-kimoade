#include "converter.hpp"

double inchesToCentimeters(double inches) {
    return inches * 2.54;
}

double centimetersToInches(double centimeters) {
    return centimeters / 2.54;
}

double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

double kilogramsToPounds(double kilograms) {
    return kilograms / 0.453592;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}
