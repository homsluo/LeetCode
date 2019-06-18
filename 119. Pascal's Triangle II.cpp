//
// Created by homsl on 2019/6/18.
//
vector<int> getRow(int rowIndex) {
    if(rowIndex <= 1)
        return vector<int>(rowIndex+1, 1);
    vector<int> last(2,1);
    vector<int> cur = last;
    int size = 2;
    while(rowIndex > 1){
        for(int j = 1; j < size; j++)
            cur[j] = last[j-1]+last[j];
        cur.push_back(1);
        last = cur;
        size++;
        rowIndex--;
    }
    return cur;
}

vector<int> result(rowIndex+1,0);
result[0]=result[rowIndex]=1;
for(int i=1;i<=rowIndex/2;i++){
result[i]=result[rowIndex-i]=(unsigned long)result[i-1]*(rowIndex-i+1)/i;
}
return result;
