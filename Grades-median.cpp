/* This program is 
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
  string name;
  double midterm,final;
  double x;
  vector <double> hwgrades;
  unsigned int size;
  double median;
  
  cout << "Please Enter your Name:"<<endl;
  getline(cin,name);
 
  cout << "Enter your mid term and final grades"<<endl;
  
  if (!(cin>>midterm))
    {cout<<"wrong midterm value, try again"<<endl;exit(1);}
  if (!(cin>>final))
    {cout<<"wrong final score value, try again"<<endl;exit(1);}
  
 
  cout << "Enter all your homework grades followed by EOF after the last hw grade"<<endl;
  while (cin >> x){
     hwgrades.push_back(x);
  }
 
  size = hwgrades.size();
 
  if (size == 0){
      cout << "No hw grades passed. exiting..."<<endl;
      exit(1);
  }
  // sort the hwgrades before calculating median
  sort (hwgrades.begin(),hwgrades.end());
  int mid =size/2;
  // median value depends on the number of elements --> is even or odd
  median = size % 2 == 0 ? (hwgrades[mid] + hwgrades[mid-1]) / 2 : hwgrades[mid];  
 
  streamsize prec = cout.precision();
  cout << "Your final grade is: " << 0.2*midterm +0.4*final+0.4*median <<setprecision(prec)<<endl;
 
  return 0;
}
 
 
     
 
