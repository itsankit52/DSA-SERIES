
class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {

        int bouquets = 0, flowers = 0;

        for (int bloom : bloomDay) {

            if (bloom <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else
                flowers = 0;
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        if ((long long)m * k > n) {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        // binary search
        while (left < right) {

            int mid = left + (right - left) / 2;

            if (isPossible(bloomDay, mid, m, k))
                right = mid;
            else
                left = mid + 1;
        }

        return left;

        // if ((long long)m * k > bloomDay.size())
        //     return -1;

        // int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        // int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        // for (int i = 0; i <= maxDay; i++) {
        //     int bookets = 0, flower = 0;

        //     for (int bloom : bloomDay) {

        //         if (bloom <= i) {
        //             flower++;

        //             if (flower == k) {
        //                 bookets++;
        //                 flower = 0;
        //             }
        //         } else
        //             flower = 0;
        //     }
        //     if (bookets >= m)
        //         return i;
        // }
        // return -1;
    }
};