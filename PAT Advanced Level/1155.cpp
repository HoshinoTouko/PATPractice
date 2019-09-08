#include<iostream>
#include<vector>

using namespace std;

vector<int> h(1, 0);
bool max_heap = false, min_heap = false;
vector<int> dis;

void display() {
    for(int i = 0; i < dis.size(); i++) {
        cout<<dis[i]<<(i == dis.size() - 1 ? "\n" : " ");
    }
}

void dfs(int s, int n) {
    dis.push_back(h[s]);
//    cout<<h[s]<<" "<<h[s / 2]<<endl;
    if(s > 1) {
        if(!max_heap and h[s] < h[s / 2]) {
            max_heap = true;
        }
        if(!min_heap and h[s] > h[s / 2]) {
            min_heap = true;
        }
    }
    if (2 * s > n) {
        display();
    } else {
        if(2 * s + 1 <= n) {
            dfs(2 * s + 1, n);
        } 
        if(2 * s <= n) {
            dfs(2 * s, n);
        } 
    }
    dis.pop_back();
}

int main() {
    int n, T, t;
    cin>>n;
    T = n;
    while(T--) {
        cin>>t;
        h.push_back(t);
    }
    if(h[1] > h[2]) {
        max_heap = h[1] > h[2];
    } else {
        max_heap = false;
    }
    dfs(1, n);
    if(max_heap and min_heap or !max_heap and !min_heap) {
        cout<<"Not Heap"<<endl;
    } else {
        if(max_heap) {
            cout<<"Max Heap"<<endl;
        } else {
            cout<<"Min Heap"<<endl;
        }
    }
    
    return 0;
}
