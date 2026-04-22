#include <iostream>
using std::endl, std::cout;
#include "handy.h"
using handy::Timer;

//unsigned long long fib(int n){
//  if (n == 0) return 0;
//  if (n == 1) return 1;
//  return fib(n-1) + fib(n-2);
//}
/** Recursive O(n) function to calculate Fibonacci numbers
   @param fib_current The current Fibonacci number
   @param fib_previous The previous Fibonacci number
   @param n The count of Fibonacci numbers left to calculate
   @return The value of the Fibonacci number calculated so far
*/
long long fibo(long long fib_current, long long fib_previous, int n)
{
    if (n == 1) return fib_current;
    return fibo(fib_current + fib_previous, fib_current, n - 1);
}
long long fib (long long n) {
    return fibo(1,0,n);
}

int main (int argc, char * argv[]){
  Timer t;
  t.start();
  unsigned long long f = fib(atoi(argv[1]));
  t.stop();
  cout << "The " << argv[1] << " Fibinocci number is " << f << endl;
  if (t.milliseconds()){
    cout << "The claculation took " << t.milliseconds() << " milliseconds." << endl;
  } else {
    cout << "The claculation took " << t.nanoseconds() << " nanoseconds." << endl;
  }
return 0;
}