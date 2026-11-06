class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // sort the array 

        int closersum = nums[0] + nums[1] + nums[2]; // store the value of first three element

        for (int i = 0; i <  nums.size() - 2; i++) {
            int left = i + 1, right =  nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(sum - target) < abs(closersum - target)) 
                    closersum = sum;
                if (sum == target) 
                    return sum;
                else if (sum < target) 
                    left++;
                else 
                    right--; 
            }
        }
        return closersum;
    }
};