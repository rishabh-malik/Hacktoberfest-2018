#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector< pair<int,int> >
#define max(x,y) (x>y)?x:y
#define min(x,y) (x<y)?x:y
#define mid(a,b) (a+b)>>1
#define all(p) p.begin(),p.end()
#define F first
#define S second
#define MP make_pair
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rloop(i,a,b) for(int i=a; i>b; i--)
#define PB push_back
#define F first
#define S second

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* sortedArraytoBST(vi &arr, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    node *root = new node();
    root->data = arr[mid];
    root->left = NULL;
    root->right = NULL;

    root->left = sortedArraytoBST(arr, start, mid-1);
    root->right = sortedArraytoBST(arr, mid+1, end);
    return root;
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int n;
    cin >> n;
    vi arr(n);
    loop(i,0,n){
        cin >> arr[i];
    }
    int start = 0;
    int end = n-1;
    node* res = sortedArraytoBST(arr, start, end);
    preOrder(res);
}