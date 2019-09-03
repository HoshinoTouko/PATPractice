#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> order;
map<int, int> count;

int main() {
    int n;
    cin>>n;
    int t;
    while(n--) {
        cin>>t;
        if(!count.count(t)) {
            count[t] = 1;
            order.push_back(t);
            continue;
        }
        count[t] ++;
    }
    
    for(int i = 0; i < order.size(); i++) {
        if(count[order[i]] == 1) {
            cout<<order[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    
    return 0;
}
