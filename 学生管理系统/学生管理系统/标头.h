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

bool distorythelist(list *plist)                  //摧毁整个链表
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

	while (scan->next!=NULL)
	{
		shownode(scan);
		scan = scan->next;
	}
}

bool searchitem(char name,list *plist)          //查找项
{
	printf("请输入要查找的学生姓名\n");
	scanf_s("%s", &name);

	node *pnode;
	pnode = plist->next;
	while (name!=plist->Item->name)
	{
		pnode = pnode->next;
		if (pnode->next==NULL)
		{
			return false;
		}
	}
	return true;
}

bool addnode(list *plist, item *pitem)          //插
{
	node *pnode;
	node *scan;
	char pname;
	scanf_s("%s", &pname);

	scanf_s("%s",&pitem->name);
	scanf_s("%")

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