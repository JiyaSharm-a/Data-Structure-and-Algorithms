class Solution {
public:
    // void solveRec(vector<int> nums,set<vector<int>> &s,vector<int> temp,int ind,int sum,int target)
    // {
    //     // base case
    //     if(ind == nums.size())
    //     {
    //         if(sum == target)
    //         {
    //             s.insert(temp);
    //         }
    //         return;
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];

    //     if(sum == target)
    //     s.insert(temp);

    //     // include
    //     temp.push_back(nums[ind]);
    //     solveRec(nums,s,temp,ind+1,sum+nums[ind],target);
    //     // exclude
    //     temp.pop_back();
    //     solveRec(nums,s,temp,ind+1,sum,target);
    // }



    void solve( vector<int> candidates, int target, int index,  vector<vector<int>>& ans, vector<int>& temp){
        //base case
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        // recurrsive case
        for(int i = index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, target, 0, ans, temp);
        return ans;
    }

};