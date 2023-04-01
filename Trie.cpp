
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct Node{
    Node * child[26];
    bool terminal;
    
    Node()
    {
        for(int i=0;i<26;i++)child[i]=NULL;
        terminal=false;
    }
    
    bool isContainsKey(char c)
    {
        return child[c]!=NULL;
    }
};

class Triee{
    private:
        Node * root;
    public:
    
        Triee()
        {
            root=new Node();
        }
        void insert(string word)
        {
            Node * cur=root;
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur=cur->child[word[i]-'a'];
                }
                else{
                    Node* newnode = new Node();
                    cur->child[word[i]-'a'] = newnode;
                    cur=newnode;
                }
            }
            cur->terminal=true;

        }
        
        bool search(string word)
        {
            Node * cur=root;
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur=cur->child[word[i]-'a'];
                }
                else{
                   return false;
                }
            }
            
            return cur->terminal;
        }
        
        bool isprefix(string word)
        {
            Node * cur=root;
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur=cur->child[word[i]-'a'];
                }
                else{
                   return false;
                }
            }
            
            return true;
        }
        
        bool startwith(string word)
        {
            Node * cur=root;
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur=cur->child[word[i]-'a'];
                }
                else{
                   return false;
                }
            }
            
            return true;
        }
};



int main()
{
    Triee triee;
    string arr[5]={"apple","mango","appe","banana","mongini"};
    for(int i=0;i<5;i++)
    triee.insert(arr[i]);
    
    cout<<triee.search("appe");
    cout<<triee.isprefix("app");
    cout<<triee.startwith("appel");
    cout<<triee.search("manto");
    cout<<triee.isprefix("mango");
    cout<<triee.startwith("mon");
    

    return 0;
}
