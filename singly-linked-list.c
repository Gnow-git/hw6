/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>      // malloc , free �Լ� ��� ���� ��� ���� ����

/* �ʿ��� ������� �߰� */

typedef struct Node {         // ��� ����ü ����
   int key;               // ����ڰ� �Է��� ��, �����͸� ������ ���.
   struct Node* link;         // ���� ����� �ּҸ� ������ ������
} listNode;

typedef struct Head {
   struct Node* first;         // ����Ʈ ������ ��Ÿ���� first ����� ����ü ����
}headNode;


/* �Լ� ����Ʈ */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
   printf("\t[-----[�� �� ��]  [2017038100]-----]\n");
   
   char command;
   int key;
   headNode* headnode=NULL;

   do{
      printf("----------------------------------------------------------------\n");
      printf("                     Singly Linked List                         \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize    = z           Print         = p \n");
      printf(" Insert Node   = i           Delete Node   = d \n");
      printf(" Insert Last   = n           Delete Last   = e\n");
      printf(" Insert First  = f           Delete First  = t\n");
      printf(" Invert List   = r           Quit          = q\n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'z': case 'Z':
         headnode = initialize(headnode);
         break;
      case 'p': case 'P':
         printList(headnode);
         break;
      case 'i': case 'I':
         printf("Your Key = ");
         scanf("%d", &key);
         insertNode(headnode, key);
         break;
      case 'd': case 'D':
         printf("Your Key = ");
         scanf("%d", &key);
         deleteNode(headnode, key);
         break;
      case 'n': case 'N':
         printf("Your Key = ");
         scanf("%d", &key);
         insertLast(headnode, key);
         break;
      case 'e': case 'E':
         deleteLast(headnode);
         break;
      case 'f': case 'F':
         printf("Your Key = ");
         scanf("%d", &key);
         insertFirst(headnode, key);
         break;
      case 't': case 'T':
         deleteFirst(headnode);
         break;
      case 'r': case 'R':
         invertList(headnode);
         break;
      case 'q': case 'Q':
         freeList(headnode);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}

headNode* initialize(headNode* h) {

   /* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
   if(h != NULL)
      freeList(h);

   /* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
   headNode* temp = (headNode*)malloc(sizeof(headNode));
   temp->first = NULL;
   return temp;
}

int freeList(headNode* h){
   /* h�� ����� listNode �޸� ����
    * headNode�� �����Ǿ�� ��.
    */
   listNode* p = h->first;

   listNode* prev = NULL;
   while(p != NULL) {
      prev = p;
      p = p->link;
      free(prev);
   }
   free(h);
   return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {         // f �Է½� ���� �޼ҵ� 

   listNode* node = (listNode*)malloc(sizeof(listNode));      // node ����
   node->key = key;      // ������ ����

   node->link = h->first;   
   h->first = node;
   

   return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
   
   return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));   // �ű� ��� ���� �� node�� ������ ������ �޸𸮿� �Ҵ� �޾� node�� ����.
   listNode* lastnode;         // ��� ����� ������ ��� ����.
   node -> key = key;         // node �ʵ忡 key�� ����
   node ->link = NULL;         // key ���� �� ���� ����Ű�� ��尡 ���⶧���� NULL �Ҵ�

   if(h -> first == NULL ){   // NULL�� ���
      h -> first = node;      // ��� ��尡 node�� ����Ŵ
      return 0;            // ����
   }
   
   // ������ ��带 ã�� �ݺ���
   lastnode = h -> first;      // ��� ����� h ���� ���� first�� ���� ���� ���� �̵�   
   while(lastnode -> link != NULL ){      // lastnode�� NULL�� �ƴҶ����� �ݺ�
      lastnode = lastnode -> link;      // ������ ��ũ ���� ã�´�.
   }
   lastnode -> link = node;         // lastnode�� node�� ����Ű�� ����.
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {


   return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {

   return 0;

}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
   listNode* frontnode;
   listNode* delLastnode;
   if(h -> first == NULL)
   {   // ������ ��尡 ���� ��� ����
      printf("������ ������ ��尡 �����ϴ�.\n");
      return 0;
   } 

   else if(h -> first -> link == NULL){         // ����Ʈ�� ��尡 1���϶�
      freeList(h);                  // �Ҵ� �޸� ����
      h -> first = NULL;               // head�� NULL�� ����
      return 0;                     // ����
   }
   else{                           // 2�� �̻��� ��尡 ���� ���
      frontnode = h -> first;               // ������ delLastnode ���� frontnode�� ù��° ���� ���� 
      delLastnode = h -> first -> link;      // ������ ��带 �ι�° ���� ����
      while(delLastnode -> link != NULL){      // ������ ��尡 NULL�� �ƴҶ����� 
         frontnode = delLastnode;         // frontnode�� delLastnode�� �ڷ� �̵�
         delLastnode = delLastnode -> link;
      }
      free(delLastnode);                  // ������ ��� �߽߰� ������ ��� �޸� ��ȯ
      frontnode -> link = NULL;            // frontnode�� delLastnode�� ����Ű�� ��ũ NULL ����
   }
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
      listNode* one;
      listNode* two;
      listNode* three;

      one = h -> first;
      two = NULL;
      three = NULL;

      while (one != NULL){
         three = two;
         two = one;
         one = one -> link;
         two -> link = three;
      }
      h -> first = two;
}


void printList(headNode* h) {
   int i = 0;
   listNode* p;

   printf("\n---PRINT\n");

   if(h == NULL) {
      printf("Nothing to print....\n");
      return;
   }

   p = h->first;

   while(p != NULL) {
      printf("[ [%d]=%d ] ", i, p->key);
      p = p->link;
      i++;
   }

   printf("  items = %d\n", i);
}
