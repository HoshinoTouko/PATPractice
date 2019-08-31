#include<iostream>
#include<map>
#include<vector>
#include<iomanip>

// Give up

map<int, double> gasStations;
vector<int> selectStations;

using namespace std;

int main() {
    int cmax, dist, davg, n;
    cin>>cmax>>dist>>davg>>n;
    
    int distPerAdd = cmax * davg;
    
    int stationDist;
    double price;
    while(n--) {
        cin>>price>>stationDist;
        gasStations[stationDist] = price;
    }
    if(!gasStations.count(0)) {
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }
    
    int cur = 0, left = 0;
    double price = 0;
    while(1) {
        int nearest = -1;
        int minS = -1, minP = 9999999;
        for(map<int, double>::iterator it = gasStations.begin(); it != gasStations.end(); it++) {
            if((*it).second <= gasStations[cur].second) {
                nearest = (*it).first;
                break;
            }
            if((*it).second < minP) {
                minP = (*it).second;
                minS = (*it).first;
            }
        }
        if(nearest != -1) {
            if(nearest > dist) {
                if (nearest + left < dist)
                    price += (dist - cur) * gasStations[cur].second;
                break;
            }
            price += (nearest - cur - left) * gasStations[cur].second;
            left = 0;
            cur = nearest;
            continue;
        } else if (minS != -1) {
            if(cur + distPerAdd > dist) {
                
            }
            left = distPerAdd - (minS - cur);
            price += distPerAdd * gasStations[cur].second;
            cur = minS;
            continue;
        }
    } 
    
    return 0;
}
