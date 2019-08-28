#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

string _to_string(int a) {
    stringstream s;
    s << a;
    return s.str();
}

string reverse_add_int(string a) {
    string ra = a;
    reverse(ra.begin(), ra.end());
    
//    cout<<a<<" "<<ra<<endl;
    
    string res;
    
    int add = 0;
    for(int i = 0; i < a.size(); i++) {
        int digit = add + a[i] - '0' + ra[i] - '0';
        add = 0;
        if (digit > 9) {
            add = 1;
            digit -= 10;
        }
        res = _to_string(digit) + res;
    }
    if (add)
        res = _to_string(add) + res;
    return res;
}

bool is_pali(string b) {
    if (b.size() == 1) {
        return true;
    }
    for(int i = 0; i < b.size() / 2; i++) {
        if (b[i] != b[b.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string a;
    int m_step;
    
    cin>>a>>m_step;
    
    int i;
    for(i = 0; i < m_step; i++) {
        if (is_pali(a)) {
            break;
        }
        a = reverse_add_int(a);
    }
    cout<<a<<endl;
    cout<<i<<endl;
    
    return 0;
}
