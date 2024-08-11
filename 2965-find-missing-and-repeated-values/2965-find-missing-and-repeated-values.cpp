class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int> mp;
        vector<int> vec;
        int a;

        // a find krte h pehle
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                vec.push_back(grid[row][col]);
                mp[grid[row][col]]++;
                if(mp[grid[row][col]] == 2)
                {
                    a = grid[row][col];
                    vec.pop_back();
                }
            }
        }

        // b find krte h ab
        sort(vec.begin(),vec.end());

        int i;

        for(i=0; i<vec.size(); i++)
        {
            if(vec[i] != i+1)
            {
                return {a,i+1};
            }
        }

        return {a,i+1};

        
    }
};