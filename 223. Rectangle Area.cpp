//
// Created by homsl on 2020/5/25.
//
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    // Edge Cases
    long long totalArea = (long long)(C-A)*(D-B)+(long long)(G-E)*(H-F);
    if(A >= G || E >= C || B >= H || F >= D)
        return totalArea;
    // Bottom Left Corner(max(A,E), max(B,F))
    // Top Right Corner(min(C,G), min(D,H))
    long long BL_x = max(A,E);
    long long BL_y = max(B,F);
    long long TR_x = min(C,G);
    long long TR_y = min(D,H);
    return totalArea-(abs(BL_x-TR_x)*abs(BL_y-TR_y));
}
