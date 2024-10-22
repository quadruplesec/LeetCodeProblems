#include <vector>

using namespace std;

class Solution {
public:
    int lowerBound_v1(const vector<int>& nums, int key) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < key) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (nums[lo] != key) return -1;
        return lo;
    }

    int lowerBound_v2(const vector<int>& nums, int key) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < key) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (nums[lo] < key) return -1;
        return lo;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};

        int low = lowerBound_v1(nums, target);
        int high = lowerBound_v2(nums, target + 1);

        if (low == -1) {
            return {-1, -1};
        }

        if (high == -1) {
            return {low, (int) nums.size() - 1};
        }

        return {low, high - 1};
    }
};