//
// Created by homsl on 2020/5/27.
//
bool isPowerOfTwo(int n) {
    return (n > 0 && (n & (n-1)) == 0);
}
