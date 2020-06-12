//
// Created by homsl on 2020/4/21.
//
/* Write an efficient function to return maximum occurring character in the input string e.g., if input string is “test” then function should return ‘t’.
*/
char getMaxOccuringChar(string str){
    unordered_map<char, int> map;
    int max = 0;
    char ans;
    for(int i = 0; i < str.size(); i++){
        map[str[i]]++;
        if(map[str[i]] > max){
            max = map[str[i]];
            ans = str[i];
        }
    }
    return ans;
}
