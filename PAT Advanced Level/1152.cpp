#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

bool isPrime(string s) {
    stringstream ss;
    ss << s;
    int a;
    ss >> a;
    for(int i = 2; i < sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin>>n>>k;
    
    string o;
    
    cin>>o;
    int p = 0;
    int firstZero = true;
    while(p <= n - k) {
        if(o[p] == '0' and firstZero) {
            p++;
            continue;
        }
        firstZero = false;
        string num = o.substr(p, k);
//        cout<<num<<endl;
        if(isPrime(num)) {
            cout<<num<<endl;
            return 0;
        }
        p++;
    }
    cout<<"404"<<endl;
    
    return 0;
}
