class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        // Step 1: Sort in ascending order
        sort(potions.begin(), potions.end());

        int n = spells.size(), k = potions.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int left = 0, right = k - 1,ans = k;
            while (left <= right) {

                int mid = left + (right - left) / 2;
                long long product = 1LL * spells[i] * potions[mid];

                if (product >= success) {
                    ans = mid;
                    right = mid - 1;
                } 
                else
                    left = mid + 1;
            }
            res[i] = k - ans;
        }
        return res;
    }
};
