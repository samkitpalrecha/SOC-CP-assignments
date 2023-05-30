#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a[t];
    for(int i=0; i<t; i++)
    cin>>a[i];
    long long int length[t];
    for(int i=0; i<t; i++){
        long long int n = a[i];
        long long int b = (n-2)*(n-1);
        length[i] = 1*3 + (n-1)*1 + n*4;
        length[i] = length[i] + b - 2;
    }
for(int i=0; i<t; i++)
cout<<length[i]<<endl;
}