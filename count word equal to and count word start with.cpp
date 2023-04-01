

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct Node{
    Node * child[26];
    int endwith;
    int countprefix;
    
    Node()
    {
        for(int i=0;i<26;i++)child[i]=NULL;
        endwith=0;
        countprefix=0;
    }
    
    bool isContainsKey(char c)
    {
        return child[c]!=NULL;
    }
    
    void put(char c,Node* node)
    {
        child[c]=node;
    }
    
    Node* get(char c)
    {
        return child[c];
    }
    
    void increasecount()
    {
        endwith++;
    }
    
    void increaseprefix()
    {
        countprefix++;
    }
    
    void decreasecount()
    {
        endwith--;
    }
    
    void decreaseprefix()
    {
        countprefix--;
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
                if(!cur->isContainsKey(word[i]-'a'))
                {
                    cur->put(word[i]-'a',new Node());
                }
                cur = cur->get(word[i]-'a');
                cur->increaseprefix();
            }
            cur->increasecount();
        }
        
        int countwordequalto(string word)
        {
            Node * cur=root;
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur=cur->get(word[i]-'a');
                }
                else{
                   return 0;
                }
            }
            
            return cur->endwith;
        }
        
        int countwordstartwith(string word)
        {
            Node * cur=root;
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur=cur->get(word[i]-'a');
                }
                else{
                   return 0;
                }
            }
            
            return cur->countprefix;
        }
        
        void erase(string word)
        {
            Node * cur=root;
            if(countwordequalto(word)==0)return;
            
            for(int i=0;i<word.size();i++)
            {
                if(cur->isContainsKey(word[i]-'a'))
                {
                    cur->decreaseprefix();
                    cur=cur->get(word[i]-'a');
                }
                else{
                   return;
                }
            }
            cur->decreasecount();
            return;
        }
};



int main()
{
    Triee triee;
    string arr[5]={"apple","apple","appe","appe","mongini"};
    for(int i=0;i<5;i++)
    triee.insert(arr[i]);
    
    cout<<triee.countwordequalto("apple");
    cout<<triee.countwordstartwith("app");
    cout<<triee.countwordstartwith("at");
    cout<<triee.countwordequalto("mat");
    cout<<triee.countwordequalto("app");
    triee.erase("apple");
    cout<<triee.countwordequalto("apple");
    triee.erase("apple");
    cout<<triee.countwordequalto("apple");
    

    return 0;
}
