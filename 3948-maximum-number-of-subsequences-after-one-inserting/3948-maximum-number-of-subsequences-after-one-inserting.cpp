class Solution {
public:
    typedef long long ll;
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<ll> prefix(n + 1, 0);
        vector<ll> suffix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                prefix[i + 1] = 1;
            }
            prefix[i + 1] += prefix[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T') {
                suffix[i] = 1;
            }
            suffix[i] += suffix[i + 1];
        }
        ll reswithC = 0;
        ll bestPosForC = 0;
        ll reswithL = 0;
        ll reswithT = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                reswithC += prefix[i] * suffix[i + 1];
                reswithL += (prefix[i] + 1) * suffix[i + 1];
                reswithT += prefix[i] * (suffix[i + 1] + 1);
            } else {
                bestPosForC = max(prefix[i] * suffix[i], bestPosForC);
            }
        }
        reswithC += bestPosForC;
        return max({reswithC, reswithL, reswithT});
    }
};