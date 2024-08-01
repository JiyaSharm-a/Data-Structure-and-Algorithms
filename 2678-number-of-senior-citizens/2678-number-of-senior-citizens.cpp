class Solution {
public:
    int countSeniors(vector<string>& details) {
        vector<int> age;

        for(auto d: details)
        {
            string s = d.substr(11,2);
            int num = std::stoi(s); // convert string to integer
            age.push_back(num);
        }

        int ans=0;
        
        for(int i=0;i<age.size();i++)
        {
            if(age[i]>60)
            ans++;
        }

        return ans;
    }
};