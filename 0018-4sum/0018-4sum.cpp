class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Optimal Approach (using two pointer) : Time Complexity -> O(n^3)

        // Better Approach (using hashset) : Time Complexity -> O(n^3)
        int n = nums.size();
        set<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                unordered_set<long long> st;

                for (int k = j + 1; k < n ; k++) {
                    long long l = (long long)target -
                                  ((long long)nums[i] + nums[j] + nums[k]);

                    if (st.find(l) != st.end()) {
                        vector<int> temp;
                        temp = {nums[i], nums[j], nums[k], (int)l};

                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());

        // Brute Force (using four loops): Time Complexity -> O(n^4) gives TLE
        /*
        int n = nums.size();
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {

                        long long sum =
                            (long long)nums[i] + nums[j] + nums[k] + nums[l];

                        if (sum == target) {
                            st.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
        */
    }
};