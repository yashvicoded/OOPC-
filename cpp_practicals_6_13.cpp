/*
================================================================================
C++ PRACTICALS 6-13 - ADVANCED OOP CONCEPTS
================================================================================
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

// ============================================================================
// PRACTICAL 6: Friend Functions
// ============================================================================

// 6.1: Sample class with friend function for mean calculation
class Sample {
private:
    int a, b;
    
public:
    Sample(int x, int y) {
        a = x;
        b = y;
    }
    
    // Friend function declaration
    friend float calculateMean(Sample obj);
    
    void display() {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

// Friend function definition
float calculateMean(Sample obj) {
    return (obj.a + obj.b) / 2.0;
}

void demonstrateSample() {
    cout << "\n=== Sample Class with Friend Function ===" << endl;
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    
    Sample s(x, y);
    s.display();
    cout << "Mean of the two members: " << calculateMean(s) << endl;
}

// 6.2: Complex class with friend function
class Complex {
private:
    float real, imag;
    
public:
    Complex() {
        real = 0;
        imag = 0;
    }
    
    Complex(float r, float i) {
        real = r;
        imag = i;
    }
    
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
    
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
    
    // Friend function to calculate sum
    friend Complex sumComplex(Complex c1, Complex c2);
};

Complex sumComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void demonstrateComplex() {
    cout << "\n=== Complex Number Addition ===" << endl;
    Complex c1, c2, c3;
    
    cout << "Enter first complex number:" << endl;
    c1.input();
    
    cout << "Enter second complex number:" << endl;
    c2.input();
    
    c3 = sumComplex(c1, c2);
    
    cout << "\nFirst complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();
    cout << "\nSum: ";
    c3.display();
    cout << endl;
}

// ============================================================================
// PRACTICAL 7: Dynamic Memory and Copy Constructor
// ============================================================================

// 7.1: String class with dynamic memory management
class String {
private:
    char *str;
    int length;
    
public:
    // Constructor to allocate memory
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }
    
    String(const char *s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    
    // Copy constructor
    String(const String &s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
        cout << "Copy constructor called!" << endl;
    }
    
    // Destructor to free memory
    ~String() {
        delete[] str;
        cout << "Destructor called for: " << (length > 0 ? str : "empty string") << endl;
    }
    
    void input() {
        char temp[100];
        cout << "Enter string: ";
        cin.ignore();
        cin.getline(temp, 100);
        
        delete[] str;
        length = strlen(temp);
        str = new char[length + 1];
        strcpy(str, temp);
    }
    
    void display() {
        cout << "String: " << str << " (Length: " << length << ")" << endl;
    }
};

void demonstrateString() {
    cout << "\n=== String Class with Dynamic Memory ===" << endl;
    
    String s1;
    s1.input();
    s1.display();
    
    cout << "\nCreating copy of string..." << endl;
    String s2 = s1;  // Copy constructor called
    s2.display();
    
    cout << "\nExiting function..." << endl;
}

// 7.2: Demonstrating copy constructor
class Demo {
private:
    int *ptr;
    
public:
    Demo(int val) {
        ptr = new int;
        *ptr = val;
        cout << "Constructor called. Value: " << *ptr << endl;
    }
    
    // Copy constructor (deep copy)
    Demo(const Demo &d) {
        ptr = new int;
        *ptr = *(d.ptr);
        cout << "Copy constructor called. Copied value: " << *ptr << endl;
    }
    
    ~Demo() {
        cout << "Destructor called. Deleting value: " << *ptr << endl;
        delete ptr;
    }
    
    void display() {
        cout << "Value: " << *ptr << endl;
    }
    
    void modify(int val) {
        *ptr = val;
    }
};

void demonstrateCopyConstructor() {
    cout << "\n=== Copy Constructor Demonstration ===" << endl;
    
    Demo d1(10);
    d1.display();
    
    Demo d2 = d1;  // Copy constructor
    d2.display();
    
    cout << "\nModifying d2..." << endl;
    d2.modify(20);
    
    cout << "After modification:" << endl;
    cout << "d1: "; d1.display();
    cout << "d2: "; d2.display();
}

// ============================================================================
// PRACTICAL 8: Operator Overloading
// ============================================================================

// 8.1: Overloading + and - operators for Complex class
class ComplexNum {
private:
    float real, imag;
    
public:
    ComplexNum() {
        real = 0;
        imag = 0;
    }
    
    ComplexNum(float r, float i) {
        real = r;
        imag = i;
    }
    
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
    
    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
    
    // Overload + operator
    ComplexNum operator+(ComplexNum c) {
        ComplexNum result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
    
    // Overload - operator
    ComplexNum operator-(ComplexNum c) {
        ComplexNum result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
};

void demonstrateComplexOperators() {
    cout << "\n=== Complex Number Operators (+, -) ===" << endl;
    ComplexNum c1, c2, c3;
    
    cout << "Enter first complex number:" << endl;
    c1.input();
    
    cout << "Enter second complex number:" << endl;
    c2.input();
    
    c3 = c1 + c2;
    cout << "\n"; c1.display(); cout << " + "; c2.display(); cout << " = "; c3.display();
    
    c3 = c1 - c2;
    cout << "\n"; c1.display(); cout << " - "; c2.display(); cout << " = "; c3.display();
    cout << endl;
}

// 8.2: Overloading unary - operator
class Number {
private:
    int value;
    
public:
    Number(int v = 0) {
        value = v;
    }
    
    void display() {
        cout << "Value: " << value << endl;
    }
    
    // Overload unary - operator
    Number operator-() {
        Number result;
        result.value = -value;
        return result;
    }
};

void demonstrateUnaryOperator() {
    cout << "\n=== Unary Minus Operator Overloading ===" << endl;
    int val;
    cout << "Enter a number: ";
    cin >> val;
    
    Number n1(val);
    cout << "Original: "; n1.display();
    
    Number n2 = -n1;
    cout << "After unary minus: "; n2.display();
}

// 8.3: Overloading || operator
class Boolean {
private:
    bool value;
    
public:
    Boolean(bool v = false) {
        value = v;
    }
    
    void input() {
        int temp;
        cout << "Enter boolean value (0 or 1): ";
        cin >> temp;
        value = temp != 0;
    }
    
    void display() {
        cout << (value ? "true" : "false");
    }
    
    // Overload || operator
    Boolean operator||(Boolean b) {
        return Boolean(value || b.value);
    }
};

void demonstrateLogicalOperator() {
    cout << "\n=== Logical OR (||) Operator Overloading ===" << endl;
    Boolean b1, b2, b3;
    
    cout << "Enter first boolean:" << endl;
    b1.input();
    
    cout << "Enter second boolean:" << endl;
    b2.input();
    
    b3 = b1 || b2;
    
    cout << "\nResult: ";
    b1.display(); cout << " || "; b2.display(); cout << " = "; b3.display();
    cout << endl;
}

// ============================================================================
// PRACTICAL 9: Type Conversion
// ============================================================================

// 9.1: Basic type to class type conversion
class Meter {
private:
    float meters;
    
public:
    Meter() {
        meters = 0;
    }
    
    // Constructor for basic to class conversion
    Meter(float m) {
        meters = m;
        cout << "Conversion: float to Meter" << endl;
    }
    
    // Conversion operator for class to basic type
    operator float() {
        cout << "Conversion: Meter to float" << endl;
        return meters;
    }
    
    void display() {
        cout << meters << " meters" << endl;
    }
};

void demonstrateTypeConversion() {
    cout << "\n=== Type Conversion ===" << endl;
    
    // Basic to class
    float distance = 5.5;
    Meter m = distance;  // Calls constructor
    cout << "After conversion: ";
    m.display();
    
    // Class to basic
    float newDistance = m;  // Calls conversion operator
    cout << "Converted back to float: " << newDistance << endl;
}

// 9.2: Object to object conversion
class Fahrenheit {
private:
    float temp;
    
public:
    Fahrenheit(float t = 0) {
        temp = t;
    }
    
    void display() {
        cout << temp << "°F";
    }
    
    float getTemp() {
        return temp;
    }
};

class Celsius {
private:
    float temp;
    
public:
    Celsius(float t = 0) {
        temp = t;
    }
    
    // Constructor for Fahrenheit to Celsius conversion
    Celsius(Fahrenheit f) {
        temp = (f.getTemp() - 32) * 5.0 / 9.0;
        cout << "Conversion: Fahrenheit to Celsius" << endl;
    }
    
    void display() {
        cout << temp << "°C";
    }
};

void demonstrateObjectConversion() {
    cout << "\n=== Object to Object Conversion ===" << endl;
    
    Fahrenheit f(98.6);
    cout << "Temperature in Fahrenheit: ";
    f.display();
    cout << endl;
    
    Celsius c = f;  // Conversion
    cout << "Temperature in Celsius: ";
    c.display();
    cout << endl;
}

// ============================================================================
// PRACTICAL 10: Inheritance
// ============================================================================

// 10.1: Single Inheritance (Public, Protected, Private)

// PUBLIC INHERITANCE
class BasePublic {
protected:
    int protectedData;
public:
    int publicData;
    
    BasePublic() {
        publicData = 10;
        protectedData = 20;
    }
    
    void display() {
        cout << "Base Public Data: " << publicData << endl;
        cout << "Base Protected Data: " << protectedData << endl;
    }
};

class DerivedPublic : public BasePublic {
public:
    void show() {
        cout << "Accessing from derived (public inheritance):" << endl;
        cout << "Public data: " << publicData << " (accessible)" << endl;
        cout << "Protected data: " << protectedData << " (accessible)" << endl;
    }
};

// PROTECTED INHERITANCE
class DerivedProtected : protected BasePublic {
public:
    void show() {
        cout << "Accessing from derived (protected inheritance):" << endl;
        cout << "Public data: " << publicData << " (now protected)" << endl;
        cout << "Protected data: " << protectedData << " (accessible)" << endl;
    }
};

// PRIVATE INHERITANCE
class DerivedPrivate : private BasePublic {
public:
    void show() {
        cout << "Accessing from derived (private inheritance):" << endl;
        cout << "Public data: " << publicData << " (now private)" << endl;
        cout << "Protected data: " << protectedData << " (accessible)" << endl;
    }
};

void demonstrateInheritance() {
    cout << "\n=== Inheritance Types ===" << endl;
    
    DerivedPublic d1;
    cout << "\n--- Public Inheritance ---" << endl;
    d1.show();
    d1.display();  // Base class method accessible
    
    DerivedProtected d2;
    cout << "\n--- Protected Inheritance ---" << endl;
    d2.show();
    // d2.display();  // NOT accessible (now protected)
    
    DerivedPrivate d3;
    cout << "\n--- Private Inheritance ---" << endl;
    d3.show();
    // d3.display();  // NOT accessible (now private)
}

// 10.2: Student and Test classes
class Student {
protected:
    int rollNumber;
    
public:
    void setRollNumber(int r) {
        rollNumber = r;
    }
    
    void displayRoll() {
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Test : public Student {
protected:
    float marks[2];
    
public:
    void setMarks(float m1, float m2) {
        marks[0] = m1;
        marks[1] = m2;
    }
    
    void displayMarks() {
        cout << "Subject 1: " << marks[0] << endl;
        cout << "Subject 2: " << marks[1] << endl;
    }
};

class Result : public Test {
private:
    float total;
    
public:
    void calculateTotal() {
        total = marks[0] + marks[1];
    }
    
    void displayResult() {
        displayRoll();
        displayMarks();
        cout << "Total Marks: " << total << endl;
    }
};

void demonstrateStudentTest() {
    cout << "\n=== Student-Test-Result Hierarchy ===" << endl;
    
    Result r;
    int roll;
    float m1, m2;
    
    cout << "Enter roll number: ";
    cin >> roll;
    r.setRollNumber(roll);
    
    cout << "Enter marks for subject 1: ";
    cin >> m1;
    cout << "Enter marks for subject 2: ";
    cin >> m2;
    r.setMarks(m1, m2);
    
    r.calculateTotal();
    
    cout << "\n--- Result ---" << endl;
    r.displayResult();
}

// ============================================================================
// PRACTICAL 11: Constructor in Inheritance
// ============================================================================

class Base {
protected:
    int baseValue;
    
public:
    Base() {
        baseValue = 0;
        cout << "Base default constructor" << endl;
    }
    
    Base(int val) {
        baseValue = val;
        cout << "Base parameterized constructor: " << val << endl;
    }
    
    void displayBase() {
        cout << "Base value: " << baseValue << endl;
    }
};

class Derived : public Base {
private:
    int derivedValue;
    
public:
    // Calling base class constructor
    Derived() : Base() {
        derivedValue = 0;
        cout << "Derived default constructor" << endl;
    }
    
    Derived(int bVal, int dVal) : Base(bVal) {
        derivedValue = dVal;
        cout << "Derived parameterized constructor: " << dVal << endl;
    }
    
    void display() {
        displayBase();
        cout << "Derived value: " << derivedValue << endl;
    }
};

void demonstrateConstructorInheritance() {
    cout << "\n=== Constructor in Inheritance ===" << endl;
    
    cout << "\n--- Creating object with default constructor ---" << endl;
    Derived d1;
    d1.display();
    
    cout << "\n--- Creating object with parameterized constructor ---" << endl;
    Derived d2(10, 20);
    d2.display();
}

// 11.2: This pointer demonstration
class ThisDemo {
private:
    int value;
    
public:
    ThisDemo(int value) {
        // Using 'this' pointer to distinguish between member and parameter
        this->value = value;
    }
    
    void setValue(int value) {
        this->value = value;
    }
    
    void display() {
        cout << "Value: " << this->value << endl;
        cout << "Address of this object: " << this << endl;
    }
    
    ThisDemo* returnThis() {
        return this;
    }
};

void demonstrateThisPointer() {
    cout << "\n=== This Pointer Demonstration ===" << endl;
    
    ThisDemo obj(42);
    obj.display();
    
    cout << "\nReturning 'this' pointer:" << endl;
    ThisDemo *ptr = obj.returnThis();
    cout << "Address returned: " << ptr << endl;
    
    obj.setValue(100);
    cout << "\nAfter modification:" << endl;
    obj.display();
}

// ============================================================================
// PRACTICAL 12: Polymorphism
// ============================================================================

// 12.1: Base class pointer to derived class object
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape" << endl;
    }
    
    virtual double area() {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
    
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
    
    double area() override {
        return length * width;
    }
};

void demonstratePolymorphism() {
    cout << "\n=== Polymorphism with Base Class Pointer ===" << endl;
    
    Shape *ptr;
    Circle c(5.0);
    Rectangle r(4.0, 6.0);
    
    cout << "\n--- Pointing to Circle ---" << endl;
    ptr = &c;
    ptr->draw();
    cout << "Area: " << ptr->area() << endl;
    
    cout << "\n--- Pointing to Rectangle ---" << endl;
    ptr = &r;
    ptr->draw();
    cout << "Area: " << ptr->area() << endl;
}

// 12.2: Virtual functions - Media hierarchy
class Media {
protected:
    string title;
    
public:
    Media(string t) : title(t) {}
    
    virtual void display() {
        cout << "Media: " << title << endl;
    }
};

class Tape : public Media {
private:
    int length;  // in minutes
    
public:
    Tape(string t, int l) : Media(t), length(l) {}
    
    void display() override {
        cout << "Tape - Title: " << title << ", Length: " << length << " min" << endl;
    }
};

class Book : public Media {
private:
    int pages;
    
public:
    Book(string t, int p) : Media(t), pages(p) {}
    
    void display() override {
        cout << "Book - Title: " << title << ", Pages: " << pages << endl;
    }
};

void demonstrateVirtualFunctions() {
    cout << "\n=== Virtual Functions - Media Hierarchy ===" << endl;
    
    Media *mediaPtr;
    
    Tape t("Classic Songs", 60);
    Book b("C++ Programming", 450);
    
    mediaPtr = &t;
    mediaPtr->display();
    
    mediaPtr = &b;
    mediaPtr->display();
}

// 12.3: Pure virtual functions (Abstract class)
class AbstractShape {
public:
    // Pure virtual function
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
};

class Triangle : public AbstractShape {
private:
    double base, height;
    
public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    void draw() override {
        cout << "Drawing a triangle" << endl;
    }
    
    double calculateArea() override {
        return 0.5 * base * height;
    }
};

class Square : public AbstractShape {
private:
    double side;
    
public:
    Square(double s) : side(s) {}
    
    void draw() override {
        cout << "Drawing a square" << endl;
    }
    
    double calculateArea() override {
        return side * side;
    }
};

void demonstratePureVirtual() {
    cout << "\n=== Pure Virtual Functions (Abstract Class) ===" << endl;
    
    // AbstractShape shape;  // ERROR: Cannot instantiate abstract class
    
    AbstractShape *ptr;
    Triangle t(5, 8);
    Square s(4);
    
    ptr = &t;
    ptr->draw();
    cout << "Area: " << ptr->calculateArea() << endl;
    
    ptr = &s;
    ptr->draw();
    cout << "Area: " << ptr->calculateArea() << endl;
}

// ============================================================================
// PRACTICAL 13: File I/O and Formatting
// ============================================================================

// 13.1: Put(), Get(), Getline(), Write()
void demonstrateBasicFileIO() {
    cout << "\n=== Basic File I/O Functions ===" << endl;
    
    // Put() - write single character
    cout << "Demonstrating put(): ";
    cout.put('H').put('i').put('!');
    cout << endl;
    
    // Get() - read single character
    char ch;
    cout << "Enter a character: ";
    cin.get(ch);
    cout << "You entered: " << ch << endl;
    
    // Getline() - read a line
    char line[100];
    cout << "Enter a line of text: ";
    cin.ignore();
    cin.getline(line, 100);
    cout << "You entered: " << line << endl;
    
    // Write() - write block of data
    char data[] = "Hello World";
    cout << "Using write(): ";
    cout.write(data, 5);  // Writes only first 5 characters
    cout << endl;
}

// 13.2: Formatted output using manipulators
void demonstrateFormatting() {
    cout << "\n=== Formatted Output with Manipulators ===" << endl;
    
    double pi = 3.14159265359;
    int num = 42;
    
    // Width()
    cout << "Width demonstration:" << endl;
    cout << setw(10) << num << endl;
    cout << setw(10) << "Hello" << endl;
    
    // Precision()
    cout << "\nPrecision demonstration:" << endl;
    cout << setprecision(2) << fixed << pi << endl;
    cout << setprecision(4) << fixed << pi << endl;
    
    // Fill()
    cout << "\nFill demonstration:" << endl;
    cout << setfill('*') << setw(10) << num << endl;
    cout << setfill('-') << setw(10) << "Test" << endl;
    
    // Setf() - scientific notation
    cout << "\nScientific notation:" << endl;
    cout.setf(ios::scientific);
    cout << pi << endl;
    
    // Unsetf()
    cout.unsetf(ios::scientific);
    cout << "Back to normal: " << pi << endl;
}

// 13.3: setw, setiosflags, setprecision
void demonstrateManipulators() {
    cout << "\n=== Manipulators: setw, setiosflags, setprecision ===" << endl;
    
    double value = 123.456789;
    
    cout << "Using setw and setprecision:" << endl;
    cout << setw(15) << setprecision(3) << fixed << value << endl;
    
    cout << "\nUsing setiosflags:" << endl;
    cout << setiosflags(ios::left) << setw(15) << value << endl;
    cout << setiosflags(ios::right) << setw(15) << value << endl;
    cout << setiosflags(ios::showpoint) << value << endl;
}

// 13.4: Item list with formatted output
struct Item {
    char name[30];
    int code;
    double cost;
};

void demonstrateItemList() {
    cout << "\n=== Item List with Formatted Output ===" << endl;
    
    Item items[100];
    int count;
    
    cout << "Enter number of items: ";
    cin >> count;
    cin.ignore();
    
    for (int i = 0; i < count; i++) {
        cout << "\nItem " << (i + 1) << ":" << endl;
        cout << "Enter name: ";
        cin.getline(items[i].name, 30);
        cout << "Enter code: ";
        cin >> items[i].code;
        cout << "Enter cost: ";
        cin >> items[i].cost;
        cin.ignore();
    }
    
    // Display formatted output
    cout << "\n" << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    cout << left << setw(25) << "NAME" 
         << setw(15) << "CODE" 
         << setw(15) << "COST" << endl;
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
    
    for (int i = 0; i < count; i++) {
        cout << left << setw(25) << items[i].name
             << setw(15) << items[i].code
             << setw(15) << fixed << setprecision(2) << items[i].cost << endl;
    }
    
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
}

// ============================================================================
// MAIN FUNCTION - Menu Driven Program
// ============================================================================

int main() {
    int choice;
    
    do {
        cout << "\n========================================" << endl;
        cout << "  C++ PRACTICALS 6-13 MENU" << endl;
        cout << "========================================" << endl;
        cout << "PRACTICAL 6: Friend Functions" << endl;
        cout << "1. Sample class with friend function" << endl;
        cout << "2. Complex number with friend function" << endl;
        
        cout << "\nPRACTICAL 7: Dynamic Memory & Copy Constructor" << endl;
        cout << "3. String class with dynamic memory" << endl;
        cout << "4. Copy constructor demonstration" << endl;
        
        cout << "\nPRACTICAL 8: Operator Overloading" << endl;
        cout << "5. Complex number operators (+, -)" << endl;
        cout << "6. Unary minus operator" << endl;
        cout << "7. Logical OR (||) operator" << endl;
        
        cout << "\nPRACTICAL 9: Type Conversion" << endl;
        cout << "8. Basic to class type conversion" << endl;
        cout << "9. Object to object conversion" << endl;
        
        cout << "\nPRACTICAL 10: Inheritance" << endl;
        cout << "10. Inheritance types demonstration" << endl;
        cout << "11. Student-Test-Result hierarchy" << endl;
        
        cout << "\nPRACTICAL 11: Constructors in Inheritance" << endl;
        cout << "12. Base class constructor via derived" << endl;
        cout << "13. This pointer demonstration" << endl;
        
        cout << "\nPRACTICAL 12: Polymorphism" << endl;
        cout << "14. Base class pointer to derived object" << endl;
        cout << "15. Virtual functions - Media hierarchy" << endl;
        cout << "16. Pure virtual functions (Abstract class)" << endl;
        
        cout << "\nPRACTICAL 13: File I/O & Formatting" << endl;
        cout << "17. Basic File I/O functions" << endl;
        cout << "18. Formatted output manipulators" << endl;
        cout << "19. setw, setiosflags, setprecision" << endl;
        cout << "20. Item list with formatted output" << endl;
        
        cout << "\n0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: demonstrateSample(); break;
            case 2: demonstrateComplex(); break;
            case 3: demonstrateString(); break;
            case 4: demonstrateCopyConstructor(); break;
            case 5: demonstrateComplexOperators(); break;
            case 6: demonstrateUnaryOperator(); break;
            case 7: demonstrateLogicalOperator(); break;
            case 8: demonstrateTypeConversion(); break;
            case 9: demonstrateObjectConversion(); break;
            case 10: demonstrateInheritance(); break;
            case 11: demonstrateStudentTest(); break;
            case 12: demonstrateConstructorInheritance(); break;
            case 13: demonstrateThisPointer(); break;
            case 14: demonstratePolymorphism(); break;
            case 15: demonstrateVirtualFunctions(); break;
            case 16: demonstratePureVirtual(); break;
            case 17: demonstrateBasicFileIO(); break;
            case 18: demonstrateFormatting(); break;
            case 19: demonstrateManipulators(); break;
            case 20: demonstrateItemList(); break;
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
