/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>      // malloc , free �Լ� ��� ���� ��� ���� ����

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
   
   char command;        // ����ڷκ��� �޴� ������ ���� ���� �޴� ���� ����
   int key;             // ����Ʈ�� �� ��, data�� �����ϴ� ���� ����
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
      case 'z': case 'Z':                 // �ʱ�ȭ �ϴ� �޴�
         headnode = initialize(headnode);
         break;
      case 'p': case 'P':                 // ����Ʈ ��� �޴�
         printList(headnode);
         break;
      case 'i': case 'I':                 // ��� �� �Է� �޴�
         printf("Your Key = ");
         scanf("%d", &key);               // ��忡 �� �� �Է�
         insertNode(headnode, key);
         break;
      case 'd': case 'D':                 // ��� ���� �޴�
         printf("Your Key = ");
         scanf("%d", &key);               // �����ϰ��� �ϴ� ��� �� �Է�
         deleteNode(headnode, key);
         break;
      case 'n': case 'N':                 // ����Ʈ�� �������� ���� �ִ� �޴�
         printf("Your Key = ");
         scanf("%d", &key);               // ������ ����Ʈ�� �� ��� �� �Է�
         insertLast(headnode, key);
         break;
      case 'e': case 'E':                 // ������ ��� �� �����ϴ� �޴�
         deleteLast(headnode);
         break;
      case 'f': case 'F':                 // ù ��忡 �� �� �Է� �޴�
         printf("Your Key = ");
         scanf("%d", &key);               // ù ��忡 �� �� �Է�
         insertFirst(headnode, key);
         break;
      case 't': case 'T':                 // ù ��� �� �����ϴ� �޴�
         deleteFirst(headnode);
         break;
      case 'r': case 'R':                 // ����Ʈ�� ��带 �������� ��ȯ�ϴ� �޴�
         invertList(headnode);
         break;
      case 'q': case 'Q':                 // ����Ʈ�� �Ҵ�� �޸𸮸� ��ȯ�ϰ� �����ϴ� �޴�
         freeList(headnode);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}

