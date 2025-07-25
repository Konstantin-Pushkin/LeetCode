// You are given an m x n integer matrix matrix with the following two properties:
// a. Each row is sorted in non-decreasing order.
// b. The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            int row = middle / n;
            int col = middle % n;
            int valueMiddle = matrix[row][col];

            if (valueMiddle == target)
                return true;
            else if (valueMiddle < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return false;
    }
};