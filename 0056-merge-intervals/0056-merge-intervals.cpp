class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> p;
        vector<vector<int>> ans;

        for(int i=0; i<intervals.size(); i++)
        {
            p.push_back({intervals[i][0],intervals[i][1]});
        }

        sort(p.begin(),p.end());

        int f = p[0].first;
        int s = p[0].second;

        vector<int> hold(2);

        for(int i=1; i<p.size(); i++)
        {
            if(s >= p[i].first)
            {
                s = max(s,p[i].second);
            }
            else
            {
                hold[0] = f;
                hold[1] = s;

                f = p[i].first;
                s = p[i].second;

                ans.push_back(hold); 
            }
        }

        ans.push_back({f,s});

        return ans;
    }
};