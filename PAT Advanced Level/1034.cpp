#include<iostream>
#include<map>
#include<vector>

// Testpoint 2 5 WA

using namespace std;

class Person {
    public:
        int time;
        int tag;
};

map<string, Person> persons;
map<int, string> tagGangs;
map<int, int> tagCount, tagUsage;

void mergeTag(int a, int b) {
    for(map<string, Person>::iterator it = persons.begin(); it != persons.end(); it++) {
        if ((*it).second.tag == b) {
            persons[(*it).first].tag = a;
        }
    }
}

int main() {
    int n, threshold;
    cin>>n>>threshold;
    
    string a, b;
    int usage;
    
    int tagNum = 0; 
    while(n--) {
        cin>>a>>b>>usage;
        if(persons.count(a) and !persons.count(b)) {
            Person p = {0, persons[a].tag};
            persons[b] = p;
        } else if (!persons.count(a) and persons.count(b)) {
            Person p = {0, persons[b].tag};
            persons[a] = p;
        } else if (persons.count(a) and persons.count(b)) {
            if (persons[a].tag != persons[b].tag)
                mergeTag(persons[a].tag, persons[b].tag);
        } else {
            Person p1 = {0, tagNum};
            Person p2 = {0, tagNum};
            persons[a] = p1;
            persons[b] = p2;
            tagNum++;
        }
//        cout<<a<<" "<<b<<" "<<usage<<endl;
        persons[a].time += usage;
        persons[b].time += usage;
    }
    
    for(map<string, Person>::iterator it = persons.begin(); it != persons.end(); it++) {
//        cout<<(*it).first<<" "<<(*it).second.tag<<endl;
        Person p = (*it).second;
        tagCount[p.tag]++;
        tagUsage[p.tag] += p.time;

        if(!tagGangs.count((*it).second.tag)){
            tagGangs[(*it).second.tag] = (*it).first;
            tagCount[(*it).second.tag] = 1;
            tagUsage[(*it).second.tag] = p.time;
            continue;
        }
        
        if(p.time > persons[tagGangs[(*it).second.tag]].time) {
            tagGangs[(*it).second.tag] = (*it).first;
        }
    }
    
    int sz = tagGangs.size();
    // Throw no more than 2
    for(map<int, string>::iterator it = tagGangs.begin(); it != tagGangs.end(); it++) {
//        cout<<(*it).first<<" "<<tagUsage[(*it).first]<<endl;
        if(tagCount[(*it).first] <= 2 or tagUsage[(*it).first] <= 2 * threshold) {
            sz--;
        }
    }
    
    cout<<sz<<endl;
    for(map<int, string>::iterator it = tagGangs.begin(); it != tagGangs.end(); it++) {
        if(tagCount[(*it).first] > 2 and tagUsage[(*it).first] > 2 * threshold) {
            cout<<(*it).second<<" "<<tagCount[(*it).first]<<endl;
        }
    }
    
    return 0;
}
