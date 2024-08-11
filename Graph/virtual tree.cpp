for(int i = 1; i <= n; i++){
    if(op[i].empty())continue;
    vector < int > cur = op[i];
    sort(all(cur), cmp);
    vector < int > tmp = cur;
    for(int j = 1; j < (int)cur.size(); j++){
        tmp.push_back(lca(cur[j - 1], cur[j]));
    }
    sort(all(tmp));
    tmp.resize(unique(all(tmp)) - tmp.begin());
    sort(all(tmp), cmp);
    cur = tmp;
    vector < int > se;
    se.push_back(cur[0]);
    for(int j = 1; j < (int)cur.size(); j++){
        while(!In(se.back(), cur[j]))se.pop_back();
        Adj[se.back()].push_back(cur[j]);
        se.push_back(cur[j]);
    }
    Dfs(cur[0], i);
    for(auto j: cur)Adj[j].clear();
}
