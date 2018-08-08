// Name: Aileen Cacayorin
// Palomar ID: 011519388
// Title: IntArray Lab
// Compiler: XCode 9.2

//  intArray.cpp
//  IntArray
//
//  Created by Aileen Cacayorin on 7/29/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.

//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "intArray.hpp"

using namespace std;

extern ofstream csis;

IntArray::IntArray() {
    capacity = 10;
    size = capacity;
    lower = 0;
    upper = 9;
    arr = new int[size];
    
};

IntArray::IntArray(int num) {
    size = num;
    capacity = num;
    lower = 0;
    upper = size-1;
    arr = new int[size];
    
};

IntArray::IntArray(int start, int end) {
    size = abs(end-start)+1;
    capacity = size;
    lower = start;
    upper = end;
    arr = new int[size];
    if ( start > end ) {
        cout << "Run-time Error: Illegal Array Bounds." << endl;
        csis << "Run-time Error: Illegal Array Bounds." << endl;
        cout << "Diagnostic: 1st indice cannot be bigger than 2nd indice" << endl;
        csis << "Diagnostic: 1st indice cannot be bigger than 2nd indice" << endl;
    }
};

IntArray::IntArray(const IntArray& original) {
    capacity = original.getCapacity();
    size = original.size;
    lower = original.lower;
    upper = original.upper;
    arr = new int[size];
    for (int i = 0; i < capacity; i++) {
        arr[i] = original.arr[i];
    }
};


IntArray::~IntArray() {
    delete[] arr;
};


//* overloads << operator  *//
ostream& operator<<(ostream& os, const IntArray& a) {
    int counter = a.low();
    for (int i = 0; i < a.getCapacity(); i++ ) {
            os << a.getName() <<"[" << counter << "]" << "=" << a.arr[i] << endl;
            counter++;
        }
    return os;
};

//* overloads [] operator *//
int& IntArray::operator[](int index) {
    if (index > upper) {
        cout << "Run-time Error: Illegal Index." << endl;
        csis << "Run-time Error: Illegal Index." << endl;
        cout << "Diagnostic: Index out of bounds" << endl;
        csis << "Diagnostic: Index out of bounds" << endl;
    }
    return arr[index-lower];
};

//* overloads = operator *//

IntArray& IntArray::operator=(const IntArray& right) {
    if (right.capacity != capacity) {
        cout << "Runtime error: Length mismatch" << endl;
        csis << "Runtime error: Length mismatch" << endl;
        cout << "Diagnostic: Unable to assign, lengths do not match up." << endl;
        csis << "Diagnostic: Unable to assign, lengths do not match up." << endl;
    }


    for (int i = 0; i < capacity; i++) {
        arr[i] = right.arr[i];
    }
    return *this;
};

//* overloads == operator *//

bool IntArray::operator==(const IntArray& comp) {
    if (comp.capacity == capacity) {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != comp.arr[i]) {
                return 0;
            }
        };
        return 1;
    }
    else {
        return 0;
    }
    
};

// overloads != operator //
bool IntArray::operator!=(const IntArray& comp) {
    return !(*this == comp);
};

//* overloads + operator *//

IntArray operator+(IntArray a1, IntArray a2) {
    IntArray temp(a1);
    for (int i = 0; i < temp.getCapacity(); i++) {
        temp.arr[i] += a2.arr[i];
    }
    return IntArray(temp);
    
};

//* overloads += operator *//
void IntArray::operator+=(const IntArray& add) {
    for (int i = 0; i < capacity; i++ ) {
        arr[i]+=  add.arr[i];
    }
};



void IntArray::setName(string name) {
    arrName = name;
};

string IntArray::getName()  const{
    return arrName;
};

int IntArray::low() const {
    return lower;
};

int IntArray::high() const {
    return upper;
};

int IntArray::getCapacity() const {
    return capacity;
};


