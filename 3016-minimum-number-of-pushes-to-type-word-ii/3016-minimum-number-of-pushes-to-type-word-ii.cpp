class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);

        for(auto ch:word)
        {
            freq[ch-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());

        int count = 0;

        for(int i=0; i<26; i++)
        {
            if(freq[i] == 0)
            {
                break;
            }
            count += (i/8 + 1) * freq[i];
        }

        return count;
    }
};