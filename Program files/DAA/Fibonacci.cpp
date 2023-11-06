#include<iostream>
#include<utility>
#include<vector>
using namespace std;

vector<int> FibonaciIterative(int n){
    if(n<=0) return vector<int> ();
    else if(n==1) return vector<int> {0};
    else if(n==2) return vector<int> {0,1};
    
    vector<int> fibonaci={0,1};
    for(int i=2;i<n;i++){
        int nextNum=fibonaci[i-1]+fibonaci[i-2];
        fibonaci.push_back(nextNum);
    }
    return fibonaci;

    // int next=0;
    // cout<<prev<<" "<<curr<<" ";
    // n-=2;
    // while (n--)
    // {
    //     next=prev+curr;
    //     cout<<next<<" ";
    //     prev=curr;
    //     curr=next;
    // }
}

//Without step count
int fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 1;
    else return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

//With step count
pair<int,int> FibonaciRecurssive_stepCnt(int n){
    if(n==0) return {0,1};
    else if(n==1) return {1,1};
    else {
        pair<int,int> fib1=FibonaciRecurssive_stepCnt(n-1);
        pair<int,int> fib2=FibonaciRecurssive_stepCnt(n-2);
        int fibNum=fib1.first+fib2.first;
        int steps=fib1.second+fib2.second;
        return {fibNum,steps};
    }
} 
int main(){
    // FibonaciIterative(20);
    int n;
    cout<<"Enter num = ";
    cin>>n;
    
    cout<<"Iterative : ";
    vector<int> result=FibonaciIterative(n);
    for(int number:result){
        cout<<number<<" ";
    }
    cout<<endl;
    cout<<"Recurssive : ";
    for(int i=0;i<n;i++){
        cout<<fibonacciRecursive(i)<<" ";
    }
}