class Solution {
public:
    int solve(int ind,int& ans,int n,vector<int>&res){
        
        if(ind>=n+1) {
           return ans++;  
        }

        for(int i=1;i<=n;i++){
            if(res[i]==0 && (i%ind==0 || ind%i==0) ) {
                res[i]=ind;
                solve(ind+1,ans,n,res);
            res[i]=0;
            }
        }

        return ans;
    }
    int countArrangement(int n) {
        vector<int>res(n+1);

        int ans =0;
        return solve(1,ans,n,res);
    }
};