#include <cstdlib>  // atof
#include <iostream>
#include <string>
using namespace std;
const double EPSILON = 0.0001;
// :)
int main(int argc, char*argv[]) {
    double userInput = stod(argv[1]);
    //We can't have negative numbers
    if (userInput< 0) {
        cout << "Input must be greater than 0" << endl;
        return 1;
    }
    double lowerBound = 0.0;
    double upperBound = userInput;
    double midPoint = (lowerBound + upperBound)/2.0;
    while (abs(midPoint * midPoint - userInput) > EPSILON) {
        cout << midPoint << " (" << midPoint * midPoint << ")" << endl;
        //We need to adjust our upper bound, we are too high, upper bounds is the midpoint
        if (midPoint * midPoint > userInput) {
            upperBound = midPoint;
        }
        //too small, it needs to become the lowerbound
        else {
            lowerBound = midPoint;
        }
        midPoint = (lowerBound + upperBound)/2.0;
    }
    cout << midPoint << " (" << midPoint * midPoint << ")" << endl;
}

