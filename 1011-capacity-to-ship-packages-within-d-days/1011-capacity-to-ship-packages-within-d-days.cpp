class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    
     int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            int reqDays = 1,cl = 0;

            for (int weight : weights) {
                if (cl + weight > mid) {
                    reqDays++;
                    cl = 0;
                }
                cl =cl+ weight;
            }
            if (reqDays <= days) high = mid;
            
            else low = mid + 1;
        }
        return low;




        // int maxWeight = *max_element(weights.begin(), weights.end());
        // int totalWeight = 0;
        // for (int weight : weights) {
        //     totalWeight += weight;
        // }
        // for (int i = maxWeight; i <= totalWeight; i++) {

        //     int reqDays = 1,cl = 0;
        //     for (int weight : weights) {

        //         if (cl + weight > i) {
        //             reqDays++;
        //             cl = 0;
        //         }

        //         cl += weight;
        //     }
        //     if (reqDays <= days) 
        //         return i; 
        // }
        // return totalWeight;
    }
};