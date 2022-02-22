#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
    public:
    /*
     * reveser the array in place
     * @param nums: an array
     * @return: None
     */
    void reverseArray(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

    }

};

int main (int argc, char *argv[])
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
    Solution sol;

    // vector<int> res = sol.rotate(nums, 3);
    sol.reverseArray(nums);

    for (auto & i: nums)
        cout << i << endl;

    return 0;
}
