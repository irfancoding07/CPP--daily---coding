 #include<map>
 #include<unordered_map>
#include <iostream>
using namespace std;

int main() {
    
    //creation
    unordered_map<string, int> m;
    
    //insertion
     //1
     pair<string,int> p = make_pair("irfan" , 3);
     m.insert(p);
     
     //2
     pair<string, int> pair2("love", 2);
     m.insert(pair2);
     
     //3
     m["mera"] = 1;
     
     //what will happen
     m["mera"] = 2;
     
     //search
     cout<< m["mera"] << endl;
     cout << m.at("irfan") << endl;
     
     cout << m["unknownkey"] << endl;
     cout << m.at("unknownkey")<< endl;
     
     //size
     cout << "size is  " <<  m.size() << endl;
     
     //to check presence
      cout << m.count("king") << endl;
      cout << m.count("love") << endl;
      
      //erase
      m.erase("love");
      cout << "size is " << m.size() << endl;
      
      //iterator
     unordered_map<string, int> :: iterator it = m.begin();
      
      while (it != m.end()){
          cout << it->first << " " << it->second << endl;
          it++;
      }
     
    return 0;
}
