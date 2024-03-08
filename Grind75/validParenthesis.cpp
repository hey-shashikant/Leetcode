class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0)
            return true;
        stack<char>stk;
        for (char ch : s) {
            if(ch == '(' or ch == '[' or ch == '{')     
                stk.push(ch);
            else if(ch == ')' and !stk.empty() and stk.top() == '(')
                stk.pop();
            else if(ch == '}' and !stk.empty() and stk.top() == '{')
                stk.pop();
            else if(ch == ']' and !stk.empty() and stk.top() == '[')
                stk.pop();
            else
                return false;
        }
        return stk.empty() ? true : false;
    }
};