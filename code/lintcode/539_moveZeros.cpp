#include <iostream>
#include <vector>

using namespace std;

class Solution
    {
        public:
        // brute force
        void moveZeros(vector<int> &nums)
        {
            vector<int> _nums(nums.size(), 0);
            for (size_t i = 0, j = 0; i < nums.size(); i++){
                if (nums[i]) _nums[j++] = nums[i];
            }
            nums = _nums;
        }


        // better version
        void moveZeros2(vector<int> &nums)
        {
            int left = 0, right = 0;
            while (right < nums.size())
            {
                if (nums[right]) {
                    nums[left] = nums[right];
                    left++;
                }
                right++;
            }
            while (left < nums.size())
            {
                nums[left] = 0;
                left++;
            }
        }

    };

int main (int argc, char *argv[])
{
    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0, 0, 0, 3, 1};

    Solution sol;
    sol.moveZeros2(nums2);

    for (auto & i: nums2)
    cout << i << endl;

    return 0;
}
