#include <stdlib.h>
#include <stdio.h>

#include "linklist.h"

int main(int argc, char* argv[]) {
    Node* node = new_Node(5); 
    printf("Deleting Node: %d\n",delete_Node(node));
    Node* node1 = (Node*)calloc(1,sizeof(Node));
    int successIsZero = init_Node(node1, 6);
    printf("Creating List: %d\n",successIsZero);
    printf("Deleting List: %d\n",delete_Node(node1));
   

    List* list = new_List();
    printf("Printing new List: ");
    List_print(list);
    printf("Deleting List: %d\n",delete_List(list));

    printf("Adding items to new list\n");
    List* list1 = (List*)calloc(1,sizeof(List));
    init_List(list1);
    
    printf("adding 5 to list: %d\n",List_append(list1,5));
    printf("adding 7 to list: %d\n",List_append(list1,7));
    List_print(list1);
    printf("Clearing List: %d\n",List_clear(list1));
    printf("printing cleared list: ");
    List_print(list1);
    printf("Deleting List: %d\n",delete_List(list1));

    List* list2 = new_List();
    printf("Printing new List: ");
    List_print(list2);
    printf("adding 5 to list: %d\n",List_append(list2,5));
    printf("adding 7 to list: %d\n",List_append(list2,7));
    List_print(list2);
    printf("prepending 4 to list: %d\n",List_prepend(list2,4));
    List_print(list2);
    printf("Deleting List: %d\n",delete_List(list2));

    List* list3=NULL;
    List_append(list3,1);
    List_append(list3,2);
    List_append(list3,3);
    printf("List3: \n");
    List_print(list3);
    List* list4=new_List();
    List_append(list4,4);
    List_append(list4,5);
    List_append(list4,6);
    printf("List4: \n");
    List_print(list4);
    printf("extending list3 by list4: %d\n",List_extend(list3,list4));
    printf("New List 3: \n");
    List_print(list3);
    for(int y=0;y<=5;y++){
        printf("Is the value %d in list3: %d (1 is true, 0 is false)\n",y,List_contains(list3,y));
    }
    delete_List(list3);
    delete_List(list4);

    List* list5=new_List();
    printf("%d\n",List_append(list5,50));
    printf("%d\n",List_append(list5,60));
    printf("%d\n",List_append(list5,70));
    printf("Printing List5: ");
    List_print(list5);
    printf("Value at index -1: %d\n",List_get(list5,-1));
    for(int x=0;x<=list5->length;x++){
        printf("Value at index %d: %d\n",x,List_get(list5,x));
    }
    delete_List(list5);

    List* list6=new_List();
    for(int num2=0;num2<=3;num2++){
        List_append(list6,1);
        List_append(list6,2);
        List_append(list6,3);
        printf("New List6: \n");
        List_print(list6);
        printf("Inserting value 5 into index %d : %d\n",num2,List_insert(list6,num2,5));
        List_print(list6);
        List_clear(list6);
        printf("\n\n");
    }
    delete_List(list6);

    List* list7=new_List();
    for(int num2=0;num2<=3;num2++){
        List_append(list7,1);
        List_append(list7,2);
        List_append(list7,3);
        printf("New List7: \n");
        List_print(list7);
        printf("setting value 5 as index %d : %d\n",num2,List_set(list7,num2,5));
        List_print(list7);
        List_clear(list7);
        printf("\n\n");
    }
    delete_List(list7);

    List* list8=new_List();
    for(int num3=0;num3<=6;num3++){
        List_append(list8,0);
        List_append(list8,1);
        List_append(list8,2);
        List_append(list8,3);
        List_append(list8,4);
        List_append(list8,5);

        printf("List8: \n");
        List_print(list8);
        printf("removing index %d from list 8: %d\n",num3,List_remove(list8,num3));
        List_print(list8);
        printf("\n");
        List_clear(list8);
    }
    delete_List(list8); 

    Node* node2=NULL;
    printf(" deleting null node: %d \n",delete_Node(node2));
    List* list9=NULL;
    printf(" extending null lists: %d \n",List_extend(list9,list8));
    printf(" appending to null list: %d\n",List_append(list9,1));
    printf(" getting element from null list: %d \n",List_get(list9,1));
    printf(" removing from null list: %d\n",List_remove(list9,2));
    printf("printing null list:");
    List_print(list9);
    printf(" appending to null list: %d\n",List_append(list9,1));
    printf(" clearing null list: %d\n",List_clear(list9));


    return EXIT_SUCCESS;
}