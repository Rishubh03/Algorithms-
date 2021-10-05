// Solution 1
#include <iostream>

using namespace std;

int main()
{ 
    int num;
    cin>>num;
    int count=0;
    while(num!=0){
        num = num/10;
        count++;
    }
    
    cout<<count;

    return 0;
}

// Solution 2

#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    int num;
    cin>>num;
    int count=log10(num) + 1;
    
    
    cout<<count;

    return 0;
}
