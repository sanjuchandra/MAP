#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

bool cmp(const pair<int , int> x , const pair<int , int> y){
    return x.second <= y.second;
}
void sort_map_using_vectors(unordered_map<int , int> m){
    vector<pair<int , int>> vect;
    for(auto x : m){
        vect.push_back({x.first , x.second});
    }
    sort(vect.begin() , vect.end() , cmp);
    for(auto x : vect){
       cout<<x.first<<" : "<<x.second<<" || ";
    }
    cout<<endl;
    return;
}

class compare_class{
    public:
    bool operator () (const pair<int , int> x , const pair<int , int > y){
        return x.second <= y.second;
    }
};

void sort_map_using_set(unordered_map<int , int> m){
    set<pair<int , int> , compare_class> s;
    for(auto x : m){
        s.insert({x.first , x.second});
    }
    for(auto x : s){
        cout<<x.first<<" : "<<x.second<<" || ";
    }
    cout<<endl; 
    return;
}


void sort_map_using_multiset(unordered_map<int , int > m){
    multiset<pair<int , int>> multi_set;
    for(auto x : m){
        multi_set.insert({x.second , x.first});
    }
    for(auto x : multi_set){
        cout<<x.second<<" : "<<x.first<<" || ";
    }
    cout<<endl;
    return;
}

void sort_map_using_multimap(unordered_map<int , int > m){
    multimap<int , int> multi_map;
    for(auto x : m){
        multi_map.insert({x.second , x.first});
    }
    for(auto x : multi_map){
        cout<<x.second<<" : "<<x.first<<" || ";
    }
    cout<<endl;
    return;
}

int main(){
    unordered_map<int , int> m = {
                    {1 , 4} , {2 , 6} , {6 , 2} , {3 , 5} , {4 , -7} , {7 , 2}
    };
    sort_map_using_vectors(m);
    sort_map_using_set(m);
    sort_map_using_multiset(m);
    sort_map_using_multimap(m);
    return 0;
}
