#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

string ltrim(const string &s) {
    return regex_replace(s, regex("^\\s+"), string(""));
}

string rtrim(const string &s) {
    return regex_replace(s, regex("\\s+$"), string(""));
}

string trim(const string &s) {
    return ltrim(rtrim(s));
}

class Node {
    private:
    Node* front = NULL;
    Node* back = NULL;
    string data;
    public:
    Node(string d){
        data = d;
    }
    Node(string d, Node& a, Node& b){
        data = d;
        back = &a;
        front =&b;
    }
    
    Node& set_data(long d){
        data = d;
        return *this;
    }
    
    Node& set_back(Node& a){
        back = &a;
        return *this;
    }
    
    Node& set_front(Node& b){
        front = &b;
        return *this;
    }
    
    void erase_back(){
        back = NULL;
        return ;
    }
    
    void erase_front(){
        front = NULL;
        return ;
    }
    
    string get_data(){
        return data;
    }
    
    Node* get_back(){
        return back;
    }
    
    Node* get_front(){
        return front;
    }
    
};
    
class Queue{
   private:
   vector<long> data;
   Node* head = NULL;
   Node* end = NULL;
   public:
   void enquete(Node& node){
       if(head == NULL){
           head = &node;
           end = &node;
       }else{
           (*end).set_back(node);
           node.set_front(*end);
           end = &node;           
       }
   }
   
    bool dequeue(){
        if (head == NULL) {
            return false;
        }else {
            Node* temp = head;
            head =  (*temp).get_back();
            if(head == NULL){
                head = NULL;
                end = NULL;
            }else{
                (*head).erase_front();
            }
            
            //cout << "Address head [" << head << " | " << end << "] temp [" << temp << "]" <<  endl;
            
            delete (temp);  
            
            return true;
        }
   }
   
   void print_front(){
       cout << (head == NULL ? "" : ((*head).get_data())) << endl;
   }

   
   string front(){
       return (head == NULL ? "\n" : ((*head).get_data()) + "\n");
   }

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int queries;
    cin >> queries;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    //cout << "queries is " << queries << endl;
    
    Queue q;
    string query, x, type;
    int query_space;
    
    string out ("");
    
    while (queries > 0) {
        getline(cin, query);
        
        if (!query.empty()) {
            //query =  trim(query);
            query_space = query.find(" ");
            
            if(query_space == string::npos){
                type = query;
                //cout << "Splitor [" << type << "]" << endl;
            }else {
                type = query.substr(0, query_space);
                x = query.substr(query_space + 1);
                //cout << "Splitor [" << type << ", " << x << "]" << endl;
            }
            
            if(type == "3"){
                out += q.front();
            }else if(type == "2"){
                q.dequeue();
            }else if (type == "1") {
                Node* node = new Node(x);
                q.enquete(*node);
            }
            //cout << "Querie " << query << (query.empty() ? " [is empty]" : " [is not empty]") << endl;
            queries--;
            
            
        }
    }
    
    cout << out << endl;

    return 0;
}
