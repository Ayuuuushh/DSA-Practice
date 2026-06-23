class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int retval = 0;

        for (int i = 0; i < heights.size(); i++) {
            int j = i;
            int volume = 0;
            while (j < heights.size()) {
                if (heights[i] < heights[j]) {
                    volume = heights[i] * ((j + 1) - (i + 1));
                    retval = max(volume, retval);
                } else {
                    volume = heights[j] * ((j + 1) - (i + 1));
                    retval = max(volume, retval);
                }
                j++;
            }
        }

        return retval;
    }
};
