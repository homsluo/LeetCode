//
// Created by homsl on 2020/4/10.
//

/* Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges,
 *
 * Example:
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 */

vector<string> findMissingRanges(vector<int> nums, int lower, int upper){
    vector<string> res;
    long int alower = lower;
    long int aupper = upper;

    for(int num:nums){
        if(alower == num)
            alower++;
        else{
            if(alower+1 == num)
                res.push_back(to_string(alower));
            else{
                res.push_back(to_string(alower) + "->" + to_string(num-1));
            }
            alower = (long int) num + 1;
        }
    }

    if(alower == aupper){
        res.push_back(to_string(alower));
    }
    else
        res.push_back(to_string(alower) + "->" + to_string(aupper));

    return res;
}