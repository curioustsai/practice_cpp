#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:

    /**
     * @param L: Given n pieces of wood with lenght L[i]
     * @param k: An integer
     * @return: The maximum length of the small piece
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        int maxLen = 0;
        int totalLen = 0;
        for (int i = 0; i < L.size(); i++) {
            totalLen += L[i];
            if (L[i] > maxLen)
                maxLen = L[i];
        }

        if (totalLen < k)
            return 0;

        // core algorithm
        // binary search [0, maxL], and check if it meets the requirements
        int left = 1;
        int right = maxLen;
        int ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (validateLen(L, k, mid) == true)
            {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    private:
    bool validateLen(vector<int> &L, int k, int candidate)
    {
        if (!candidate) return false;

        int count = 0;
        for (size_t i = 0; i < L.size(); i++)
            count += (L[i] / candidate);

        return count >= k;
    }
};

int main (int argc, char *argv[])
{
    Solution sol;
    vector<int> L = {232, 124, 456};
    int k = 7;
    cout << sol.woodCut(L, k) << endl;

    return 0;
}
