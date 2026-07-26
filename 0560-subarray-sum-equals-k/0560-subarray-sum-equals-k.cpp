class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Brute force : Time Complexity O(n^2)
        int count = 0;
        for (int i =0 ; i< nums.size(); i++) {
            int sum = 0;
            for (int j = i ; j< nums.size(); j++){
                sum += nums[j];

                if (sum == k )
                    count ++;
                
            }
        }
        return count;
    }
};