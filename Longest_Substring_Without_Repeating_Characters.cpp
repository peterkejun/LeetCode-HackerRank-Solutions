/*
Problem Name: Longest Substring Without Repeating Characters
Problem Algorithm: Two Pointers
Problem URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

int lengthOfLongestSubstring(string s) {
    int *count = (int *)calloc(256, sizeof(int));
    int length = s.length();
    if (length == 1) return 1;
    int left = 0, right = 0;
    int max_count = 0;
    while (right < length) {        
        count[s[right]]++;
        while (count[s[right]] > 1) {
            count[s[left++]]--;
        }
        max_count = max(max_count, right - left + 1);
        right++;
    }
    return max_count;
}