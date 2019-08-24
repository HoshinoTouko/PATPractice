#include<iostream>
#include<vector>

using namespace std;

vector<string> split(string a, string b){
    string::iterator it;
    vector<string> res;
    string t;
    for (it = a.begin(); it != a.end(); it++){
        if (*it != b){
            t += *it;
            continue;
        }
        res.push_back(t);
        t = "";
    }
    return res;
}

int main(){
    vector<int> costs;
    int T = 24, t, n;
    string name, time, op;
    while(T--){
        cin>>t;
        costs.push_back(t);
    }
    
    
    while(n--){
        cin>>name>>time>>op;
    }
    
    return 0;
}
