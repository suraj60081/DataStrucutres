#include<iostream>
#include<queue>
#define MIN_V -1
#define MAX_V 100
using namespace std;

struct bstNode
{
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode* newNode(int x)
{
    bstNode* node = new bstNode();
    node->data=x;
    node->left=node->right=NULL;
    return node;
}
bstNode* Insert(bstNode* root,int data)
{
    if(root==NULL)
    {
        root=newNode(data);
    }
    else if(data<root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
        root->right=Insert(root->right,data);

    return root;
}
bool Search(bstNode* root,int x)
{
    if(root==NULL) return false;
    else if(x==root->data) return true;
    else if(x<root->data) Search(root->left,x);
    else Search(root->right,x);
}
int findMin(bstNode* root)
{
    if(root==NULL) return -1;
    else if(root->left==NULL)
    {
        return root->data;
    }
    return findMin(root->left);
}
int findMax(bstNode* root)
{
    if(root==NULL) return -1;
    else if(root->right==NULL) return root->data;
    return findMax(root->right);
}
void Bfs(bstNode* root)
{
    if(root==NULL) return;
    queue <bstNode*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        bstNode* current=Q.front();
        cout<<current->data<<"\n";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }

}
void Dfs(bstNode* root)
{
        if(root==NULL) return;
        cout<<root->data<<"\n";
        Dfs(root->left);
        Dfs(root->right);

}
bool issubl(bstNode* root,int x)
{
    if(root==NULL) return true;
    if(root->data<=x &&issubl(root->left,x)&&issubl(root->right,x)) return true;
    else return false;
}
bool issubg(bstNode* root,int x)
{
    if(root=NULL) return true;
    if(root->data>=x&&issubg(root->left,x)&&issubg(root->right,x)) return true;
    else return false;
}
bool isbst(bstNode* root)
{
    if(root==NULL){
            cout<<"haan haan bsdk";
            return true;}
    if(issubl(root->left,root->data)&&issubg(root->right,root->data)&&isbst(root->left)&&isbst(root->right))
       {
           return true;
       }
    else return false;
}
bool isbt(bstNode* root,int maxv,int minv)
{
    if(root==NULL) return true;
    if(root->data>minv && root->data<maxv&&isbt(root->left,root->data,minv)&&isbt(root->right,minv,root->data)) return true;
    else return false;
}
int main()
{
    bstNode* root;
    root=NULL;
    root=Insert(root,4);
    root=Insert(root,7);
    root=Insert(root,0);
    root=Insert(root,3);
    Search(root,2);

    //cout<<findMin(root)<<"\n";
    //cout<<findMax(root)<<"\n";
    //Bfs(root);
      //Dfs(root);
      isbst(root);
      isbt(root,MAX_V,MIN_V);
}
