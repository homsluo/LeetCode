//
// Created by homsl on 2020/4/8.
//

int read4(char* buf);
int casize = 0;
char* cache;
int read(char* buf, int n){
    int bufcur = 0;
    while(n){
        for(int i = 0; i < casize && i < n; i++, bufcur++){
            buf[bufcur] = casize[i];
        }
        cache += casize;
        casize = 0;
        if(bufcur < n){
            char* tmp;
            int len = read4(buf);
            int tmpcur = 0;
            for(; tmpcur < len && bufcur < n; tmpcur++, bufcur++){
                buf[bufcur] = tmp[tmpcur];
            }
            for(; tmpcur < len; tmpcur++, casize++){
                cache[casize] = tmp[tmpcur];
            }
        }
    }
    return bufcur;
}