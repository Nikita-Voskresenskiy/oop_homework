#include <iostream>
#include <vector>

using namespace std;


class Node
{
public:
    int* key;
    Node* left;
    Node* right;
    Node(int& value)
    {
        key = new int(value);
        left = NULL;
        right = NULL;
    }
};


class Tree
{
private:
    Node* root;
    void add_in_tree(int& new_value, Node*& node)
    {
        if (new_value < *(node->key) && node->left == NULL)
        {
            node->left = new Node(new_value);
            //cout<<"Node allocated"<<endl;
        }
        else if (new_value >= *(node->key) && node->right == NULL)
        {
            node->right = new Node(new_value);
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
    void print_tree(Node*& node)
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
    bool find_tree(Node*& node, int& value)
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
    void clearNode(Node*& node)
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
    void add(int& new_value)
    {
        if (root == NULL)
        {
            root = new Node(new_value);
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
    bool find(int& value)
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
    Tree nd; //initializing tree with root
    vector<int> values = {6, -9, 6, 10, -12, 5, 89, 17, -23, 0, 5};
    cout << "input: ";
    for (int& el : values)
    {
        nd.add(el);
        cout << el << " ";
    }
    nd.print(); //printing tree
    vector<int> find_values = {6, 100, -23, 57, 0, 6};
    for (int& el : find_values)
    {
        cout << "result find(" << el << ") = " << nd.find(el) <<  endl;
    }
    return 0;
}
