
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> newArr;

        // Merge both arrays
        for (int num : nums1) 
            newArr.push_back(num);

        for (int num : nums2)
            newArr.push_back(num);

        // Sort the new array
        sort(newArr.begin(), newArr.end());
        int n = newArr.size();

        // Find median
        if (n % 2 == 1)
            return newArr[n / 2];
        else 
            return (newArr[n / 2 - 1] + newArr[n / 2]) / 2.0;
    }
};
