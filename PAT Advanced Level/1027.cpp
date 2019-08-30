#include<iostream>
#include<string>

const char dict[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

using namespace std;

int getValue(char a) {
    if (a >= 'A') {
        return a - 'A' + 10;
    }
    return a - '0';
}

string trans(string a) {
    int mid = 0;
    int radix = 10;
    int count = 1;
    for(string::reverse_iterator rit = a.rbegin(); rit != a.rend(); rit++) {
        mid += count * getValue(*rit);
        count *= radix;
//        cout<<getValue(*rit)<<endl; 
    }
//    cout<<mid<<endl;
    radix = 13;
    string res;
    while(mid) {
        res = dict[mid % radix] + res;
        mid /= radix;
    }
    if(res.size() == 1) {
        res = "0" + res;
    }
    if(res.size() == 0) {
        res = "00";
    }
    return res;
}

int main() {
    string r, g, b;
    cin>>r>>g>>b;
    cout<<"#"<<trans(r)<<trans(g)<<trans(b)<<endl;
    
    return 0;
}
