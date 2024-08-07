class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        
        for(int i=0; i<colors.size(); i++)
        {
            int one = i;
            int two = (i+1) % n;
            int third = (i+2) % n;

            if(colors[one] != colors[two] && colors[two] != colors[third])
            count++;
        }

        return count;
        
    }
};