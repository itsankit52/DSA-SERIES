class Solution {
public:

    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
                high = mid;
            
            else
                low = mid + 1;
        
        }

        return low ;
    }

    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) 
                high = mid;
            else 
                low = mid + 1;
        }

        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int firstOccu = lowerBound(nums, target);

        // Target doesn't exist
        if (firstOccu == nums.size() || nums[firstOccu] != target) 
            return {-1, -1};

        int lastOccu = upperBound(nums, target) - 1;

        return {firstOccu, lastOccu};
    }
};