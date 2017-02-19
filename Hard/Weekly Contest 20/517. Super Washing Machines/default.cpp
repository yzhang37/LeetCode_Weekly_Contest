#define max(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        vector <int> presum;
        size_t total = 0;
        for (size_t i = 0; i != machines.size(); ++i)
        {
            total += machines[i];
            presum.push_back(total);
        }
        if (total % machines.size() != 0)
            return -1;
        size_t pre = total / machines.size();
        size_t max_move = 0;
        for (size_t i = 0; i != machines.size(); ++i)
        {
            int L = 0, R = 0;
            if (i > 0)
                L = i * pre - presum[i - 1];
            if (i < machines.size() - 1)
                R = (machines.size() - i - 1) * pre - presum[machines.size() - 1] + presum[i];
            if (L == 0)
                max_move = max(max_move, abs(R));
            else if (R == 0)
                max_move = max(max_move, abs(L));
            else
            {
                if (L > 0 && R > 0)
                    max_move = max(max_move, abs(R) + abs(L));
                else
                    max_move = max(max_move, max(abs(R), abs(L)));
            }
        }
        return max_move;
    }
};