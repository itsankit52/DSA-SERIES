class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1 = 0, x2 = 1;
        int counter1 = 0, counter2 = 0;

        // First pass: Find potential candidates
        for (int num : nums) {
            if (num == x1) 
                counter1++;
            
            else if (num == x2) 
                counter2++;
            
            else if (counter1 == 0) {
                x1 = num;
                counter1 = 1;
            }
            else if (counter2 == 0) {
                x2 = num;
                counter2 = 1;
            }
            else {
                counter1--;
                counter2--;
            }
        }

        // Second pass: Verify candidates
        counter1 = 0;
        counter2 = 0;

        for (int num : nums) {
            if (num == x1)
                counter1++;
            else if (num == x2)
                counter2++;
        }

        vector<int> ans;

        if (counter1 > nums.size() / 3)
            ans.push_back(x1);

        if (counter2 > nums.size() / 3)
            ans.push_back(x2);

        return ans;
    }
};