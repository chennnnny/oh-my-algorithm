#include <iostream>

typedef struct _node {
    char data;
    struct _node *lchild;
    struct _node *rchild;
} BTNode, *PBTNode;
typedef BTNode BTTree, *PBTTree;

//! 通过 前序序列 和 中序序列 创建 二叉树
PBTTree CreateBTree(char* preorder, char* inorder, int len) {
    if (len <= 0) return NULL;
    PBTNode node = new BTNode;
    node->data = preorder[0];
    int pos = 0;
    for (pos = 0; pos < len; ++pos) {
        if (inorder[pos] == preorder[0]) break;
    }
    if (pos == len) return NULL;
    node->lchild = CreateBTree(preorder + 1, inorder, pos);
    node->rchild = CreateBTree(preorder + pos + 1, inorder + pos + 1, len - pos - 1);
    return node;
}
void DeleteBTree(PBTTree tree) {
    if (tree == NULL) return;
    DeleteBTree(tree->lchild);
    DeleteBTree(tree->rchild);
    delete tree, tree = NULL;
}

//! 前序遍历
void PreOrder(PBTTree tree) {
    if (tree == NULL) return;
    std::cout << tree->data;
    PreOrder(tree->lchild);
    PreOrder(tree->rchild);
}
//! 中序遍历
void InOrder(PBTTree tree) {
    if (tree == NULL) return;
    InOrder(tree->lchild);
    std::cout << tree->data;
    InOrder(tree->rchild);
}
//! 后序遍历
void PostOrder(PBTTree tree) {
    if (tree == NULL) return;
    PostOrder(tree->lchild);
    PostOrder(tree->rchild);
    std::cout << tree->data;
}

int main(int argc, char* argv[]) {
    char preorder[] = "ABDGCEF";
    char inorder[] = "DGBAECF";
    PBTTree tree = CreateBTree(preorder, inorder, strlen(preorder));
    PreOrder(tree);
    std::cout << std::endl;
    InOrder(tree);
    std::cout << std::endl;
    PostOrder(tree);
    std::cout << std::endl;
    DeleteBTree(tree);
    return 0;
}