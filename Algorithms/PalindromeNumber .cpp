// Given an integer x, return true if x is a , and false otherwise.

// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        size_t rev = 0;
        auto copyX = x;
        while (x > 0) {
            auto digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return copyX == rev;
    }
};