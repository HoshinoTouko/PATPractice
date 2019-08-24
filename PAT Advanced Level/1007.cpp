#include<iostream>
#include<vector>

using namespace std;

int main(){
    int max_sum = -1;
    int temp_sum = 0;
    int max_start, max_end;
    int temp_start = 0;
    int n, now;

    cin>>n;
    vector<int> data(n);
    max_start = 0;
    max_end = n - 1;
    bool flag = false;
    
    for (int i = 0; i < n; i++){
        cin>>now;
        if (now >= 0)
           flag = true;
        data[i] = now;
        temp_sum += now;
        if (temp_sum < 0){
            temp_sum = 0;
            temp_start = i + 1;
        } else if (temp_sum > max_sum) {
            max_start = temp_start;
            max_end = i;
            max_sum = temp_sum;
        }
    }
    
    if (!flag){
        max_sum = 0;
        max_start = 0;
        max_end = n - 1;
    }
    
    cout<<max_sum<<" "<<data[max_start]<<" "<<data[max_end]<<endl;
    
    return 0;
}
