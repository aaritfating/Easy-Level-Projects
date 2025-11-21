#include <iostream>
using namespace std;

// Function declarations
void basicPointerDemo();
void swapUsingPointers();
void dynamicArrayLab();
void pointerArithmeticDemo();
void charPointerDemo();

void waitForEnter() {
    cout << "\nPress Enter to return to menu...";
    cin.ignore(10000, '\n');  // clear leftover input until newline
    cin.get();                // wait for user to press Enter
}

int main() {
    int choice;

    while (true) {
        cout << "====================================\n";
        cout << "         POINTERS PLAYGROUND        \n";
        cout << "====================================\n";
        cout << "1. Basic Pointer Demo\n";
        cout << "2. Swap Using Pointers\n";
        cout << "3. Dynamic Array Lab\n";
        cout << "4. Pointer Arithmetic Demo\n";
        cout << "5. Char Pointer Demo\n";
        cout << "6. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                basicPointerDemo();
                break;
            case 2:
                swapUsingPointers();
                break;
            case 3:
                dynamicArrayLab();
                break;
            case 4:
                pointerArithmeticDemo();
                break;
            case 5:
                charPointerDemo();
                break;
            case 6:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n\n";
    }
}

// ----------------------------------------------------
// 1️⃣ Basic Pointer Demo
// ----------------------------------------------------
void basicPointerDemo() {
    cout << "\n====== Basic Pointer Demo ======\n";

    int x;
    cout << "Enter a value for x: ";
    cin >> x;

    int* p = &x;  // p stores address of x

    cout << "\n[STEP 1] Variable and its value\n";
    cout << "  x = " << x << "\n";

    cout << "\n[STEP 2] Address of x\n";
    cout << "  &x = " << &x << "\n";

    cout << "\n[STEP 3] Pointer p stores address of x\n";
    cout << "  p  = " << p << "\n";

    cout << "\n[STEP 4] Dereferencing pointer (value at address)\n";
    cout << "  *p = " << *p << "\n";

    cout << "\n[STEP 5] Modify x using pointer (*p = *p + 10)\n";
    *p = *p + 10;

    cout << "  New x = " << x << "\n";
    cout << "  *p    = " << *p << "\n";

    waitForEnter();
}

// ----------------------------------------------------
// 2️⃣ Swap Using Pointers
// ----------------------------------------------------
void swapTwo(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingPointers() {
    cout << "\n====== Swap Using Pointers ======\n";

    int a, b;
    cout << "Enter first number (a): ";
    cin >> a;
    cout << "Enter second number (b): ";
    cin >> b;

    cout << "\nBefore swap:\n";
    cout << "  a = " << a << ", b = " << b << "\n";

    cout << "\nCalling swapTwo(&a, &b)...\n";
    swapTwo(&a, &b);

    cout << "\nAfter swap (using pointers):\n";
    cout << "  a = " << a << ", b = " << b << "\n";

    cout << "\nExplanation:\n";
    cout << "  - We passed the addresses of a and b\n";
    cout << "  - Inside swapTwo(), *a and *b directly modify original variables\n";

    waitForEnter();
}

// ----------------------------------------------------
// 3️⃣ Dynamic Array Lab
// ----------------------------------------------------
void dynamicArrayLab() {
    cout << "\n====== Dynamic Array Lab ======\n";

    int n;
    cout << "Enter size of array (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size. n should be > 0.\n";
        waitForEnter();
        return;
    }

    // Allocate memory on heap
    int* arr = new int[n];

    cout << "\nEnter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\nStored values and their addresses:\n";
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "] = " << arr[i]
             << "  at address: " << (arr + i) << "\n";
    }

    cout << "\nNow we will free the memory using delete[] arr;\n";
    delete[] arr;

    cout << "Memory freed successfully.\n";
    cout << "Note: After delete[], arr becomes a dangling pointer (invalid).\n";

    waitForEnter();
}

// ----------------------------------------------------
// 4️⃣ Pointer Arithmetic Demo
// ----------------------------------------------------
void pointerArithmeticDemo() {
    cout << "\n====== Pointer Arithmetic Demo ======\n";

    int n;
    cout << "Enter size of array for pointer demo: ";
    cin >> n;

    if (n < 3) {
        cout << "Please enter n >= 3 for a better demo.\n";
        waitForEnter();
        return;
    }

    int* arr = new int[n];

    cout << "\nEnter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cout << "  arr[" << i << "]: ";
        cin >> arr[i];
    }

    int* p = arr;  // p points to first element of array

    cout << "\nBase pointer p points to arr[0]\n";
    cout << "  p       = " << p << "\n";
    cout << "  *p      = " << *p << "  (same as arr[0])\n";

    cout << "\nNow, p + 1 points to arr[1]\n";
    cout << "  p + 1   = " << (p + 1) << "\n";
    cout << "  *(p + 1)= " << *(p + 1) << "  (same as arr[1])\n";

    cout << "\nNow, p + 2 points to arr[2]\n";
    cout << "  p + 2   = " << (p + 2) << "\n";
    cout << "  *(p + 2)= " << *(p + 2) << "  (same as arr[2])\n";

    cout << "\nLoop using pointer arithmetic (*(p + i)):\n";
    for (int i = 0; i < n; i++) {
        cout << "  *(p + " << i << ") = " << *(p + i)
             << "  (same as arr[" << i << "])\n";
    }

    delete[] arr;
    cout << "\nMemory freed.\n";

    waitForEnter();
}

// ----------------------------------------------------
// 5️⃣ Char Pointer Demo
// ----------------------------------------------------
void charPointerDemo() {
    cout << "\n====== Char Pointer Demo ======\n";

    char ch = 'A';
    char* pCh = &ch;

    cout << "[Single char demo]\n";
    cout << "  ch   = " << ch << "\n";
    cout << "  &ch  = " << (void*)&ch << "  (address of ch)\n";
    cout << "  pCh  = " << (void*)pCh << "  (pointer storing same address)\n";
    cout << "  *pCh = " << *pCh << "  (value at that address)\n";

    cout << "\n[Char array (C-style string) demo]\n";
    char name[20];
    cout << "Enter a word (no spaces): ";
    cin >> name;

    cout << "\nYou entered: " << name << "\n";

    char* pName = name;  // points to first char of array

    cout << "  pName points to first character of the string.\n";
    cout << "  pName (as C-string) = " << pName << "\n";
    cout << "  *pName (first char) = " << *pName << "\n";

    cout << "\nPrinting each character using pointer arithmetic:\n";
    for (int i = 0; pName[i] != '\0'; i++) {
        cout << "  *(pName + " << i << ") = " << *(pName + i) << "\n";
    }

    cout << "\nKey idea:\n";
    cout << "  - For char arrays, a char* is often printed as a C-string\n";
    cout << "  - That's why cout << pName prints the whole word\n";

    waitForEnter();
}
