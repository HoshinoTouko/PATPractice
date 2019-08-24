#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

const string label[] = {"A", "C", "M", "E"};

double get_a(double c, double m, double e){
    return (c + m + e) / 3;
}

int main(){
    string id;
    double c, m, e;
    map<string, int> pointer;
    vector<vector<double> > data;

    int n, _m;
    cin>>n>>_m;
    for(int i = 0; i < n; i++){
        cin>>id>>c>>m>>e;
        pointer[id] = i;
        
        double arr[] = {get_a(c, m, e), c, m, e}; 
        int n = sizeof(arr) / sizeof(arr[0]); 
        vector<double> t(arr, arr + n);
        data.push_back(t);
    }
    
    while(_m--) {
        cin>>id;
        if (pointer.count(id) == 0) {
            cout<<"N/A"<<endl;
            continue;
        }
        int p = pointer[id];
        
        vector<double> self = data[p];
        int min_rank = data.size(), min_offset = 0;
        int rank;
        for(int i = 0; i < 4; i++){
            rank = 1;
            for(int j = 0; j < data.size(); j++){
                if (data[j][i] > self[i])
                   rank ++;
            }
            if(rank < min_rank){
                min_rank = rank;
                min_offset = i;
            }
        }
        cout<<min_rank<<" "<<label[min_offset]<<endl;
    }
    
    return 0;
}
