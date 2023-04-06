#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
       this->data=d;
       this->left=NULL;
       this->right=NULL;
    }
};
node* insertinbst(node* root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }else{
        if(data>root->data){
            root->right=insertinbst(root->right,data);
        }else{
            root->left=insertinbst(root->left,data);
        }
    }return root;
}
void takeinput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
         insertinbst(root,data);
         cin>>data;
    }
}
void levelordertraversal(node* root){
queue<node*>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    node* temp=q.front();
    q.pop();//2 contion ya to NULL ya fr element hn
    if(temp==NULL){//purana complete
        cout<<endl;
        if(!q.empty()){//qeue still has elemnet to last m NULL daldo
            q.push(NULL);
        }
    }else{
        cout<<temp->data<<" ";
        if(temp->left){//agr left ka right m hn to quee m daldena
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
}
int main(){
    node* root=NULL;
    cout<<"enter the bst to insert="<<endl;
    takeinput(root);
    cout<<"print level";
    levelordertraversal(root);

    return 0;
}