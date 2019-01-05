struct student
{
	char name;
	int number;
	int score1;
	int score2;
	int score3;
};
typedef struct student item;
struct node
{
	item *Item;
	node *next;
};
typedef struct node list;

void intializelist(list *plist)                //初始化链表
{
	plist = NULL;
}

bool listisfull(list *plist)                   //判断链表是否已满
{
	node *pt;
	list *pnew;
	pnew = plist;

	while (pnew->next != NULL)
	{
		pnew = pnew->next;
	}
	pnew->next = pt;
	if (pt == NULL)
	{
		return false;
	}
	else
		return true;
	free(pt);
}

bool listisempty(list *plist)                   //判断链表是否为空
{
	if (plist == NULL)
		return true;
	else
		return false;
}

bool copytonode(list *plist, item *pitem)       //拷贝项至链表
{
	node *pnode;

	pnode->Item->name = pitem->name;
	pnode->Item->number = pitem->number;
	pnode->Item->score1 = pitem->score1;
	pnode->Item->score2 = pitem->score2;
	pnode->Item->score3 = pitem->score3;

	if (pnode->Item->name == pitem->name&&pnode->Item->number == pitem->number&&pnode->Item->score1 == pitem->score1&&pnode->Item->score2 == pitem->score2&&pnode->Item->score3 == pitem->score3)
		return true;
	else
	{
		return false;
	}
}

bool addnode(list *plist, item *pitem)          //往链表中添加节点
{
	node *pnode;
	node *scan;

	pnode = (node *)malloc(sizeof(node));
	if (pnode == NULL)
	{
		return false;
	}

	scan = pnode->next;
	if (scan != NULL)
	{
		scan = scan->next;
	}
	copytonode(plist, pitem);
	return true;
}

bool emptythelist(list *plist)                  //摧毁整个链表
{
	node *pnode;
	while (plist->next != NULL)
	{
		pnode = plist->next;
		free(plist);
		plist = pnode;
	}
	if (plist == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void shownode(node *pnode)                      //展示一个节点中的项
{
	printf("%s %d %d %d %d %d", pnode->Item->name, pnode->Item->number, pnode->Item->score1, pnode->Item->score2, pnode->Item->score3);
}

void travelthelist(list *plist)                 //遍历链表
{
	node *scan;
	scan = plist->next;
}