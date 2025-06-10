#include<iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

TreeNode* buildTree(const string& input){
    if(input.empty() || input[0]== -1) return nullptr ;
    
     istringstream iss(input);
    string val;
    iss>>val;
    
    TreeNode* root = new TreeNode(stoi(val));
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        
        if(!(iss>>val)) break;
        if(val != "-1"){
            curr->left = new TreeNode(stoi(val));
            q.push(curr->left);
        }
        
        if(!(iss>>val)) break;
        if(val != "-1"){
            curr->right = new TreeNode(stoi(val));
            q.push(curr->right);
        }
    }
    return root;
}


void preorder(TreeNode* root,vector<TreeNode*>& nodes){
    if (!root) return;
    nodes.push_back(root);
    preorder(root->left,nodes);
    preorder(root->right,nodes);
}

void flatten(TreeNode* root){
    vector<TreeNode*> nodes;
    preorder(root,nodes);
    
    for(int i=1;i<nodes.size();i++){
        TreeNode* prev = nodes[i-1];
        TreeNode* curr = nodes[i];
        prev->left = NULL;
        prev->right = curr;
    }
}

void print(TreeNode* root){
    while(root!=NULL){
        cout<<root->val;
        if(root->right) cout<<" -1 ";
        root = root->right;
        // if(root) cout<<" ";
    }
}


int main(){
    cout<<"enter the input";
    string input;
    getline(cin,input);
    TreeNode * root = buildTree(input);
    
    flatten(root);
    print(root);
    
    return 0;
}