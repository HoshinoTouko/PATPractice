#include<iostream>
#include<vector>

using namespace std;

class Account {
    public:
        string name, password;
        bool changed;
};

Account replacePwd(Account acc) {
    bool changed = false;
    string a = acc.password;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == '1') {
            acc.password[i] = '@';
            changed = true;
        } else if (a[i] == '0') {
            acc.password[i] = '%';
            changed = true;
        } else if (a[i] == 'l') {
            acc.password[i] = 'L';
            changed = true;
        } else if (a[i] == 'O') {
            acc.password[i] = 'o';
            changed = true;
        }
    }
    acc.changed = changed;
    return acc;
}

int main() {
    int n, T;
    cin>>n;
    T = n;
    
    vector<Account> accounts;
    string name, password;
    while(T--) {
        cin>>name>>password;
        Account acc = {name, password, false};
        acc = replacePwd(acc);
        if(acc.changed) {
            accounts.push_back(acc);
        }
    }
    
    if(accounts.size()) {
        cout<<accounts.size()<<endl;
        for(int i = 0; i < accounts.size(); i++) {
            cout<<accounts[i].name<<" "<<accounts[i].password<<endl;
        }
    } else {
        if(n == 1) {
            cout<<"There is 1 account and no account is modified"<<endl;
        } else {
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
        }
    }
    
    return 0;
}
