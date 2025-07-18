#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
private:
    Node *root;

public:
    Tree();
    ~Tree();
    void CreateTree();
    void iterativePreorder(Node *p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node *p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node *p);
    void iterativePostorder() { iterativePostorder(root); }
};

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    // Recursively delete all nodes in the tree
    if (root == nullptr)
        return;
    std::stack<Node *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        Node *curr = stk.top();
        stk.pop();
        if (curr->rchild)
            stk.push(curr->rchild);
        if (curr->lchild)
            stk.push(curr->lchild);
        delete curr;
    }
}

void Tree::CreateTree()
{
    Node *p;
    Node *t;
    int x;
    queue<Node *> q;

    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::iterativePreorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node *p)
{
    stack<Node *> stk;
    Node *lastVisited = nullptr;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace(p);
            p = p->lchild;
        }
        else
        {
            Node *peekNode = stk.top();
            if (peekNode->rchild != nullptr && lastVisited != peekNode->rchild)
            {
                p = peekNode->rchild;
            }
            else
            {
                cout << peekNode->data << ", " << flush;
                lastVisited = peekNode;
                stk.pop();
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int main()
{
    Tree bt;
    bt.CreateTree();
    cout << endl;
    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();
    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();
    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();
    return 0;
}