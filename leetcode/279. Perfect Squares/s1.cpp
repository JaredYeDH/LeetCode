class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1, INT_MAX);
        for (int i = 1; i * i <= n; ++i) {
            v[i * i] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (v[i] == 1) continue;
            for (int j = 1; j * j < i; ++j) {
                v[i] = min(v[i], 1 + v[i - j * j]);
            }
        }
        return v[n];
    }
};