class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if array is empty simply return : no common prefix
        if (strs.empty())
            return "";

        // store first value of string
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                // Remove last character from prefix.
                prefix.pop_back();

                if (prefix.empty())
                    return "";
            }
        }

        // Return longest common prefix found.
        return prefix;
    }
};