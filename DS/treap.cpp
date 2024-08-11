mt19937 rnd(time(0));
struct Node{
    //put your stuff here
    Node(ll V){
        
    }
    Node(){}
};
struct node{
    node *left, *right;
    ll w, v;
    int siz;
    Node cur;
    node(ll V){
        left = right = NULL;
        v = V;
        w = rnd();
        siz = 1;
        cur = Node(V);
    }
    node(){}
};
int Size(node *treap){
    if(treap == NULL)return 0;
    return treap->siz;
}
void lz(node *treap){
    if(treap == NULL)return;
}
Node Mrg(Node a, Node b){
    Node ret;
    return ret;
}
void split(node *treap, node* &left, node* &right, int cnt){
    if(treap == NULL){
        left = NULL, right = NULL;
        return;
    }
    lz(treap);
    if(Size(treap->left) < cnt){
        split(treap->right, treap->right, right, cnt - Size(treap->left) - 1);
        left = treap;
    }
    else {
        split(treap->left, left, treap->left, cnt);
        right = treap;
    }
    treap->siz = Size(treap->left) + Size(treap->right) + 1;
    treap->cur = Node(treap->v);
    if(treap->left != NULL)treap->cur = Mrg(treap->left->cur, treap->cur);
    if(treap->right != NULL)treap->cur = Mrg(treap->cur, treap->right->cur);
}
int Cur = 0;
void mrg(node* &treap, node *left, node *right){
    if(left == NULL){
        treap = right;
        return;
    }
    if(right == NULL){
        treap = left;
        return;
    }
    lz(left), lz(right);
    if(left->w < right->w){
        mrg(left->right, left->right, right);
        treap = left; 
    }
    else {
        mrg(right->left, left, right->left); 
        treap = right; 
    }
    treap->siz = Size(treap->left) + Size(treap->right) + 1;
    treap->cur = Node(treap->v);
    if(treap->left != NULL)treap->cur = Mrg(treap->left->cur, treap->cur);
    if(treap->right != NULL)treap->cur = Mrg(treap->cur, treap->right->cur);
}
void Print(node *treap){
    if(treap == NULL)return;
    lz(treap);
    Print(treap->left);
    cout << char(treap->v + 'A');
    Print(treap->right);
}
int n, m;
void solve(){
    node *treap = NULL;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        Cur++;
        char c;
        cin >> c;
        mrg(treap, treap, new node(c - 'A'));
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        node *A, *B, *C, *D;w
        split(treap, A, B, l - 1);
        split(B, C, D, r - l + 1);
        mrg(treap, A, D);
        mrg(treap, treap, C);
    }
    Print(treap);
}
