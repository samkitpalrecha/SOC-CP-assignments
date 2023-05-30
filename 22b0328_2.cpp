#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long unsigned> a(n + 1);
    a[1] = 0;
    for (long long k = 2; k <= n; k++){
    a[k] = (k * k * (k * k - 1) / 2) - (4 * (k - 1) * (k - 2));
    }
    for(int i=1; i<=n; i++){
    cout<<a[i]<<endl;
    }
}
