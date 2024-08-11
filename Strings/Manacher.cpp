#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Manacher {
    public:
    void set(const vector<T>& s) {
        int n = s.size();
        d1 = vector<int>(n);
        d2 = vector<int>(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;   
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k; 
            }
        }
    }
    vector<int> d1; // # of odd palindromes centered at i
    vector<int> d2; // # of even palindromes centered at i (right)
};
