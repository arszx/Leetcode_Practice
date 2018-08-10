//树的深度

//树的定义
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode * m_pLeft;
	BinaryTreeNode * m_pRight;
};

int TreeDepth(BinaryTreeNode * pRoot)
{
	if(pRoot==Null)
		return 0;
	
	int depth,depth_left,depth_right;
	depth_left=TreeDepth(pRoot->m_pLeft);
	depth_right=TreeDepth(pRoot->m_pRight);
	depth=max(depth_left,depth_right)++;
	
	return depth;
}

// 判断平衡二叉树，采用后续遍历的方法

bool IsBalancedTree(BinaryTreeNode* pRoot, int* pDepth)
{
	if(pRoot==NULL)
	{
		*pDepth=0;
		return true;
	}
	
	int left,right;
	if(IsBalancedTree(pRoot->m_pLeft,&left)==true
	&& IsBalancedTree(pRoot->m_pRight,&right)==true)
	{
		int diff;
		diff=left-right;
		if(diff<=1 && diff>=-1)
		{	
			*pDepth=1+(left>right? left:right);
			return true;
		}
	}
	
	return false;
}
