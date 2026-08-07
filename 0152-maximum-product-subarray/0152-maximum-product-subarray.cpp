class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        // Brute : O(n^3)
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         int p = 1;
        //         for (int k = i; k <= j; k++)
        //             p = p * nums[k];

        //         maxi = max(maxi, p);
        //     }
        // }

        // Better than brute force : O(n^2)
        for (int i = 0; i < n; i++) {
            int p = 1;
            for (int j = i; j < n; j++) {
                p *= nums[j];
                maxi = max(maxi, p);
            }
        }
        return maxi;

    }
};