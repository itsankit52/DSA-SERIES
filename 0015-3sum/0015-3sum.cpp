class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Vector to store the final list of unique triplets
        vector<vector<int>> ans;

        // Sort the array to use the two-pointer approach
        sort(nums.begin(), nums.end());

        // Traverse the array fixing one element at a time
        for (int i = 0; i < nums.size() - 2; i++) {

            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Initialize two pointers
            int left = i + 1, right = nums.size() - 1;

            // Search for the remaining two numbers
            while (left < right) {

                // Calculate the sum of the current triplet
                int sum = nums[i] + nums[left] + nums[right];

                // Triplet found
                if (sum == 0) {

                    // Store the triplet
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for the left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate values for the right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move both pointers to search for the next pair
                    left++;
                    right--;
                }

                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }

        return ans;
    }
};