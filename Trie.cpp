#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define pb          push_back
#define pii         pair<int,int>
#define pll         pair<long,long>
#define vi          vector<int>
#define vll         vector<ll>
#define vii         vector<pii>
#define Mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
//#define endl        '\n'
#define mod        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rem(i,a,b)  for(int i=a;i>b;i--)
#define mp(a,b)     make_pair(a,b)
#define INF         numeric_limits<ll>::max();
#define NINF        numeric_limits<ll>::min();
#define vvi(a,b,name)    vector<vector<int>> name(a,vector<int>(b,-1))

struct node{
    node* par=nullptr;
    node* child[26]={nullptr};
    int occ=0;
};

void ins(node* root, string s){
    node* cur=root; //cur is the pointer to the current node;
    int n=s.length();
    rep(i,0,n){
        if(cur->child[s[i]-'a']==nullptr){ //if it is not initialized
            cur->child[s[i]-'a']=new node(); //we initialize
            cur->child[s[i]-'a']->par=cur; // we set its parent as cur
        }
        cur=cur->child[s[i]-'a']; //cur node is changed and child becomes new cur
    }
    cur->occ++; //finally when cur points to last string element we increase the occurrence
}

//How to delete a word
// search for the word
// if the word exists, then we start at the ending node
// the first thing we do is decrement the occurrence of the node by one

//Delete the Node if
//1. it has no children
//2. It's occurrence is 0
//3. Move to the parent node and repeat

node* look(node* root,string s){
    node* cur=root;
    int n=s.length();
    rep(i,0,n){
        if(cur->child[s[i]-'a']!=nullptr){//as long as we have non-null child
            cur=cur->child[s[i]-'a'];//cur is changed to child of cur
        }
        else return nullptr;// if no child is found we return null
    }
    return cur->occ!=0?cur:nullptr;//if no words end at cur we return null
}

void del(node* root,string s){
    int n=s.length();
    node* cur=look(root,s);
    if(cur!=nullptr){
        cur->occ--;// decrease occurrence
        node* parent=nullptr;//variable parent initialized
        bool isleaf=true;// variable isleaf that checks if parent of cur is leaf node or not

        for(int i=0;i<26;i++){
            if(cur->child[i]!=nullptr){// if any child of cur has non-null child it means it is not leaf
                isleaf=false;
                break;
            }
        }
        while(cur->par!=nullptr && isleaf && cur->occ==0){
            parent=cur->par;// variable parent is not cur's parent
            for(int i=0;i<26;i++){
                if(parent->child[i]==cur){//if a child of parent is found equal to cur
                    parent->child[i]=nullptr;//we make it null
                    delete cur;//delete it
                    cur=parent;// now cur points to parent
                }
                else if(parent->child[i]!=nullptr){//in case before coming across cur we get any other child that is not null means parent is not leaf
                    isleaf=false;
                }
            }
        }
    }
}

void inorder(node* cur,string s){
    if(cur->occ>0){
        cout<<s<<" "<<cur->occ<<endl;
    }
    for(int i=0;i<26;i++){
        if(cur->child[i]!=nullptr){
            s+=(char)('a'+i);
            inorder(cur->child[i],s);
            s.pop_back();
        }
    }
}


void solve(){
    node root;
    string s;
    rep(i,0,3){

        cin>>s;
        ins(&root,s);
    }
    inorder(&root,"");
    cin>>s;
    look(&root,s);
    del(&root,s);
    inorder(&root,"");



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

Motivation
The main motivation for using trie is that we want to efficiently search for a word in a dataset of strings. We can use hash table or balanced trees for this task. However, trie has its unique advantages:

VS. Hash Table:

Hash table has O(1) time complexity for looking up a key but it is not efficient for the operations:

Finding all keys with a common prefix. We have to traverse all keys in hash table, which can be O(n) (n is the number of keys inserted). However, trie takes O(k) (k is the length of the prefix).
Enumerating a dataset of strings in lexicographical order. There is a sorting on all strings (i.e. keys) and thus O(nlogn). However, trie takes O(n) time only.
Search in hash table can be O(n) if there are plenty of hash collisions. However, trie only takes O(m) (m is the key length)

Compared to hash table, trie saves space when storing many keys with the same prefix.

VS. balanced trees:

Search in balanced tree can take O(mlogn) time. However, trie only takes O(m).
    
    
Applications
Trie is useful when we want to search some string based on the character appearance of the characters within the string:

Autocomplete
Spell checker
IP routing (Longest prefix matching
T9 predictive text
Solving Boggle
Huffman Codes (§10.1.2 in MAW(cpp))
