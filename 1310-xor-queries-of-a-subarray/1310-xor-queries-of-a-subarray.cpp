class Solution {
public:
    int calc(vector<int> arr,int s,int e)
    {
        int ans = arr[s];
        s++;

        while(s <= e)
        {
            ans ^= arr[s];
            s++;
        }

        return ans;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> vec;

        for(int i=0; i<queries.size(); i++)
        {
            int s = queries[i][0];
            int e = queries[i][1];

            int ans = calc(arr,s,e);
            vec.push_back(ans);
        }

        return vec;
    }
};