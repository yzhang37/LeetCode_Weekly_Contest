class Solution {
public:
    int countArrangement(int N)
    {
        vector <int> vs;
        for (int i = 1; i <= N; ++i)
            vs.push_back(i);
        return counts(N, vs);
    }
private:
    int counts(int n, vector<int> &vs)
    {
        if (n <= 0)
            return 1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            //题目中的两种要求
            if (vs[i] % n == 0 || n % vs[i] == 0)
            {
                swap(vs[i], vs[n - 1]);
                ans += counts(n - 1, vs);
                swap(vs[i], vs[n - 1]);
            }
        }
        return ans;
    }
};