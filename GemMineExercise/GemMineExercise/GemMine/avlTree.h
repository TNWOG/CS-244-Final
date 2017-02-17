// ---------------------------------------------------------------------------
//    
//                   University of Wisconsin-Stout
//            Mathematics, Statistics & Computer Science
//                 CS-244 Data Structures - Fall 2016
//
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2016
//
// avlTree.h
//
// AVL (Height-Balanced) Tree
//
// Instructor: Jocelyn Richardt
// Assignment: Chapter 11 Programming Exercise 9
// Author: Malik
// Date: Unknown
//
// Updated:  12/5/2016 by Richardt to rename variables with more meaning
// ---------------------------------------------------------------------------
#ifndef H_AVLTree
#define H_AVLTree

#include <iostream>

using namespace std;


template <class elemT>
class AVLNode
{
public:
    elemT mInfo;
    int	mBalanceFactor; // balance factor
    AVLNode *mLeftSubtree;
    AVLNode *mRightSubtree;
};


template <class elemT>
class AVLTreeType
{
public:
    void insert(const elemT &newItem);
    void rotateToLeft(AVLNode<elemT>* &root);
    void rotateToRight(AVLNode<elemT>* &root);
    void balanceFromLeft(AVLNode<elemT>* &root);
    void balanceFromRight(AVLNode<elemT>* &root);

    virtual void insertIntoAVL(AVLNode<elemT>* &root, 
                       AVLNode<elemT>  *newNode, 
                       bool& isTaller);
	void functionTraverse(void(*f)(elemT item));
	void gemBagTraverse(AVLNode<elemT>* root, void(*f)(elemT item));
	void inorderTraversal();
    void preorderTraversal();
    AVLTreeType();   //default constructor

private:
    AVLNode<elemT>* mRoot;

    void inorder(AVLNode<elemT> *p);
    void preorder(AVLNode<elemT> *p);
};
template <class elemT>
void AVLTreeType<elemT>::functionTraverse(void(*f)(elemT item))
{
	gemBagTraverse(mRoot, f);
}

template <class elemT>
void AVLTreeType<elemT>::gemBagTraverse(AVLNode<elemT>* root, void(*f)(elemT item))
{
	if (root)
	{
		(f)(root->mInfo);
		gemBagTraverse(root->mLeftSubtree, f);
		gemBagTraverse(root->mRightSubtree, f);
	}
}


template <class elemT>
void AVLTreeType<elemT>::rotateToLeft(AVLNode<elemT>* &root)
{
    AVLNode<elemT> *p;  //pointer to the root of the
                        //right subtree of root
    if (root == NULL)
        cerr << "Error in the tree" << endl;
    else if (root->mRightSubtree == NULL)
        cerr << "Error in the tree:"
             <<" No right subtree to rotate." << endl;
    else
    {
        p = root->mRightSubtree;
        root->mRightSubtree = p->mLeftSubtree; //the left subtree of p becomes
                                //the right subtree of root
        p->mLeftSubtree = root; 
        root = p;	//make p the new root node
    }
}//rotateLeft

template <class elemT>
void AVLTreeType<elemT>::rotateToRight(AVLNode<elemT>* &root)
{
    AVLNode<elemT> *p;  //pointer to the root of	
                        //the left subtree of root

    if (root == NULL)
        cerr << "Error in the tree" << endl;
    else if (root->mLeftSubtree == NULL)
        cerr << "Error in the tree:"
             << " No left subtree to rotate." << endl;
    else
    {
        p = root->mLeftSubtree;
        root->mLeftSubtree = p->mRightSubtree; //the right subtree of p becomes
                                //the left subtree of root
        p->mRightSubtree = root; 
        root = p;	//make p the new root node
    }
}//end rotateRight

template <class elemT>
void AVLTreeType<elemT>::balanceFromLeft(AVLNode<elemT>* &root)
{
    AVLNode<elemT> *p;
    AVLNode<elemT> *w;

    p = root->mLeftSubtree;   //p points to the left subtree of root

    switch (p->mBalanceFactor)
    {
    case -1: 
        root->mBalanceFactor = 0;
        p->mBalanceFactor = 0;
        rotateToRight(root);
        break;

    case 0:  
        cerr << "Error: Cannot balance from the left." << endl;
        break;

    case 1:  
        w = p->mRightSubtree;
        switch (w->mBalanceFactor)  //adjust the balance factors
        {
        case -1: 
            root->mBalanceFactor = 1;
            p->mBalanceFactor = 0;
            break;

        case 0:  
            root->mBalanceFactor = 0;
            p->mBalanceFactor = 0;
            break; 

        case 1:  
            root->mBalanceFactor = 0;
            p->mBalanceFactor = -1;
        }//end switch

        w->mBalanceFactor = 0;	
        rotateToLeft(p);
        root->mLeftSubtree = p;
        rotateToRight(root);
    }//end switch;
}//end balanceFromLeft

