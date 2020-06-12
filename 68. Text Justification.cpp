//
// Created by homsl on 2020/1/31.
//
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int index = 0;
    int curNum = words[0].size();
    int wordNum = words[0].size();
    vector<string> list;
    vector<string> res;
    int n = words.size();
    while(index < n){
        if(curNum > maxWidth){
            constructLine(res, list, maxWidth-(wordNum-words[index].size()), maxWidth);
            vector<string>().swap(list);
            curNum = words[index].size();
            wordNum = words[index].size();
        }
        list.push_back(words[index]);
        index++;
        if(index < n){
            curNum += words[index].size()+1;
            wordNum += words[index].size();
        }
    }
    if(!list.empty()){
        constructLeftLine(res, list, maxWidth);
    }
    return res;
}

void constructLine(vector<string>& res, vector<string>& list, int spaces, int maxWidth){
    string path = list[0];
    int gap = list.size()-1;
    if(gap > 0){
        int eachspace = spaces/gap;
        int extra = spaces%gap;
        for(int i = 1; i < list.size(); i++){
            if(extra-- > 0)
                path += ' ';
            path += string(eachspace, ' ') + list[i];
        }
    }
    if(maxWidth-path.size() > 0)
        path += string(maxWidth-path.size(), ' ');
    res.push_back(path);
}
void constructLeftLine(vector<string>& res, vector<string>& list, int maxWidth){
    string path = list[0];
    if(list.size()>1){
        for(int i = 1; i < list.size(); i++){
            path += " " + list[i];
        }
    }
    if(maxWidth-path.size() > 0){
        path += string(maxWidth-path.size(), ' ');
    }
    res.push_back(path);
}
