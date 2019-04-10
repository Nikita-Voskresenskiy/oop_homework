#include <iostream>
#include <vector>

using namespace std;


template <typename T> class Node
{
public:
    T* key;
    Node* left;
    Node* right;
    Node(T& value)
    {
        key = new T(value);
        left = NULL;
        right = NULL;
    }
};


template <typename T> class Tree
{
private:
    Node<T>* root;
    void add_in_tree(T& new_value, Node<T>*& node)
    {
        if (new_value < *(node->key) && node->left == NULL)
        {
            node->left = new Node<T>(new_value);
            //cout<<"Node allocated"<<endl;
        }
        else if (new_value >= *(node->key) && node->right == NULL)
        {
            node->right = new Node<T>(new_value);
            //cout<<"Node allocated"<<endl;
        }
        else if (new_value < *(node->key) && node->left != NULL)
        {
            add_in_tree(new_value, node->left);
        }
        else if (new_value >= *(node->key) && node->right != NULL)
        {
            add_in_tree(new_value, node->right);
        }
    }
    void print_tree(Node<T>*& node)
    {
        if (node->left != NULL)
        {
            print_tree(node->left);
        }
        cout << *(node->key) << " ";
        if (node->right != NULL)
        {
            print_tree(node->right);
        }
    }
    bool find_tree(Node<T>*& node, T& value)
    {
        bool rtn_val = (*(node->key) == value);
        if (*(node->key) != value)
        {
            if (node->left != NULL)
            {
                rtn_val += find_tree(node->left, value);
            }
            if (node->right != NULL)
            {
                rtn_val += find_tree(node->right, value);
            }
        }
        return rtn_val;

    }
    void clearNode(Node<T>*& node)
    {
        if (node != NULL)
        {
            clearNode(node->left);
            clearNode(node->right);
            //cout << *(node->key) <<endl;
            delete(node->key);
            delete(node);
            //cout << "Node deleted" << endl;
        }
    }

public:
    Tree()
    {
        root = NULL;
    }
    void add(T& new_value)
    {
        if (root == NULL)
        {
            root = new Node<T>(new_value);
        }
        else
        {
            add_in_tree(new_value, root);
        }
    }
    void print()
    {
        cout << endl;
        cout << "output: ";
        print_tree(root);
        cout << endl;
    }
    bool find(T& value)
    {
        return find_tree(root, value);
    }
    ~Tree()
    {
        clearNode(root);
    }

};



int main()
{
    cout << "TESTING TEMPLATES" << endl;
    Tree <int> nd; //initializing tree with root
    vector<int> values = {6, -9, 6, 10, -12, 5, 89, 17, -23, 0, 5};
    cout << "input: ";
    for (int& el : values)
    {
        nd.add(el);
        cout << el << " ";
    }
    nd.print(); //printing tree
    vector<int> find_values = {6, 100, -23, 57, 0, 6};
    cout << "Testing ints:" << endl;
    for (int& el : find_values)
    {
        cout << "result find(" << el << ") = " << nd.find(el) <<  endl;
    }


    Tree <string> nds; //initializing tree with root
    vector<string> values2 = {"a1", "hello", "7853", "ab12", "world"};
    cout << endl;
    cout << "input: ";
    for (string& el : values2)
    {
        nds.add(el);
        cout << el << " ";
    }
    nds.print(); //printing tree
    vector<string> find_values2 = {"qwerty", "7853", "a1", "xyz"};
    cout << "Testing strings:" << endl;
    for (string& el : find_values2)
    {
        cout << "result find(" << el << ") = " << nds.find(el) <<  endl;
    }

    return 0;
}
