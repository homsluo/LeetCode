//
// Created by homsl on 2020/4/8.
//
/* The API: int read4(char *buf) reads 4 characters at a time from a file.
 * The return value is the actual number of characters read. For example, it returns 3 if there
 * is only 3 characters left in the file.
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n
 * characters from the file.
 * Note: The read function will only be called once for each test case.
 */
int read4(char* buf);
int read(char* buf, int n){
    int count = 0;
    while(count < n){
        char* tmp[4];
        int len = read4(tmp);
        for(int i = 0; i < len && count < n; count++, i++){
            buf[count] = tmp[i];
        }
        if(len < 4)
            break;
    }
    return count;
}