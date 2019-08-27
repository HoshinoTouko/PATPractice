#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

string to_str(int a) {
    stringstream s;
    s << a;
    return s.str();
}

int to_int(char a) {
    stringstream s;
    s << a;
    int r;
    s >> r;
    return r;
}

string mul_two(string a) {
    string res = "";
    int add = 0;
    for(string::reverse_iterator it = a.rbegin(); it != a.rend(); it++) {
        int digit = to_int(*it) * 2 + add;
        if (digit >= 10) {
            add = 1;
            digit %= 10;
        } else {
            add = 0;
        }
        res = to_str(digit) + res; 
    }
    if (add){
        res = to_str(add) + res; 
    }
    return res;
}

int main() {
    string s1;
    cin>>s1;
    string s2 = mul_two(s1);
    string out = s2; 
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    bool flag = s1.size() == s2.size();
    for(int i = 0; i < s1.size(); i++) {
        if (!flag) break;
        if (s1[i] != s2[i]) {
            flag = false;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    cout<<out<<endl;
    
    return 0;
} 
