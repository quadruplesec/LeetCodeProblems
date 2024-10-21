#include <vector>
using namespace  std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + ((hi - lo) / 2);
            if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (nums[lo] == target) {
            return lo;
        } else {
            return -1;
        }
    }
};