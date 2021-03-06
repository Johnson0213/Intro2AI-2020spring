#ifndef DFS_H
#define DFS_H

#include "custom_header.hpp"

class DFS : public Solver
{
private:
public:
    //string name; this will cause the name be empty string
    DFS();
    bool dfs(int d, pii s, pii p, pii t);
    pair<vector<pii>, int> solve(pii x, pii y, double TL);
};

DFS::DFS()
{
    name = "DFS";
}

bool DFS::dfs(int d, pii s, pii p, pii t) //s = current, p = from, d = current depth, t =  
{
    bool ret = false;
    node_expanded++;
    cur_node_expanded++;
    max_node_expanded = max(max_node_expanded, cur_node_expanded);
    vis[cor(s)] = p;
    if(s == t) return true;
    for(auto &di : dxdy)
    {
        pii nxt = s + di;
        if(!inrange(nxt)||vis[cor(nxt)] != pii(-1,-1)) continue; //typo, continue to break
        ret |= dfs(d+1, nxt, s, t);
        if(ret) break;
    }
    cur_node_expanded--;
    if(!ret) vis[cor(s)] = pii(-1,-1);
    return ret;
}

pair<vector<pii>, int> DFS::solve(pii s, pii t, double TL)
{
    node_expanded = 0;
    max_node_expanded = 0;
    cur_node_expanded = 0;
    init();
    dfs(0, s, s, t);
    vector<pii> path;
    construct_path(path, t);
    return mp(path, node_expanded);
}
#endif