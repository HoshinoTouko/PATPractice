#include<iostream>

using namespace std;

class Stu{
    public:
        string name, ID;
        int grade;
};

int main() {
    int n;
    cin>>n;
    
    string name, gender, ID;
    int grade;
    Stu maxF = {"DEF", "DEF", 0}, minM = {"DEF", "DEF", 9999};
    while(n--) {
        cin>>name>>gender>>ID>>grade;
        if(gender == "M") {
            if (grade < minM.grade) {
                Stu stu = {name, ID, grade};
                minM = stu;
            }
        } else {
            if (grade > maxF.grade) {
                Stu stu = {name, ID, grade};
                maxF = stu;
            }
        }
    }
    bool na = false;
    if(maxF.name != "DEF") {
        cout<<maxF.name<<" "<<maxF.ID<<endl;
    } else {
        cout<<"Absent"<<endl;
        na = true;
    }
    if(minM.name != "DEF") {
        cout<<minM.name<<" "<<minM.ID<<endl;
    } else {
        cout<<"Absent"<<endl;
        na = true;
    }
    if(na) {
        cout<<"NA"<<endl;
    } else {
        cout<<maxF.grade - minM.grade<<endl; 
    }
    
    return 0;
}
