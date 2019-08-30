#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> data;

int main(){
    
    int n, m, t, T;
    cin>>n;
    T = n;
    while(T--) {
        cin>>t;
        data.push_back(t);
    } 

    int count = 0, i = 0;

    cin>>m;
    int mid = (n + m - 1) / 2; 
    T = m;
    while(T--) {
        cin>>t;
        while(data[i] < t and i < n) {
            if (count == mid) {
                cout<<data[i]<<endl;
                return 0;
            }
            count++;
            i++;
        }
        
        if (count == mid) {
            cout<<t<<endl;
            return 0;
        }
        count++;
    }
    while(i <= n) {
        
        if (count == mid) {
            cout<<data[i]<<endl;
            return 0;
        }
        count++;
        i++;
    }

    return 0;
}
