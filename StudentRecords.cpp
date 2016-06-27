# include<iostream>
  2 # include<vector>
  3 #include<string>
  4 
  5 
  6 using namespace std;
  7 
  8 struct studentrec {
  9  string name;
 10  double midterm,finals;
 11  vector<double> homework;
 12 };
 13  
 14  
 15 istream& read_studentrec(studentrec& student){
 16   cout <<"Enter the name of the student and his marks"<<endl;
 17   cin>>student.name>>student.midterm >> student.finals;
 18   cin.ignore();
 19   double x;
 20   while ((cin >> x) && (x!=9999)){
 21    student.homework.push_back(x);
 22 }
 23  
 24  return cin;
 25 }
 26  
 27 bool comp(const studentrec& s1, const studentrec& s2){
 28 return s2.name>s1.name; // sort in descending order
 29 }
 30  
 31 int main(){
 32  
 33 studentrec record;
 34 vector<studentrec> vec;
 35 string instatus;
 36  
 37 while ((read_studentrec(record)) && (instatus!="quit")){
 38    vec.push_back(record);
 39    cin.ignore();
 40    cin >>instatus;
 41    cout << instatus;
 42 }
 43  
 44 //vector<studentrec> :: iterator i;
 45 //for (i=vec.begin();i!=vec.end();i++){
 46  
 47 //cout<<(*i).name<<endl;
 48 //cout<<.midterm << endl;
 49 //cout<<record.finals<<endl;
 50  
                                                                                                                                                                       1,1           Top
