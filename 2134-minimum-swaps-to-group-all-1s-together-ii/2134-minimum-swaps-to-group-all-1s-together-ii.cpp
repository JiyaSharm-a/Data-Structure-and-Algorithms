class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        int currOnes = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                totalOnes++;
            }
        }
        for(int i=0;i<totalOnes;i++){
            if(nums[i]==1){
                currOnes++;
            }
        }
        int maxOnes = currOnes;
        for(int i=totalOnes;i<totalOnes+nums.size();i++){
            currOnes = currOnes + nums[i%nums.size()] - nums[(i-totalOnes+nums.size())%nums.size()];
            maxOnes = max(maxOnes, currOnes);
        }
        return totalOnes-maxOnes;
    }
};