template <class elemT>
void AVLTreeType<elemT>::balanceFromRight(AVLNode<elemT>* &root)
{
    AVLNode<elemT> *p;
    AVLNode<elemT> *w;

    p = root->mRightSubtree;   //p points to the left subtree of root

    switch (p->mBalanceFactor)
    {
    case -1: 
        w = p->mLeftSubtree;
        switch (w->mBalanceFactor)  //adjust the balance factors
        {
        case -1: 
            root->mBalanceFactor = 0;
            p->mBalanceFactor = 1;
            break;

        case 0:  
            root->mBalanceFactor = 0;
            p->mBalanceFactor = 0;
            break;

        case 1:  
            root->mBalanceFactor = -1;
            p->mBalanceFactor = 0;
        }//end switch

        w->mBalanceFactor = 0;	
        rotateToRight(p);
        root->mRightSubtree = p;
        rotateToLeft(root);
        break;

    case 0:  
        cerr << "Error: Cannot balance from the left." << endl;
        break;

    case 1:  
        root->mBalanceFactor = 0;
        p->mBalanceFactor = 0;
        rotateToLeft(root);
    }//end switch;
}//end balanceFromRight

template <class elemT>
void AVLTreeType<elemT>::insertIntoAVL(AVLNode<elemT>* &root, 
                                AVLNode<elemT>  *newNode, 
                                bool& isTaller)
{
    if (root == NULL)
    {
        root = newNode;
        isTaller = true;
    }
    else if (root->mInfo == newNode->mInfo)
        cerr << "No duplicates are allowed." << endl;
    else if (root->mInfo > newNode->mInfo) //newItem goes in 
                                         //the left subtree
    {
        insertIntoAVL(root->mLeftSubtree, newNode, isTaller);

        if (isTaller) //after insertion, the subtree grew in height
            switch (root->mBalanceFactor)
            {
            case -1:
                balanceFromLeft(root);
                isTaller = false;
                break;

            case 0:  
                root->mBalanceFactor = -1;
                isTaller = true;
                break;

            case 1:  
                root->mBalanceFactor = 0;
                isTaller = false;
            }//end switch
        }//end if
        else
        {
            insertIntoAVL(root->mRightSubtree, newNode, isTaller);

            if (isTaller) //after insertion, the subtree grew in
                          //height
                switch (root->mBalanceFactor)
                {
                case -1: 
                    root->mBalanceFactor = 0;
                    isTaller = false;
                    break;

                case 0:  
                    root->mBalanceFactor = 1;
                    isTaller = true;
                    break;

                case 1:  
                    balanceFromRight(root);
                    isTaller = false;
                }//end switch
        }//end else
}//insertIntoAVL


template<class elemT>
void AVLTreeType<elemT>::insert(const elemT &newItem)
{
    bool isTaller = false;
    AVLNode<elemT>  *newNode;

    newNode = new AVLNode<elemT>;
    newNode->mInfo = newItem;
    newNode->mBalanceFactor = 0;
    newNode->mLeftSubtree = NULL;
    newNode->mRightSubtree = NULL;

    insertIntoAVL(mRoot, newNode, isTaller);
}


template<class elemT>
void AVLTreeType<elemT>::inorderTraversal()
{
    inorder(mRoot);
}

template<class elemT>
void AVLTreeType<elemT>::inorder(AVLNode<elemT> *p)
{
    if (p != NULL)
    {
        inorder(p->mLeftSubtree);
		cout << p->mInfo << std::endl;
        inorder(p->mRightSubtree);
    }
}

template<class elemT>
void AVLTreeType<elemT>::preorderTraversal()
{
	preorder(mRoot);
}

template<class elemT>
void AVLTreeType<elemT>::preorder(AVLNode<elemT> *p)
{
    if (p != NULL)
    {
        cout << p->mInfo << " ";
        preorder(p->mLeftSubtree);
        preorder(p->mRightSubtree);
    }
}

template<class elemT>
AVLTreeType<elemT>::AVLTreeType()
{
    mRoot = NULL;
}

#endif