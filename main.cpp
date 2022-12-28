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
    /*
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
    */
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
            }
        }
        else if (x == k)
        {
            amount++;
        }
    }
    /*
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
    */
    int Height()
    {
        if (left == nullptr && right == nullptr)
        {
            return 1;
        }
        else if (left == nullptr && right != nullptr)
        {
            return right->Height() + 1;
        }
        else if (right == nullptr && left != nullptr)
        {
            return left->Height() + 1;
        }
        else
        {
            int l = left->Height();
            int r = right->Height();
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

    bool Is_balanced()
    {
        //cout<<"gg\n";
        if (left == nullptr && right == nullptr)
        {
            cout << "trushka\n";
            return true;
        }
        else if (left == nullptr && right != nullptr)
        {
            cout << "huy\n";
            if (right->Height() < 2)
            {
                cout<<"ladno\n";
                return true;
            }
            else
            {
                cout << "tafak\n";
                return false;
            }
        }
        else if (right == nullptr && left != nullptr)
        {
            cout << "gavno\n";
            if (left->Height() < 2)
            {
                cout<<"ladno\n";
                return true;
            }
            else
            {
                cout << "tafak\n";
                return false;
            }
        }
        else
        {
            cout << "13yo demon\n";
            return left->Is_balanced() & right->Is_balanced() & (abs(right->Height() - left->Height()) < 2);
        }
    }

    /*
    Node* Rotate_right(Node* pnode)
    {
        Node* res = pnode->left;
        Node* ptr = pnode->left->right;
        pnode->left->right = pnode;
        pnode->left = ptr;
        return res;
    }*/

    Node* Rotate_right()
    {
        Node* res = left;
        Node* ptr = left->right;
        left->right = this;
        left = ptr;
        return res;
    }

    /*
    Node* Rotate_left(Node* pnode)
    {
        Node* res = pnode->right;
        Node* ptr = pnode->right->left;
        pnode->right->left = pnode;
        pnode->right = ptr;
        return res;
    }*/

    Node* Rotate_left()
    {
        //Node* res = right;
        Node* res = right->left;
        left = this;
        //right = ptr;
        return res;
    }

    /*
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
    }*/

    Node* Balance()
    {
        cout << "sha budet balanceeee\n";
        if (!Is_balanced())
        {
            cout << "TOCHNO sha budet balanceeee\n";
            if (left !=  nullptr)
            {
                if (!left->Is_balanced())
                {
                    cout << "balancim levo\n";
                    left = left->Balance();
                }
            }
            if (right != nullptr)
            {
                if (!right->Is_balanced())
                {
                    cout << "balancim pravo\n";
                    right = right->Balance();
                }
            }
            if (left != nullptr && right != nullptr)
            {
                cout << "obadva\n";
                if (left->Height() - right->Height() == 2)
                {
                    cout << "leftik\n";
                    if (left->right != nullptr && left->left != nullptr)
                        left = left->Rotate_left();
                    //return Rotate_right();
                    Node* R = Rotate_right();
                    if (R->left !=  nullptr)
                    {
                        if (!R->left->Is_balanced())
                        {
                            cout << "balancim levo\n";
                            R->left = R->left->Balance();
                        }
                    }
                    if (R->right != nullptr)
                    {
                        if (!R->right->Is_balanced())
                        {
                            cout << "balancim pravo\n";
                            R->right = R->right->Balance();
                        }
                    }
                    return R;
                }
                else if (right->Height() - left->Height() == 2)
                {
                    cout << "rightik\n";
                    if (right->right != nullptr && right->left != nullptr)
                        right = right->Rotate_right();
                    //return Rotate_left();
                    Node* R = Rotate_left();
                    if (R->left !=  nullptr)
                    {
                        if (!R->left->Is_balanced())
                        {
                            cout << "balancim levo\n";
                            R->left = R->left->Balance();
                        }
                    }
                    if (R->right != nullptr)
                    {
                        if (!R->right->Is_balanced())
                        {
                            cout << "balancim pravo\n";
                            R->right = R->right->Balance();
                        }
                    }
                    return R;
                }
            }
            else if (left == nullptr && right != nullptr)
            {
                cout <<"spravanalevo\n";
                return Rotate_left();
            }
            else
            {
                cout <<"slevanaprava\n"; return Rotate_right();
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
    }

    void Insert(int x)
    {
        if (Pnode == nullptr)
        {
            Pnode = new Node;
            Pnode->k = x;
            Pnode->left = nullptr;
            Pnode->right = nullptr;
            //cout << "blya\n";
        }
        else
            Pnode->Insert(x);
        cout << "dalshe balancing\n";
        Balance();
    }

    void Print()
    {
        Pnode->Print();
    }

    int Height()
    {
        return Pnode->Height() + 1;
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
       Pnode = Pnode->Balance();
       //Pnode->Balance();
    }

    void Print_with_sons()
    {
        Pnode->print_with_sons();
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
