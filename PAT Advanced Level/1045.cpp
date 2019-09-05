#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<bool> fav;
vector<int> seq;
map<int, int> favOrder;

int maxSum = 0;

int main() {
    int n;
    cin>>n;
    fav = vector<bool>(n+1, false);
    
    int m, t;
    cin>>m;
    int order = 1;
    while(m--) {
        cin>>t;
        fav[t] = true;
        favOrder[t] = order++;
    }
    
    cin>>m;
    int DPMAX = m; 
    while(m--) {
        cin>>t;
        if(!fav[t]) continue;
        seq.push_back(favOrder[t]);
    }

    // Max not decreasing sequence
    vector<int> dp(DPMAX, 0);
    int p = 1;
    dp[p] = seq[0];
    for(int i = 1; i < seq.size(); i++) {
        if(seq[i] >= dp[p]) {
            dp[++p] = seq[i];
        } else {
//            for(int j = 0; j <= p; j++) {
//                if(dp[j] > seq[i]) {
//                    dp[j] = seq[i];
//                    break;
//                }
//            }
            int index = upper_bound(dp.begin(), dp.begin() + p + 1, seq[i]) - dp.begin();
            dp[index] = seq[i];
        }
    }
    cout<<p<<endl;
    
    return 0;
}
