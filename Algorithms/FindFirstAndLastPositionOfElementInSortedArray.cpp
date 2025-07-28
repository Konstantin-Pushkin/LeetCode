// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = search(nums, target, true);
        if (start == -1)
            return {-1, -1};
        int end = search(nums, target, false);

        return {start, end};
    }

    int search(vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (target < nums[middle])
                right = middle - 1;
            else if (target > nums[middle])
                left = middle + 1;
            else {
                bound = middle;
                if (!isFirst)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }

        return bound;
    }
};