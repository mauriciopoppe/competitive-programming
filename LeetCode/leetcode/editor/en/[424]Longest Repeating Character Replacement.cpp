//Given a string s that consists of only uppercase English letters, you can perf
//orm at most k operations on that string. 
//
// In one operation, you can choose any character of the string and change it to
// any other uppercase English character. 
//
// Find the length of the longest sub-string containing all repeating letters yo
//u can get after performing the above operations. 
//
// Note: 
//Both the string's length and k will not exceed 104. 
//
// Example 1: 
//
// 
//Input:
//s = "ABAB", k = 2
//
//Output:
//4
//
//Explanation:
//Replace the two 'A's with two 'B's or vice versa.
// 
//
// 
//
// Example 2: 
//
// 
//Input:
//s = "AABABBA", k = 1
//
//Output:
//4
//
//Explanation:
//Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//The substring "BBBB" has the longest repeating letters, which is 4.
// 
//
// 
// Related Topics Two Pointers Sliding Window


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int characterReplacement(string s, int k) {
/*
aababba
-   +
-   +
a = 1
b = 3

k = 1
*/
    }
};
//leetcode submit region end(Prohibit modification and deletion)
