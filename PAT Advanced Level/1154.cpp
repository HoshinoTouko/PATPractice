#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
    int n, m, T, check;
    cin>>n>>m;
    
    vector<vector<int> > graph(n, vector<int>());
    
    int a, b;
    while(m--) {
        cin>>a>>b;
        if(a < b) swap(a, b);
        graph[a].push_back(b);
    }

    cin>>check;
    while(check--) {
        int c;
        int succeed = true;
        vector<int> color(n, -1);
        map<int, int> colorType;
        for(int i = 0; i < n; i++) {
            cin>>c;
            if(!succeed) continue;
            colorType[c] = 0;
            color[i] = c;
            for(int j = 0; j < graph[i].size(); j++) {
                int cj = graph[i][j];
                if(color[cj] == color[i]) {
                    cout<<"No"<<endl;
                    succeed = false;
                    break;
                }
            }
        }
        if(succeed) {
            cout<<colorType.size()<<"-coloring"<<endl;
        }
    }
    
    
    return 0;
}
