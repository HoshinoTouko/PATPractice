#include <iostream>
#include <sstream>
#include <iomanip> 

using namespace std;

int main() {
    double data[1007];
    for (int i = 0; i < 1005; i++) {
        data[i] = 0.;
    }
    int k, count;
    count = 2;
    while (count --) {
        cin>>k;
        for (int i = 0; i < k; i++) {
            int a;
            double b;
            cin>>a>>b;
            data[a] += b;
        }
    }

    int res_k = 0;
    ostringstream res;
    res<<fixed<<setprecision(1);
    for (int i = 1000; i >= 0; i--) {
        if (data[i] != 0) {
            res<<" "<<i<<" "<<data[i];
            res_k ++;
        }
    }
    
    cout<<res_k<<res.str()<<endl;

    return 0;
}
