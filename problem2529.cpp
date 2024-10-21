#include <vector>

using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int key) {
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

    int maximumCount(vector<int>& nums) {
        int posCount, negCount;

        int posBound = lowerBound(nums, 1);
        if (posBound != -1) {
            posCount = nums.size() - posBound;
        } else {
            posCount = -1;
        }

        int negBound = lowerBound(nums, 0);

        if (negBound == -1) {               // There are no numbers greater than 0.
            negCount = nums.size();         // Hence, all numbers are negative.
        } else if (negBound == 0) {         // The first number >=0 is at index 0.
            negCount = 0;                   // Hence, there are no negatives.
        } else {                            // If any other case, then negBound is the position of the first
            negCount = negBound;            // non-negative value.
        }

        if (posCount > negCount) return posCount;
        return negCount;
    }
};