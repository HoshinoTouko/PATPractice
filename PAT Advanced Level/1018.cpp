#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

vector<int> visited;
vector<vector<int> > dists;
vector<vector<int> > paths;
vector<int> nums(1, 0);
vector<int> path;
int min_dist = 99999999999;
int dist_sum = 0;
int cmax, n, sp, m;


void dfs(int start, int end){
    if (visited[start]){
        return;
    }
    visited[start] = 1;
    path.push_back(start);
    if(start == end){
        if (dist_sum < min_dist){
            paths.clear();
            paths.push_back(vector<int>(path));
            min_dist = dist_sum;
        } else if (dist_sum == min_dist) {
            paths.push_back(vector<int>(path));
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if(dists[start][i] and !visited[i]) {
                dist_sum += dists[start][i];
                dfs(i, end);
                dist_sum -= dists[start][i];
            }
        }
    }
    visited[start] = 0;
    path.pop_back();
}

int main(){
    cin>>cmax>>n>>sp>>m;
    int T = n, t, a, b;
    while(T--) {
        cin>>t;
        nums.push_back(t - cmax / 2);
    }
    dists = vector<vector<int> >(n + 7, vector<int>(n + 7, 0));
    visited = vector<int>(n + 7, 0);
    while(m--) {
        cin>>a>>b>>t;
        dists[a][b] = dists[b][a] = t;
    }
    dfs(0, sp);
    
    int min_bring = 999999999, min_take = 999999999, select = -1;
    int bring, take;
    for(int i = 0; i < paths.size(); i++) {
        bring = 0;
        take = 0;
        for(vector<int>::iterator iit = paths[i].begin(); iit != paths[i].end(); iit++) {
            if (*iit == 0)
               continue;
            if (*iit == sp) {
                if (nums[*iit] < 0) {
                    if (bring > -nums[*iit]){
                        bring -= -nums[*iit];
                    } else {
                        take = take + -nums[*iit] - bring;
                        bring = 0;
                    }
                }
                if (nums[*iit] > 0) {
                    bring += nums[*iit];
                }
                continue;
            }
            if (nums[*iit] < 0) {
                take += -nums[*iit];
            }
            if (nums[*iit] > 0) {
                bring += nums[*iit];
            }
        }
//        cout<<take<<" "<<bring<<endl;
        if (take < min_take) {
            min_take = take;
            min_bring = bring;
            select = i;
        } else if (take == min_take) {
            if (bring < min_bring) {
                min_take = take;
                min_bring = bring;
                select = i;
            }
        }
    }
    cout << min_take << " 0";
    for(vector<int>::iterator iit = paths[select].begin(); iit != paths[select].end(); iit++) {
        if (*iit == 0)
           continue;
        cout<<"->"<<*iit;
    }
    cout<<" "<<min_bring<<endl;
    
    return 0;
}
