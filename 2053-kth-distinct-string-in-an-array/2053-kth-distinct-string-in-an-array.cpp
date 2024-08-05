class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for(auto ch:arr)
        {
            mp[ch]++;
        }

        int count = 0;

        for(auto ele : arr)
        {
            if(mp[ele] == 1)
            {
                count++;
                if(count == k)
                {
                    return ele;
                }
            }
        }

        return "";
    }
};