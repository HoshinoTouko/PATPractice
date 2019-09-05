#include<iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int d[n];
    int total = 0;
    int sum[n] = {0};
    for(int i = 0; i < n; i++) {
        cin>>d[i];
        sum[i] = total;
        total += d[i];
    }
    
    int a, b, m;
    cin>>m;
    while(m--) {
        cin>>a>>b;
        
        if(b < a) swap(a, b);
        a--;b--;
        int res = sum[b] - sum[a];
        cout<<min(res, total - res)<<endl;
    }
    
    return 0;
}
