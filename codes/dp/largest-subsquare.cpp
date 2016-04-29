/*----------------------------------------------------------------
 *  Problem:       Largest subsquare
 *
 *  Easy and practical dp problem.
 *  For a given boolean matrix, find largest square of 0s.
 *----------------------------------------------------------------*/

#include <iostream>

using namespace std;

int largestSquare(bool  matrix[200][200], int rows, int cols) {

    int i,j;
    int temp[rows][cols] = {0};

    /* First row is the same */
    for(i=0; i<cols; i++)
        temp[0][i] = matrix[0][i];

    /* First column is the same */
    for(i=0; i<rows; i++)
        temp[i][0] = matrix[i][0];

    for(i=1; i<rows; i++)
        for(j=1; j<cols; j++)
            if(matrix[i][j] == 1)
                temp[i][j] = min(temp[i-1][j], min( temp[i][j-1], temp[i-1][j-1])) + 1;
            else
                temp[i][j] = 0;


    /* Find max of a matrix */
    int max=temp[0][0];
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            if(max < temp[i][j])
                max = temp[i][j];

    return max;
}

int main() {

    int i, j, rows, cols;
    bool matrix[200][200];

    /* Size of the matrix */
    cin >> rows >> cols;

    /* Read matrix from stdin */
    for( i=0; i<rows; i++)
        for( j=0; j<cols; j++)
            cin >> matrix[i][j];

    cout << largestSquare(matrix, rows, cols);

    return 0;
}
