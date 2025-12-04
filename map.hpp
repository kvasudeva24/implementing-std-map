#include <algorithm>


using Color = bool;
constexpr Color RED = false;
constexpr Color BLACK = true;




template<typename K, typename V>
class map_rb{
private:

    struct Node{
        std::optional<K> key;
        std::optional<V> value;
        Color color = RED;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;

        Node(K k, V v) : key(k), value(v) {};
        Node() = default;
    };  


    Node* root = nullptr;
    Node*  NIL = nullptr;
    size_t size = 0;

    void rotate_left(Node* x){
        Node* y = x->right;
        x->right = y->left;
        if(y->left != NIL){
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr){
            root = y;
        } else if (x->parent->right == x){
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotate_right(Node* x){
        Node* y = x->left;
        x->left = y->right;
        y->parent = x->parent;
        if(y->right != NIL){
            y->right->parent = x;
        }
        if(x->parent == nullptr){
            root = y;
        } else if(x->parent->right == x){
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insert(const K& key, const V& value){
        Node* newNode = new Node<K, V>(key, value);
        newNode->left = newNode->right = NIL;
        Node* iter = root;
        if(iter == NIL){
            root = newNode;
            newNode->color = BLACK;
            newNode->parent = NIL;
            return;
        }

        Node* node_par = nullptr;
        while(iter != NIL){
            node_par = iter;
            if(iter->key.value() > key){
                iter = iter->left;
            } else {
                iter =  iter->right;
            }
        }

        newNode->parent = node_par;

        if(node_par->key.value() > key){
            node_par->left = newNode;
        } else {
            node_par->right = newNode;
        }
        rebalance(newNode);
    }
    void rebalance(Node* x){
        //see readme for rebalancing details and cases
        Node* iter = x;

        while(iter->parent->color == RED){
            if(iter->parent == iter->parent->parent->left){
                Node* uncle = iter->parent->parent->right;
                if(uncle->color == RED){
                    unlce->color = BLACK;
                    iter->parent->color = BLACK;
                    iter->parent->parent->color = RED;
                    iter = iter->parent->parent;
                } else {
                    if(iter->parent->right == iter){
                        iter = iter->parent;
                        rotate_left(iter);
                        //because the rotation changes the parent child property we need
                        //to go up a level
                    }
                    iter->parent->color = BLACK;
                    iter->parent->parent->color = RED;
                    rotate_right(iter->parent->parent);
                }
            } else {
                Node* uncle = iter->parent->parent->left;
                if(uncle->color == RED){
                    uncle->color = BLACK;
                    iter->parent->color = BLACK;
                    iter->parent->parent->color = RED;
                    iter = iter->parent->parent;
                } else {
                    if(iter->parent->left == iter){
                        iter = iter->parent;
                        rotate_right(iter);
                        //because the rotation changes the parent child property we need
                        //to go up a level
                    }
                    iter->parent->color = BLACK;
                    iter->parent->parent->color = RED;
                    rotate_left(iter->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

public:
    map_rb<K, V>(){
        NIL = new Node<K,V>();
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
    }


    V& at(const K& key);
    V& operator[](const K& key);

    size_t size(){
        return size;
    }






};