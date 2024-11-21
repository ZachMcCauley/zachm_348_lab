#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//function that removes the first character in the string
//called if str[0] is a plus or minus
string removeFirstChar(string& str) {
    string new_str = "";
    for (int i = 1; i < str.size(); i++) {
        new_str = new_str + str[i];
    }
    return new_str;
}

double extractNumeric(string& str) {
    bool is_float = false;
    bool is_negative = false;
    int decimal_place = str.size();
    //for loop checks to make sure all characters are numbers or + or -
    for (char ch : str) {
        int asciiValue = static_cast<int>(ch);
        if (asciiValue < 43 || asciiValue > 57 || asciiValue == 44 || asciiValue == 47) {
            return -999999.99;
        } 
        //if there is a decimal check if there was already one
        if (asciiValue == 46) {
            if (is_float) return -999999.99; 
            else is_float = true;
        }
    }
    
    //check if the first character is a + or -
    if (str[0] == '-') {
        is_negative = true;
        str = removeFirstChar(str);
    } else if (str[0] == '+') {
        str = removeFirstChar(str);
    }
    
    //checks if any character other than the first is a + or -
    for (int i = 0; i < str.size(); i++) {
        int asciiValue = static_cast<int>(str[i]);
        if (asciiValue == 43 || asciiValue == 45) {
            return -999999.99;
        }
        if (asciiValue == 46) decimal_place = i;
    }
    
    float number = 0;
    if (is_float) { //totals the number if a decimal was found
        for (int i = 0; i < decimal_place; i++) { //adds before the decimal
            int asciiValue = static_cast<int>(str[i]);
            number += (asciiValue - 48) * pow(10, (decimal_place - 1 - i));
        }
        for (int i = (decimal_place + 1); i < str.size(); i++) { //adds after the decimal
            int asciiValue = static_cast<int>(str[i]);
            number += (asciiValue - 48) * pow(10, (i - decimal_place) * -1);
        }
    } else { //totals the number if a decimal was not found
        for (int i = 0; i < str.size(); i++) {
            int asciiValue = static_cast<int>(str[i]);
            number += (asciiValue - 48) * pow(10, (str.size() - i - 1));
        }
    }
    if (is_negative) number *= -1; //makes result negative if a - was entered
    return number;
}

int main() {
    string input;
    
    while(true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        
        if (input == "END") {
            break;
        }
        
        double number = extractNumeric(input);
        
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    
    return 0;
}
