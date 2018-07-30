//
//  intArray.hpp
//  IntArray
//
//  Created by Aileen Cacayorin on 7/29/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef intArray_hpp
#define intArray_hpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

#include <stdio.h>


using namespace std;

class IntArray {
public:
    IntArray();
    IntArray(int num);
    IntArray(int start, int end);
    IntArray(const IntArray&);
    ~IntArray();
    void setName(string name);
    friend ostream& operator<<(ostream& os,const IntArray& a);    // overloads << operator
    int& operator[](int index);             // overloads [] operator
    IntArray& operator=(const IntArray&);       // overloads assignemtn operator
    bool operator==(const IntArray&);           // overloads == operator //
    bool operator!=(const IntArray&);
    friend IntArray operator+(IntArray, IntArray);
    int low() const;
    int high() const;
    string getName() const;
    int getCapacity() const;
    
    
    
private:
    int capacity;
    int size;
    int lower;
    int upper;
    int *arr;
    string arrName;
};

#endif /* intArray_hpp */
