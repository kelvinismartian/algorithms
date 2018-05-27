#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class BinarySearchTree{
private:
    struct BinaryNode{
        T element;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode(T ele, BinaryNode* lt, BinaryNode* rt): element(ele),
            left(lt), right(rt){}
    };

    BinaryNode* root;

    BinaryNode* clone(BinaryNode* root)const{
        if(root == NULL)
            return NULL;
        return new BinaryNode(root->element, clone(root->left), clone(root->right));
    }

    void makeEmpty(BinaryNode* &root){
        if(root != NULL){
            makeEmpty(root->left);
            makeEmpty(root->right);
            delete root;
        }
        root = NULL;
    }
public:

    BinarySearchTree(){
        root = new BinaryNode(0, NULL, NULL);
    }

    BinarySearchTree(const BinarySearchTree& rhs): root(clone(rhs.root)){}

    const BinarySearchTree& operator=(const BinarySearchTree& rhs){
        if(this != &rhs){
            makeEmpty(this->root);
            root = clone(rhs.root);
        }
        return *this;
    }

    ~BinarySearchTree(){
        if(root != NULL){
            makeEmpty(root);
        }
    }

    BinaryNode* findMax(const BinaryNode* root){
        if(root == NULL)
            return NULL;
        if(root->right == NULL)
            return root;
        return findMax(root->right);
    }

    BinaryNode* findMin(const BinaryNode* root){
        if(root == NULL)
            return NULL;
        if(root->left == NULL)
            return root;
        return findMin(root->left);
    }

    bool contains(const T& x, const BinaryNode* root){
        if(root == NULL)
            return false;
        if(x < root->element)
            return contains(x, root->left);
        else if(x > root->element)
            return contains(x, root->right);
        else
            return true;
    }

    void insert_s(const T& x, BinaryNode* &root){
        if(root == NULL)
            root = new BinaryNode(x, NULL, NULL);
        if(x < root->element)
            insert_s(x, root->left);
        else if(x > root->element)
            insert_s(x, root->right);
        else;
    }
    void insert(const T& x){
        insert_s(x, root);
    }

    void remove_s(const T& x, BinaryNode* &root){
        if(root == NULL)
            return;
        if(x < root->element)
            remove_s(x, root->left);
        else if(x > root->element)
            remove_s(x, root->right);
        else if(root->right != NULL && root->left != NULL){
            root->element = findMin(root->right)->element;
            remove_s(root->element, root->right);
        }
        else{
            BinaryNode* old = root;
            root = (root->left != NULL)? root->left: root->right;
            delete old;
        }
    }
    void remove(const T& x){
        remove_s(x, root);
    }

    //preOrderTraverse
    void preOrderTraverseRec(BinaryNode* root){
        if(root != NULL){
            cout << root->element << endl;
            preOrderTraverseRec(root->left);
            preOrderTraverseRec(root->right);
        }
    }

    void preOrderTraverseNonRec_1(BinaryNode* root){
        if(root == NULL)
            cout << "empty tree...\n";
        else{
            stack<BinaryNode*> st;
            BinaryNode* curr = root;
            while(!st.empty() || curr != NULL){
                while(curr != NULL){
                    st.push(curr);
                    cout << curr->element << endl;
                    curr = curr->left;
                }
                if(!st.empty()){
                    curr = st.top();
                    st.pop();
                    curr = curr->right;
                }
            }
        }
    }
    void preOrderTraverseNonRec_2(BinaryNode* root){
        if(root == NULL)
            cout << "empty tree...\n";
        else{
            stack<BinaryNode*> st;
            BinaryNode* curr = root;
            st.push(curr);
            while(!st.empty()){
                curr = st.top();
                st.pop();
                cout << curr->element << endl;
                if(curr->right != NULL)
                    st.push(curr->right);
                if(curr->left != NULL)
                    st.push(curr->left);
            }
        }
    }

    void preOrderMorrisTraverse(BinaryNode* root){
        BinaryNode* curr = root;
        BinaryNode* pre = NULL;
        while(curr != NULL){
            if(curr->left == NULL){
                cout << curr->element << endl;
                pre = curr;
                curr = curr->right;
            }
            else{
                pre = curr->left;
                while(pre->right != NULL && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = curr;
                    cout << curr->element << endl;
                    curr = curr->left;
                }
                else{
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }


    //inOrderTraverse
    void inOrderTraverseRec(BinaryNode* root){
        if(root != NULL){
            inOrderTraverseRec(root->left);
            cout << root->element << endl;
            inOrderTraverseRec(root->right);
        }
    }
    void inOrderTraverseNonRec(BinaryNode* root){
        if(root == NULL)
            cout << "empty tree...\n";
        else{
            stack<BinaryNode*> st;
            BinaryNode* curr = root;
            while(!st.empty() || curr != NULL){
                while(curr != NULL){
                    st.push(curr);
                    curr = curr->left;
                }
                if(!st.empty()){
                    curr = st.top();
                    st.pop();
                    cout << curr->element << endl;
                    curr = curr->right;
                }
            }
        }
    }

    void inOrderMorrisTraverse(BinaryNode* root){
        BinaryNode* curr = root;
        BinaryNode* pre = NULL;
        while(curr != NULL){
            if(curr->left == NULL){
                cout << curr->element << endl;
                pre = curr;
                curr = curr->right;
            }
            else{
                pre = curr->left;
                while(pre->right != NULL && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                else{
                    pre->right = NULL;
                    cout << curr->element << endl;
                    curr = curr->right;
                }
            }
        }
    }


    //postOrderTraverse
    void postOrderTraverseRec(BinaryNode* root){
        if(root != NULL){
            postOrderTraverseRec(root->left);
            postOrderTraverseRec(root->right);
            cout << root->element << endl;
        }
    }
    void postOrderTraverseNonRec_1(BinaryNode* root){
        if(root == NULL)
            cout << "empty tree...\n";
        else{
            stack<BinaryNode*> st;
            BinaryNode* curr = root;
            BinaryNode* pre = NULL;
            while(!st.empty() || curr != NULL){
                while(curr != NULL){
                    st.push(curr);
                    curr = curr->left;
                }
                if(!st.empty()){
                    curr = st.top();
                    if(curr->right == NULL || pre == curr->right){
                        cout << curr->element << endl;
                        st.pop();
                        pre = curr;
                        curr = NULL;
                    }
                    else
                        curr = curr->right;
                }
            }
        }
    }

    void postOrderTraverseNonRec_2(BinaryNode* root){
        if(root == NULL)
            cout << "empty tree...\n";
        else{
            stack<BinaryNode*> st;
            BinaryNode* curr = root;
            BinaryNode* pre = NULL;
            st.push(curr);
            while(!st.empty()){
                curr = st.top();
                if((curr->right == NULL && curr->left == NULL) || 
                    pre != NULL && (pre == curr->right || pre == curr->left)){
                    cout << curr->element << endl;
                    st.pop();
                    pre = curr;
                }
                if(curr-> right != NULL)
                    st.push(curr->right);
                if(curr->left != NULL)
                    st.push(curr->left);
            }
        }
    }

    void reverse(BinaryNode* from, BinaryNode* to){
        BinaryNode* temp = NULL;
        BinaryNode* next = from->right;
        from->right = NULL;
        while(from != to){
            temp = from;
            from = next;
            next = from->right;
            from->right = temp;
        }
    }

    void visitreverse(BinaryNode* from, BinaryNode* to){
        reverse(from, to);
        BinaryNode* temp = to;
        while(temp != from){
            cout << temp->element << endl;
            temp = temp->right;
        }
        cout << temp->element << endl;
        reverse(to, from);
    }

    void postOrderMorrisTraverse(BinaryNode* root){
        BinaryNode* preroot = new BinaryNode(0, root, NULL);
        BinaryNode* curr = preroot;
        BinaryNode* pre = NULL;
        while(curr != NULL){
            if(curr->left == NULL){
                curr = curr->right;
            }
            else{
                pre = curr->left;
                while(pre->right != NULL && pre->right != curr){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                else{
                    visitreverse(curr->left, pre);
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }

    void printTree(){
        preOrderTraverseRec(root);
    }

};

int main(){
    BinarySearchTree<int> lt;
    lt.insert(10);
    lt.insert(100);
    lt.insert(1000);
    lt.printTree();
    return 0;
}
