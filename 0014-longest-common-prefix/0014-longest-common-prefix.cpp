class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // someone else solution
        // Since is sorted, if you have 'fl' in the first string, having 'fl' in the 
        // last string means that all the in-between strings also have 'fl'.
        // So you pretty much can only compare these two and ignore the rest.
        
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";

        for(int i=0;i<n.size();i++)
        {
            if(n[i]==m[i])
            {
                ans+=n[i];
            }
            else break;
        }
        return ans;
        
    }
};

