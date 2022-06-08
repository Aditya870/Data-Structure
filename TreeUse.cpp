#include<iostream>
#include<bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

// TreeNode<int> * takeInput(int i){
//   int rootData;
//   cout<<"Enter ith child "<<endl;
//   cin>>rootData;
//   TreeNode<int> * root =new TreeNode<int>(rootData);
  

//   for(int i=0;i<n;i++){
//     TreeNode<int> * child=takeInput();
//     root->children.push_back(child);
//   }
//   return root;

// }

TreeNode<int> * takeInputLevelWise(){
  int rootData;
  cout<<"Enter root data"<<endl;
  cin>>rootData;
  TreeNode<int> * root =new TreeNode<int>(rootData);
  queue<TreeNode<int> *> q;
  q.push(root);
  
 
 while(!q.empty())
 {
        TreeNode<int> * node=q.front();
        q.pop();
        int n;
        cout<<"Enter number of children of "<<node->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
          int Data;
          cout<<"Enter the "<<i<<" th child of "<<node->data<<endl;
          cin>>Data;
          TreeNode<int> * child=new TreeNode<int>(Data);
          node->children.push_back(child);
          q.push(child);
        }
        
  
 }
  
  
  return root;

}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)return root;
    
    TreeNode<int>* max=root;
    
    for(int i=0;i<root->children.size();i++)
    {
        if(max->data < root->children[i]->data)
        {
            max=root->children[i];
        }
        TreeNode<int>* childMax = maxDataNode(root->children[i]);
        if(childMax->data > max->data)
            max=childMax;
    }
    
    return max;
    
    
    
}


void printAtLevelK(TreeNode<int>* root,int k)
{
  if(root==NULL)return;

  if(k==0)
  {
    cout<<root->data<<" ";
  }
  else{
    for(int i=0;i<root->children.size();i++)
    {
      printAtLevelK(root->children[i],k-1); 
    }
  }
}

void preOrder(TreeNode<int>* root)
{
  if(root==NULL)return;

    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
      preOrder(root->children[i]); 
    }
}

void postOrder(TreeNode<int>* root)
{
  if(root==NULL)return;

    
    for(int i=0;i<root->children.size();i++)
    {
      postOrder(root->children[i]); 
    }
    cout<<root->data<<" ";
}

int countNodes(TreeNode<int>* root){

   int count=1;


   for(int i=0;i<root->children.size();i++)
   {
     count+=countNodes(root->children[i]);
   }

   return count;
}

int noOfLeafNodes(TreeNode<int>* root)
{
  if(root==NULL)return 0;
  
   if(root->children.size()==0) return 1;
  
   int count=0;
   for(int i=0;i<root->children.size();i++)
   {
     count+=noOfLeafNodes(root->children[i]);
   }

   return count;

}

void deleteTree(TreeNode<int>* root)
{
  if(root==NULL)return;
  
  for(int i=0;i<root->children.size();i++)
  {
    deleteTree(root->children[i]);
  }
  delete root;
}


void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int> *> q;
    q.push(root);
  
 
 while(!q.empty())
 {
        TreeNode<int> * node=q.front();
        q.pop();
        cout<<node->data<<" : ";
        for(int i=0;i<node->children.size();i++)
        {
          cout<<node->children[i]->data<<" -> ";
          q.push(node->children[i]);
        }
        cout<<endl;
  
 }
    
}

void printTree(TreeNode<int>* root)
{
  
  cout<<root->data<<" : ";
  int i=0;
  while(i<root->children.size())
  {
      cout<<root->children[i]->data<<"  ";
      i++;
  } 
  cout<<endl;
   i=0;
  while(i<root->children.size())
  {
      printTree(root->children[i]);
      i++;
  } 
}


        //       1
        //     / \ \
        //    2   3 8
        //   / \ / \
        //  4  5 6  7


int main()
{
  // TreeNode<int> * root = new TreeNode<int>(1);
  // TreeNode<int> * child1 = new TreeNode<int>(2);
  // TreeNode<int> * child2 = new TreeNode<int>(3);
  // TreeNode<int> * child3 = new TreeNode<int>(4);
  // TreeNode<int> * child4 = new TreeNode<int>(5);
  // TreeNode<int> * child5 = new TreeNode<int>(6);
  // TreeNode<int> * child6 = new TreeNode<int>(7);
  

  // root->children.push_back(child1);
  // root->children.push_back(child2);
  // root->children[0]->children.push_back(child3);
  // root->children[0]->children.push_back(child4);
  // root->children[1]->children.push_back(child5);
  // root->children[1]->children.push_back(child6);
  TreeNode<int> * root = takeInputLevelWise();
  // printTree(root);
 // cout<<endl<<endl<<endl;
  printLevelWise(root);
  cout<< "\n No. of nodes is : "<<countNodes(root)<<endl<<endl;

  printAtLevelK(root,1);

  cout<< "\n No. of Leaf nodes is : "<<noOfLeafNodes(root)<<endl<<endl;

  //preOrder(root);
  postOrder(root);

  //to delete the tree destructor will be called
  delete root;
  
}