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

bool addnode(list *plist, item *pitem)          //����������ӽڵ�
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

bool emptythelist(list *plist)                  //�ݻ���������
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
}