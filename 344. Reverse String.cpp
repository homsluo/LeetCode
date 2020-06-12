//
// Created by homsl on 2020/6/4.
//
void reverseString(vector<char>& s) {
    if(s.empty())
        return;
    int left = 0;
    int right = s.size()-1;
    while(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return;
}
