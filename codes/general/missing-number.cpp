/*
{
    "name": "Find the Missing Number from 1 to n-1",
    "desc": "http://www.practice.geeksforgeeks.org/problem-page.php?pid=414",
    "tags": "bits, bitset, logic, c, hacks, mathish",
    "tests": {
    }
}
*/
#include <iostream>

using namespace std;


int main() {

    int T, num, tmp, sum=0;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> num;
        sum = 0;
        /* Calculate the sum of first n nums */
        sum = (num+1)*(num+2)/2;

        /* Substract every given num until the only one remains */
        for(int k=0; k<num; k++) {
            cin >> tmp;
            sum -= tmp;
        }
        cout << sum << endl;
    }
return 0;
}
