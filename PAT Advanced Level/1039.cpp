#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

map<string, vector<int> > students;

int main() {
    int n, cns;
    cin>>n>>cns;
    
    int cNo, cnt;
    string name;
    while(cns--) {
        cin>>cNo>>cnt;
        while(cnt--) {
            cin>>name;
            if(!students.count(name)) {
                students[name] = vector<int>();
            }
            students[name].push_back(cNo);
        }
    }
    while(n--) {
        cin>>name;
        if(!students.count(name)) {
            cout<<name<<" "<<0; 
        } else {
            sort(students[name].begin(), students[name].end());
            cout<<name<<" "<<students[name].size();
            for(int i = 0; i < students[name].size(); i++) {
                cout<<" "<<students[name][i];
            }
        }
        cout<<endl;
    }
    
    return 0;
}
