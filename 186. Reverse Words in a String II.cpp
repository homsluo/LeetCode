//
// Created by homsl on 2020/4/27.
//
/*Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

// 1. Reverse the whole string
// 2. Recognize each word and reverse

class Solution {
public:
    void reverseWords(string &s) {
        int length = s.length();
        if (length == 0) {
            return;
        }
        reverseWords(s, 0, length - 1);
        int start = 0, end = 0;
        while (start < length) {
            end = start;
            while (end + 1 < length && s[end + 1] != ' ') {
                ++end;
            }
            reverseWords(s, start, end);
            start = end + 2;
        }
    }
private:
    void reverseWords(string &s, int start, int end) {
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            ++start, --end;
        }
    }
};