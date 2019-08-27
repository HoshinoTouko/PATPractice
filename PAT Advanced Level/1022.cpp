#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

vector<map<string, vector<int> > > books(5, map<string, vector<int> >());

vector<string> split(string a, char b) {
    vector<string> res;
    string tmp;
    for(int i = 0; i < a.size(); i++) {
        if (a[i] == b) {
            res.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += a[i];
    }
    res.push_back(tmp);
    return res;
}

int main() {
    int n, num;
    string title, author, keyword, publisher, year;
    vector<string> keywords;
    cin>>n;
    while(n--) {
        cin>>num;
        cin.ignore(); // Basically, we can use getchar() or cin.sync(), but PTA online OJ do not accept the cin.sync().

        getline(cin, title);
        if(!books[0].count(title)){
            books[0][title] = vector<int>();
        }
        books[0][title].push_back(num);

        getline(cin, author);
        if(!books[1].count(author)){
            books[1][author] = vector<int>();
        }
        books[1][author].push_back(num);

        getline(cin, keyword);
        keywords = split(keyword, ' ');
        for(int i = 0; i < keywords.size(); i++) {
            if(!books[2].count(keywords[i])){
                books[2][keyword] = vector<int>();
            }
            books[2][keywords[i]].push_back(num);
        }

        getline(cin, publisher);
        if(!books[3].count(publisher)){
            books[3][publisher] = vector<int>();
        }
        books[3][publisher].push_back(num);

        getline(cin, year);
        if(!books[4].count(year)){
            books[4][year] = vector<int>();
        }
        books[4][year].push_back(num);
    }
    
    int m;
    cin>>m;
    string query;
    cin.ignore();
    while(m--) {
        getline(cin, query);
        int op = query[0] - '1';
        string qu = query.substr(3, query.size() - 3);
        
        cout<<query<<endl;

        if (books[op].count(qu)){
           vector<int> res = books[op][qu];
           sort(res.begin(), res.end());
            for(int i = 0; i < res.size(); i++) {
                printf("%07d\n", res[i]);
            }
        } else {
            cout<<"Not Found"<<endl;
        }
    }
    
    
    return 0;
}
