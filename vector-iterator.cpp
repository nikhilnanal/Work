#include <iostream>
#include <vector>

using namespace std;

void printvector(vector<int> &v) {
    vector <int> :: iterator itr;
    for (itr = v.begin();itr!=v.end();++itr){
        cout <<(*itr)<<" "<< endl;
    }
}
void printcall (vector<int> &v){
    printvector(v);
}
int main()
{
  vector<int> v;
  v.push_back(45);
  v.push_back(3);
  v.push_back(7);
  v.push_back(3);
  v.push_back(9);
  
  printcall(v);

    return 0;
}
