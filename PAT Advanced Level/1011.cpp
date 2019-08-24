#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double w, t, l, m;
    double rate = 1.0;
    for(int i = 0; i < 3; i++){
        cin>>w>>t>>l;
        m = max(w, max(t, l));
        if(m == w)
             cout<<"W ";
        else if(m == t)
             cout<<"T ";
        else
            cout<<"L ";
        rate *= m;
    }
    cout<<fixed<<setprecision(2)<<(rate * 0.65 - 1) * 2<<endl;
    
    return 0;
}
