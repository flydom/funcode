// 二叉树的前中后序遍历（递归/非递归） + 层序遍历

struct BTreeNode
{
	int m_nValue;
	BTreeNode *m_pLeft;
	BTreeNode *m_pRight;
} ;


// 宽度优先遍历(层序遍历)
void BTree_LevelOrder(BTreeNode *pRoot)
{
	BTreeNode *pTemp = NULL;
	std::queue <BTreeNode *> nodes;

	nodes.push(pRoot);

	while (!nodes.empty())
	{
		pTemp = nodes.front();
		nodes.pop();
		printf("%d\n", pTemp->m_nValue);
		
		if (NULL != pTemp->m_pLeft)
		{
			nodes.push(pTemp->m_pLeft);
		}
	
		if (NULL != pTemp->m_pRight)
		{
			nodes.push(pTemp->m_pRight);
		}
	}
}

// 前序遍历： 
void BTree_RrcPreOrder(BTreeNode *pRoot) // 递归
{
	if (NULL != pRoot)
	{
		printf("%d\n", pRoot->m_nValue);
		BTree_PreOrder(pRoot->m_pLeft);
		BTree_PreOrder(pRoot->m_pRight);
	}
}

void BTree_UnRecPreOrder(BTreeNode *pRoot) // 非递归
{
	std::stack <BTreeNode *> nodes;
	
	while (NULL != pRoot || !nodes.empty())
	{
		if (NULL != pRoot)
		{
			printf("%d\n", pRoot->m_nValue);
			nodes.push(pRoot);
			pRoot = pRoot->m_pLeft;
		}
		else
		{
			pRoot = nodes.top();
			nodes.pop();
			pRoot = pRoot->m_pRight;
		}
	}
}

// 中序遍历：
void BTree_RrcInOrder(BTreeNode *pRoot) // 递归
{
	if (NULL != pRoot)
	{
		BTree_RrcInOrder(pRoot->m_pLeft);
		printf("%d\n", pRoot->m_nValue);
		BTree_RrcInOrder(pRoot->m_pRight);
	}
}

void BTree_UnRecInOrder(BTreeNode *pRoot) // 非递归
{
	std::stack <BTreeNode *> nodes;
	
	while (NULL != pRoot || !nodes.empty())
	{
		if (NULL != pRoot)
		{
			nodes.push(pRoot);
			pRoot = pRoot->m_pLeft;
		}
		else
		{
			pRoot = nodes.top();
			printf("%d\n", pRoot->m_nValue);
			nodes.pop();
			pRoot = pRoot->m_pRight;
		}
	}
}

// 后序遍历： 
void BTree_RrcPostOrder(BTreeNode *pRoot) // 递归
{
	if (NULL != pRoot)
	{
		BTree_PreOrder(pRoot->m_pLeft);
		BTree_PreOrder(pRoot->m_pRight);
		printf("%d\n", pRoot->m_nValue);
	}
}

// 后续遍历非递归完整实现，需要借助辅助栈
strcut StackNode
{
	int sign;
	BTreeNode *pTNode;
}

class BTreeStack
{
public:
	BTreeStack();
	~BTreeStack();
	
	int empty() const {return (top==-1);}
	void push(BTreeNode *pTNode, int m_sign);
	void pop();
	
	StackNode* top();
	
private:
	StackNode *m_pSNode;
};

void BTree_UnRecPostOrder(BTreeNode *pRoot) // 非递归
{
	BTreeStack *Stack;
	StackNode *pTmpSNode = NULL
	BTreeNode *pTmpTNode = NULL;
	
	// Stack = malloc(STACK_SIZE);
	Stack.init();
	
	while (NULL != pRoot)
	{
		Stack.push(pRoot, 0);
		pRoot = pRoot->m_pLeft;
	}

	while (!Stack.empty())
	{
		pTmpSNode = Stack.top();
		if ((NULL == pTmpSNode->pTNode->m_pRight) || pTmpSNode->sign)
		{
			printf("%d\n", pTmpSNode->pTNode->m_nValue);
			Stack.pop();
		}
		else
		{
			pTmpSNode->sign = 1;
			pTmpTNode = pTmpSNode->pTNode->m_pRight;
			while (NULL != pTmpTNode)
			{
				Stack.push(pTmpTNode, 0);
				pTmpTNode = pTmpTNode->m_pLeft;
			}
		}
	}
}

// 网上搜的相关栈的实现，先留着
typedef struct
{
  BiTree *base;
  BiTree *top;
  int stacksize;
} Stack;

//初始化栈
Status InitStack(Stack *s)
{
  s->base = (BiTree*)malloc(sizeof(BiTree)*STACK_INIT_SIZE);
  s->top = s->base;
  s->stacksize = STACK_INIT_SIZE;
  return OK;
}

//获得栈顶元素
Status GetTop(Stack *s, BiTree *c)
{
  if (StackEmpty(s))	
    return ERROR;
  *c = *(s->top - 1);
  return OK;
}

//判断栈是否为空
Status StackEmpty(Stack *s)
{
  if (s->base == s->top)
    return OK;
  return ERROR;
}

//进栈
Status Push(Stack *s, BiTree c)
{
  //如果空间不够，增加空间的分配
  if (s->top - s->base >= s->stacksize)
  {
    s->base = (BiTree*)realloc(s->base, sizeof(BiTree)*(s->stacksize + STACKINCREMENT));
    s->stacksize = s->stacksize + STACKINCREMENT;
  }

  *(s->top++) = c;
  return OK;
}

//出栈
Status Pop(Stack *s, BiTree *c)
{
  if (StackEmpty(s))
    return ERROR;
  *c = *(--s->top);
  return OK;
}



