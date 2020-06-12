//
// Created by homsl on 2020/4/21.
//
/*Given an array of words find the most occurring word in it

Examples:

Input : arr[] = {"geeks", "for", "geeks", "a",
                "portal", "to", "learn", "can",
                "be", "computer", "science",
                 "zoom", "yup", "fire", "in",
                 "be", "data", "geeks"}
Output : Geeks
"geeks" is the most frequent word as it
occurs 3 times
 */

string func(vector<string> arr){
    unordered_map<string, int> map;
    int max = 0;
    string ans;
    for(string s:arr){
        if(++map[s] > max){
            max = map[s];
            ans = s;
        }
    }
    return ans;
}
