#include <iostream>

/*----------------------------------------------------------------
 *  Problem:       Find max-sum subarray with no adjacent nodes.
 *
 *----------------------------------------------------------------*/

using namespace std;

int main() {
    int nums[] = {1, -2, 0, 8, 10, 3, -11};
    int nums_len = sizeof(nums)/sizeof(nums[0]);
    int temp_nums[nums_len];

    /* Initialize */
    temp_nums[0] = nums[0];
    temp_nums[1] = max(nums[0],nums[1]);

    for(int i=2; i < nums_len; i++)
        temp_nums[i] = max(temp_nums[i-2] + nums[i], temp_nums[i-1]);

    cout << temp_nums[nums_len-1];

    return 0;
}