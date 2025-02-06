class Solution {
public:
    bool isValid(string s) {
        stack<char> bracStack;
        if(s.size() % 2 != 0)
            return false;

        for(int i = 0;i<s.size();i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                bracStack.push(s[i]);
            } else {
                if( !bracStack.empty() 
                && (
                (s[i] == ')' && bracStack.top() == '(') || (s[i] == '}' && bracStack.top() == '{') ||( s[i] == ']' && bracStack.top() == '[' ))) {
                    bracStack.pop();
                } else {
                    return false;
                }
            }
        }

        if(bracStack.size() > 0) {
            return false;
        }

        return true;
    }
};