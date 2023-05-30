#include<iostream>
using namespace std;
int d=0;

void algorithm(long long int* a, long long int n, long long int k, long long int b, long long int s, long long int cb){
d=0;
    for(long long int i=0; i<k; i++){    
    a[0] = cb+i;
    long long int rs = s - a[0];
    if(rs < 0) {cout<<-1<<endl; return;}

    if(k == 1){
            if(b == s){
            long long int space = 0;
        for(long long int j=n-1; j>=0; j--){
        cout<<a[j];
        space++;
        if(space != n) cout<<" ";
    }
    if(space == n){
    cout<<endl;
    d++;
    return;
    }
    } else {cout<<-1<<endl; return;}

    } else {
        
        long long int q = rs/(k-1);
        long long int r = rs%(k-1);

        if(q > n) {d--; cout<<d<<endl; return;}

        if(q == n-1 && r != 0) { if( (a[0] + r)/k == b ) { i=i+r-1; continue; } else {d--; cout<<-1<<endl; return;} }

        if(q == n) if(r==0 && i==0) { i=i+k-2; continue; } else { d--; cout<<d<<endl; return; }

        if(q+2 <= n) a[n-1] = r;

        for(long long int j=0; j<q; j++)
        a[j+1] = k-1;

        long long int space = 0;
        for(long long int j=n-1; j>=0; j--){
        cout<<a[j];
        space++;
        if(space != n) cout<<" ";
    }
    if(space == n){
    cout<<endl;
    d++;
    return;
    }
    }

}
if(d==0) cout<<-1<<endl;
}
int main(){
int t;
cin>>t;
long long int n[t],k[t],b[t],s[t];
for(int i=0; i<t; i++){
cin>>n[i]>>k[i]>>b[i]>>s[i];
}

for(int i=0; i<t; i++){

        long long int* a = new long long int[n[i]];
    for (long long int j = 0; j < n[i]; j++)
        a[j] = 0;

    long long int cb = k[i]*b[i];

    if(s[i] < k[i]*b[i] || (s[i] - n[i]*k[i]) >= k[i]*b[i] || b[i] > s[i]){
        cout<<-1<<endl;
    }
    else{
    algorithm(a,n[i],k[i],b[i],s[i],cb);
    }
    delete[] a;
}
return 0;
}