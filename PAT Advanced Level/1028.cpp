#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Stu {
    public:
        int id;
        string name;
        int grade;
        
        string getID() {
            char a[8];
            sprintf(a, "%06d", this->id);
            string res = a;
            return res;
        }
};

vector<Stu> stus;

bool compID(Stu a, Stu b) {
    return a.id < b.id;
}

bool compName(Stu a, Stu b) {
    map<string, int> t;
    t[a.name] = 0;
    t[b.name] = 0;
    return (*t.begin()).first == a.name;
}

bool compGrade(Stu a, Stu b) {
    return (a.grade < b.grade) or ((a.grade == b.grade) and a.id < b.id);
}

int main() {
    int n, op;
    cin>>n>>op;
    
    int id, grade;
    string name;
    while(n--) {
        cin>>id>>name>>grade;
        Stu stu = {id, name, grade};
        stus.push_back(stu);
    }
    
    switch (op) {
        case 1:
            sort(stus.begin(), stus.end(), compID);
            break;
        case 2:
            sort(stus.begin(), stus.end(), compName);
            break;
        case 3:
            sort(stus.begin(), stus.end(), compGrade);
            break;
    }
    
    for(vector<Stu>::iterator it = stus.begin(); it != stus.end(); it++) {
        cout<<(*it).getID()<<" "<<(*it).name<<" "<<(*it).grade<<endl;
    }
    
    return 0;
}