headNode* initialize(headNode* h) {		// ����Ʈ �ʱ�ȭ�ϱ� ���� �޼ҵ�

   /* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
   if(h != NULL)
      freeList(h);

   /* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
   headNode* temp = (headNode*)malloc(sizeof(headNode));		//temp��� ��� ����
   temp->first = NULL;                          // temp����� first �� NULLó���� �ʱ�ȭ
   return temp;
}

int freeList(headNode* h){             // ����Ʈ�� ��忡 �Ҵ�� �޸𸮸� ��ȯ���ִ� �޼ҵ�
   /* h�� ����� listNode �޸� ����
    * headNode�� �����Ǿ�� ��.
    */
   listNode* p = h->first;          // ��� p�� ��� �� first ����

   listNode* prev = NULL;           // prev��� ��忡 NULL ����
   while(p != NULL) {               // ��� P�� NULL�� �ƴҶ����� �ݺ�
      prev = p;                     
      p = p->link;
      free(prev);                   // prev ��忡 �Ҵ�� �޸� ��ȯ
   }
   free(h);                         // ��尪 ��ȯ
   return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {         // f �Է½� ���� �޼ҵ� 

   listNode* node = (listNode*)malloc(sizeof(listNode));      // ���� �޸� �Ҵ��Ͽ� node ����
   node->key = key;      // node�� ������ �ʵ忡 �Էµ� ������ ����

   node->link = h->first;   // node�� linke�� h�� first ����
   h->first = node;         // ���۳��� node�� ����
   

   return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
   /*listNode* newNode;
   listNode* temp = h->first;

   int max_val = temp ->key;
   for(temp; temp !=NULL; temp = temp->link)
      if (max_val <temp->key)
      newNode->link = NULL;
      h->first->link = newNode;
      printf("%d", max_val);*/
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));   // �ű� ��� ���� �� node�� ������ ������ �޸𸮿� �Ҵ� �޾� node�� ����.
   listNode* lastNode;         // ��� ����� ������ ��� ����.
   node -> key = key;         // node �ʵ忡 key�� ����
   node ->link = NULL;         // key ���� �� ���� ����Ű�� ��尡 ���⶧���� NULL �Ҵ�

   if(h -> first == NULL ){   // NULL�� ���
      h -> first = node;      // ��� ��尡 node�� ����Ŵ
      return 0;            // ����
   }
   
   // ������ ��带 ã�� �ݺ���
   lastNode = h -> first;      // ��� ����� h ���� ���� first�� ���� ���� ���� �̵�   
   while(lastNode -> link != NULL ){      // lastnode�� NULL�� �ƴҶ����� �ݺ�
      lastNode = lastNode -> link;      // ������ ��ũ ���� ã�´�.
   }
   lastNode -> link = node;         // �ش� ���� ������ ���� ���� �̵�
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
   listNode* trail;
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
   else{                 
   trail = h -> first;              // ���۳�带 trail�� ����
   h -> first = trail ->link;       // ���۳�带 trail�� ���� link�� ����
   
   }
   return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {          // ���ϴ� ��� �� �����ϴ� �޼ҵ�
  listNode *find = h -> first;                  // find ��尡 first�� ����Ų��
  listNode *frontfind;                          // ���� ��ų ���
  if(h->first->link == NULL)                    // head�� ù ������ Ž�� ����
  {
     printf("����� �����Ͱ� �����ϴ� !\n");
  }
  else{
     while(find->link!=NULL){                    // find�� link�� NULL�� �ɶ����� ����.
        if (find-> link-> key == key)            // �Է��� key ���� ���� ����� ���� �ִٸ�
        {
           frontfind = find ->link;              // ã�����ϴ� ���� frontfind�� ����Ų��.
           find -> link = find ->link->link;     // �����ϰ����ϴ� ����� �翷�� �̾��ش�.
           free(frontfind);                      // ��� ��带 ������Ų��.
           printf("%d\n", key);
           return 0;
        }
        find = find -> link;                      // ã�� ���� ������ ���� �����ͷ� �Ѿ��.
     }
     if (find == NULL) printf("ã�� �����Ͱ� �����ϴ�\n");
  }
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {          // ������ ��� �����ϴ� �޼ҵ�
   listNode* frontnode;                // ������ ����
   listNode* delLastnode;              // �����ϰ��ϴ� ���� ����Ű�� ��� ����
   if(h -> first == NULL)
   {   // ������ ��尡 ���� ��� ����
      printf("������ ������ ��尡 �����ϴ�.\n");
      return 0;
   } 

   else if(h -> first -> link == NULL){         // ����Ʈ�� ��尡 1���϶�
      freeList(h);                  // �Ҵ� �޸� ����
      h -> first = NULL;               // head�� first�� NULL�� ����
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
int invertList(headNode* h) {          // ����Ʈ�� �������� ��ġ�ϴ� �޼ҵ�
      listNode* one;                   // ��� one, two, three ����
      listNode* two;
      listNode* three;

      one = h -> first;                // one �����͸� ù��° ��忡 ����
      two = NULL;
      three = NULL;

      while (one != NULL){             // one�� ���� NULL�� �ƴҵ��� �ݺ�
         three = two;                  // three�� two�� ����Ű�� ��忡 ����
         two = one;                    // two ��带 one�� ����Ű�� ��忡 ����
         one = one -> link;            // one ��带 ���� ���� �̵�
         two -> link = three;          // three�� ���� two ��ũ �ʵ忡 ����
      }
      h -> first = two;                // ���� ��带 two�� ����
}


void printList(headNode* h) {          // ����Ʈ�� ����ϴ� �޼ҵ�
   int i = 0;
   listNode* p;

   printf("\n---PRINT\n");

   if(h == NULL) {                       // ����� ����Ʈ ���� ������ ���
      printf("Nothing to print....\n");
      return;
   }

   p = h->first;                       // p�� ���� ���� ����

   while(p != NULL) {
      printf("[ [%d]=%d ] ", i, p->key);  // ��� ���� ��ȣ�� �� �� ���
      p = p->link;
      i++;
   }

   printf("  items = %d\n", i);
}
