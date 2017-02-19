#define max(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i)
            if (nums[i] == 0) nums[i] = -1;
        map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        
        int sum = 0, maxValue = 0;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (!sumToIndex.count(sum))
            {
                sumToIndex[sum] = i;
            }
            else
            {
                maxValue = max(maxValue, i - sumToIndex[sum]);
            }
        }
        return maxValue;
    }
};