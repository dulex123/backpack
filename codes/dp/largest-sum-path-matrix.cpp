/*----------------------------------------------------------------
 *  Problem:       Largest sum path within matrix
 *
 * Given a matrix A, and valid moves only down and right, find
 * maximum sum path from 0,0 to n,n
 *----------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main() {
    int n=4, m=5;
    int A[n][m] = {
        {1, 3, 1, 0, 0},
        {-11, 4, 10, -10, 8},
        {4, 2, 5, 7, 0},
        {10, 1, -2, 1, 1}
    };

    int D[n][m];
    D[0][0] = A[0][0];

    for(int i=1; i<n; i++)
        D[i][0] = D[i-1][0] + A[i][0];

    for(int i=1; i<m; i++)
        D[0][i] = D[0][i-1] + A[0][i];

    for(int i=1; i<n; i++)
        for(int j=1; j<m; j++)
            D[i][j] = max(D[i-1][j],D[i][j-1]) + A[i][j];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout << D[i][j] << " ";

        cout << endl;
    }

    /*
     * Reconstruction of the path can be done with greedy approach
     * starting at D[n][m] and going back to 0,0 only with up and left
     * movements
     */

    cout << endl;
    cout << "Result is: " << D[n-1][m-1];

    return 0;
}