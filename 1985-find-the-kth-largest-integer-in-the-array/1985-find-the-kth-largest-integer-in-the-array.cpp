class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        
        // creating min heap of first k elements
        for(int i=0; i<k; i++)
        {
            int num = stoi(nums[i]);
            pq.push(num);
        }

        // remaining elements jo bde h unko add krlo
        for(int i=k; i<nums.size(); i++)
        {
            int num = stoi(nums[i]);
            if(pq.top() < num)
            {
                pq.pop();
                pq.push(num);
            }
        }

        return to_string(pq.top());
    }
};