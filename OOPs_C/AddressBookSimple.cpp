// This is a simple address book using vectors data structures. This allows duplicate entries.
// to Prevent duplicate entries, map data structures should be used.

#include <iostream>
#include <vector>

using namespace std;


class Person {
    public:
    string name;
    string addr;
    string phone;
    Person(string sname ="",string saddr="",string sphone=""){
        name =sname;
        addr = saddr;
        phone = sphone;
    }
    void editname (string newname){
        name = newname;
    }
    void editaddr(string newaddr) {
        addr = newaddr;
    }
    void editphone(string newphone){
        phone = newphone;
    }
};
class AddressBook{
    public:
        vector<Person> AB;// use map instead, since entries should be unique
        string name;
        AddressBook(string AddBookname) {
            name = AddBookname;
        }
        void Newentry(string personname, string personadd, string phonenum){
            Person P = Person(personname,personadd,phonenum);
            AB.push_back(P);
        }
        void ShowAll(){
            cout <<" Printing contents of: "<<name<<endl;
            vector<Person> :: iterator itr;
            itr =AB.begin();
            while (itr!=AB.end()){
                cout <<"name: "<<itr->name<<" addr: "<<itr->addr<<" phone number: "<<itr->phone<<endl;
                ++itr;
            }
        }
        void searchentry(string sname){
            int size = AB.size();
            int i = 0;
            bool found = false;
            for (i = 0 ;i<size;i++){
                 
                if (AB[i].name == sname) {
                     cout <<"name: "<<AB[i].name<<" addr: "<<AB[i].addr<<" phone number: "<<AB[i].phone<<endl;
                      break;
                     }
                
                }
            }
           
            
        }
        
};
int main() {
    
    AddressBook AB = AddressBook("MyAddressBook");
    AB.Newentry("Nikhil", "2818 Ellendale Pl","2134567");
    AB.Newentry("Abhinav", "2818 Ellendale Pl","56789900");
    AB.Newentry("Abhinav", "2816 Ellendale Pl","5653");
    
   // AB.ShowAll();
    AB.searchentry("Abhinav");
    return 0;
}
