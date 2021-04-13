/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>      // malloc , free 함수 사용 위해 헤더 파일 포함

/* 필요한 헤더파일 추가 */

typedef struct Node {         // 노드 구조체 정의
   int key;               // 사용자가 입력한 값, 데이터를 저장할 멤버.
   struct Node* link;         // 다음 노드의 주소를 저장할 포인터
} listNode;

typedef struct Head {
   struct Node* first;         // 리스트 시작을 나타내는 first 노드의 구조체 정의
}headNode;


/* 함수 리스트 */
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
   printf("\t[-----[이 명 국]  [2017038100]-----]\n");
   
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

   /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
   if(h != NULL)
      freeList(h);

   /* headNode에 대한 메모리를 할당하여 리턴 */
   headNode* temp = (headNode*)malloc(sizeof(headNode));
   temp->first = NULL;
   return temp;
}

int freeList(headNode* h){
   /* h와 연결된 listNode 메모리 해제
    * headNode도 해제되어야 함.
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
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {         // f 입력시 실행 메소드 

   listNode* node = (listNode*)malloc(sizeof(listNode));      // node 생성
   node->key = key;      // 데이터 저장

   node->link = h->first;   
   h->first = node;
   

   return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
   
   return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));   // 신규 노드 지정 후 node의 데이터 공간을 메모리에 할당 받아 node에 저장.
   listNode* lastnode;         // 노드 존재시 마지막 노드 정의.
   node -> key = key;         // node 필드에 key를 저장
   node ->link = NULL;         // key 저장 후 아직 가리키는 노드가 없기때문에 NULL 할당

   if(h -> first == NULL ){   // NULL일 경우
      h -> first = node;      // 헤드 노드가 node를 가리킴
      return 0;            // 종료
   }
   
   // 마지막 노드를 찾는 반복문
   lastnode = h -> first;      // 헤드 노드인 h 부터 시작 first를 따라 다음 노드로 이동   
   while(lastnode -> link != NULL ){      // lastnode가 NULL이 아닐때까지 반복
      lastnode = lastnode -> link;      // 마지막 링크 값을 찾는다.
   }
   lastnode -> link = node;         // lastnode가 node를 가리키게 선언.
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {


   return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

   return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
   listNode* frontnode;
   listNode* delLastnode;
   if(h -> first == NULL)
   {   // 삭제할 노드가 없을 경우 종료
      printf("삭제할 마지막 노드가 없습니다.\n");
      return 0;
   } 

   else if(h -> first -> link == NULL){         // 리스트에 노드가 1개일때
      freeList(h);                  // 할당 메모리 해제
      h -> first = NULL;               // head를 NULL로 지정
      return 0;                     // 종료
   }
   else{                           // 2개 이상의 노드가 있을 경우
      frontnode = h -> first;               // 삭제할 delLastnode 앞의 frontnode를 첫번째 노드로 설정 
      delLastnode = h -> first -> link;      // 삭제할 노드를 두번째 노드로 설정
      while(delLastnode -> link != NULL){      // 삭제할 노드가 NULL이 아닐때까지 
         frontnode = delLastnode;         // frontnode와 delLastnode를 뒤로 이동
         delLastnode = delLastnode -> link;
      }
      free(delLastnode);                  // 마지막 노드 발견시 마지막 노드 메모리 반환
      frontnode -> link = NULL;            // frontnode가 delLastnode에 가리키는 링크 NULL 지정
   }
}


/**
 * 리스트의 링크를 역순으로 재 배치
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
