#include<bits/stdc++.h>
using namespace std;
void build(vector<int> &fenwick, vector<int> &vec){
    for(int i = 1; i < vec.size(); i++){
        int index = i;
        while(index < fenwick.size()){
            fenwick[index] += vec[i];
            index += index&(-index);
        }
    }
}
int prefixsum(int index, vector<int> &fenwick){
    if(index <= 0 || index >= fenwick.size()) return -1;
    int sum = 0;
    while(index > 0)
    {
        sum+=fenwick[index];
        index-=index&(-index);
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    vec[0] = 0;
    for(int i = 1; i < n; i++) cin >> vec[i];
    vector<int> fenwick(n,0);
    build(fenwick,vec);
    cout << "Fenwick Tree: ";
    for(int i = 1; i < n; i++) cout << fenwick[i] << " ";
    bool ask = 1;
    while(ask)
    {
        int k;
        cout << "Ask prefix for k elements: " << endl;
        cin >> k;
        cout << "Prefix sum for " << k << " elements: " << prefixsum(k,fenwick) << endl;
        cout << "Enter your choice:";
        cin >> ask;
    }
}