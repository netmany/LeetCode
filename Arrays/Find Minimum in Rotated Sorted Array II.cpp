/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1, mid = 0;
        while(left < right && num[left] >= num[right]){
            mid = (left + right) >> 1;
            if(num[left] < num[mid]) {
                left = mid + 1;
            } else if(num[left] > num[mid]){
                right = mid;
            } else {
                left++;
            }
        }
        return num[left];
    }
};
