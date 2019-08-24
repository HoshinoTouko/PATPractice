#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

string show_res(int seconds){
    stringstream res;
    int min = 8 + seconds / 60;
    int sec = seconds % 60;
    if (min < 10){
        res << "0";
    }
    res << min;
    res << ":";
    if (sec < 10){
        res << "0";
    }
    res << sec;
    return res.str();
}

class Queue {
    public:
        int next_time;
        int end_time;
        queue<int> q;
        Queue() {
            this->next_time = 0;
            this->end_time = 0;
        }
        void show() {
            cout<<"Next: "<<this->next_time<<"End: "<<this->end_time<<endl;
        }
};

int main(){
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    
    vector<int> cost;
    
    int t, T;
    T = k;
    while(T--) {
        cin>>t;
        cost.push_back(t);
    }
    
    int res[k] = {0,};
    vector<Queue> data(n, Queue());
    int sq, min_next;
    for(int i = 0; i < k; i++) { 
    
        if (data[n - 1].q.size() < m) {
            sq = 0;
            for (int j = 0; j < n - 1; j++) {
                if (data[j].q.size() - data[j+1].q.size() == 1) {
                    sq = j + 1;
                    break;
                }
            }
            
            if (data[sq].q.size() == 0){
                data[sq].next_time = cost[i];
            }
            data[sq].end_time += cost[i];
            data[sq].q.push(cost[i]);
            res[i] = data[sq].end_time;
//            cout<<sq<<" ";
//            data[sq].show();
            continue;
        } 
        
        sq = 0;
        min_next = data[0].next_time;
        for (int j = 0; j < n; j++) {
            if (data[j].next_time < min_next) {
                min_next = data[j].next_time;
                sq = j;
            }
        }
        data[sq].q.pop();
        data[sq].next_time += data[sq].q.front();
        data[sq].end_time += cost[i];
        data[sq].q.push(cost[i]);
        res[i] = data[sq].end_time;
    }
    
    while(q--) {
        cin>>t;
        int _res = res[t-1];
        if (_res - cost[t-1] < 540) {
            cout<<show_res(_res)<<endl;
        }
        else {
            cout<<"Sorry"<<endl;
        }
    }
    
    return 0;
}
