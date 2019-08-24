#include<iostream>
#include<vector>

using namespace std;

int visited[507] = {0,};
int paths[507][507];
int rescue[507];
int n, m, c1, c2;

vector<pair<int, int> > result;

void dfs(int start, int length, int rescue_count, int target) {
    if (start == target) {
        result.push_back(make_pair(length, rescue_count));
        return;
    }


    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i] or paths[start][i] == -1)
            continue;

        dfs(i, length + paths[start][i], rescue_count + rescue[i], target);
        visited[i] = 0;
    }
}

int main() {
    int T;

    cin>>n>>m>>c1>>c2;
    T = n;

    int pointer = 0;
    while (T--) {
        cin>>rescue[pointer];
        pointer++;
    }

    T = m;
    int tc1, tc2, path_len;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            paths[i][j] = -1;
            paths[j][i] = -1;
        }
    }
    while (T--) {
        cin>>tc1>>tc2>>path_len;
        paths[tc1][tc2] = path_len;
        paths[tc2][tc1] = path_len;
    }

    dfs(c1, 0, rescue[c1], c2);

    int min_path = 9999999;
    int max_rescue = 0;
    int min_count = 1;
    for(int i = 0; i < result.size(); i++) {
        if (result[i].first < min_path){
            min_path = result[i].first;
            max_rescue = result[i].second;
            min_count = 1;
        }
        else if (result[i].first == min_path){
            min_count ++;
            if (result[i].second > max_rescue){
                max_rescue = result[i].second;
            } 
        }
    }
    cout<<min_count<<" "<<max_rescue<<endl;

    return 0;
}
