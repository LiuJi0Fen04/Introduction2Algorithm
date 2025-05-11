#include <iostream>
#include "export_macro.h"
// using enum class to address some limitations of enum
enum class RBT_Color{
    RED = 0,
    BLACK
};

/// <summary>
/// red black tree node 
/// </summary>
/// <param name="data"></param>
/// <param name="lchild"></param>
/// <param name="rchild"></param>
/// <param name="parent"></param>
/// <param name="color"></param>
typedef struct _RBTree_Node_
{
    int data;
    RBT_Color color;
    struct _RBTree_Node_ *lchild, *rchild, *parent;
}RBTree_Node;


I2A_API RBTree_Node* createRBNode(int value);

/// @brief calculate the pointer to the mimimum node 
/// @param root I- the root of red black tree
/// @return pointer to the minimum node
I2A_API RBTree_Node* RBTreeMinimum(RBTree_Node* root);

I2A_API void RBTreeDelete(RBTree_Node** root, RBTree_Node* z);

/// @brief  insert a node into red black tree
/// @param root I- the root node which should be init as pointer NULL or pointer of other node 
/// @param z I- only the color and the data is important
I2A_API void RBTreeInsert(RBTree_Node** root, RBTree_Node* z);

I2A_API void RBTreeInorder(RBTree_Node* p);

I2A_API RBTree_Node* createRBNode(int value);

/// @brief 
/// @param p 
I2A_API void RBTreeHeightCheck(RBTree_Node* p);

I2A_API RBTree_Node* RBTreeSearch(RBTree_Node* p, int key);

I2A_API void callRedBlackTree();