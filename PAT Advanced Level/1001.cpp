#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b;
    c = a + b;

    ostringstream stream;
    stream << c;
    string _res = stream.str();
    string res = "";

    int len = _res.length();
    for (int i = 0; i < len; i++) {
        int pointer = len-i-1;
        res = _res[pointer] + res;
        if ((i + 1) % 3 == 0) {
            if (c < 0 and i < len - 2 or c > 0 and i < len-1){
                res = "," + res;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}

