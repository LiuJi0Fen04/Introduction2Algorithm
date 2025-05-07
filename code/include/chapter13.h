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

I2A_API void callRedBlackTree();