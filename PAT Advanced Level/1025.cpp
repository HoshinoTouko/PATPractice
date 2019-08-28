#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Stu {
    public:
        long long id;
        int score;
        int loc;
};

bool comp(Stu a, Stu b) {
    if(a.score > b.score) {
        return true;
    }
    if(a.score == b.score) {
        return a.id < b.id;
    }
    return false;
}

int main() {
    int n, m;
    vector<Stu> data;
    cin>>n;
    long long id;
    int score; 
    for(int loc = 1; loc <= n; loc++) {
        cin>>m;
        while(m--) {
            cin>>id>>score;
            Stu stu = {id, score, loc};
            data.push_back(stu);
        }
    }

    sort(data.begin(), data.end(), comp);
    cout<<data.size()<<endl;
    
    int rank = 0, ranks[n+1], last = -1, lasts[n+1];
    int dis_rank = rank, dis_ranks[n+1];
    for(int i = 0; i < n+1; i++) {
        ranks[i] = 0;
        dis_ranks[i] = 0;
        lasts[i] = -1;
    }
    for(vector<Stu>::iterator it = data.begin(); it != data.end(); it++) {
                              
        printf("%013lld ", (*it).id);
        int loc = (*it).loc;
        int score = (*it).score;
        
        rank ++;
        ranks[loc] ++;
        if(last != score) {
            dis_rank = rank;
            last = score;
        }
        if(lasts[loc] != score) {
            dis_ranks[loc] = ranks[loc];
            lasts[loc] = score;
        }
        
        cout<<dis_rank<<" "<<loc<<" "<<dis_ranks[loc]<<endl;
    }
    
    return 0;
} 
