#include<iostream>
#include<string>
# define d 256 //No of types of characters in my string.
//Basicallly the base of the hash function (Binary,Decimal);
# define q 101 //A prime number to take modulus
//To avoid collisions we don't take it pow(10,9)+7;
using namespace std;
void Rabin_Karp(string str, string pat){
  int n=str.size();
  int m=pat.size();
  int t=0; //Hash value of text
  int p=0; //Hash value of pattern
  int h=1;
  int j;
  for(int i=0;i<m-1;i++){
    h=(h*d)%q;
  }
  //Calculate hash value of pattern and first window of text
  for(int i=0;i<m;i++){
    t=(t*d+str[i])%q;
    p=(p*d+pat[i])%q;
  }
  //Slide the pattern over text one bt once
  for(int i=0;i<=n-m;i++){
    //In case hash key matches then match character by character
    if(p==t){
      for(j=0;j<m;j++){
        if(str[i+j]!=pat[j]) break;
      }
        if(j==m)
          cout<<"Pattern found at index" <<i<<endl;
    }
    if(i<n-m){
      t=(d*(t-str[i]*h)+str[i+m])%q;
      if(t<0) t=t+q;
    }
  }
}
int main(){
  string str; cin>>str;
  string pat; cin>>pat;
  Rabin_Karp(str,pat);
}
