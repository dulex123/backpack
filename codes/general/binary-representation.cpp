/*----------------------------------------------------------------
 *  Problem: Binary representation
 *
 *  Description/Link: 
 *  http://www.practice.geeksforgeeks.org/problem-page.php?pid=602
 *
 *
 *----------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>

using namespace std;

int stac_k[100], point=0;

int pop() {
    if(point != 0)
        return stac_k[--point];
    else
        return 0;
}

void push(int val) {
    stac_k[point++] = val;
}

void empty() {
    point=0;
}

int main() {
    int number, T;

    cin >> T;
    for (int k = 0; k < T; ++k) {
        cin >> number;
        /* Standard boring way
        for (int i = 0; i < 14; i++) {
            push(number % 2);
            number /= 2;
        }
        for (int j = 0; j < 14; ++j)
            cout << pop();
        */

        /* So much better :) */
        for (unsigned int i = 1<<13; i > 0; i >>= 1)
            (number & i) ? cout << 1 : cout << 0;

        cout << "\n";
    }

return 0;
}
