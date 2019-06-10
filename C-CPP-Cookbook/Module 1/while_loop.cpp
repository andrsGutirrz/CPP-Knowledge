#include <iostream>
using namespace std;

// IMPORTANT!! We are going to work with them for the rest of our lives as well in this repo!
int main(){

    /*
    All the lopp statements, need a boolean condition (true/false). It says when to stop the loop
    There are many ways to implement the while loop
    Some times we use a int variable for controling the loop, and we increment the variable inside 
    the while block
    We can broke a loop when we need it, using the key word 'break'
    */

    // Basic while structure 
    while(true){ //infinite loop
        //code
        break; //We use break to stop the loop, no matter the condition, we stop it when we want
    }

    // Using a variable exaple
    int c = 0; 
    while(c<10){ //will iterate 10 times, from 0 to 10, NOTE that 10 can be a variable as well
        //code
        cout<<"Number: "<<c<<endl;//0,1,2,3,4,5,6,7,8,9
        c++; //incremente value 
    }

    //When found something throw the loop
    // Stop the loop when find 55
    int c = 0;
    int total = 1000; 
    while(c<total){// will iterate 1000 times
        if(c == 55){ // if statement, we will see that later
            cout<<"Number found!"<<endl;
        }
        c++;// incremente value, theres is a way to avoid this line
    }

    // avoid a line
    int c = 0; 
    while(c<10){ //will iterate 10 times, from 0 to 10, NOTE that 10 can be a variable as well
        //code
        cout<<"Number: "<<c++<<endl;//0,1,2,3,4,5,6,7,8,9
        //c++; //incremente value 
        //Note that we increment the c value when we print it
    }

    //using a boolean flag
    bool condition = true;
    while(condition){
        //code
        //something you want to detect, then you want to stop loop
        condition = false;
    }
    
    return 0;
}// end main