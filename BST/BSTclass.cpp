#include <iostream>
#include <queue>
#include "bstNode.h"
using namespace std;

class BST
{
private:
    bstNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bstNode<int> *deleteDataHelper(bstNode<int> *node, int data)
    {
        if (!node)
        {
            return NULL;
        }
        if (node->data > data)
        {
            node->left = deleteDataHelper(node->left, data);
            return node;
        }
        else if (node->data < data)
        {
            node->right = deleteDataHelper(node->right, data);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL && node->right != NULL)
            {
                bstNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->left != NULL && node->right == NULL)
            {
                bstNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                bstNode<int> *rightMinNode = node->right;
                while (rightMinNode->left != NULL)
                {
                    rightMinNode = rightMinNode->left;
                }
                int rightMinData = rightMinNode->data;
                node->data = rightMinData;
                node->right = deleteDataHelper(node->right, rightMinData);
                return node;
            }
        }
    }

public:
    void deleteData(int data)
    {
        if (findData(data))
        {
            this->root = deleteDataHelper(this->root, data);
        }
    }

private:
    bstNode<int> *insertDataHelper(bstNode<int> *node, int data)
    {
        if (!node)
        {
            node = new bstNode<int>(data);
            return node;
        }
        if (node->data > data)
        {
            node->left = insertDataHelper(node->left, data);
        }
        else
        {
            node->right = insertDataHelper(node->right, data);
        }
        return node;
    }

public:
    void insertData(int data)
    {
        this->root = insertDataHelper(this->root, data);
    }

private:
    bool findDataHelper(bstNode<int> *node, int data)
    {
        if (!node)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return findDataHelper(node->left, data);
        }
        else
        {
            return findDataHelper(node->right, data);
        }
    }

public:
    bool findData(int data)
    {
        return findDataHelper(this->root, data);
    }

private:
    void printBTLevelWise(bstNode<int> *root)
    {
        if (!root)
            return;
        queue<bstNode<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            bstNode<int> *front = q.front();
            q.pop();
            cout << front->data << ": ";
            if (front->left)
            {
                cout << "L=" << front->left->data << " ";
                q.push(front->left);
            }
            if (front->right)
            {
                cout << "R=" << front->right->data << " ";
                q.push(front->right);
            }
            cout << '\n';
        }
    }

public:
    void print()
    {
        printBTLevelWise(this->root);
    }
};

int main()
{
    BST b;
    b.insertData(10);
    b.insertData(4);
    b.insertData(12);
    b.insertData(13);
    b.insertData(3);
    b.insertData(1);
    b.insertData(5);
    b.insertData(11);
    b.insertData(7);
    b.print();
    b.deleteData(10);
    b.deleteData(100);
    b.print();
}
/*Do read AVL trees*/