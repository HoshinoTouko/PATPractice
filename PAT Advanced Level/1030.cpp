#include<iostream>
#include<vector>

using namespace std;

vector<vector<pair<int, int> > > paths; // First dist, second cost
vector<bool> visited;

int minCost = 9999999;
int minDist = 9999999;
vector<int> minPath, path;

int n, m, s, d;

void dfs(int start, int end, int dist, int cost) {
    if(visited[start]) {
        return;
    }
    if (start == end) {
        if(dist < minDist or dist == minDist and cost < minCost) {
            minPath = vector<int>(path);
            minPath.push_back(start);
            minDist = dist;
            minCost = cost;
            return;
        }
    }
    visited[start] = true;
    path.push_back(start);
    for(int i = 0; i < n; i++) {
        if(visited[i]) {
            continue;
        }
        if(paths[start][i].first) {
            dist += paths[start][i].first;
            cost += paths[start][i].second;
            dfs(i, end, dist, cost);
            dist -= paths[start][i].first;
            cost -= paths[start][i].second;
        }
    }
    visited[start] = false;
    path.pop_back();
}

int main() {
    
    cin>>n>>m>>s>>d;
    paths = vector<vector<pair<int, int> > >(n, vector<pair<int, int> >(n, make_pair(0, 0)));
    visited = vector<bool>(n, false);
    
    int c1, c2, dist, cost;
    while(m--) {
        cin>>c1>>c2>>dist>>cost;
        paths[c1][c2] = make_pair(dist, cost);
        paths[c2][c1] = make_pair(dist, cost);
    }
    dfs(s, d, 0, 0);
    for(int i = 0; i < minPath.size(); i++) {
        cout<<minPath[i]<<" ";
    }
    cout<<minDist<<" "<<minCost<<endl;
    
    return 0;
}
