#include<algorithm>
#include<iostream>
using namespace std;
int inversion(int* head,int i,int n){
    int total=0;
    if(i!=n-1){
    for(int j=i;j<n;j++){
        if(head[i]>head[j]){
            total++;
        }
    }
    return total+inversion(head,i+1,n);}
    else{
        return total;
    }
}
int main(){
    int* sub=new int;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sub[i];
    }
    int total=inversion(sub,0,n);
    cout<<total;
}
