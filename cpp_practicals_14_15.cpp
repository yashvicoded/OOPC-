/*
================================================================================
C++ PRACTICALS 14-15 - FILE HANDLING & ADVANCED INHERITANCE
================================================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

// ============================================================================
// PRACTICAL 14: File Handling
// ============================================================================

// 14.1: File operations with constructor, open, and various file modes
void demonstrateFileOperations() {
    cout << "\n=== File Operations with Different Modes ===" << endl;
    
    // 1. Using constructor to open file (write mode)
    cout << "\n--- Method 1: Constructor ---" << endl;
    ofstream outFile1("test1.txt");
    if (outFile1) {
        outFile1 << "File created using constructor (default mode)" << endl;
        outFile1 << "This is line 2" << endl;
        cout << "File 'test1.txt' created successfully using constructor!" << endl;
        outFile1.close();
    } else {
        cout << "Error creating file!" << endl;
    }
    
    // 2. Using open() function with ios::out
    cout << "\n--- Method 2: open() with ios::out ---" << endl;
    ofstream outFile2;
    outFile2.open("test2.txt", ios::out);
    if (outFile2.is_open()) {
        outFile2 << "File opened with ios::out mode" << endl;
        cout << "File 'test2.txt' created successfully!" << endl;
        outFile2.close();
    }
    
    // 3. Append mode (ios::app)
    cout << "\n--- Method 3: Append mode (ios::app) ---" << endl;
    ofstream outFile3;
    outFile3.open("test2.txt", ios::app);
    if (outFile3.is_open()) {
        outFile3 << "This line is appended to existing file" << endl;
        cout << "Data appended to 'test2.txt'!" << endl;
        outFile3.close();
    }
    
    // 4. Read mode
    cout << "\n--- Method 4: Read mode (ios::in) ---" << endl;
    ifstream inFile;
    inFile.open("test2.txt", ios::in);
    if (inFile.is_open()) {
        cout << "Contents of test2.txt:" << endl;
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    
    // 5. Binary mode
    cout << "\n--- Method 5: Binary mode (ios::binary) ---" << endl;
    ofstream binFile("test3.bin", ios::binary);
    if (binFile) {
        int num = 12345;
        binFile.write((char*)&num, sizeof(num));
        cout << "Binary data written to 'test3.bin'" << endl;
        binFile.close();
    }
    
    // 6. Read and Write mode
    cout << "\n--- Method 6: Read and Write (ios::in | ios::out) ---" << endl;
    fstream file;
    file.open("test4.txt", ios::in | ios::out | ios::trunc);
    if (file.is_open()) {
        file << "This file is opened in read/write mode" << endl;
        file.seekg(0);  // Move to beginning
        string content;
        getline(file, content);
        cout << "Read from file: " << content << endl;
        file.close();
    }
    
    // Summary
    cout << "\n=== File Mode Summary ===" << endl;
    cout << "ios::in     - Open for reading" << endl;
    cout << "ios::out    - Open for writing (overwrites)" << endl;
    cout << "ios::app    - Append to end of file" << endl;
    cout << "ios::ate    - Open and seek to end" << endl;
    cout << "ios::trunc  - Truncate file if exists" << endl;
    cout << "ios::binary - Open in binary mode" << endl;
}

// 14.2: File positioning functions
void demonstrateFilePositioning() {
    cout << "\n=== File Positioning Functions ===" << endl;
    
    // Create a test file
    ofstream outFile("position_test.txt");
    outFile << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    outFile << "0123456789" << endl;
    outFile.close();
    
    // Open file for reading
    ifstream inFile("position_test.txt");
    
    if (inFile.is_open()) {
        // 1. Seekg() - Set get pointer position
        cout << "\n--- Seekg() - Move read position ---" << endl;
        inFile.seekg(5, ios::beg);  // Move 5 positions from beginning
        char ch;
        inFile.get(ch);
        cout << "Character at position 5: " << ch << endl;
        
        // 2. Tellg() - Get current position of get pointer
        cout << "\n--- Tellg() - Get current position ---" << endl;
        streampos pos = inFile.tellg();
        cout << "Current position: " << pos << endl;
        
        // 3. Seekg with different positions
        cout << "\n--- Seekg() with different origins ---" << endl;
        inFile.seekg(0, ios::beg);     // Beginning
        inFile.get(ch);
        cout << "From beginning (0): " << ch << endl;
        
        inFile.seekg(-5, ios::end);    // 5 positions before end
        inFile.get(ch);
        cout << "5 positions from end: " << ch << endl;
        
        inFile.seekg(10, ios::beg);    // 10 positions from beginning
        inFile.get(ch);
        cout << "At position 10: " << ch << endl;
        
        inFile.close();
    }
    
    // Demonstrate with write operations
    cout << "\n--- Seekp() and Tellp() - Write operations ---" << endl;
    fstream file("position_test.txt", ios::in | ios::out);
    
    if (file.is_open()) {
        // Tellp() - Get current write position
        streampos writePos = file.tellp();
        cout << "Initial write position: " << writePos << endl;
        
        // Seekp() - Set write position
        file.seekp(5, ios::beg);
        cout << "Write position after seekp(5): " << file.tellp() << endl;
        
        file << "12345";  // Overwrite 5 characters
        
        file.close();
        
        // Read modified file
        ifstream checkFile("position_test.txt");
        cout << "\nModified file contents:" << endl;
        string line;
        while (getline(checkFile, line)) {
            cout << line << endl;
        }
        checkFile.close();
    }
}

// 14.3: Put(), Get(), Write(), Read() functions
void demonstrateFileIOFunctions() {
    cout << "\n=== File I/O Functions ===" << endl;
    
    // 1. Put() - Write single character
    cout << "\n--- Put() - Write single character ---" << endl;
    ofstream outFile1("put_test.txt");
    if (outFile1) {
        outFile1.put('H');
        outFile1.put('e');
        outFile1.put('l');
        outFile1.put('l');
        outFile1.put('o');
        cout << "Characters written using put()" << endl;
        outFile1.close();
    }
    
    // 2. Get() - Read single character
    cout << "\n--- Get() - Read single character ---" << endl;
    ifstream inFile1("put_test.txt");
    if (inFile1) {
        char ch;
        cout << "Reading characters: ";
        while (inFile1.get(ch)) {
            cout << ch;
        }
        cout << endl;
        inFile1.close();
    }
    
    // 3. Write() - Write block of data
    cout << "\n--- Write() - Write block of data ---" << endl;
    struct Student {
        char name[50];
        int rollNo;
        float marks;
    };
    
    Student s1;
    strcpy(s1.name, "John Doe");
    s1.rollNo = 101;
    s1.marks = 85.5;
    
    ofstream outFile2("student.dat", ios::binary);
    if (outFile2) {
        outFile2.write((char*)&s1, sizeof(s1));
        cout << "Student record written using write()" << endl;
        outFile2.close();
    }
    
    // 4. Read() - Read block of data
    cout << "\n--- Read() - Read block of data ---" << endl;
    Student s2;
    ifstream inFile2("student.dat", ios::binary);
    if (inFile2) {
        inFile2.read((char*)&s2, sizeof(s2));
        cout << "Student record read using read():" << endl;
        cout << "Name: " << s2.name << endl;
        cout << "Roll No: " << s2.rollNo << endl;
        cout << "Marks: " << s2.marks << endl;
        inFile2.close();
    }
    
    // 5. Combined example
    cout << "\n--- Combined Example ---" << endl;
    ofstream outFile3("mixed.txt");
    if (outFile3) {
        // Using put()
        outFile3.put('A');
        outFile3.put(' ');
        
        // Using write()
        char data[] = "Hello World";
        outFile3.write(data, 11);
        
        cout << "Mixed data written to file" << endl;
        outFile3.close();
    }
    
    ifstream inFile3("mixed.txt");
    if (inFile3) {
        cout << "Reading mixed data: ";
        char ch;
        while (inFile3.get(ch)) {
            cout << ch;
        }
        cout << endl;
        inFile3.close();
    }
}

// Complete demonstration combining all file operations
void completeFileHandlingDemo() {
    cout << "\n=== Complete File Handling Demonstration ===" << endl;
    
    string filename;
    int choice;
    
    cout << "Enter filename to work with: ";
    cin >> filename;
    
    do {
        cout << "\n--- File Operations Menu ---" << endl;
        cout << "1. Create/Write to file" << endl;
        cout << "2. Read from file" << endl;
        cout << "3. Append to file" << endl;
        cout << "4. Display file size" << endl;
        cout << "5. Check if file exists" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                ofstream file(filename);
                if (file) {
                    cout << "Enter text (end with empty line):" << endl;
                    string line;
                    while (getline(cin, line) && !line.empty()) {
                        file << line << endl;
                    }
                    file.close();
                    cout << "File written successfully!" << endl;
                }
                break;
            }
            case 2: {
                ifstream file(filename);
                if (file) {
                    cout << "\nFile contents:" << endl;
                    cout << "----------------------------------------" << endl;
                    string line;
                    while (getline(file, line)) {
                        cout << line << endl;
                    }
                    cout << "----------------------------------------" << endl;
                    file.close();
                } else {
                    cout << "File not found!" << endl;
                }
                break;
            }
            case 3: {
                ofstream file(filename, ios::app);
                if (file) {
                    cout << "Enter text to append: ";
                    string text;
                    getline(cin, text);
                    file << text << endl;
                    file.close();
                    cout << "Text appended successfully!" << endl;
                }
                break;
            }
            case 4: {
                ifstream file(filename, ios::ate);
                if (file) {
                    streampos size = file.tellg();
                    cout << "File size: " << size << " bytes" << endl;
                    file.close();
                } else {
                    cout << "File not found!" << endl;
                }
                break;
            }
            case 5: {
                ifstream file(filename);
                if (file) {
                    cout << "File exists!" << endl;
                    file.close();
                } else {
                    cout << "File does not exist!" << endl;
                }
                break;
            }
        }
    } while (choice != 0);
}

// ============================================================================
// PRACTICAL 15: Advanced Inheritance
// ============================================================================

// 15.1: Single Inheritance with different access specifiers
class StudentBase {
protected:
    int rollNumber;
    string name;
    
public:
    void setStudentInfo(int roll, string n) {
        rollNumber = roll;
        name = n;
    }
    
    void displayStudentInfo() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
    }
};

class TestMarks : public StudentBase {
protected:
    float subject1, subject2;
    
public:
    void setMarks(float s1, float s2) {
        subject1 = s1;
        subject2 = s2;
    }
    
    void displayMarks() {
        cout << "Subject 1 Marks: " << subject1 << endl;
        cout << "Subject 2 Marks: " << subject2 << endl;
    }
};

class Result : public TestMarks {
private:
    float totalMarks;
    float percentage;
    
public:
    void calculateResult() {
        totalMarks = subject1 + subject2;
        percentage = (totalMarks / 200) * 100;
    }
    
    void displayResult() {
        cout << "\n=== Student Result ===" << endl;
        displayStudentInfo();
        displayMarks();
        cout << "Total Marks: " << totalMarks << " / 200" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        
        if (percentage >= 75)
            cout << "Grade: A" << endl;
        else if (percentage >= 60)
            cout << "Grade: B" << endl;
        else if (percentage >= 45)
            cout << "Grade: C" << endl;
        else if (percentage >= 33)
            cout << "Grade: D" << endl;
        else
            cout << "Grade: F (Failed)" << endl;
    }
};

void demonstrateSingleInheritance() {
    cout << "\n=== Single Inheritance Demonstration ===" << endl;
    
    Result student;
    int roll;
    string name;
    float m1, m2;
    
    cout << "Enter Roll Number: ";
    cin >> roll;
    cin.ignore();
    
    cout << "Enter Name: ";
    getline(cin, name);
    
    cout << "Enter marks for Subject 1 (out of 100): ";
    cin >> m1;
    
    cout << "Enter marks for Subject 2 (out of 100): ";
    cin >> m2;
    
    student.setStudentInfo(roll, name);
    student.setMarks(m1, m2);
    student.calculateResult();
    student.displayResult();
}

// 15.2: Demonstrating access specifiers in inheritance

// Example with PUBLIC inheritance
class PublicBase {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
    
public:
    PublicBase() {
        publicVar = 1;
        protectedVar = 2;
        privateVar = 3;
    }
    
    void showBase() {
        cout << "Base class can access all:" << endl;
        cout << "Public: " << publicVar << endl;
        cout << "Protected: " << protectedVar << endl;
        cout << "Private: " << privateVar << endl;
    }
};

class PublicDerived : public PublicBase {
public:
    void showDerived() {
        cout << "Derived (public inheritance) can access:" << endl;
        cout << "Public: " << publicVar << " - accessible" << endl;
        cout << "Protected: " << protectedVar << " - accessible" << endl;
        // cout << "Private: " << privateVar << " - NOT accessible" << endl;
    }
};

// Example with PROTECTED inheritance
class ProtectedDerived : protected PublicBase {
public:
    void showDerived() {
        cout << "Derived (protected inheritance):" << endl;
        cout << "Public becomes Protected: " << publicVar << " - accessible" << endl;
        cout << "Protected remains Protected: " << protectedVar << " - accessible" << endl;
    }
};

// Example with PRIVATE inheritance
class PrivateDerived : private PublicBase {
public:
    void showDerived() {
        cout << "Derived (private inheritance):" << endl;
        cout << "Public becomes Private: " << publicVar << " - accessible" << endl;
        cout << "Protected becomes Private: " << protectedVar << " - accessible" << endl;
    }
};

void demonstrateAccessSpecifiers() {
    cout << "\n=== Access Specifiers in Inheritance ===" << endl;
    
    cout << "\n--- PUBLIC Inheritance ---" << endl;
    PublicDerived pd;
    pd.publicVar = 10;  // Accessible
    pd.showDerived();
    pd.showBase();      // Base public method accessible
    
    cout << "\n--- PROTECTED Inheritance ---" << endl;
    ProtectedDerived protD;
    // protD.publicVar = 10;  // NOT accessible (now protected)
    protD.showDerived();
    // protD.showBase();  // NOT accessible (now protected)
    
    cout << "\n--- PRIVATE Inheritance ---" << endl;
    PrivateDerived privD;
    // privD.publicVar = 10;  // NOT accessible (now private)
    privD.showDerived();
    // privD.showBase();  // NOT accessible (now private)
    
    cout << "\n=== Access Summary ===" << endl;
    cout << "PUBLIC inheritance:" << endl;
    cout << "  - Public members remain Public" << endl;
    cout << "  - Protected members remain Protected" << endl;
    cout << "  - Private members are NOT accessible" << endl;
    
    cout << "\nPROTECTED inheritance:" << endl;
    cout << "  - Public members become Protected" << endl;
    cout << "  - Protected members remain Protected" << endl;
    cout << "  - Private members are NOT accessible" << endl;
    
    cout << "\nPRIVATE inheritance:" << endl;
    cout << "  - Public members become Private" << endl;
    cout << "  - Protected members become Private" << endl;
    cout << "  - Private members are NOT accessible" << endl;
}

// 15.3: Complete Student-Test-Result System
class StudentInfo {
protected:
    int rollNumber;
    string name;
    string department;
    
public:
    void inputStudentInfo() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        
        cout << "Enter Name: ";
        getline(cin, name);
        
        cout << "Enter Department: ";
        getline(cin, department);
    }
    
    void displayStudentInfo() {
        cout << "\n--- Student Information ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }
};

class TestInfo : public StudentInfo {
protected:
    float theory[3];    // Theory marks for 3 subjects
    float practical[3]; // Practical marks for 3 subjects
    string subjects[3];
    
public:
    void inputTestInfo() {
        subjects[0] = "Mathematics";
        subjects[1] = "Physics";
        subjects[2] = "Chemistry";
        
        cout << "\n--- Enter Test Marks ---" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "\n" << subjects[i] << ":" << endl;
            cout << "  Theory marks (out of 100): ";
            cin >> theory[i];
            cout << "  Practical marks (out of 50): ";
            cin >> practical[i];
        }
    }
    
    void displayTestInfo() {
        cout << "\n--- Subject-wise Marks ---" << endl;
        cout << left << setw(15) << "Subject" 
             << setw(12) << "Theory" 
             << setw(12) << "Practical" 
             << "Total" << endl;
        cout << string(50, '-') << endl;
        
        for (int i = 0; i < 3; i++) {
            cout << left << setw(15) << subjects[i]
                 << setw(12) << theory[i]
                 << setw(12) << practical[i]
                 << (theory[i] + practical[i]) << endl;
        }
    }
};

class FinalResult : public TestInfo {
private:
    float totalTheory;
    float totalPractical;
    float grandTotal;
    float percentage;
    string grade;
    
public:
    void calculateResult() {
        totalTheory = 0;
        totalPractical = 0;
        
        for (int i = 0; i < 3; i++) {
            totalTheory += theory[i];
            totalPractical += practical[i];
        }
        
        grandTotal = totalTheory + totalPractical;
        percentage = (grandTotal / 450) * 100;
        
        // Calculate grade
        if (percentage >= 90)
            grade = "A+";
        else if (percentage >= 80)
            grade = "A";
        else if (percentage >= 70)
            grade = "B+";
        else if (percentage >= 60)
            grade = "B";
        else if (percentage >= 50)
            grade = "C";
        else if (percentage >= 40)
            grade = "D";
        else
            grade = "F";
    }
    
    void displayCompleteResult() {
        cout << "\n" << string(60, '=') << endl;
        cout << "          STUDENT RESULT CARD" << endl;
        cout << string(60, '=') << endl;
        
        displayStudentInfo();
        displayTestInfo();
        
        cout << "\n--- Overall Result ---" << endl;
        cout << "Total Theory Marks: " << totalTheory << " / 300" << endl;
        cout << "Total Practical Marks: " << totalPractical << " / 150" << endl;
        cout << "Grand Total: " << grandTotal << " / 450" << endl;
        cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;
        
        if (grade == "F") {
            cout << "\nStatus: FAILED" << endl;
        } else {
            cout << "\nStatus: PASSED" << endl;
        }
        
        cout << string(60, '=') << endl;
    }
};

void demonstrateCompleteSystem() {
    cout << "\n=== Complete Student Result System ===" << endl;
    
    FinalResult student;
    
    cout << "\nEnter Student Details:" << endl;
    student.inputStudentInfo();
    student.inputTestInfo();
    student.calculateResult();
    student.displayCompleteResult();
}

// ============================================================================
// MAIN FUNCTION - Menu Driven Program
// ============================================================================

int main() {
    int choice;
    
    do {
        cout << "\n========================================" << endl;
        cout << "  C++ PRACTICALS 14-15 MENU" << endl;
        cout << "========================================" << endl;
        
        cout << "\nPRACTICAL 14: File Handling" << endl;
        cout << "1. File Operations (Constructor, open, modes)" << endl;
        cout << "2. File Positioning (Seekg, Tellg, Seekp, Tellp)" << endl;
        cout << "3. File I/O Functions (Put, Get, Write, Read)" << endl;
        cout << "4. Complete File Handling Demo" << endl;
        
        cout << "\nPRACTICAL 15: Advanced Inheritance" << endl;
        cout << "5. Single Inheritance (Student-Test-Result)" << endl;
        cout << "6. Access Specifiers Demonstration" << endl;
        cout << "7. Complete Student Result System" << endl;
        
        cout << "\n0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                demonstrateFileOperations();
                break;
            case 2:
                demonstrateFilePositioning();
                break;
            case 3:
                demonstrateFileIOFunctions();
                break;
            case 4:
                completeFileHandlingDemo();
                break;
            case 5:
                demonstrateSingleInheritance();
                break;
            case 6:
                demonstrateAccessSpecifiers();
                break;
            case 7:
                demonstrateCompleteSystem();
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
