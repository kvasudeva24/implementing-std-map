#include <algorithm>


using Color = bool;
constexpr Color RED = false;
constexpr Color BLACK = true;

template <typename K, typename V>
struct Node{
    std::optional<K> key;
    std::optional<V> value;
    Color color = RED;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;

    Node(K k, V v) : key(k), value(v) {};
};

template<typename K, typename V>
class map_rb{
private:
    Node* root = nullptr;
    Node*  NIL = nullptr;

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

public:
    map_rb<K, V>(){
        NIL = new Node<K,V>();
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;

        root = NIL;
    }






};