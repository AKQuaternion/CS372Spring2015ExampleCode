//
//  main.cpp
//  CS372Spring2015Examples
//
//  Created by Chris Hartman on 1/26/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void foo(T& i)
{
    i++;
}

int main() {
    int x=5;
    cout << x << endl;
    foo(x);
    cout << "Now x is " << x << endl;
    return 0;
}
