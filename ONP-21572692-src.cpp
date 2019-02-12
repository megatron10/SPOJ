#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main() 
{
  int i,t,l;char arr[401]; cin>>t;
  while(t--)
  {
    stack <char> op;
    cin>>arr;
    l=strlen(arr);
    for(i=0;i<l;i++)
    {
      if(arr[i]==')'){ cout<<op.top(); op.pop(); }
      else if(arr[i]=='+'||arr[i]=='-'||arr[i]=='/'||arr[i]=='*'||arr[i]=='^')op.push(arr[i]);
      else if(arr[i]=='(');
      else cout<<arr[i];
    }
    cout<<"\n";
  }
  
  return 0;
}