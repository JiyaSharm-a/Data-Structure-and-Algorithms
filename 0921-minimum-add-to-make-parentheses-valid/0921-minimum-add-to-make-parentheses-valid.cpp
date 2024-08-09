class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty()) return 0;

        stack<char> st;

        for(int i=0; i<s.size(); i++)
        {
            if(!st.empty() && s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        return st.size();  // The number of unmatched parentheses left in the stack
    }
};
