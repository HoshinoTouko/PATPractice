#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> new_int;

void get_by_base(int a, int radix) {
    while(a){
        new_int.push_back(a % radix);
        a /= radix;
    }
}

int main(){
    int a, radix;
    cin>>a>>radix;
    
    if (a == 0) {
        cout<<"Yes"<<endl<<a<<endl;
    }
    
    get_by_base(a, radix);
    
    bool flag = true;
    for(int i = 0; i < new_int.size(); i++) {
        if(new_int[i] != new_int[new_int.size() - 1 - i]){
            flag = false;
            break;
        }
    }
    
    if (flag) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    for (int i = new_int.size() - 1; i >= 0; i--) {
        cout<<new_int[i]<<(i == 0 ? "" : " ");
    }
    
    return 0;
}
