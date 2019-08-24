#include<iostream>
#include<string>

using namespace std;

int main(){
    long long total = 0;
    int n, now, last = 0;
    cin>>n;
    while(n--){
        cin>>now;
        total += 5;
        if (now > last){
            total += 6 * (now - last);
        }
        else {
            total += 4 * (last - now);
        }
        last = now;
    }
    
    cout<<total<<endl;
    
    return 0;
}
