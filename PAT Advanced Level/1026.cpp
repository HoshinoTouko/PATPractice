#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

// Two test point failed (due to the missing of problem information)

class People {
    public:
        int needTime;
        bool isVip;
        int waitTime;
        int table;
};

map<int, People> peoples;
map<int, People> finishPeoples;
 
int n, k, m;

int to_int(string a) {
    stringstream s;
    s << a;
    int res;
    s >> res;
    return res;
}

vector<int> split(string a) {
    vector<int> res;
    string tmp = "";
    for(int i = 0; i <= a.size(); i++) {
        if(i == a.size() or a[i] == ':') {
            res.push_back(to_int(tmp));
//            cout<<tmp<<" ";
            tmp = "";
            continue;
        }
        tmp += a[i];
    }
//    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
    return res;
}

string getTimeString(int a) {
    char sb[100]; 
    a += 8 * 3600;
    sprintf(sb, "%02d:%02d:%02d", a / 3600, (a % 3600) / 60, a % 60);
    string s = sb;
    return s;
}

int getTime(string a) {
    vector<int> res = split(a);
    return res[0] * 3600 + res[1] * 60 + res[2] - (8 * 3600);
}

int upper(double a) {
    int b = a;
    if(a > b) {
        return b + 1;
    }
    return b;
}

int main() {
    cin>>n;
    
    int T = n, t;
    string arrTime;
    int needTime, isvip;
    while(T--) {
        cin>>arrTime>>needTime>>isvip;
        People p = {needTime * 60, isvip, 0};
        peoples[getTime(arrTime)] = p;
//        cout<<getTime(arrTime)<<endl;
    }
    
    cin>>k>>m;
    vector<bool> vip(m, false);
    vector<int> endTime(k, 0), peopleCount(k, 0);
    T = m;
    while(T--){
        cin>>t;
        vip[--t] = true;
    }
    while(!peoples.empty()) {
        // Find table
        int minTable = 0, minEndTime = endTime[minTable];
        bool vipTable = (*(peoples.begin())).second.isVip;
        
        bool vipFound = false;
        if (vipTable) {
            for(int i = 0; i < k; i++) {
                if(vip[i] and endTime[i] < minEndTime) {
                    minEndTime = endTime[i];
                    minTable = i;
                    vipFound = true;
                }
            }
        } 
        if ((vipTable and !vipFound) or !vipTable) {
            for(int i = 0; i < k; i++) {
                if(endTime[i] < minEndTime) {
                    minEndTime = endTime[i];
                    minTable = i;
                }
            }
        }
//        cout<<minTable<<endl;
        bool isVip = vip[minTable];
        map<int, People>::iterator it, selectPeople;
        selectPeople = peoples.begin();
        if(isVip) {
            for(it = peoples.begin(); it != peoples.end(); it++) {
                if ((*it).first > minEndTime)
                    break;
                if ((*it).second.isVip) {
                    selectPeople = it;
                    break;
                }
            }
        }
        (*selectPeople).second.table = minTable;
        int waitTime = minEndTime - (*selectPeople).first;
        if(waitTime > 0) {
            (*selectPeople).second.waitTime = waitTime;
            endTime[minTable] = minEndTime + (*selectPeople).second.needTime;
        } else {
            endTime[minTable] = (*selectPeople).first + (*selectPeople).second.needTime;
        }
        finishPeoples[(*selectPeople).first + (*selectPeople).second.waitTime] = (*selectPeople).second;
        peoples.erase(selectPeople);
    }

    map<int, People>::iterator it;
    for(it = finishPeoples.begin(); it != finishPeoples.end(); it++) {
        int arrivingTime = (*it).first - (*it).second.waitTime;
        int servingTime = (*it).first;
        double waitTime = (*it).second.waitTime;
        if (servingTime >= 3600 * (21 - 8)) {
            continue;
        }
        peopleCount[(*it).second.table] ++;
        cout<<getTimeString(arrivingTime)<<" "<<getTimeString(servingTime)<<" "<<upper(waitTime / 60)<<endl;
    }
    for(int i = 0; i < k; i++) {
        cout<<peopleCount[i]<<(i == k - 1 ? "" : " ");
    }
    
    return 0;
}
