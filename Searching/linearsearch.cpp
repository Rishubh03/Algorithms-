#include <bits/stdc++.h>
using namespace std;

void binary_search(int num, int arr[],int key){
    int i;
    for(i=0;i<num;i++){
        if(arr[i]==key){
        cout<<"Element Found at location "<<i+1;
        return;
        }
    }
    cout<<"Element Not found ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num,key;
    
    cin>>num;
    int arr[num];
    
    for(int i =0; i<num;i++){
        cin>>arr[i];
    }
    cin>>key;
    
    binary_search(num,arr,key);
    

    return 0;
}
