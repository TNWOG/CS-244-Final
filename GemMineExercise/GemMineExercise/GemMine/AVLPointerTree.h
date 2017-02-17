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
// AVLPointerTree.h
//
// Extends AVLTree so that you can define a tree of pointers.  However, the order is based on the comparison of dereferencing those pointers.
//
// Instructor: Jocelyn Richardt
// Assignment: HW #12 Gem Mine
// Author: Jocelyn Richardt
// Date: 12/7/2016
//
// ---------------------------------------------------------------------------
#ifndef H_AVL_POINTER_TREE
#define H_AVL_POINTER_TREE

#include "avlTree.h"

template <class elemT>
class AVLPointerTree : public AVLTreeType<elemT>
{
public:
	AVLPointerTree() : AVLTreeType() {}
	~AVLPointerTree() {}
	void insertIntoAVL(AVLNode<elemT>*& root, AVLNode<elemT>* newNode, bool & isTaller);
};


template <class elemT>
void AVLPointerTree<elemT>::insertIntoAVL(AVLNode<elemT>* &root,
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
	else if (*(root->mInfo) > *(newNode->mInfo)) //newItem goes in 
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

#endif