class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Optimal Approach (using two pointer) : Time Complexity -> O(n^3)
        // Sort the array first 
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1,right = n - 1;

                while (left < right) {

                    long long sum =
                        (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {

                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1])
                            left++;

                        while (left < right && nums[right] == nums[right + 1])
                            right--;

                    } 
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }

        return ans;

        /*
                // Better Approach (using hashset) : Time Complexity -> O(n^3)
                set<vector<int>> ans;

                for (int i = 0; i < nums.size() - 3; i++) {
                    for (int j = i + 1; j < nums.size() - 2; j++) {
                        unordered_set<long long> st;

                        for (int k = j + 1; k < nums.size(); k++) {
                            long long l = (long long)target -
                                          ((long long)nums[i] + nums[j] +
           nums[k]);

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
        */

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