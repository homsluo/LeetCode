//
// Created by homsl on 2020/5/16.
//
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for(int i = 0; i < prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<int> visit(numCourses, 0);
    vector<int> ans;
    for(int i = 0; i < numCourses; i++){
        if(DFS(i, visit, ans, graph))
            return {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool DFS(int cur, vector<int>& visit, vector<int>& ans, vector<vector<int>>& graph){
    if(visit[cur] == 1) return true;
    if(visit[cur] == 2) return false;

    visit[cur] = 1;
    for(int i:graph[cur]){
        if(DFS(i, visit, ans, graph)) return true;
    }
    visit[cur] = 2;
    ans.push_back(cur);
    return false;
}
