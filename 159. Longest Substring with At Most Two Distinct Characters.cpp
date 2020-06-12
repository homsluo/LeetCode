//
// Created by homsl on 2020/4/9.
//
/*Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/
int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> map;
    int start = 0;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        map[s[i]] = i;

        if(map.size() > 2){
            int leftmost = s.size();
            for(auto it:map){
                leftmost = min(leftmost, it.second);
            }
            start = leftmost+1;
        }

        res = max(res, i-start+1);
    }
    return res;
}