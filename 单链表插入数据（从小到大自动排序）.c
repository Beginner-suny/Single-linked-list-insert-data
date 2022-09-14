#include <stdio.h>
#include <stdlib.h>

struct Int
{
	int num;
	struct Int *next;
};

void addInt(struct Int **, int);
void printInt(struct Int *);
void freeInt(struct Int *);

void addInt(struct Int **head, int inp)
{
	struct Int *temp = *head;
	struct Int *former;//����λ�õ�ǰһ���ṹ��ռ�λ��

	struct Int *num;//������Ķ����ռ�
	num = (struct Int*)malloc(sizeof(struct Int));
	if (num == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		return;
	}
	num->num = inp;

//	if (*head == NULL) {
//		*head = num;
//		num->next = NULL;
//		return;
//	}

	while (temp != NULL)
	{
		if (temp->num > num->num)
		{
			break;
		}
		former = temp;
		temp = temp->next;
	}

	if (temp == *head)
	{
		num->next = temp;
		*head = num;
	}
	else
	{
		num->next = temp;
		former->next = num;
	}
}

void printInt(struct Int *head)
{
	while (head != NULL)
	{
		printf("%d ", head->num);
		head = head->next;
	}
}

void freeInt(struct Int *head)
{
	struct Int *temp;
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

int main(void)
{
	struct Int *head = NULL;
	printf("�����������������ո�ֿ���-9999��������\n");
	int inp;
	do
	{

		scanf("%d", &inp);
		if (inp == -9999)
		{
			break;
		}
		addInt(&head, inp);
	}
	while (1);

	printInt(head);
	freeInt(head);

	return 0;
}
