#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>
#include<iomanip>

using namespace std;

vector<int> split(string a, char b){
    vector<int> res;
    string tt;
    int tint;
    for (int i = 0; i <a.size(); i++){
        if (a[i] != b){
            tt += a[i];
            continue;
        }
        stringstream t;
        t << tt;
        t >> tint;
        res.push_back(tint);
        tint = 0;
        tt = "";
    }
    stringstream t;
    t << tt;
    t >> tint;
    res.push_back(tint);
    return res;
}

int get_seconds(string time) {
    vector<int> res = split(time, ':');
    return (res[0] - 8) * 3600 + res[1] * 60 + res[2];
}

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

class Queue{
    public:
        int end_time;
        bool init;
        Queue(){
            this->end_time = 0;
            this->init = false;
        }
};

int main(){
    int n, k, T;
    cin>>n>>k;
    string origin_time;
    int time, cost;
    vector<pair<int, int> > data;
    T = n;
    while(T--){
        cin>>origin_time>>cost;
        time = get_seconds(origin_time);
//        cout<<time<<endl;
        if (time <= 32400){
            data.push_back(make_pair(time, cost * 60));
        }
    }
    sort(data.begin(), data.end(), comp);
    
    vector<Queue> que(k, Queue());
    int sq, min_end, wait;
    double count = 0, total = 0; 
    for(vector<pair<int, int> >::iterator it = data.begin(); it != data.end(); it++) {
//        cout<<"Data: "<<(*it).first<<" "<<(*it).second<<endl;
        if (!que[k - 1].init){
            for(int i = 0; i < k; i++){
                if(!que[i].init){
                    que[i].init = true;
                    count++;
                    
                    wait = - (*it).first;
                    if (wait > 0){
                        total += wait;
                        que[i].end_time = (*it).second;
                    } else {
                        que[i].end_time = (*it).first + (*it).second;
                    }
                    break;
                } 
            }
            continue;
        }
        sq = 0;
        min_end = que[sq].end_time;
        for(int i = 0; i < k; i++){
            if (que[i].end_time < min_end){
                sq = i;
                min_end = que[i].end_time;
            }
        }
        count++;
        wait = que[sq].end_time - (*it).first;
        if (wait > 0){
            total += wait;
            que[sq].end_time += (*it).second;
        } else {
            que[sq].end_time = (*it).first + (*it).second;
        }
//        cout<<(*it).first<<" "<<que[sq].end_time<<" Wait: "<<wait<<endl;
    }
//    cout<<total<<" "<<count<<endl;
    cout<<fixed<<setprecision(1)<<total/count/60<<endl;
    
    return 0;
}
