
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Optimal solution
        // Time : O(n), space : O(n)

        unordered_set<int> st(nums.begin(), nums.end());
        int longer = 0;

        for (int num : st) {
            // Check if it is the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int current = num, length = 1;

                // Count consecutive numbers
                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                longer = max(longer, length);
            }
        }

        return longer;
    }
};
// Linear search function
// bool linearSearch(vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] == target)
//             return true;
//     }
//     return false;
// }

// Brute Force :
// int longer = 0;

// for (int i = 0; i < nums.size(); i++) {
//     int current = nums[i], count = 1;

//     // Linear search Check for consecutive numbers
//     while (linearSearch(nums, current + 1)) {
//         current++;
//         count++;
//     }

//     longer = max(longer, count);
// }
// return longer;

// Better than brute force
/*
 if (nums.empty())
     return 0;

 sort(nums.begin(), nums.end());

 int longer = 1, count = 1;

 for (int i = 1; i < nums.size(); i++) {
     if (nums[i] == nums[i - 1])
         continue; // Ignore duplicates

     else if (nums[i] == nums[i - 1] + 1)
         count++;

     else
         count = 1;

     longer = max(longer, count);
 }

 return longer;
 */