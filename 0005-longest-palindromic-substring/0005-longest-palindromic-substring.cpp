class Solution {
public:

// we hv passed s by reference not by value ..bcoz if pass by value then
// it create copy first for string s so time limit will get exceed.

// Passing a string by reference in the ispal function does not modify 
// the original string s. This is because the ispal function is only reading 
// from the string, not writing to it.

    bool ispal(string& s,int i,int j) 
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {return false;}

            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.length();
        int starting_index=0;
        int max_len=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                bool val= ispal(s,i,j);
                if(val==true)
                {
                    if(j-i+1>max_len)
                    {
                        starting_index=i;
                        max_len=j-i+1;
                    }
                }

            }
        }

        return s.substr(starting_index,max_len);
    }
};