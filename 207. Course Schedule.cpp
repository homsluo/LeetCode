//
// Created by homsl on 2020/5/16.
//
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> visit(numCourses, 0);
    vector<vector<int>> graph(numCourses);
    for(int i = 0; i < prerequisites.size(); i++){
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    // 0:not visited, 1:visiting, 2:visited
    for(int i = 0; i < numCourses; i++){
        if(DFS(i, visit, graph))
            return false;
    }
    return true;
}

bool DFS(int i, vector<int>& visit, vector<vector<int>>& graph){
    if(visit[i] == 1) return true;
    if(visit[i] == 2) return false;

    visit[i] = 1;

    for(int cur:graph[i]){
        if(DFS(cur, visit, graph))  // if there is a cycle
            return true;
    }

    visit[i] = 2;
    return false;
}
