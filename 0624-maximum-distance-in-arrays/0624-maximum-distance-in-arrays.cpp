class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //Min value of 1st array
        int MinI=arrays[0][0];

        //Max value of 1st array
        int MaxI=arrays[0][arrays[0].size()-1];

        int ans=0;

        for(int i=1;i<arrays.size();i++){

            //Current minimum
            int CurMin=arrays[i][0];

            //Current maximum
            int CurMax=arrays[i][arrays[i].size()-1];

            ans=max({ ans , (MaxI-CurMin) , (CurMax-MinI) });
            MinI=min(MinI,CurMin);
            MaxI=max(MaxI,CurMax);
        }
        return ans;
    }
};