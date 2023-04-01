Problem Statement
A string is called a copmplete string if every prefix of this string is also present in the array A.
Ninja is challenged to find the longest complete string in the array 'A'.
If there are multiple strings with the same length return the lexicographically smallest one and if no string exists,return "none"


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
6
n ni nin ninj ninja ninga
2
ab bc
Sample Output 1 :
ninja
None
Explanation Of Sample Input 1 :
For test case 1 we have, 

All the prefixes of “ninja” -> “n”, “ni”, “nin”, “ninj” and “ninja” are present in array ‘A’. So, “ninja” is a valid answer whereas for “ninga” , the prefix “ning” is not present in array ‘A’.

So we output “ninja”.

For test case 2 we have, 

The prefixes of “ab” are “a” and “ab”. “a” is not present in array ‘A’. So, “ab” is not a valid answer.

The prefixes of “bc” are “b” and “bc”. “b” is not present in array ‘A’. So, “ab” is not a valid answer.

Since none of the strings is a valid answer we output “None”.
Sample Input 2 :
2
5
g a ak szhkb hy 
4
kez vfj vfjq vfjqo 
Sample Output 2 :
ak
None






code :

#include <bits/stdc++.h> 


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
                if(cur->isContainsKey(word[i]-'a') && cur->child[word[i]-'a']->terminal)
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


string completeString(int n, vector<string> &a){
    // Write your code here.

    Triee triee;
    for(auto x:a)
    triee.insert(x);

    string ans="";
    for(auto x:a)
    {
        if(triee.search(x))
        {
            if(ans.length()<x.length())
            {
                ans=x;
            }
            else if(ans.length()==x.length())
            {
                ans = ans<x?ans:x;
            }
        }
    }
    if(ans=="")return "None";
    return ans;
}


TC : O(2*N*len(string))
SC: 26*26*26... (not to say)
