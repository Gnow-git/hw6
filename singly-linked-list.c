/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>      // malloc , free 함수 사용 위해 헤더 파일 포함

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
   
   char command;        // 사용자로부터 메뉴 선택을 위한 값을 받는 변수 선언
   int key;             // 리스트에 들어갈 값, data를 저장하는 변수 선언
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
      case 'z': case 'Z':                 // 초기화 하는 메뉴
         headnode = initialize(headnode);
         break;
      case 'p': case 'P':                 // 리스트 출력 메뉴
         printList(headnode);
         break;
      case 'i': case 'I':                 // 노드 값 입력 메뉴
         printf("Your Key = ");
         scanf("%d", &key);               // 노드에 들어갈 값 입력
         insertNode(headnode, key);
         break;
      case 'd': case 'D':                 // 노드 삭제 메뉴
         printf("Your Key = ");
         scanf("%d", &key);               // 삭제하고자 하는 노드 값 입력
         deleteNode(headnode, key);
         break;
      case 'n': case 'N':                 // 리스트의 마지막에 값을 넣는 메뉴
         printf("Your Key = ");
         scanf("%d", &key);               // 마지막 리스트에 들어갈 노드 값 입력
         insertLast(headnode, key);
         break;
      case 'e': case 'E':                 // 마지막 노드 값 삭제하는 메뉴
         deleteLast(headnode);
         break;
      case 'f': case 'F':                 // 첫 노드에 들어갈 값 입력 메뉴
         printf("Your Key = ");
         scanf("%d", &key);               // 첫 노드에 들어갈 값 입력
         insertFirst(headnode, key);
         break;
      case 't': case 'T':                 // 첫 노드 값 삭제하는 메뉴
         deleteFirst(headnode);
         break;
      case 'r': case 'R':                 // 리스트의 노드를 역순으로 변환하는 메뉴
         invertList(headnode);
         break;
      case 'q': case 'Q':                 // 리스트에 할당된 메모리를 반환하고 종료하는 메뉴
         freeList(headnode);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}

headNode* initialize(headNode* h) {		// 리스트 초기화하기 위한 메소드

   /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
   if(h != NULL)
      freeList(h);

   /* headNode에 대한 메모리를 할당하여 리턴 */
   headNode* temp = (headNode*)malloc(sizeof(headNode));		//temp라는 노드 생성
   temp->first = NULL;                          // temp노드의 first 값 NULL처리로 초기화
   return temp;
}

int freeList(headNode* h){             // 리스트와 노드에 할당된 메모리를 반환해주는 메소드
   /* h와 연결된 listNode 메모리 해제
    * headNode도 해제되어야 함.
    */
   listNode* p = h->first;          // 노드 p에 헤드 값 first 지정

   listNode* prev = NULL;           // prev라는 노드에 NULL 지정
   while(p != NULL) {               // 노드 P가 NULL이 아닐때까지 반복
      prev = p;                     
      p = p->link;
      free(prev);                   // prev 노드에 할당된 메모리 반환
   }
   free(h);                         // 헤드값 반환
   return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {         // f 입력시 실행 메소드 

   listNode* node = (listNode*)malloc(sizeof(listNode));      // 동적 메모리 할당하여 node 생성
   node->key = key;      // node의 데이터 필드에 입력된 데이터 저장

   node->link = h->first;   // node의 linke가 h의 first 지정
   h->first = node;         // 시작노드로 node를 지정
   

   return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
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
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));   // 신규 노드 지정 후 node의 데이터 공간을 메모리에 할당 받아 node에 저장.
   listNode* lastNode;         // 노드 존재시 마지막 노드 정의.
   node -> key = key;         // node 필드에 key를 저장
   node ->link = NULL;         // key 저장 후 아직 가리키는 노드가 없기때문에 NULL 할당

   if(h -> first == NULL ){   // NULL일 경우
      h -> first = node;      // 헤드 노드가 node를 가리킴
      return 0;            // 종료
   }
   
   // 마지막 노드를 찾는 반복문
   lastNode = h -> first;      // 헤드 노드인 h 부터 시작 first를 따라 다음 노드로 이동   
   while(lastNode -> link != NULL ){      // lastnode가 NULL이 아닐때까지 반복
      lastNode = lastNode -> link;      // 마지막 링크 값을 찾는다.
   }
   lastNode -> link = node;         // 해당 사항 없을시 다음 노드로 이동
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
   listNode* trail;
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
   else{                 
   trail = h -> first;              // 시작노드를 trail에 지정
   h -> first = trail ->link;       // 시작노드를 trail의 다음 link에 지정
   
   }
   return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {          // 원하는 노드 값 삭제하는 메소드
  listNode *find = h -> first;                  // find 노드가 first를 가리킨다
  listNode *frontfind;                          // 삭제 시킬 노드
  if(h->first->link == NULL)                    // head의 첫 노드부터 탐색 시작
  {
     printf("저장된 데이터가 없습니다 !\n");
  }
  else{
     while(find->link!=NULL){                    // find의 link가 NULL이 될때까지 돈다.
        if (find-> link-> key == key)            // 입력한 key 값과 같은 노드의 값이 있다면
        {
           frontfind = find ->link;              // 찾고자하는 값을 frontfind로 가리킨다.
           find -> link = find ->link->link;     // 삭제하고자하는 노드의 양옆을 이어준다.
           free(frontfind);                      // 대상 노드를 삭제시킨다.
           printf("%d\n", key);
           return 0;
        }
        find = find -> link;                      // 찾는 값이 없으면 다음 데이터로 넘어간다.
     }
     if (find == NULL) printf("찾는 데이터가 없습니다\n");
  }
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {          // 마지막 노드 삭제하는 메소드
   listNode* frontnode;                // 선행노드 선언
   listNode* delLastnode;              // 삭제하고하는 곳을 가리키는 노드 선언
   if(h -> first == NULL)
   {   // 삭제할 노드가 없을 경우 종료
      printf("삭제할 마지막 노드가 없습니다.\n");
      return 0;
   } 

   else if(h -> first -> link == NULL){         // 리스트에 노드가 1개일때
      freeList(h);                  // 할당 메모리 해제
      h -> first = NULL;               // head의 first를 NULL로 지정
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
int invertList(headNode* h) {          // 리스트를 역순으로 배치하는 메소드
      listNode* one;                   // 노드 one, two, three 생성
      listNode* two;
      listNode* three;

      one = h -> first;                // one 포인터를 첫번째 노드에 설정
      two = NULL;
      three = NULL;

      while (one != NULL){             // one의 값이 NULL이 아닐동안 반복
         three = two;                  // three를 two가 가리키는 노드에 지정
         two = one;                    // two 노드를 one이 가리키는 노드에 지정
         one = one -> link;            // one 노드를 다음 노드로 이동
         two -> link = three;          // three의 값을 two 링크 필드에 설정
      }
      h -> first = two;                // 시작 노드를 two로 변경
}


void printList(headNode* h) {          // 리스트를 출력하는 메소드
   int i = 0;
   listNode* p;

   printf("\n---PRINT\n");

   if(h == NULL) {                       // 저장된 리스트 값이 없을때 출력
      printf("Nothing to print....\n");
      return;
   }

   p = h->first;                       // p를 시작 노드로 지정

   while(p != NULL) {
      printf("[ [%d]=%d ] ", i, p->key);  // 노드 순서 번호와 그 값 출력
      p = p->link;
      i++;
   }

   printf("  items = %d\n", i);
}
