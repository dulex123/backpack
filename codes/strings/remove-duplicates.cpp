/*
{
    "name": "Remove Duplicates",
    "desc": "http://www.practice.geeksforgeeks.org/problem-page.php?pid=462",
    "tags": "strings",
    "tests": {
    }
}
*/
#include <iostream>
#include <cstring>

using namespace std;


int main() {
    bool passed[256] = {false};
    int T, index=0;
    char data[200];
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> data;

        index = 0;
        for (int j = 0; j < strlen(data); ++j)
            passed[data[j]] = true;

        for (int k = 0; k < strlen(data); ++k) {
            if(passed[data[k]] == true) {
                data[index++] = data[k];
                passed[data[k]] = false;
            }
        }
        data[index]='\0';
        cout  <<data << endl;
    }

return 0;
}
