#include<iostream>
#include<cmath>
using namespace std;
long long unsigned int checkallcases(long long int* a, int n){
   long long unsigned int sumofsqrs = 0;
   for(int i=0; i<n; i++){
   sumofsqrs += pow(a[i] , 2);    //sum of squares of original elements
   }
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         long long int x = a[i] , y = a[j];
         if(j != i){
            a[i] = x & y;
            a[j] = x | y;
         }
         long long unsigned int sos;
         sos = sumofsqrs - pow(x,2) - pow(y,2) + pow(a[i] , 2) + pow(a[j] , 2); //sum of squares of new elements
         if(sos > sumofsqrs) sumofsqrs = sos;
         else{ a[i] = x; a[j] = y; }
      }
   }
   return sumofsqrs;
}
int main(){
   int n;
   cin>>n;
   long long int nums[n];
    for(int i=0; i<n; i++)
        cin>>nums[i];
    for(int i=0; i<n-1; i++){    //arranging in descending order
        for(int j=0; j<n-i-1; j++){
            if(nums[j] < nums[j + 1])
               swap(nums[j] , nums[j + 1]);
        }
      }
   long long unsigned int sumofsquares = checkallcases(nums , n);
   cout<<sumofsquares;
   return 0;
}