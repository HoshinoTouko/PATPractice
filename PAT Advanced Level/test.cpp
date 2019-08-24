#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;


vector<vector<int> > ret(){
    vector<vector<int> > a(10, vector<int>(10, 1));
    
    return a;
}

int main(){
    vector<vector<int> > x;
    x = ret();
    cout<<x[0][0]<<endl;
    
    return 0;
}
