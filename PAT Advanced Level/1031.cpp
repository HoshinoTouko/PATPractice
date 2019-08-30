#include<iostream>

using namespace std;

int main() {
    string s;
    cin>>s;
    
    int n1, n2, n3, n = s.size(), T;
    n1 = n3 = (n + 2) / 3;
    n2 = n + 2 - n1 - n3;
//    cout<<n1<<endl;
    for(int i = 0; i < n1 - 1; i++) {
        cout<<s[i];
        T = n2 - 2;
        while(T--) {
            cout<<" ";
        }
        cout<<s[n - 1 - i]<<endl;
    }
    for(int i = n1 - 1; i <= n - n1; i++){
        cout<<s[i];
    }
    
    return 0;
}
