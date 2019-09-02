#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<char, vector<int> > dict;

int main() {
    string s;
    cin.clear();
    getline(cin, s);
    
    int maxLen = 1;
    for(int i = 0; i < s.size(); i++) {
        int offset = 0;
        int len = 1;
        while(i - offset >= 0 and i + offset < s.size()) {
            if(s[i - offset] != s[i + offset]) {
                break;
            }
            len = 2 * offset + 1;
            offset++;
        }
        maxLen = max(maxLen, len);
    }
    for(int i = 0; i < s.size(); i++) {
        int offset = 0;
        int len = 1;
        while(i + 1 - offset >= 0 and i + offset < s.size()) {
            if(s[i + 1 - offset] != s[i + offset]) {
                break;
            }
            len = 2 * offset;
            offset++;
        }
        maxLen = max(maxLen, len);
    }
    
    cout<<maxLen<<endl;
    
    
    return 0;
}
