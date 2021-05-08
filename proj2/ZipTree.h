#ifndef ZIPTREE_H
#define ZIPTREE_H

#include <iostream>

// explanations for public member functions are provided in project2.h
// each file that uses a WAVL tree should #include this file
template <typename KeyType, typename ValType>
class ZipTree
{
public:
	// DO NOT MODIFY METHOD SIGNATURES BELOW THIS LINE
	ZipTree();
	~ZipTree();
	static unsigned getRandomRank();
	void insert(const KeyType& key, const ValType& val, unsigned rank = getRandomRank());
	void remove(const KeyType& key);
	ValType find(const KeyType& key);
	unsigned getSize();
	int getHeight();
	unsigned getDepth(const KeyType& key);
	// DO NOT MODIFY METHOD SIGNATURES ABOVE THIS LINE

	// define new public methods
	struct node
	{
		KeyType key;
		ValType val;
		unsigned int rank;
		//node* parent;
		node* left;
		node* right;	
	};

public:
	node* zip(node* left, node* right);
	void updateValue(const KeyType& key, const ValType& value);
	void print(node* node, int level);
	node* getRoot();

private:
	// define private methods
	void heightRecur(node* node, int depth, int& maxDepth);
	void deleteTree(node* node);
	node* m_root;
	unsigned int m_size;	
};

// fill in the definitions for each required member function and for any additional member functions you define


template <typename KeyType, typename ValType>
ZipTree<KeyType, ValType>::ZipTree()
{
	// TODO
	m_root = nullptr;
	srand(time(NULL));
	m_size = 0;
}

template <typename KeyType, typename ValType>
ZipTree<KeyType, ValType>::~ZipTree()
{
	// TODO
	deleteTree(m_root);
}

