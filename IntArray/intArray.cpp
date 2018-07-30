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
    size = abs(end-start);
    capacity = size + 1;
    lower = start;
    upper = end;
    arr = new int[size];
    if ( start > end ) {
        cout << "Run-time Error: Illegal Array Bounds." << endl;
        cout << "Diagnostic: 1st indice cannot be bigger than 2nd indice" << endl;
    }
};

IntArray::IntArray(const IntArray& original) {
    capacity = original.getCapacity();
    size = original.size;
    lower = original.lower;
    upper = original.upper;
    arr = new int[capacity];
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
    if (index > upper) {
        cout << "Run-time Error: Illegal Index." << endl;
        cout << "Diagnostic: Index out of bounds" << endl;
    }
    return arr[index];
};

//* overloads == operator *//

bool IntArray::operator==(const IntArray& comp) {
    int counter = comp.low();
    if (comp.capacity == capacity) {
        for (int i = lower; i <= upper; i++) {
            if (arr[i] != comp.arr[counter]) {
                return 0;
            }
            counter++;
        };
        return 1;
    }
    else {
        return 0;
    }
    
    
    
}
IntArray& IntArray::operator=(const IntArray& right) {
    if (right.capacity != capacity) {
        cout << "Runtime error: Length mismatch" << endl;
        
        cout << "Diagnostic: Unable to assign, lengths do not match up." << endl;
    }
    int counter = right.lower;
    
    for (int i = lower; i <= upper; i++) {
        arr[i] = right.arr[counter];
        counter++;
    }
    return *this;
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

int IntArray::getCapacity() const {
    return capacity;
}


