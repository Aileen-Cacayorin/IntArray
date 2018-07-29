//
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

IntArray::IntArray() {
    capacity = 10;
    size = capacity-1;
    lower = 0;
    upper = 9;
    arr = new int[size];
    
}

IntArray::IntArray(int num) {
    size = num -1;
    capacity = num;
    lower = 0;
    upper = size;
    arr = new int[size];
    
};

IntArray::IntArray(int start, int end) {
    capacity = abs(end) - abs(start) + 1;
    size = end;
    lower = start;
    upper = end;
    arr = new int[size];
    if ( start > end ) {
        cout << "Run-time Error: Illegal Array Bounds." << endl;
        cout << "Diagnostic: 1st indice cannot be bigger than 2nd indice" << endl;
    }
};

IntArray::IntArray(const IntArray& original) {
    capacity = original.capacity;
    size = original.size;
    lower = original.lower;
    upper = original.upper;
    arr = new int[size];
    for (int i = lower; i <= upper; i++) {
        arr[i] = original.arr[i];
    }
};



IntArray::~IntArray() {
    delete [] arr;
};


//* overloads << operator  *//
ostream& operator<<(ostream& os, const IntArray& a) {
    for (int i = a.low(); i <= a.high(); i++ )
        os << a.getName() <<"[" << i << "]" << a.arr[i] << endl;
    return os;
};

//* overloads [] operator *//
int& IntArray::operator[](int index) {
    if (index > size) {
        cout << "Run-time Error: Illegal Index." << endl;
        cout << "Diagnostic: Index cannot be bigger than size" << endl;
    }
    return arr[index];
};

void IntArray::initialize() {
    for (int i = lower; i < capacity; i++) {
        arr[i] = 0;
    }
};


void IntArray::setName(string name) {
    arrName = name;
};

string IntArray::getName()  const{
    return arrName;
}



int IntArray::low() const {
    return lower;
}

int IntArray::high() const {
    return upper;
}
