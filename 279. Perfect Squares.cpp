//
// Created by homsl on 2019/9/25.
//
int numSquares(int n) {             // BFS
    if(n < 1)
        return 0;
    queue<int> num, path;
    unordered_map<int, bool> visited;
    num.push(n), path.push(0);
    visited[n] = true;
    int i = 0, v = 0, step = 0, tnum = 0;
    while(!num.empty())
    {
        i = 1, step = path.front(), v = num.front();
        num.pop(), path.pop();
        tnum = v - i*i;
        while(tnum >= 0)
        {
            if(tnum == 0)
                return step+1;
            else if(visited.find(tnum) == visited.end())
            {
                num.push(tnum), path.push(step+1);
                visited[tnum] = true;
            }

            i += 1;
            tnum = v - i*i;
        }
    }
    return 0;
}

//------------------------------------------------------------------//
int numSquares(int n) { // Any number consists of 4 perfect square must be n=4^a*(8*b+7)
    if(n < 1)
        return 0;
    int n1 = n;
    while(n1 % 4 == 0)
        n1 /= 4;
    if(n1 % 8 == 7)
        return 4;

    int a = 0;          // Consists of 2 or 1 perfect square
    while(a*a <= n)
    {
        int b = int(sqrt(n-(a*a)));
        if(b*b+a*a == n)
            return !!a + !!b;       // Make sure 0 won't consider as 2
        a += 1;
    }

    return 3;
}

//----------------------------------------------------------------//
int numSquares(int n) {     //dp
    if(n < 1)
        return 0;
    vector<int>dp(n+1, INT_MAX);
    for(int i = 1; i*i <= n; i++)
    {
        dp[i*i] = 1;
    }
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j*j < i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    return dp[n];
}
