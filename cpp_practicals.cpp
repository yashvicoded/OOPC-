/*
================================================================================
C++ PRACTICALS / TUTORIALS - COMPLETE SOLUTIONS
================================================================================
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// ============================================================================
// PRACTICAL 1: Basic Programs
// ============================================================================

// 1.1: Vowel or Consonant Checker
void checkVowelConsonant() {
    char ch;
    cout << "\n=== Vowel or Consonant Checker ===" << endl;
    cout << "Enter a single character: ";
    cin >> ch;
    
    if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ||
        (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
        cout << "It is a vowel" << endl;
    } else {
        cout << "It is a consonant" << endl;
    }
}

// 1.2: Print Multiplication Tables from 1 to 12
void printTables() {
    cout << "\n=== Multiplication Tables (1 to 12) ===" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << "\nTable of " << i << ":" << endl;
        for (int j = 1; j <= 10; j++) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
    }
}

// 1.3: Single cout statement output
void singleCoutOutput() {
    cout << "\n=== Single cout Statement ===" << endl;
    cout << "Maths = 90, Physics = 77, Chemistry = 69" << endl;
}

// ============================================================================
// PRACTICAL 2: Functions and Arrays
// ============================================================================

// 2.1: Find largest of three integers using function with reference parameters
void findLargest(int &a, int &b, int &c, int &largest) {
    largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
}

void largestOfThree() {
    cout << "\n=== Largest of Three Numbers ===" << endl;
    int num1, num2, num3, largest;
    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;
    
    findLargest(num1, num2, num3, largest);
    cout << "The largest number is: " << largest << endl;
}

// 2.2: Create array using new operator
void dynamicArray() {
    cout << "\n=== Dynamic Array Creation ===" << endl;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    
    int *arr = new int[size];
    
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "\nArray elements are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
}

// ============================================================================
// PRACTICAL 3: Classes and Objects
// ============================================================================

// 3.1: Simple class for basic arithmetic operations
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    int subtract(int a, int b) {
        return a - b;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
    
    float divide(int a, int b) {
        if (b != 0)
            return (float)a / b;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

void demonstrateCalculator() {
    cout << "\n=== Basic Arithmetic Calculator ===" << endl;
    Calculator calc;
    int a, b;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "Addition: " << calc.add(a, b) << endl;
    cout << "Subtraction: " << calc.subtract(a, b) << endl;
    cout << "Multiplication: " << calc.multiply(a, b) << endl;
    cout << "Division: " << calc.divide(a, b) << endl;
}

// 3.2: Temperature Converter (Fahrenheit to Celsius)
class TemperatureConverter {
private:
    float fahrenheit;
    float celsius;
    
public:
    void inputFahrenheit() {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fahrenheit;
    }
    
    void convertToCelsius() {
        celsius = (fahrenheit - 32) * 5.0 / 9.0;
    }
    
    void display() {
        cout << fahrenheit << "°F = " << celsius << "°C" << endl;
    }
};

void demonstrateTemperatureConverter() {
    cout << "\n=== Temperature Converter ===" << endl;
    TemperatureConverter temp;
    temp.inputFahrenheit();
    temp.convertToCelsius();
    temp.display();
}

// 3.3: Shape Classes (Triangle, Square, Circle)
class Triangle {
private:
    float base, height;
    
public:
    void inputData() {
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
    }
    
    float findArea() {
        return 0.5 * base * height;
    }
};

class Square {
private:
    float side;
    
public:
    void inputData() {
        cout << "Enter side: ";
        cin >> side;
    }
    
    float findArea() {
        return side * side;
    }
};

class Circle {
private:
    float radius;
    
public:
    void inputData() {
        cout << "Enter radius: ";
        cin >> radius;
    }
    
    float findArea() {
        return 3.14159 * radius * radius;
    }
};

void demonstrateShapes() {
    cout << "\n=== Shape Area Calculator ===" << endl;
    
    Triangle t;
    cout << "\n--- Triangle ---" << endl;
    t.inputData();
    cout << "Area of Triangle: " << t.findArea() << endl;
    
    Square s;
    cout << "\n--- Square ---" << endl;
    s.inputData();
    cout << "Area of Square: " << s.findArea() << endl;
    
    Circle c;
    cout << "\n--- Circle ---" << endl;
    c.inputData();
    cout << "Area of Circle: " << c.findArea() << endl;
}

// ============================================================================
// PRACTICAL 4: Pointers and Function Overloading
// ============================================================================

// 4.1: String Reverse Function with default parameter
void reverse(char *str, int count = -1) {
    int len = strlen(str);
    
    // If count is -1 (default), reverse entire string
    if (count == -1) {
        count = len;
    }
    
    // Ensure count doesn't exceed string length
    if (count > len) {
        count = len;
    }
    
    // Reverse the first 'count' characters
    for (int i = 0; i < count / 2; i++) {
        char temp = str[i];
        str[i] = str[count - 1 - i];
        str[count - 1 - i] = temp;
    }
}

void demonstrateReverse() {
    cout << "\n=== String Reverse Function ===" << endl;
    char str1[100], str2[100];
    int count;
    
    cout << "Enter a string: ";
    cin.ignore();
    cin.getline(str1, 100);
    strcpy(str2, str1);
    
    // Reverse entire string
    reverse(str1);
    cout << "Reversed entire string: " << str1 << endl;
    
    // Reverse specific number of characters
    cout << "Enter number of characters to reverse: ";
    cin >> count;
    reverse(str2, count);
    cout << "Reversed " << count << " characters: " << str2 << endl;
}

// 4.2: Function Overloading - Power Calculation
class Power {
public:
    // Case 1: m is double, n is int
    double power(double m, int n) {
        return pow(m, n);
    }
    
    // Case 2: m and n are both int
    int power(int m, int n) {
        return (int)pow(m, n);
    }
};

void demonstratePower() {
    cout << "\n=== Function Overloading - Power Calculation ===" << endl;
    Power p;
    
    cout << "2.5 ^ 3 = " << p.power(2.5, 3) << " (double, int)" << endl;
    cout << "2 ^ 3 = " << p.power(2, 3) << " (int, int)" << endl;
}

// ============================================================================
// PRACTICAL 5: Static Members and Advanced Classes
// ============================================================================

// 5.1: Static Members and Static Member Functions
class StaticDemo {
private:
    static int count;
    int id;
    
public:
    StaticDemo() {
        count++;
        id = count;
    }
    
    static int getCount() {
        return count;
    }
    
    void display() {
        cout << "Object ID: " << id << ", Total Objects: " << count << endl;
    }
};

int StaticDemo::count = 0;

void demonstrateStatic() {
    cout << "\n=== Static Members Demo ===" << endl;
    
    cout << "Initial count: " << StaticDemo::getCount() << endl;
    
    StaticDemo obj1, obj2, obj3;
    
    obj1.display();
    obj2.display();
    obj3.display();
    
    cout << "Total objects created: " << StaticDemo::getCount() << endl;
}

// 5.2: Time Class with Addition
class Time {
private:
    int hours;
    int minutes;
    
public:
    Time() {
        hours = 0;
        minutes = 0;
    }
    
    Time(int h, int m) {
        hours = h;
        minutes = m;
    }
    
    void inputTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
    }
    
    void add(Time t1, Time t2) {
        minutes = t1.minutes + t2.minutes;
        hours = t1.hours + t2.hours;
        
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
    }
    
    void display() {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

void demonstrateTime() {
    cout << "\n=== Time Addition Demo ===" << endl;
    Time t1, t2, t3;
    
    cout << "Enter first time:" << endl;
    t1.inputTime();
    
    cout << "Enter second time:" << endl;
    t2.inputTime();
    
    t3.add(t1, t2);
    
    cout << "\nFirst Time: ";
    t1.display();
    cout << "Second Time: ";
    t2.display();
    cout << "Sum: ";
    t3.display();
}

// 5.3: Distance Class
class Distance {
private:
    int feet;
    int inches;
    
public:
    Distance() {
        feet = 0;
        inches = 0;
    }
    
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }
    
    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    
    void outputDistance() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
    
    Distance addDistance(Distance d) {
        Distance result;
        result.inches = inches + d.inches;
        result.feet = feet + d.feet;
        
        if (result.inches >= 12) {
            result.feet += result.inches / 12;
            result.inches = result.inches % 12;
        }
        
        return result;
    }
};

void demonstrateDistance() {
    cout << "\n=== Distance Addition Demo ===" << endl;
    Distance d1, d2, d3;
    
    cout << "Enter first distance:" << endl;
    d1.inputDistance();
    
    cout << "Enter second distance:" << endl;
    d2.inputDistance();
    
    d3 = d1.addDistance(d2);
    
    cout << "\nFirst Distance: ";
    d1.outputDistance();
    cout << "Second Distance: ";
    d2.outputDistance();
    cout << "Sum: ";
    d3.outputDistance();
}

// ============================================================================
// MAIN FUNCTION - Menu Driven Program
// ============================================================================

int main() {
    int choice;
    
    do {
        cout << "\n========================================" << endl;
        cout << "     C++ PRACTICALS MENU" << endl;
        cout << "========================================" << endl;
        cout << "PRACTICAL 1:" << endl;
        cout << "1. Vowel or Consonant Checker" << endl;
        cout << "2. Multiplication Tables (1-12)" << endl;
        cout << "3. Single cout Output" << endl;
        cout << "\nPRACTICAL 2:" << endl;
        cout << "4. Largest of Three Numbers" << endl;
        cout << "5. Dynamic Array" << endl;
        cout << "\nPRACTICAL 3:" << endl;
        cout << "6. Calculator Demo" << endl;
        cout << "7. Temperature Converter" << endl;
        cout << "8. Shape Areas" << endl;
        cout << "\nPRACTICAL 4:" << endl;
        cout << "9. String Reverse" << endl;
        cout << "10. Power Function Overloading" << endl;
        cout << "\nPRACTICAL 5:" << endl;
        cout << "11. Static Members Demo" << endl;
        cout << "12. Time Addition" << endl;
        cout << "13. Distance Addition" << endl;
        cout << "\n0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                checkVowelConsonant();
                break;
            case 2:
                printTables();
                break;
            case 3:
                singleCoutOutput();
                break;
            case 4:
                largestOfThree();
                break;
            case 5:
                dynamicArray();
                break;
            case 6:
                demonstrateCalculator();
                break;
            case 7:
                demonstrateTemperatureConverter();
                break;
            case 8:
                demonstrateShapes();
                break;
            case 9:
                demonstrateReverse();
                break;
            case 10:
                demonstratePower();
                break;
            case 11:
                demonstrateStatic();
                break;
            case 12:
                demonstrateTime();
                break;
            case 13:
                demonstrateDistance();
                break;
            case 0:
                cout << "\nThank you for using the program!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
        
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while(choice != 0);
    
    return 0;
}
