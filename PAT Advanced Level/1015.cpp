#include<iostream>
#include<cmath>
#include<sstream>

using namespace std;

bool is_prime(int a){
    if (a < 2){
        return false;
    }
    double s = sqrt(a);
    for (int i = 2; i <= s; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int ctoi(char c){
    stringstream s;
    s << c;
    int res;
    s >> res;
    return res;
}

int to_ten(string a, int radix) {
    int res = 0;
    int mul = 1;
    string::reverse_iterator rit;
    for (rit = a.rbegin(); rit != a.rend(); rit++) {
        res += ctoi(*rit) * mul;
        mul *= radix;
    }
    return res;
}

int to_ten_r(string a, int radix) {
    int res = 0;
    int mul = 1;
    string::iterator it;
    for (it = a.begin(); it != a.end(); it++) {
        res += ctoi(*it) * mul;
        mul *= radix;
    }
    return res;
}

string fr(int a, int radix){
    stringstream s;
    while (a >= radix){
        s << a % radix;
        a /= radix;
    }
    s << a;
    return s.str();
}

int main(){
    string a;
    int x, radix, ten;
    
    while (true) {
        cin>>x;
        if (x < 0) {
            return 0;
        }
        cin>>radix;
        a = fr(x, radix);
//        cout<<a<<endl;
        int s, r;
        s = to_ten(a, radix);
        r = to_ten_r(a, radix);
        if (!is_prime(s) or !is_prime(r)){
            cout<<"No"<<endl;
        } else{
            cout<<"Yes"<<endl;
        }
    }
    
    
    return 0;
}
