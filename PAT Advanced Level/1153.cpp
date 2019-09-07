#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

// Need index to pass the last two testcase, no need to write them when practice.

using namespace std;

map<string, int> data;

vector<pair<string, int> > f(string query) {
    vector<pair<string, int> > res;
    for(map<string, int>::iterator it = data.begin(); it != data.end(); it++) {
        string s = (*it).first;
        if(s.find(query) == s.npos) {
            continue;
        }
        res.push_back(make_pair(s, (*it).second));
    }
    return res;
}

bool soryByScore(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second or a.second == b.second and a.first < b.first;
}

//bool case3Sort()

void doOP(int op, string query) {
    if(op < 1 or op > 3) {
        cout<<"NA"<<endl;
        return;
    }
    vector<pair<string, int> > res = f(query);
    if(!res.size()) {
        cout<<"NA"<<endl;
        return;
    }
    int tC = 0, tS = 0;
    switch(op) {
        case 1:
            sort(res.begin(), res.end(), soryByScore);
            for(int i = 0; i < res.size(); i++) {
                cout<<res[i].first<<" "<<res[i].second<<endl;
            }
            break;
        case 2:
            for(int i = 0; i < res.size(); i++) {
                tC++;
                tS += res[i].second;
            }
            cout<<tC<<" "<<tS<<endl;
            break;
        case 3:
            map<string, int> o;
            for(int i = 0; i < res.size(); i++) {
                string site = res[i].first.substr(1, 3);
                if(!o.count(site)) {
                    o[site] = 1;
                } else {
                    o[site] ++;
                }
            }
            vector<pair<string, int> > oo;
            for(map<string, int>::iterator it = o.begin(); it != o.end(); it++) {
                oo.push_back(make_pair((*it).first, (*it).second));
            }
            sort(oo.begin(), oo.end(), soryByScore);
            for(int i = 0; i < oo.size(); i++) {
                cout<<oo[i].first<<" "<<oo[i].second<<endl;
            }
            break;
    }
}

int main() {
    int qs, os;
    cin>>qs>>os;
    
    string ID;
    int score;
    while(qs--) {
        cin>>ID>>score;
        data[ID] = score;
    }
    
    int op;
    string query;
    int order = 1;
    while(os--) {
        cin>>op>>query;
        cout<<"Case "<<order<<": "<<op<<" "<<query<<endl;
        doOP(op, query);
        order++;
    }
    
    return 0;
}
