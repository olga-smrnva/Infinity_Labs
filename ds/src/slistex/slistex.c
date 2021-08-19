/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: slistex.c                                                               *
*Description: Functions to simulate the Singly Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer: Jake Belinky                                                        *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stdio.h>		/* printf */
#include <stddef.h>		/* size_t */
#include <stdlib.h>		/* mallocs */
#include <assert.h>		/* assert */


#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

/******************************* Node *****************************************/

typedef struct node
{
	void *data;
	struct node *next;
} node_t;


/******************************* Declarations *********************************/
/******************************* Functions to inplement ***********************/

node_t *Flip(node_t *head);
int HasLoop(const node_t *head);
node_t *FindIntersection(node_t *head_1, node_t *head_2);

/******************************* Test functions *******************************/
int TestFlip(void);
int TestHasLoop(void);
int TestFindIntersection(void);

/******************************* Helping functions ****************************/
static void IsTestPassed(node_t *expected, node_t *result);
void IsTestPassed_int(int result, int expected);
node_t *CreateList5NodesLooped(void);
node_t *CreateList5Nodes(void);
void ListRemove(node_t *head);
size_t ListCount(node_t *head);


/******************************* Main *****************************************/

int main()
{
	TestFlip();
	TestHasLoop();
	TestFindIntersection();
	
	return 0;
}


/******************************* Functions ************************************/
/******************************* Flip *****************************************/

node_t *Flip(node_t *head)
{
	node_t *before = NULL;
	node_t *current = NULL;
	node_t *after = NULL;
	
	assert(head);
	
	current = head;
	after =  current->next;
	
	while(NULL != current->next)
	{
		current->next = before;
		before = current;
		current = after;
		after = current->next;
	}
	
	current->next = before;
	
	return current;
}


/******************************* HasLoop **************************************/

int HasLoop(const node_t *head)
{
	node_t *slow = (node_t *)head;
	node_t *fast = (node_t *)head;
	
	assert(head);
	
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast)
		{
			return 1;
		}
	}
	
	return 0;
}


/******************************* FindIntersection *****************************/

node_t *FindIntersection(node_t *head_1, node_t *head_2)
{
	size_t count_1 = 0; 
	size_t count_2 = 0; 
	size_t dif = 0;
	node_t *temp_short = NULL;
	node_t *temp_long = NULL;
	
	assert(head_1);
	assert(head_2);
	
	count_1 = ListCount(head_1);
	count_2 = ListCount(head_2);
	
	if (count_1 > count_2)
	{
		dif = count_1 - count_2;
		temp_short = head_2;
		temp_long = head_1;
	}
	else
	{
		dif = count_2 - count_1;
		temp_short = head_1;
		temp_long = head_2;
	}
	while (0 != dif)
	{
		temp_long = temp_long->next;
		--dif;
	}
	while (NULL != temp_short)
	{
		if (temp_short == temp_long)
		{
			return temp_short;
		}
		temp_long = temp_long->next;
		temp_short = temp_short->next;
	}
	
	return NULL;
}


/******************************* Test *****************************************/
/******************************* TestFlip *************************************/

int TestFlip()
{
	int one = 1;
	int two = 2;
	int three = 3;

	void *data1 = &one;
	void *data2 = &two;
	void *data3 = &three;

	node_t node1 = {NULL, NULL};
	node_t node2 = {NULL, NULL};
	node_t node3 = {NULL, NULL};

	node3.data = data3;
	node3.next = NULL;

	node2.data = data2;
	node2.next = &node3;

	node1.data = data1;
	node1.next = &node2;
	
	printf(KYEL"\nTEST for FLIP function\n\n"KNRM);
	
/******************************* FlipTest with 3 nodes ************************/
	
	printf("Test FLIP with 3 nodes: ");
	IsTestPassed(&node3, Flip(&node1));

/******************************* FlipTest with 2 nodes ************************/
	
	node1.next = &node2;
	node2.next = NULL;
	printf("Test FLIP with 3 nodes: ");
	IsTestPassed(&node2, Flip(&node1));

/******************************* FlipTest with 1 node *************************/

	node1.next = NULL;
	printf("Test FLIP with 1 node: ");
	IsTestPassed(&node1, Flip(&node1));
	
	
	return 0;
}

