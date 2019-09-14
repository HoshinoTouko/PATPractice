#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    bool ds;
    if(n % 2 == 0) {
        ds = false;
    } else {
        ds = true;
    }
    
    int t;
    bool ascend, checked = false;
    int maxx, minn;
    double mid;
    
    int first;
    cin>>first;
    for (int i = 1; i < n; i++) {
        cin>>t;
        if(!checked) {
            if(t > first) {
                ascend = true;
                minn = first;
                checked = true;
            } else if (t < first){
                ascend = false;
                maxx = first;
                checked = true;
            }
        }
        if(ds) {
            if (i == n / 2) {
                mid = t;
            }
        } else {
            if (i == n / 2) {
                mid += t;
                mid /= 2;
            } else if (i == n / 2 - 1) {
                mid = t;
            }
        }
        if(i == n-1) {
            if(ascend) {
                maxx = t;
            } else {
                minn = t;
            }
            if(!checked) {
                maxx = mid = minn = t;
                break;
            }
        }
    }
    
    char a[1000];
    
    int test = mid;
    if(test == mid) {
        sprintf(a, "%d", test);
    } else {
        sprintf(a, "%.1f", mid);
    }
    
    string minRes = a;
    cout<<maxx<<" "<<minRes<<" "<<minn<<endl;
    
    return 0;
}
