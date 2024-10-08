class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char c : s ) {
            if(c==']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } 
            } else {
                st.push(c);
            }
        }
        return (st.size()+1) / 2;
    }
};