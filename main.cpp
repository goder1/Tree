#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;


class Node
{

public:

    int k;
    Node* left;
    Node* right;
    int height = 1;
    int amount = 1;

    void Insert(Node* pnode, int x)
    {
        if (x < k)
        {
            if (pnode->left != nullptr)
            {
                pnode->left->Insert(pnode, x);
                pnode = Balance(pnode);
            }
            else
            {
                pnode->left = new Node;
                pnode->left->k = x;
                pnode->left->left = nullptr;
                pnode->left->right = nullptr;
                //pnode = Balance(pnode);
            }
        }
        else if (x > k)
        {
            if (pnode->right != nullptr)
            {
                pnode->right->Insert(pnode, x);
                pnode = Balance(pnode);
            }
            else
            {
                pnode->right = new Node;
                pnode->right->k = x;
                pnode->right->left = nullptr;
                pnode->right->right = nullptr;
                //height = Height();
            }
        }
        else if (x == k)
        {
            amount++;
        }
    }

    int Height(Node* pnode)
    {
        if (pnode->left == nullptr && pnode->right == nullptr)
        {
            return 0;
        }
        else if (pnode->left == nullptr && pnode->right != nullptr)
        {
            return pnode->right->Height(pnode->right) + 1;
        }
        else if (pnode->right == nullptr && pnode->left != nullptr)
        {
            return pnode->left->Height(pnode->left) + 1;
        }
        else
        {
            int l = left->Height(pnode->left);
            int r = right->Height(pnode->right);
            if (l > r)
            {
                return l + 1;
            }
            else if (l <= r)
            {
                return r + 1;
            }
        }
        return 1;
    }

    void Print()
    {
        if (left != nullptr)
            left->Print();

        cout << k << " ";

        if (right != nullptr)
            right->Print();
    }

    void Print_amount()
    {
        if (left != nullptr)
            left->Print_amount();

        cout << k << " " << amount << endl;

        if (right != nullptr)
            right->Print_amount();
    }

    void Print_leaves()
    {
        if (left != nullptr)
            left->Print_leaves();

        if (left == nullptr && right == nullptr)
            cout << k << "\n";

        if (right != nullptr)
            right->Print_leaves();
    }

    bool Is_balanced(Node* pnode)
    {
        if (pnode->left == nullptr && pnode->right == nullptr)
        {
            return true;
        }
        else if (pnode->left == nullptr && pnode->right != nullptr)
        {
            if (pnode->right->Height(pnode->right) < 2)
                return true;
            else
                return false;
        }
        else if (pnode->right == nullptr && pnode->left != nullptr)
        {
            if (pnode->left->Height(pnode->left) < 2)
                return true;
            else
                return false;
        }
        else
            return pnode->left->Is_balanced(pnode->left) & pnode->right->Is_balanced(pnode->right) & (abs(pnode->right->Height(pnode->right) - left->Height(pnode->left)) < 2);
    }

    Node* Rotate_right(Node* pnode)
    {
        Node* res = pnode->left;
        Node* ptr = pnode->left->right;
        pnode->left->right = pnode;
        pnode->left = ptr;
        return res;
    }

    Node* Rotate_left(Node* pnode)
    {
        Node* res = pnode->right;
        Node* ptr = pnode->right->left;
        pnode->right->left = pnode;
        pnode->right = ptr;
        return res;
    }

    Node* Balance(Node* pnode)
    {
        if (!Is_balanced(pnode))
        {
            if (pnode->left->Height(pnode->left) - pnode->right->Height(pnode->right) == 2)
            {
                pnode->left = Rotate_left(pnode->left);
                pnode = Rotate_right(pnode);
            }
            else if (pnode->right->Height(pnode->right) - pnode->left->Height(pnode->left) == 2)
            {
                pnode->right = Rotate_right(pnode->right);
                pnode = Rotate_left(pnode);
            }
        }
        return pnode;
    }

};

class Balanced_Tree
{
public:

    Node* Pnode;

    Balanced_Tree()
    {
        Pnode = nullptr;
    }

    Balanced_Tree(vector<int> arr)
    {
        if (arr.size())
        {
            Pnode = new Node;
            Pnode->k = arr[0];
            Pnode->left = nullptr;
            Pnode->right = nullptr;
            for (int i = 1; i < arr.size(); i++)
            {
                Insert(arr[i]);
            }
        }

        else
        {
            Pnode = nullptr;
        }
    }

    void Insert(int x)
    {
        if (Pnode == nullptr)
        {
            Pnode = new Node;
            Pnode->k = x;
            Pnode->left = nullptr;
            Pnode->right = nullptr;
        }
        else
            Pnode->Insert(Pnode, x);
        Balance();
    }

    void Print()
    {
        Pnode->Print();
    }

    int Height()
    {
        return Pnode->Height(Pnode) + 1;
    }

    void Print_leaves()
    {
        Pnode->Print_leaves();
    }

    bool Is_balanced()
    {
        return Pnode->Is_balanced(Pnode);
    }

    void Print_amount()
    {
        Pnode->Print_amount();
    }

    void Balance()
    {
        Pnode = Pnode->Balance(Pnode);
    }

};


int main()
{
    Balanced_Tree tree;
    int a;
    cin >> a;
    while (a)
    {
        tree.Insert(a);
        cin >> a;
    }
    //tree.Print();
    //cout << endl;
    //cout << tree.Height();
    if (tree.Is_balanced())
        cout << "YES";
    else
        cout << "NO";
    //tree.Print_amount();
    return 0;
}
