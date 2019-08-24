#include<iostream>
#include<vector>

using namespace std;

int calc(vector<int> data, int start, int end){
    int res = 0;
    for(int i = start; i <= end; i++){
        res += data[i];
    }
    return res;
}

int main(){
    vector<int> prob_start, prob_end;
    int n, last, now;
    vector<int> data;
    
    cin>>n;
    last = -1;
    for (int i = 0; i < n; i++){
        cin>>now;
        data.push_back(now);
        if(last <= 0 and now >= 0){
            prob_start.push_back(i);
        }
        if(last >= 0 and now <= 0){
            prob_end.push_back(i-1);
        }
        last = now; 
    }
    if(now >= 0){
        prob_end.push_back(n-1);
    }
    
//    if(prob_start.size() == prob_end.size() == 0){
//        cout<<0<<" "<<data[0]<<" "<<data[n-1]<<endl;
//    }

    int max_sum = 0;
    int max_start = 0;
    int max_end = n - 1;
    for (int _start = 0; _start < prob_start.size(); _start++){
        for (int _end = 0; _end < prob_end.size(); _end++){
            int start = prob_start[_start];
            int end = prob_end[_end];
            
            int cal = calc(data, start, end);
            if (cal > max_sum){
                max_sum = cal;
                max_start = start;
                max_end = end;
            }
        }
    }
    
    cout<<max_sum<<" "<<data[max_start]<<" "<<data[max_end]<<endl;
    
    return 0;
}
