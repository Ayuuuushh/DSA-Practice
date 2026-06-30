class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            if(nums[left] <= nums[right])
                return nums[left];

            int mid = left + (right - left) / 2;

            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;

            if (nums[mid] < nums[next] && nums[mid] < nums[prev])
                return nums[mid];

            else if (nums[mid] >= nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};