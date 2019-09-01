#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
    long long n, t;
    deque<long long> coupons, products;
    cin>>n;
    while(n--) {
        cin>>t;
        if(t == 0)
            continue;
        coupons.push_back(t);
    }
    cin>>n;
    while(n--) {
        cin>>t;
        if(t == 0)
            continue;
        products.push_back(t);
    }
    sort(coupons.begin(), coupons.end());
    sort(products.begin(), products.end());
    
    long long profit = 0;
    while(coupons.size() and  products.size()) {
        if(coupons[0] < 0 and products[0] < 0) {
            profit += coupons[0] * products[0];
            coupons.pop_front();
            products.pop_front();
            continue;
        }
        if(coupons[coupons.size() - 1] > 0 and products[products.size() - 1] > 0) {
            profit += coupons[coupons.size() - 1] * products[products.size() - 1];
            coupons.pop_back();
            products.pop_back();
            continue;
        }
        break;
    }
    
    cout<<profit<<endl;
    
    return 0;
}
