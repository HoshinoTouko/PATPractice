#include<iostream>
#include<vector>

using namespace std;

int get_int(char a){
    if ((a - 0) >= 48 and (a - 0) <= 57){
        return a - 48;
    }
    return a - 87;
}

long long get_ten(vector<int> a, int radix){
    vector<int>::reverse_iterator rit;
    long long mul = 1, res = 0;
    for(rit = a.rbegin(); rit != a.rend(); rit++){
        res += (*rit) * mul;
        mul *= radix;
    }
    return res;
}

long long get_max(vector<int> a){
    int max = -1;
    for(vector<int>::iterator it = a.begin(); it != a.end(); it++){
        if ((*it) > max)
           max = (*it);
    }
    return max;
}

long long binary_search(long long low, long long high, long long origin, vector<int> bb){
    long long test_radix = (low + high) / 2;
    long long res = get_ten(bb, test_radix);
    if (get_ten(bb, test_radix) == origin){
        return test_radix;
    }
    if (low > high){
        return -1;
    }
    if (res > origin or res < 0){
        return binary_search(low, test_radix - 1, origin, bb);
    }
    return binary_search(test_radix + 1, high, origin, bb);
}

int main(){
    string a, b;
    int tag, radix;
    
    cin>>a>>b>>tag>>radix;
    if (tag == 2) {
        swap(a, b);
    }
    
    vector<int> aa, bb;
    for (int i = 0; i < a.length(); i++){
        aa.push_back(get_int(a[i]));
    }
    for (int i = 0; i < b.length(); i++){
        bb.push_back(get_int(b[i]));
    }
    
    long long origin = get_ten(aa, radix);

    long long now = -1;
    
    long long low = get_max(bb) + 1, high = max(get_max(bb), origin) + 1;
    long long res = binary_search(
        low,
        high,
        origin, bb 
    );
    if (res == -1){
        cout<<"Impossible"<<endl;
    } else {
        cout<<res<<endl;
    }
    
    return 0;
}
