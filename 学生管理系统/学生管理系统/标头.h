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

void intializelist(list *plist)                //��ʼ������
{
	plist = NULL;
}

bool listisfull(list *plist)                   //�ж������Ƿ�����
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

bool listisempty(list *plist)                   //�ж������Ƿ�Ϊ��
{
	if (plist == NULL)
		return true;
	else
		return false;
}

bool copytonode(list *plist, item *pitem)       //������������
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

bool distorythelist(list *plist)                  //�ݻ���������
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

void shownode(node *pnode)                      //չʾһ���ڵ��е���
{
	printf("%s %d %d %d %d %d", pnode->Item->name, pnode->Item->number, pnode->Item->score1, pnode->Item->score2, pnode->Item->score3);
}

void travelthelist(list *plist)                 //��������
{
	node *scan;
	scan = plist->next;

	while (scan->next!=NULL)
	{
		shownode(scan);
		scan = scan->next;
	}
}

bool searchitem(char name,list *plist)          //������
{
	printf("������Ҫ���ҵ�ѧ������\n");
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

bool addnode(list *plist, item *pitem)          //��
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