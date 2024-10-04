#include <stdio.h>

float celsius_to_fahrenheit(float celsius){
    return (9.0/5) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (5.0/9) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return (fahrenheit - 32) * (5.0/9) + 273.15;
}

float kelvin_to_fahrenheit(float kelvin){
    return (kelvin - 273.15) * (9.0/5) + 32;
}

void categorize_temperature(float celsius){
    if(celsius < 0){
        printf("Temperature category: Freezing\nWeather advisory: Watch out for snowmen!\n");
    }
    else if(celsius >= 0 && celsius < 10){
        printf("Temperature category: Cold\nWeather advisory: Bring a jacket!");
    }
    else if(celsius >= 10 && celsius < 25){
        printf("Temperature category: Comfortable\nWeather advisory: It's nice out.");
    }
    else if(celsius >= 25 && celsius < 35){
        printf("Temperature category: Hot\nWeather advisory: Bring some icecream!");
    }
    else{
        printf("Temperature category: Extreme Heat\nWeather advisory: Put on sunscreen!");
    }
}

void fahrenheit(float temp, int unit)
{
    if(unit == 1) {
        temp = celsius_to_fahrenheit(temp);
    }
    else if(unit == 3) {
        temp = kelvin_to_fahrenheit(temp);
    }
    else {
        printf("Unit not recognized, exiting program");
        return;
    }
    
    printf("Converted temperature: %.2f degrees F\n", temp);
    categorize_temperature(fahrenheit_to_celsius(temp));
}

void celsius(float temp, int unit)
{
    if(unit == 2) {
        temp = fahrenheit_to_celsius(temp);
    }
    else if(unit == 3) {
        temp = kelvin_to_celsius(temp);
    }
    else {
        printf("Unit not recognized, exiting program");
        return;
    }
    
    printf("Converted temperature: %.2f degrees C\n", temp);
    categorize_temperature(temp);
}

void kelvin(float temp, int unit)
{
    if(unit == 1) {
        temp = celsius_to_kelvin(temp);
    }
    else if(unit == 2) {
        temp = fahrenheit_to_kelvin(temp);
    }
    else {
        printf("Unit not recognized, exiting program");
        return;
    }
    
    printf("Converted temperature: %.2fK\n", temp);
    categorize_temperature(kelvin_to_celsius(temp));
}

int main()
{
    float temp;
    int unit;
    int conversion;
    
    printf("Enter the temperature: ");
    scanf("%f", &temp);
    printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &unit);
    printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &conversion);
    printf("\n");
    
    if(unit == conversion) {
        printf("Conversion scale cannot be the same as current scale\n");
        main();
    }
    else if((unit == 3 && temp < 0) || (unit == 2 && temp < -459.67) || (unit == 1 && temp < -273.15)){
        printf("Temperature entered is not valid\n");
        main();
    }
    else if(conversion == 2) {
        fahrenheit(temp, unit);
    }
    else if(conversion == 1) {
        celsius(temp, unit);
    }
    else if(conversion == 3) {
        kelvin(temp, unit);
    }
    else {
        printf("Unit entered is not valid");
    }

    return 0;
}
