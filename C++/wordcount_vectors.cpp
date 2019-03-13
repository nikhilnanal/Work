// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  vector <string> words;
  string input;
  int i;
   cout <<"Enter a list of words, possibly non distinct"<<endl;
   
   // until EOF
   while (cin >> input){
       words.push_back(input);
   }
   
   sort(words.begin(),words.end());
   int length =words.size();
   int k=0,l=0;;
   int wordcount[length]={1};
   for ( i=0;i<length;i++){
       k=i;
       while (words[i]==words[k]){
           wordcount[l]++;
           k++;
       }
       i=k;
       l++;
   }
   
  for (i=0;i<l;i++){
      cout <<wordcount[i]<<" ";
  }
}
