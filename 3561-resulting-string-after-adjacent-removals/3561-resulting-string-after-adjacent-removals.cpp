class Solution {
public:
    bool isAdjacent(char a, char b) {
        int diff = abs(a - b);
        return diff == 1 || diff == 25; 
    }

    string resultingString(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && isAdjacent(stack.back(), c)) {
                stack.pop_back(); 
            } else {
                stack.push_back(c); 
            }
        }
        return stack;
    }
};
