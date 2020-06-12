//
// Created by homsl on 2020/3/25.
//
// Greedy method
int candy(vector<int>& ratings) {
    if(ratings.empty())
        return 0;

    vector<int> candy(ratings.size(), 1);
    int sum = ratings.size();
    for(int i = 0; i < ratings.size()-1; i++){
        if(ratings[i] < ratings[i+1]){
            sum += candy[i]-candy[i+1]+1;
            candy[i+1] = candy[i]+1;
        }
    }
    for(int i = ratings.size()-1; i > 0; i--){
        if(ratings[i] < ratings[i-1] && candy[i] >= candy[i-1]){
            sum += candy[i]-candy[i-1]+1;
            candy[i-1] = candy[i]+1;
        }
    }

    return sum;
}
