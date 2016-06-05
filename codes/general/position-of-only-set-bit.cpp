/*
{
    "name": "Find position of the only set bit",
    "desc": "http://www.practice.geeksforgeeks.org/problem-page.php?pid=638",
    "tags": "bits, bitset, logic, c, hacks",
    "tests": {
    }
}
*/
#include <iostream>

using namespace std;

/* Awesome trick - if it is power of two then only one bit is set
   when we invert it all following bits will be set and the bit will
   be inverted to zero. When we AND them we should get zero. For the
   case when n is zero we && them */
bool isPowerOfTwo(int n) {
    return n && (!(n & (n-1)));
}

int main() {

    int T;
    unsigned int N, tmp=1, pos=1;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        if(!isPowerOfTwo(N)) {
            cout << -1 << endl;
            continue;
        }
        tmp = 1, pos=1;
        while( !(tmp&N)) {
            tmp <<= 1;
            ++pos;
        }
        cout << pos << endl;

    }
return 0;
}