/******************************* TestHasLoop **********************************/

int TestHasLoop()
{
	node_t *head_loop = CreateList5NodesLooped();
	node_t *head_no_loop = CreateList5Nodes();

	printf(KYEL"\nTEST for HAS_LOOP function\n\n"KNRM);
	
	printf("Test HAS_LOOP with loop: ");
	IsTestPassed_int(HasLoop(head_loop), 1);
	
	printf("Test HAS_LOOP without loop: ");
	IsTestPassed_int(HasLoop(head_no_loop), 0);
	
	ListRemove(head_loop);
	ListRemove(head_no_loop);
	
	return 0;
}


/******************************* TestFindIntersection *************************/

int TestFindIntersection()
{
	node_t node1 = {NULL, NULL};
	node_t node2 = {NULL, NULL};
	node_t node3 = {NULL, NULL};
	node_t node4 = {NULL, NULL};
	node_t node5 = {NULL, NULL};
	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	node4.next = &node5;
	node5.next = &node3;

	printf(KYEL"\nTEST for FIND_INTERSECTION function\n\n"KNRM);
	
	printf("Test FIND_INTERSECTION with intersection: ");
	IsTestPassed(&node3, FindIntersection(&node4, &node1));
	
	node5.next = NULL;
	printf("Test FIND_INTERSECTION without intersection: ");
	IsTestPassed(NULL, FindIntersection(&node4, &node1));
	
	return 0;
}


/******************************* Helping Functions ****************************/
/******************************* IsTestPassed *********************************/

static void IsTestPassed(node_t *expected, node_t *result)
{
	if(expected != result)
	{
		printf(KRED"\nFAILED\n\n"KNRM);
	}
	else
	{
		printf(KGRN"\nSUCCEEDED\n\n"KNRM);
	}
}


void IsTestPassed_int(int result, int expected)
{
	if(result != expected)
	{
		printf(KRED"\nFAILED\n\n"KNRM);
	}
	else
	{
		printf(KGRN"\nSUCCEEDED\n\n"KNRM);
	}
}

/******************************* CreateList5NodesLooped ***********************/

node_t *CreateList5NodesLooped(void)
{
	node_t *node1 = (node_t *)malloc(sizeof(node_t));
	node_t *node2 = (node_t *)malloc(sizeof(node_t));
	node_t *node3 = (node_t *)malloc(sizeof(node_t));
	node_t *node4 = (node_t *)malloc(sizeof(node_t));
	node_t *node5 = (node_t *)malloc(sizeof(node_t));
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node2;
	
	return node1;
}


/******************************* CreateList5Nodes *****************************/

node_t *CreateList5Nodes(void)
{
	node_t *node1 = (node_t *)malloc(sizeof(node_t));
	node_t *node2 = (node_t *)malloc(sizeof(node_t));
	node_t *node3 = (node_t *)malloc(sizeof(node_t));
	node_t *node4 = (node_t *)malloc(sizeof(node_t));
	node_t *node5 = (node_t *)malloc(sizeof(node_t));
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	return node1;
}


/******************************* ListRemove ***********************************/

void ListRemove(node_t *head)
{
	node_t *p_next = NULL;
	node_t *p_iter = head;
	int counter = 5;
	
	if (HasLoop(head))
	{
		while (counter)
		{
			p_next = p_iter->next;
			free(p_iter);
			p_iter = p_next;
			counter--;
		}
	}
	else 
	{
		while (NULL != p_iter)
		{
			p_next = p_iter->next;
			free(p_iter);
			p_iter = p_next;
			counter--;
		}
	}
	head = NULL;
}


/******************************* ListCount ************************************/

size_t ListCount(node_t *head)
{
	size_t count = 0;
	node_t *current = head;
	
	while(NULL != current->next)
	{
		++count;
		current = current->next;
	}
	return count;
}



