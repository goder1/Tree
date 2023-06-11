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

    void Insert(int x)
    {
        if (x < k)
        {
            if (left != nullptr)
            {
                left->Insert(x);
            }
            else
            {
                left = new Node;
                left->k = x;
                left->left = nullptr;
                left->right = nullptr;
                left->amount = 1;
                FixHeight();
            }
        }
        else if (x > k)
        {
            if (right != nullptr)
            {
                right->Insert(x);
            }
            else
            {
                right = new Node;
                right->k = x;
                right->left = nullptr;
                right->right = nullptr;
                right->amount = 1;
                FixHeight();
            }
        }
        else if (x == k)
        {
            amount++;
        }
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

    void print_with_sons()
    {
        cout << k;
        if (left != nullptr)
            cout << ", left is " << left->k;
        else
            cout << ", left is none";
        if (right != nullptr)
            cout << ", right is " << right->k;
        else
            cout << ", right is none";
        cout << endl;
        if (left != nullptr)
            left->print_with_sons();
        if (right != nullptr)
            right->print_with_sons();
    }

    void print_with_heights()
    {
        cout << k;
        cout << ", height is " << height << endl;
        if (left != nullptr)
            left->print_with_heights();
        if (right != nullptr)
            right->print_with_heights();
    }

    int Height()
    {
        if (left == nullptr && right != nullptr)
        {
            return right->Height() + 1;
        }
        else if (left != nullptr && right == nullptr)
        {
            return left->Height() + 1;
        }
        else if (left != nullptr && right != nullptr)
        {
            return max(left->Height(), right->Height()) + 1;
        }
        return 1;
    }

    void FixHeight()
    {
        if (left != nullptr && right == nullptr)
        {
            height = left->Height() + 1;
            left->FixHeight();
        }
        else if (left == nullptr && right != nullptr)
        {
            height = right->Height() + 1;
            right->FixHeight();
        }
        else if(left != nullptr && right != nullptr)
        {
            if(left->Height() > right->Height())
            {
                height = left->Height() + 1;
            }
            else
            {
                height = right->Height() + 1;
            }
            right->FixHeight();
            left->FixHeight();
        }
        else
        {
            height = 1;
        }
    }

    bool Is_balanced()
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left == nullptr && right != nullptr)
        {
            if (right->height < 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (right == nullptr && left != nullptr)
        {
            if (left->height < 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return left->Is_balanced() & right->Is_balanced() & (abs(right->height - left->height) < 2);
        }
    }

    Node* Rotate_right()
    {
        Node* p = left;
        left = p->right;
        p->right = this;
        FixHeight();
        p->FixHeight();
        return p;
    }

    Node* Rotate_left()
    {
        Node* p = right;
        right = p->left;
        p->left = this;
        FixHeight();
        p->FixHeight();
        return p;
    }

    Node* Balance()
    {
        if (!Is_balanced())
        {
            if (left !=  nullptr)
            {
                if (!left->Is_balanced())
                {
                    left = left->Balance();
                }
            }
            if (right != nullptr)
            {
                if (!right->Is_balanced())
                {
                    right = right->Balance();
                }
            }
            if (left != nullptr && right != nullptr)
            {
                if (left->height - right->height == 2)
                {
                    if (left->right != nullptr && left->left != nullptr)
                        left = left->Rotate_left();
                    Node* R = Rotate_right();
                    if (R->left !=  nullptr)
                    {
                        if (!R->left->Is_balanced())
                        {
                            R->left = R->left->Balance();
                        }
                    }
                    if (R->right != nullptr)
                    {
                        if (!R->right->Is_balanced())
                        {
                            R->right = R->right->Balance();
                        }
                    }
                    return R;
                }
                else if (right->height - left->height == 2)
                {
                    if (right->right != nullptr && right->left != nullptr)
                        right = right->Rotate_right();
                    Node* R = Rotate_left();
                    if (R->left !=  nullptr)
                    {
                        if (!R->left->Is_balanced())
                        {
                            R->left = R->left->Balance();
                        }
                    }
                    if (R->right != nullptr)
                    {
                        if (!R->right->Is_balanced())
                        {
                            R->right = R->right->Balance();
                        }
                    }
                    return R;
                }
            }
            else if (left == nullptr && right != nullptr)
            {
                return Rotate_left();
            }
            else
            {
                return Rotate_right();
            }
        }
        return this;
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

        Balance();
    }

    void Insert(int x)
    {
        if (Pnode == nullptr)
        {
            Pnode = new Node;
            Pnode->k = x;
            Pnode->left = nullptr;
            Pnode->right = nullptr;
            Pnode->height = 1;
            Pnode->amount = 1;
        }
        else
        {
            Pnode->Insert(x);
            Balance();
        }
    }

    void Print()
    {
        Pnode->Print();
    }

    int Height()
    {
        if (Pnode != nullptr)
            return Pnode->height;
        return 0;
    }

    void Print_leaves()
    {
        Pnode->Print_leaves();
    }

    bool Is_balanced()
    {
        return Pnode->Is_balanced();
    }

    void Print_amount()
    {
        Pnode->Print_amount();
    }

    void Balance()
    {
       Pnode->FixHeight();
       Pnode = Pnode->Balance();
       Pnode->FixHeight();
    }

    void Print_with_sons()
    {
        Pnode->print_with_sons();
        cout << endl;
    }

    void Print_with_heights()
    {
        Pnode->print_with_heights();
        cout << endl;
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
        if (tree.Is_balanced())
        cout << "YES\n";
        else
        cout << "NO\n";
        tree.Print_with_sons();
        tree.Print_with_heights();
        cin >> a;
    }

    if (tree.Is_balanced())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
