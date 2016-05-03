/*----------------------------------------------------------------
 *  Problem:    Largest common subsequence
 *
 *  Description/Link:
 *  Find the largest common subsequence of two arrays/strings.
 *  Important: Subsequence means it is not required to occupy
 *  consecutive positions within the original sequences.
 *
 *----------------------------------------------------------------*/
#include <iostream>
#include <stack>

using namespace std;

int main() {

    string seq1 = "we are the champions of all", seq2="he is the one, he is the champion";

    stack<char> rev_out;

    int  rows = (int)seq1.length() + 1,
         cols = (int)seq2.length() + 1;

    /* Initialize DP matrix with zeros in first row/col */
    int matrix[rows][cols];

    for (int i = 0; i < rows; ++i)
        matrix[i][0] = 0 ;

    for (int i = 0; i < cols; ++i)
        matrix[0][i] = 0;

    /* Compute the matrix */
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (seq1[i-1] == seq2[j-1])
                matrix[i][j] = matrix[i-1][j-1]+1;
            else
                matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
        }
    }
    cout << "Length of LCS: " << matrix[rows-1][cols-1] << endl;

    /* Reconstruct the subsequence, greedy if different letters, i-1 j-1 if letters are the same. */
    int i = rows-1, j = cols-1;
    while(i != 0 && j != 0) {
        if( seq1[i-1] == seq2[j-1]) {
            i -=1 ;
            j -=1 ;
            rev_out.push(seq1[i]);
        } else {
            if (matrix[i-1][j] > matrix[i][j-1]) {
                i -= 1;
            }
            else {
                j -= 1;
            }
        }
    }

    cout << "Subsequence: ";
    while(!rev_out.empty()) {
        cout << rev_out.top();
        rev_out.pop();
    }


    return 0;
}