

// Some operators we can use in C++

/*
//arithmetic operators, a and b must be the same object ie numbers with numbers, strings with strings ...
addition	    a + b	
subtraction	    a - b	
multiplication	a * b	
division	    a / b	
modulo	        a % b	

// Logic operators, a and b must be true or false
NOT	             !a	
AND	            a && b	
OR	            a || b
*/
// for more details visit: https://en.cppreference.com/w/cpp/language/operator_arithmetic

#include <iostream>
using namespace std;

// using operators
int main(){

    // good practice, initialize variables
    int a = 4;
    int b = 5;
    bool a2 = true;
    bool b2 = false;
    int result = 0;

    result = a + b; // result = 4 + 5 = 9
    cout<<result<<endl;

    result = a - b;// result = 4 - 5 = -1
    cout<<result<<endl;

    result = a * b;// result = 4 * 5 = 20
    cout<<result<<endl;

    result = a % b;// result = 4 % 5 = 4
    cout<<result<<endl;

    // logic operrators

    cout << a2 && b2 << endl; // prints false
    cout << a2 || b2 << endl; // prints true
    cout << !a2 <<endl; // prints false       

    return 0;
}