 #include <iostream>
 using namespace std;

// IMPORTANT!! We are going to work with them for the rest of our lives as well in this repo!
int main(){
  //FOR LOOP
  /*
      As a loop, we need a somewhere to start and finish
      the for statement has 3 params
      1) is where we start the loop (int i = 0), it means that the loop will start at 0
      2) Condition to stop (i < 10), is when the loop will stop moving, a huge amount of errors
         is due to this part, because people create infinite loop, it cannot be computed.
         In this case, the loop will move 10 times, starting with 0 to 9, so the variable
         i will take those values
      3) The increment statement (i++) it says that the value of the stop condition will increment its
         value, in order to achieve the stop condition!
      Note1: If we dont privide the params, the for will work ass a infinite loop
      Note2: Insteat of increment variable, we can decrement, usen i--
  */
    // Basic for example
    for(int i=0;i<10;i++){
        cout<<"value: "<<i<<endl;// 0,1,2,3,4,5,6,7,8,9
    }

    //we can chanche the number 10 for a variable
    int stop = 10;
    for(int i=0;i<stop;i++){
        cout<<"value: "<<i<<endl;// 0,1,2,3,4,5,6,7,8,9
    }

    //Infinite LOOP
    for(;;){
      //code
    }

    //decrement
    for (int i = 9; i <= 0; i--) { // 9,8,7,6,5,4,3,2,1,0
      // code
    }

    // we can also do crazy stuff here, we can iterate chars
    for(char c ='A';c<'Z';c++){
      // A,B,C,D,....,Z
    }
    
    for(char c ='A';c<'z';c++){
      // A,B,C,D,...,z,1,2,3..9,a,b,c,d...,z
    }

  return 0;
} // end main
