#include <iostream>
using namespace std;
//#define _DEBUGMODE_

int main(){

#ifdef _DEBUGMODE_
cout << "debugmode" << endl;

#endif
cout << "hello" << endl;

    return 0;
}
//g++ macrosample.cpp 