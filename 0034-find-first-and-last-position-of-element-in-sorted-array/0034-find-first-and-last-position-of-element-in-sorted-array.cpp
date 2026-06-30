class Solution {
public:
    int getOcc(vector<int>& arr, int target, bool isFirst) {
        int left = 0;
        int right = arr.size() - 1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                res = mid;
                isFirst ? right = mid - 1 : left = mid + 1;
            } else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        ans[0] = getOcc(nums, target, true);
        ans[1] = getOcc(nums, target, false);
        return ans;
    }
};