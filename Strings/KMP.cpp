//P[i] is the longest prefix of the substring (0 , i) that is also a suffix of the string
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])j = pi[j-1];
        if (s[i] == s[j])j++;
        pi[i] = j;
    }
    return p;
}
