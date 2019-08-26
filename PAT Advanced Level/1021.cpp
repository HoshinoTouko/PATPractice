#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Testcase 3 TLE;

vector<bool> visited;
vector<vector<int> > paths;
int n;

void show_vec(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int get_layer(int start) {
    vector<bool> local_visited(n + 1, false);
    vector<bool> last;
    vector<int> old;
    vector<int> cur;
    
    cur.push_back(start);
    
    int layer = 0;
    
    while(cur.size()) {  
        vector<int> new_cur;
        
        for(vector<int>::iterator it = cur.begin(); it != cur.end(); it++) {
            visited[*it] = true;
            local_visited[*it] = true;
            
            vector<int> path = paths[*it];
            for (vector<int>::iterator iit = path.begin(); iit != path.end(); iit++) {
                if (local_visited[*iit])
                   continue;
                new_cur.push_back(*iit);
            }
        }
        
        old = cur;
        cur = new_cur;
        layer++;
    }
    return layer;
}

int get_k(){
    visited = vector<bool>(n + 1, false);

    int count = 0;
    for(int i = 1; i <= n; i++) {
        if (visited[i])
           continue;
        get_layer(i);
        count++;
    }
    return count; 
}

int main() {
    cin>>n;
    paths = vector<vector<int> >(n + 1, vector<int>());
    
    int T = n - 1, a, b;
    while(T--) {
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    
    int max_layer = 0;
    bool flag = true, checked = false;
    vector<int> max_layer_start;
    vector<int> deepests;
    
    visited = vector<bool>(n + 1, false);
    for (int i = 1; i <= n; i++) {
        visited = vector<bool>(n + 1, false);
        
        int layer = get_layer(i);
//        cout<<i<<" "<<layer<<endl;
        
        if (!checked) {
            for(int j = 1; j <= n; j++) {
                if (visited[j])
                   continue;
                flag = false;
                break;
            }
            checked = true;
        }
        if (!flag) break;
        if (layer > max_layer) {
            max_layer = layer;
            max_layer_start = vector<int>();
        }
        if (layer >= max_layer) {
            max_layer_start.push_back(i);
        }
    }
    
    if (flag) {
        for (int i = 0; i < max_layer_start.size(); i++) {
            cout<<max_layer_start[i]<<endl;
        }
    } else {
        cout<<"Error: "<<get_k()<<" components"<<endl;
    }
    
    return 0;
}
