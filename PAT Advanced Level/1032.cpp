#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

map<int, pair<char, int> > dict;
map<int, bool> hasAppear; 

int main() {
    int sa, sb, n;
    cin>>sa>>sb>>n;
    
    int s, e;
    char c;
    while(n--) {
        cin>>s>>c>>e;
        dict[s] = make_pair(c, e);
        hasAppear[s] = false;
    }
    string fsa, fsb;
    vector<int> va, vb;
    int endPointer = -1;

    for (int i = sa; i != -1; i = dict[i].second) {
        hasAppear[i] = true;
    }
    for (int i = sb; i != -1; i = dict[i].second) {
        if(hasAppear[i]) {
            endPointer = i;
            break;
        }
    }

    if(endPointer == -1) {
        cout<<-1<<endl;
    } else {
        printf("%05d", endPointer);
    }
    
    return 0;
}
