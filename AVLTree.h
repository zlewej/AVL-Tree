/*
 Julius Garma
 Hank Stalica
 HW 5
 *****************
 
 extending class Tree(inheritance), saves us from rewriting code
 from scratch, which is a core benefit of object-oriented
 programming
 */


#ifndef HW_5_AVL_Tree_AVLTree_h
#define HW_5_AVL_Tree_AVLTree_h
#include "Tree.h"

class AVLTree : public Tree
{
private:
    int height(Node* r) const;
    int difference(Node* r) const;
    void rotateRight(Node* &r);
    void rotateLeft(Node* &r);
    void rotateRightLeft(Node* &r);
    void rotateLeftRight(Node* &r);
    void balance(Node* &r);
    void remove(Node* &r, int i);
    void add(Node* &r, int i);
    
public:
    void remove(int i);
    void add(int i);
    
};

int AVLTree::height(Node* r) const
{
        if(r == nullptr)
            return 0;
    
        int lh = height(r->left);
        int rh = height(r->right);
    
        if(lh > rh)
        {
            return (1 + lh);
        }
        else{
            return (1 + rh);
        }
    
}

int AVLTree::difference(Node* r)
{
    diff = height(r->left) - height(r->right);
    return diff;
}

void AVLTree::rotateRight(Node* &r)
{
    Node* p = r->left;
    r->left = p->right;
    p->right = r;
    r = p;
}

void AVLTree::rotateLeft(Node* &r)
{
    Node* p = r->right;
    r->right = p->left;
    p->left = r;
    r = p;
}

void AVLTree::rotateRightLeft(Node* &r)
{
    rotateRight(r->right);
    rotateLeft(r);
}

void AVLTree::rotateLeftRight(Node* &r)
{
    rotateLeft(r->left);
    rotateRight(r);
}

void AVLTree::balance(Node* &r)
{
    if(difference(r) == -2)
    {
        if(difference(r->left) == -1)
        {
            rotateRight(r);
        }
        else{
            rotateLeftRight(r);
        }
    }
    else if(difference(r) == 2)
    {
        if(difference(r) == 1)
        {
            rotateLeft(r);
        }
        else{
            rotateRightLeft(r);
        }
    }
}

void AVLTree::remove(Node* &r, int i)
{
    if(r == nullptr)
    {
        return;
    }
    else if(i < r->i)
    {
        remove(r->left, i);
    }
    else if(i > r->i)
    {
        remove(r->right, i);
    }
    else
    {
        
        Node* p;
        
        if(r->left == nullptr && r->right == nullptr)		// no kids
        {
            delete r;
            r = nullptr;
        }
        else if(r->left != nullptr && r->right == nullptr)	// left kid
        {
            p = r;
            r = r->left;
            delete p;
        }
        else if(r->left == nullptr && r->right != nullptr)	// right kid
        {
            p = r;
            r = r->right;
            delete p;
        }
        else												// two kids
        {
            p = r->right;
            
            while(p->left)
                p = p->left;
            
            p->left = r->left;
            p = r;
            r = r->right;
            
            delete p;
        }
    }
}

void AVLTree::remove(int i)
{
    remove(root, i);
    balance(root);
}

void AVLTree::add(Node* &r, int i)
{
    if(r == nullptr)
    {
        Node* r = new Node;
        r->i = i;
        r->left = nullptr;
        r->right = nullptr;
    }
    else if(i r->i)
    {
        insert(r->left, i);
    }
    else
    {
        insert(r->right, i);
    }
    balance(r);
}

void AVLTree::add(int i)
{
    add(root, i);
    balance(root);
}



#endif
