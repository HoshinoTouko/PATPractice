#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include <iomanip>

using namespace std;


string fix_one(double a){
    stringstream res;
    res<<fixed<<setprecision(1)<<a;
    return res.str();
}


int main(){
    int n;
    int k1;
    double k2;
    vector<pair<int, double> > poly_a, poly_b;
    
    cin>>n;
    while(n--){
        cin>>k1>>k2;
        poly_a.push_back(make_pair(k1, k2));
    }
    cin>>n;
    while(n--){
        cin>>k1>>k2;
        poly_b.push_back(make_pair(k1, k2));
    }
    
    map<int, double> result;
    for(int i = 0; i < poly_a.size(); i++) {
        for(int j = 0; j < poly_b.size(); j++) {
            k1 = poly_a[i].first + poly_b[j].first;
            k2 = poly_a[i].second * poly_b[j].second;
            if (result.count(k1) == 0){
                result[k1] = k2;
            } else {
                result[k1] += k2;
            }
        }
    }
    
    stringstream output;
    int count = 0;
    map<int, double>::reverse_iterator rit;
    for(rit = result.rbegin(); rit != result.rend(); rit++){
        if ((*rit).second == 0){
            continue;
        }
        count ++;
        output<<" "<<(*rit).first<<" "<<fix_one((*rit).second);
    }
    cout<<count<<output.str();
    
    return 0;
}
