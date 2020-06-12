//
// Created by homsl on 2020/4/11.
//
int compareVersion(string version1, string version2) {
    int p1 = 0;
    int p2 = 0;
    int num1 = 0;
    int num2 = 0;
    while(p1 < version1.size() && p2 < version2.size()){
        while(p1 < version1.size() && version1[p1] != '.')
            num1 = 10*num1+version1[p1++]-48;
        while(p2 < version2.size() && version2[p2] != '.')
            num2 = 10*num2+version2[p2++]-48;
        if(num1 > num2)
            return 1;
        else if(num1 < num2)
            return -1;
        num1 = 0;
        num2 = 0;
        p1++;
        p2++;
    }
    while(p1 < version1.size()){
        if(version1[p1] != '.' && version1[p1] != '0')
            return 1;
        p1++;
    }
    while(p2 < version2.size()){
        if(version2[p2] != '.' && version2[p2] != '0')
            return -1;
        p2++;
    }
    return 0;
}
