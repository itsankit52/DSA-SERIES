class Solution {
public:
    int findMin(vector<int>& nums) {

        // sort(nums.begin(), nums.end());
        // return nums[0];

        // Using Binary Search : Time: O(log n)
                            //   Space: O(1)
        int left = 0, right = nums.size()-1;

        while (left < right ){
            int mid = left+(right-left)/2;

            if (nums[mid] > nums[right])
            left = mid+1;

            else right = mid ;

        }

        return nums[left];
    }
};