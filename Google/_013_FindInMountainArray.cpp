/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 1;
        int e = n - 2;
        while(s != e){
            int mid = (s + e) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                s = mid + 1;
            } else{
                e = mid;
            }
        }

        int idx = s;

        s = 0;
        e = idx;

        while(s != e){
            int mid = (s + e) / 2;
            if(mountainArr.get(mid) < target){
                s = mid + 1;
            } else {
                e = mid;
            }
        }        

        if(mountainArr.get(s) == target){
            return s;
        }

        s = idx + 1;
        e = n - 1;
        while (s != e) {
            int mid = (s + e) / 2;
            if (mountainArr.get(mid) > target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        
        if (mountainArr.get(s) == target) {
            return s;
        }

        return -1;
    }
};