template <typename KeyType, typename ValType>
unsigned ZipTree<KeyType, ValType>::getRandomRank()
{
	unsigned int temp = rand() % 2;
	unsigned int rank = 0;
	while (temp == 0)
	{
		temp = rand() % 2;
		rank++;
	}
	//std::cout << "rank: " << rank << std::endl;
	return rank; // remove this line when you implement this function
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::insert(const KeyType& key, const ValType& val, unsigned rank)
{
	//std::cout << "Inserting: " << key << ", rank: " << rank << std::endl;
	// cursor starts at root
	node* cursor = m_root;
	// cursorParent keeps track of cursor's parent
	node* cursorParent = nullptr;
	// cursorPtr is the pointer pointing to the cursor. so above
	// gonna need this later for attaching everything nicely
	node** cursorPtr = nullptr;
	// iterate through till correct rank is reached
	while (cursor != nullptr && cursor->rank > rank)
	{
		if (key < cursor->key)
		{
			cursorParent = cursor;
			cursorPtr = &(cursor->left);
			cursor = cursor->left;
		}
		else if (key > cursor->key)
		{
			cursorParent = cursor;
			cursorPtr = &(cursor->right);
			cursor = cursor->right;
		}
		else
		{
			//std::cout << "key exists\n";
			return;
		}
	}	
	//if rank tie, if key is greater, iterate right
	while (cursor != nullptr && cursor->rank == rank)
	{
		if (key > cursor->key)
		{
			cursorParent = cursor;
			cursorPtr = &(cursor->right);
			cursor = cursor->right;
		}
		else
		{
			break;
		}
	}
	// let's get to unzipping
	// this ended up being some major spagetti code, so let's talk it out
	// Iterate the cursor down the tree according to binary tree rules
	// If the cursor key is less than the key, take the subtree at the cursor and throw it into the newLeft
	// Opposite for greater than
	// Gotta make sure to decouple the parent node from cursor after it's  added to the new subtree
	// That's about it
	

	// these two keep track of the start of the new paths
	node* newLeft = nullptr;
	node* newRight = nullptr;

	// these two keep track of end of new paths
	node* endLeft = nullptr;
	node* endRight = nullptr;

	// iterate to end of search path
	while (cursor != nullptr)
	{
		// check if node belongs in left subtree
		// left can only add right
		if (cursor->key < key) 
		{
			// check if left subtree exists
			if (newLeft == nullptr)
			{
				// set start and end as cursor
				newLeft = cursor;
				endLeft = cursor;
			}
			// check is node belong on left of end of left subtree
			else
			{
				//add to end of left subtree
				endLeft->right = cursor;
				//update newLeft
				endLeft = endLeft->right;
				//endLeft->right = nullptr;
			}
			// check is node belong on right of end of left subtree
			//else if (cursor->key > endLeft->key) 
			//{
			//	//add to end of left subtree
			//	endLeft->right = cursor;
				//update newLeft
			//	endLeft = newLeft->right;
			//}
			// key already exists
			//else if (cursor->key == endLeft->key)
			//{
			//	return;
			//}
			// increment cursor
			cursorParent = cursor;
			//cursorPtr = &(cursor->right);
			cursor = cursor->right;
			//get rid of old pointer attachment from parent
			//otherwise duplicates can happen
			cursorParent->right = nullptr;
		}
		// check is node belongs in right subtree
		else if (cursor->key > key) 
		{
			// check if right subtree exists
			if (newRight == nullptr)
			{
				// set start and end as cursor
				newRight = cursor;
				endRight = cursor;
			}
			// check is node belong on left of end of right subtree
			else 
			{
				//add to end of left subtree
				endRight->left = cursor;
				//update newLeft
				endRight = endRight->left;
				//endRight->left = nullptr;
			}
			//check is node belong on right of end of right subtree
			//else if (cursor->key > endRight->key) 
			//{
				//add to end of right subtree
			//	endRight->right = cursor;
				//update newLeft
			//	endRight = endRight->right;
			//}
			// key already exists
			//else if (cursor->key == endRight->key)
			//{
			//	return;
			//}
			// increment cursor
			cursorParent = cursor;
			//cursorPtr = &(cursor->right);
			cursor = cursor->left;
			cursorParent->left = nullptr;
		}
		else if (cursor->key == key)
		{
			return;
		}
	}

	//if (newLeft)
	//	std::cout << "newLeft: " << newLeft->key << std::endl;
	//if (newRight)
	//	std::cout << "newRight: " << newRight->key << std::endl;
	//set left and right ends to nullptr
	//endLeft->left = nullptr;
	//endLeft->right = nullptr;
	//endRight->left = nullptr;
	//endRight->right = nullptr;

	// create new node
	node* newNode = new node;
	newNode->key = key;
	newNode->val = val;
	newNode->rank = rank;
	//newNode.parent = newParent;
	newNode->left = newLeft;
	newNode->right = newRight;
	/**
	if (startLeft)
	{
		startLeft->parent = newNode;
	}
	if (startRight)
	{
		startRight->parent = newNode;
	}**/
	if (cursorPtr == nullptr)
	{
		m_root = newNode;
	}
	else
	{
		*cursorPtr = newNode;
	}
	m_size++;

	//print(m_root, 0);
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::remove(const KeyType& key)
{
	// TODO
	//std::cout << "Removing: " << key << std::endl;
	// cursor starts at root
	node* cursor = m_root;
	// cursorParent keeps track of cursor's parent
	node* cursorParent = nullptr;
	// cursorPtr is the pointer pointing to the cursor. so above
	// gonna need this later for attaching everything nicely
	node** cursorPtr = nullptr;
	// iterate through till correct key is reached
	while (cursor != nullptr)
	{
		if (key < cursor->key)
		{
			cursorParent = cursor;
			cursorPtr = &(cursor->left);
			cursor = cursor->left;
		}
		else if (key > cursor->key)
		{
			cursorParent = cursor;
			cursorPtr = &(cursor->right);
			cursor = cursor->right;
		}
		else
		{
			break;
		}
	}
	if (cursor == nullptr)
	{
	//	std::cout << "key not found\n";
		return;
	}
	//std::cout << "a\n";
	if (cursorParent == nullptr)
	{
		m_root = zip(cursor->left, cursor->right);
	}
	else
	{
		*cursorPtr = zip(cursor->left, cursor->right);
	}
	delete cursor;
	m_size--;
	//print(m_root, 0);
	
	/**
	node* leftCur = cursor->left;
	node* leftCurPar = cursor;
	node** leftCurPtr = &(cursor->left);
	node* rightCur = cursor->right;
	node* rightCurPar = cursor;
	node** rightCurPtr = &(cursor->right);
	cursor->left = nullptr;
	nursor->right = nullptr;
	node* newStart = nullptr;
	node* newEnd = nullptr;
	while (leftCur || rightCur)
	{
		if (!leftCur)
		{
			if (newStart == nullptr)
			{
				newStart = rightCur;
				newEnd = rightCur;
				rightCurPar = rightCur;
				rightCur = rightCur->left;
			}
			else if (rightCur->key > newEnd->key)
			{
				newEnd->right = rightCur;
				newEnd = newEnd->right;
				rightCur = rightCur->left;
			}
			else if (rightCur->key < newEnd->key)
			{
				newEnd->left = rightCur;
				newEnd = newEnd->left;
				rightCur = rightCur->left;
			}
		}
		else if (!rightCur)
		{
			if (newStart == nullptr)
			{
				newStart = leftCur;
				newEnd = leftCur;
				leftCur = leftCur->right;
			}
			else if (leftCur->key > newEnd->key)
			{
				newEnd->right = leftCur;
				newEnd = newEnd->right;
				leftCur = leftCur->right;
			}
			else if (leftCur->key < newEnd->key)
			{
				newEnd->left = leftCur;
				newEnd = newEnd->left;
				leftCur = leftCur->right;
			}
		}
		if (rightCur->rank == leftCur->rank)
		{
			if (newStart == nullptr)
			{
				newStart = leftCur;
				newEnd = leftCur;
				leftCur = leftCur->right;
			}
			else
			{
				
			}
		}
	}**/
}

template <typename KeyType, typename ValType>
ValType ZipTree<KeyType, ValType>::find(const KeyType& key)
{
	// cursor starts at root
	node* cursor = m_root;
	while (cursor != nullptr)
	{
		if (key < cursor->key)
		{
			cursor = cursor->left;
		}
		else if (key > cursor->key)
		{
			cursor = cursor->right;
		}
		else
		{
			return cursor->val;
		}
	}
	//return -1;
	//return 0; // remove this line when you implement this function
}

template <typename KeyType, typename ValType>
unsigned ZipTree<KeyType, ValType>::getSize()
{
	// TODO
	return m_size; // remove this line when you implement this function
}

template <typename KeyType, typename ValType>
int ZipTree<KeyType, ValType>::getHeight()
{
	// TODO
	int height = 0;
	ZipTree<KeyType, ValType>::heightRecur(m_root, 0, height);
	return height - 1; // remove this line when you implement this function
}

template <typename KeyType, typename ValType>
unsigned ZipTree<KeyType, ValType>::getDepth(const KeyType& key)
{
	// cursor starts at root
	node* cursor = m_root;
	unsigned int depth = 0;
	while (cursor != nullptr)
	{
		if (key < cursor->key)
		{
			cursor = cursor->left;
			depth++;
		}
		else if (key > cursor->key)
		{
			cursor = cursor->right;
			depth++;
		}
		else
		{
			return depth;
		}
	}
	return 0;
	//return 0; // remove this line when you implement this function
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::print(node* node, int level)
{
	if (node == nullptr)
		return;
	std::cout << "key: " << node->key << ", rank: " << node->rank << ", level: " << level << std::endl;
	level++;
	print(node->left, level);
	print(node->right, level);
}

template <typename KeyType, typename ValType>
typename ZipTree<KeyType, ValType>::node* ZipTree<KeyType, ValType>::zip(node* left, node* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}
	if (left->rank >= right->rank)
	{
		node* nextLeft = left->right;
		if (nextLeft != nullptr && nextLeft->rank >= right->rank)
		{
			left->right = zip(nextLeft, right);
		}
		else
		{
			left->right = right;
			right->left = zip(nextLeft, right->left);
		}
		return left;
	}
	else
	{
		node* nextRight = right->left;
		if (nextRight != nullptr && nextRight->rank >= right->rank)
		{
			right->left = zip(left, nextRight);
		}
		else
		{
			right->left = left;
			left->right = zip(left->right, nextRight);
		}
		return right;
	}
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::heightRecur(node* node, int depth, int& maxDepth)
{
	if (node == nullptr)
		return;
	depth++;
	if (depth > maxDepth)
	{
		maxDepth = depth;
	}
	heightRecur(node->left, depth, maxDepth);
	heightRecur(node->right, depth, maxDepth);
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::deleteTree(node* node)
{
	if (node == NULL)
	{
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

template <typename KeyType, typename ValType>
void ZipTree<KeyType, ValType>::updateValue(const KeyType& key, const ValType& value)
{
	// cursor starts at root
	node* cursor = m_root;
	while (cursor != nullptr)
	{
		if (key < cursor->key)
		{
			cursor = cursor->left;
		}
		else if (key > cursor->key)
		{
			cursor = cursor->right;
		}
		else
		{
			cursor->val = value;
			return;
		}
	}

}

template <typename KeyType, typename ValType>
typename ZipTree<KeyType, ValType>::node* ZipTree<KeyType, ValType>::getRoot()
{
	return m_root;
}

#endif
