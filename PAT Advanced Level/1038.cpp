#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

bool cmp(string a, string b) {
    return a + b < b + a;
//    stringstream ab, ba;
//    ab << a << b;
//    ba << b << a;
//    long long _ab, _ba;
//    ab >> _ab;
//    ba >> _ba;
//    return _ab < _ba;
}

vector<string> nums;

int main() {
    int n;
    string t;
    cin>>n;
    while(n--) {
        cin>>t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end(), cmp);
    
    stringstream _output;
    for(int i = 0; i < nums.size(); i++) {
        _output<<nums[i];
    }
    string output;
    _output >> output;
    while(output[0] == '0' and output.size() > 1) {
        output = output.substr(1, output.size() - 1);
    }
    cout<<output<<endl;
    
    return 0;
}
