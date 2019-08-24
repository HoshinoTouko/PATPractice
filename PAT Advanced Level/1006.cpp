#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int get_seconds(int hour, int minute, int second){
    return 3600 * hour + 60 * minute + second;
}

int str_to_int(string s){
    stringstream a(s);
    int res = 0;
    a >> res;
    return res;
}

vector<int> split(string str, char* sep) {
    string temp;
    vector<int> result;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == *sep){
            result.push_back(str_to_int(temp));
            temp.clear();
            continue;
        }
        temp += str[i];
    }
    result.push_back(str_to_int(temp));
    return result;
}

int main(){
    int n;
    cin>>n;
    int unlock_time = get_seconds(23, 59, 59);
    string unlock_name = "";
    int lock_time = get_seconds(0, 0, 0);
    string lock_name = "";
    while(n--){
        string name, signin, signout;
        cin>>name>>signin>>signout;
        vector<int> signin_vec = split(signin, ":");
        vector<int> signout_vec = split(signout, ":");
        int signin_time = get_seconds(signin_vec[0], signin_vec[1], signin_vec[2]);
        int signout_time = get_seconds(signout_vec[0], signout_vec[1], signout_vec[2]);
        if (unlock_time > signin_time){
            unlock_time = signin_time;
            unlock_name = name;
        }
        if (lock_time < signout_time){
            lock_time = signout_time;
            lock_name = name;
        }
    } 
    cout<<unlock_name<<" "<<lock_name; 
    
    return 0;
}
