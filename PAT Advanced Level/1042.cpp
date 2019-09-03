#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector<string> genCards() {
    vector<string> res;
    for(int i = 0; i < 54; i++) {
        stringstream s;
        switch(i / 13) {
            case 0:
                s << "S";
                break;
            case 1:
                s << "H";
                break;
            case 2:
                s << "C";
                break;
            case 3:
                s << "D";
                break;
            case 4:
                s << "J";
                break;
        }
        s << (i % 13) + 1;
//        cout<<s.str()<<endl;
        res.push_back(s.str());
    }
    return res;
}

int main() {
    int n, T = 54, t;
    cin>>n;
    
    vector<int> mat;
    vector<string> oCards = genCards();
    while(T--) {
        cin>>t;
        t--;
        mat.push_back(t);
    }
    while(n--) {
        vector<string> nCards(54, "");
        for(int i = 0; i < 54; i++) {
            nCards[mat[i]] = oCards[i];
        }
        oCards = nCards;
    }
    for(int i = 0; i < oCards.size(); i++) {
        cout<<oCards[i]<<(i == oCards.size() - 1 ? "" : " ");
    }
    
    return 0;
}
