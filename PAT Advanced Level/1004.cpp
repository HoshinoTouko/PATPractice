#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m, T;
    cin>>n>>m;
    
    vector<vector<int> > data = vector<vector<int> >(n + 5, vector<int>());
    
    T = m;
    
    int father, nums, child;
    while(T--){
        cin>>father>>nums;
        while(nums--){
            cin>>child;
            data[father].push_back(child);
        }
    }
    
    vector<int> past = vector<int>();
    vector<int> current = vector<int>(1, 1);
    
    while (true) {
        past = vector<int>(current);
        current = vector<int>(); 
        
        int count = 0;
        for (int i = 0; i < past.size(); i++){
            if(data[past[i]].size() == 0){
                count ++;
                continue;
            }
            current.insert(current.end(), data[past[i]].begin(), data[past[i]].end());
        }
        cout<<count;
        if (count == past.size())
           break;
        cout<<" ";
    }
    
    return 0;
}
