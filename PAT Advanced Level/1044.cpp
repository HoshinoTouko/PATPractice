#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first or a.first == b.first and a.second < b.second;
}

int main() {
    int n, m, T, t;
    cin>>n>>m;
    T = n;
    
    vector<int> data;
    while(T--) {
        cin>>t;
        data.push_back(t);
    }
    int start = 0, end = 0;
    int tmp = data[0];
    bool finded = false;
    int minSubVal = 999999;
    
    vector<pair<int, int> > res;
    while(start <= end and end < n) {
//        cout<<start + 1<<"-"<<end<<" "<<tmp<<endl;
        if (tmp == m) {
            finded = true;
            res.push_back(make_pair(start + 1, end + 1));
        }
        if(tmp > m and start < end) {
            if(tmp - m){
                minSubVal = min(tmp - m, minSubVal);
            }
            tmp -= data[start++];
            continue;
        }
        tmp += data[++end];
    }
//    cout<<minSubVal<<endl;
    if(!finded) {
        m += minSubVal;
        start = 0, end = 0;
        tmp = data[0];
        while(start <= end and end < n) {
//            cout<<start + 1<<"-"<<end<<" "<<tmp<<endl;
            if (tmp == m) {
                res.push_back(make_pair(start + 1, end + 1));
            }
            if(tmp > m and start < end) {
                tmp -= data[start++];
                continue;
            }
            tmp += data[++end];
        }
    }
    
    sort(res.begin(), res.end(), cmp);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i].first<<"-"<<res[i].second<<endl;
    }
    
    return 0;
}
