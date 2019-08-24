#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> visited;
map<int, vector<int> > paths;

void dfs(int start){
    if (visited[start]) {
        return;
    }
    visited[start] = 1;
    vector<int>::iterator it;
    for(it = paths[start].begin(); it != paths[start].end(); it++){
        if (!visited[*it])
           dfs(*it);
    }
}

int main(){
    int n, m, k;
    int a, b;
    cin>>n>>m>>k;
     
    paths.clear();
    
    for(int i = 1; i <= n; i++){
        paths[i] = vector<int>();
    }
    
    while(m--){
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    
    int black_sheep, single;
    while(k--) {
        single = 0;
        visited = vector<int>(n+1, 0);
        cin>>black_sheep;
        visited[black_sheep] = 1;
        for(int i = 1; i <= n; i++) {
            if(visited[i]){
                continue;
            }
            dfs(i);
            single++;
        }
        cout<<single-1<<endl;
    }
    
    return 0;
}
