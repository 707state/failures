#include<algorithm>
#include<iostream>
using namespace std;
int inversion(int* head,int i,int n){

    int total=0;
    for(int j=i;j<n;j++){
        if(head[i]>head[j]){
            total++;
        }
    }
    return total+inversion(head,i+1,n);
}
int main(){
    printf("这是一个简单的逆序数求解器");
    printf("第一行输入一个数，表示序列长度；第二行输入每个序数，以空格隔开");
    printf("点击回车查看答案");
    int* sub=new int;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sub[i];
    }
    int total=inversion(sub,0,n);
    cout<<total;
}