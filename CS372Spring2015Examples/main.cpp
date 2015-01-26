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
#include <utility>
#include <list>
using std::list;
#include <vector>
using std::vector;

template <typename T>
void foo(T& i)
{
    i++;
}

template <typename Func, typename T>
void callFunc(Func f, T i)
{
    f(i);
}

constexpr int fac(int n)
{
    return n==0 ?
        1 :
        n*fac(n-1);
}

template <typename Container>
auto maxValue(const Container &c) -> typename std::remove_reference<decltype(c.front())>::type
{
    //Containter::value_type biggest;
    auto biggest = c.front();
    for(const auto &x : c)
    {
        if(x>biggest)
            biggest = x;
    }
    return biggest;
}

template <typename T, typename R>
auto add(T t, R r) -> decltype(t+r)
{
    return t+r;
}
         
int main() {
    auto x=5;
    cout << x << endl;
    //    foo(x);
    callFunc(foo<int>,std::ref(x));
    cout << "Now x is " << x << endl;
    cout << fac(11) << endl;
    static_assert(fac(11)==39916800, "Wrong value for fac(11)");
    
    const vector<int> l{1,2,3,13,4,5};
    
//    for(auto i=l.begin();i!=l.end();++i)
//        cout << *i << " ";
    
    decltype(l) l2;
    
    for(auto i:l)
        cout << i << " ";
  
    cout << endl;
    
    cout << maxValue(l) << endl;
    
    cout << add(4.3, 13) << endl;
    return 0;
}
