class Solution {
public:
    bool detectCapitalUse(string word) {
        // Countuppercase letters
        int upperCase = 0;

        // Traverse each character
        for (int i = 0; i < word.length(); i++) {
            if (isupper(word[i])) {
                upperCase++;
            }
        }

        // Valid cases:
        return (upperCase == word.length()) || (upperCase == 0) ||
               (upperCase == 1 && isupper(word[0]));
    }
};