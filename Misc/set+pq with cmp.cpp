auto cmp = [](const int& a, const int& b) {
    return a < b;  
};
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
set < int, decltype(cmp) > se(cmp);
