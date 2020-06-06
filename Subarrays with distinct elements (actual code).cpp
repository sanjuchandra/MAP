#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int Subarrays_with_distinct_elements(int *arr , int n){
    int ans = 0;
    unordered_map<int , int> m;
    int j = 0;
    for(int i = 0 ; i < n ; i++){
        while(j < n and m.count(arr[j]) == 0){
            m.insert({arr[j] , 1});
            j++;
        }
        ans += ((j-1-i+1)*(j-1-i+2))/2;
        m.erase(arr[i]);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    int arr[1000000] = {0};
    while(t--){
        int n;
        cin>>n;
        for(int i = 0 ;i < n ; i++){
            cin>>arr[i];
        }
        cout<<Subarrays_with_distinct_elements(arr , n)<<endl;
    } 
    return 0;
}
