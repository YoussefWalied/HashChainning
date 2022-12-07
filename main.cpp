#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class table{
    struct node{
        string data;
        node *next=nullptr;
        node(){
            data="*";
        }
        node(string x){
            data=x;
        }
    };
    int size;
    node *list;
    int h(int key){
        return (key +(13-(key%13)))%this->size;
    }
    int getAscii(string x){
        int ascii=0;
        for(auto ch:x){
            ascii+= (int)ch;
        }
        return ascii;
    }
public:
    table(int size=0){
        this->size=size;
        list= new node[size];
    }
    void add(string x){
        int index=h(getAscii(x));
        node *newNode=new node(x);
        newNode->next=list[index].next;
        list[index].next=newNode;
    }
    void print(){
        node* itr;
        for(int i=0;i<size;i++){
            itr=list[i].next;
            cout<<i;
            while(itr!=nullptr){
                cout<<" --> "<<itr->data;
                itr=itr->next;
            }
            cout<<endl;
        }
    }
    void search(string key){
        int index=h(getAscii(key));
        node *itr=list[index].next;
        cout<<index;
        while(itr!=nullptr){
            cout<<" --> "<<itr->data;
            itr=itr->next;
        }
        cout<<endl;
    }
};
int main() {
    table HashTable(17);
    HashTable.add("car");
    HashTable.add("acr");
    HashTable.add("cra");
    HashTable.add("arc");
    HashTable.add("zeyad");
    HashTable.add("sayed");
    HashTable.add("abdelrahman");
    HashTable.add("youssef");
    HashTable.print();
    cout<<"------------------\n";
    HashTable.search("cra");
    return 0;
}
