//
// Created by homsl on 2020/2/2.
//
string simplifyPath(string path) {
    string res, temp;
    vector<string> stack;
    stringstream ss(path);
    while(getline(ss, temp, '/')){
        if(temp == ".."){
            if(!stack.empty())
                stack.pop_back();
        }
        else if(temp != "." && !temp.empty())
            stack.push_back(temp);
    }
    for(string str:stack)
        res += "/" + str;
    return res.empty() ? "/" : res;
}
