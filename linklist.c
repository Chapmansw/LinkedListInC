/**
 * @file datelib.c
 * @author Samuel Chapman
 * @date 2026-03-27
 * @brief Linked List Project
 * 
 */
#include "linklist.h"


# define FUNCTION_SUCCESS 0
# define FUNCTION_FAILURE 1

/**
 * @brief Initialize an existing Node pointer.
 * 
 * When a node is initialized its value should be set to the given val, and the 
 * next node should be reset to NULL.
 * 
 * @param node  An existing Node to be initialized
 * @param data  The value to be stored in this node
 * @return 0 if the operation was successful otherwise 1 (e.g. null node)
 */
int init_Node(Node* node, int data) {
    if(node!=NULL){
        node->data=data;
        node->next=NULL;
        return FUNCTION_SUCCESS;
    }
    return FUNCTION_FAILURE; 
}

/**
 * @brief Allocates memory and initializes a new Node with the given value.
 * 
 * @param data  The value to be stored in this node
 */
Node* new_Node(int data) {
    Node* newNode=(Node*)calloc(1,sizeof(Node));//allocate memory for the node
    int e=init_Node(newNode,data);
    if(e==FUNCTION_SUCCESS){//if successfully initialized the node, return the node
        return newNode;
    }    
    return NULL;
}

/**
 * @brief Deletes a node and frees the memory allocated for it.
 * 
 * @param node  The node to be deleted
 * @return 0 if the operation was successful otherwise 1 (e.g. null node)
 */
int delete_Node(Node* node) {
    if(node!=NULL){
        free(node);//free memory allocated for it
        node=NULL;//set the node to NULL
        return FUNCTION_SUCCESS;
    }
    return FUNCTION_FAILURE;
}

/**
 * @brief Initialize a list that already exists in memory.
 * 
 * @param list the list to be initialized
 * @return 0 if the operation was successful otherwise 1 (e.g. null list)
 */
int init_List(List* list) {
    if(list!=NULL){
        list->length=0;
        list->head=NULL;//empty List on ititializing, so the head is null
        return FUNCTION_SUCCESS;
    }
    return FUNCTION_FAILURE;
}

/**
 * @brief Allocate memory and create a new empty list.
 * 
 * @return List* to the newly created list
 */
List* new_List() {
    List* list=(List*)calloc(1,sizeof(List));//allocate memory for the list
    init_List(list);//initialize the list
    return list;
}

/**
 * @brief Prints out an entire list
 * 
 * @param list the list to be printed
 */
void List_print(List* list) {
    if (list == NULL) {
        printf("NULL\n");
    } else {
        Node* cursor = list->head;//start of list
        printf("[ ");
        while (cursor != NULL) {//cycle through the entire list
            printf("%d ", cursor->data);
            cursor = cursor->next;
        }
        printf("]\n");
    }
}

/**
 * @brief Appends the given value to the list.
 * 
 * When a value is appended to a list, it should become the last item in the 
 * list and the length of the list should increase by one. This should function 
 * the same as the add method of Java's LinkedList with no index argument.
 * 
 * @param list The list to which a value should be appended.
 * @param data  The value to be appended to the list
 * @return 0 if the operation was successful otherwise 1 (e.g. null list)
 */
int List_append(List* list, int data) {
    if(list!=NULL){
        Node* newNode=new_Node(data);
        if(list->head!=NULL){//if there are other items in the list
            Node* nextValidNode=list->head;
            while(true){
                if(nextValidNode->next!=NULL){
                    nextValidNode=nextValidNode->next;
                }
                else{
                    break;
                }
            }//now at the end of the list
            nextValidNode->next=newNode;//set the newNode as next element of the list the list
        }
        else{//if there are no elements currently in the list
            list->head=newNode;//set newNode as the first node
        }
        list->length=list->length+1;//adjust length
        return FUNCTION_SUCCESS;
    }
    return FUNCTION_FAILURE;
}

/**
 * @brief Prepends the given value to the list.
 * 
 * When a value is prepended to a list, it should become the first item in the 
 * list and the length of the list should increase by one and all the old values 
 * should follow the new one maintaining their order. This should function the 
 * same as the add method of Java's LinkedList with 0 as the index argument.
 * 
 * @param node The list to which the value will be appended.
 * @param data The value to be prepended to the list
 * @return 0 if the operation was successful otherwise 1 (e.g. null list)
 */
int List_prepend(List* list, int data) {
    if(list!=NULL){
        Node* newNode=new_Node(data);
        if(list->head!=NULL){//if there are currently items in the list
            Node* headNode=list->head;//store the current start of list
            list->head=newNode;//set the newNode as the start of the list
            list->head->next=headNode;//set the current start (and rest) of the list to be after the new head of the list
            list->length=list->length+1;//adjust length
            if(list->head->data==data && list->head->next->data==headNode->data){//if the list is shifted correctly
                return FUNCTION_SUCCESS;
            }
        }else{//if there are no other items in the list
            list->head=newNode;
            list->length=1;
            return FUNCTION_SUCCESS;
        }
    }
    return FUNCTION_FAILURE;
}

/**
 * @brief Extends list A by adding all elements of list B to the end in order
 * 
 * When a list is extended with another list, all the elements in the second 
 * list are effectively appended to the first list. These elements maintain the 
 * same order they had in their original list.
 * 
 * @param listA The list to be extended
 * @param listB The list to be added to the end of list A
 * @return 0 if the operation was successful otherwise 1 (e.g. null list)
 */
int List_extend(List* listA, List* listB) {
    if(listA!=NULL && listB!=NULL){
        Node* lastValidNode=listA->head;
        while(true){//get to the last NOT NULL node of the list
            if(lastValidNode->next!=NULL){
                lastValidNode=lastValidNode->next;
            }
            else{
                break;
            }
        }
        lastValidNode->next=listB->head;//set the next Node of the last valid node of List A to be the start of List B, combining them. 
        listA->length=listA->length+listB->length;//combine lengths of lists
        return FUNCTION_SUCCESS;   
    }
    return FUNCTION_FAILURE; // TODO: complete this stub
}

/**
 * @brief Checks whether or not the given list contains the given value
 * 
 * This function should set errno to EFAULT for bad address if list is NULL.
 * 
 * @param list   The list to be checked for the item
 * @param value  The value for which the list should be searched
 * @return true  If the list contains the item
 * @return false If the list does not contain the item
 */
bool List_contains(List* list, int value) {
    if(list==NULL){//if list is null
        errno=EFAULT;
        return false;
    }    
    if(list->head==NULL){//if there are no items in the list
        return false;
    }
    Node* nextValidNode=list->head;
    while(true){
        if(nextValidNode->data==value){//check if the node is the value
            return true;
        }
        if(nextValidNode->next!=NULL){//if not, if there is a next node, check that too
            nextValidNode=nextValidNode->next;
        }else{
            return false;//repeat until there are no new nodes, but the current node is NOT the value either.
        }
    }
}

/**
 * @brief Returns the value of the ith node in the list.
 * 
 * This function should set errno to EFAULT for bad address if list is NULL.
 * 
 * This function should set errno to EINVAL for invalid argument 
 * if the index is out of bounds
 * 
 * @param list  The list to be indexed for the element
 * @param index The index of the node to be retrieved
 * @return      The value in the node at the index
 */
int List_get(List* list, size_t index) {
    if(list==NULL){//if list is null
        errno=EFAULT;
        return -1;
    }
    if(index>=list->length||index<0){//if invalid index
        errno=EINVAL;
        return -1;
    }
    Node* node=list->head;
    for(int x=1;x<=index;x++){//cycle through each Node of the list
        node=node->next;
    }//now node is the node at the index
    return node->data;
}

/**
 * @brief Changes the value of the ith node in the list.
 * 
 * This function should set errno to EFAULT for bad address if list is NULL.
 * 
 * This function should set errno to EINVAL for invalid argument 
 * if the index is out of bounds
 * 
 * @param list  The list to be indexed and modified
 * @param index The index of the node to be modified
 * @param value The value that should now be stored at this index
 * @return      0 if the operation was successful otherwise 1 (e.g. null list or out of bounds)
 */
int List_set(List* list, size_t index, int value) {
    if(list==NULL){//if invalid list
        errno=EFAULT;
        return FUNCTION_FAILURE;
    }
    if(index>=list->length||index<0){//if invalid index
        errno=EINVAL;
        return FUNCTION_FAILURE;
    }
    Node* node=list->head;
    for(int x=0;x<index;x++){//cycle through the nodes
        node=node->next;
    }//now at the node at the index
    node->data=value;//set the data of the node to be value
    return FUNCTION_SUCCESS;
}

/**
 * @brief Inserts a new value into the list at a particular position shifting 
 *        any items at later indices further down in the list to make space.
 * 
 * This function should set errno to EFAULT for bad address if list is NULL.
 * 
 * This function should set errno to EINVAL for invalid argument 
 * if the index is out of the range 0 -> list->length (inclusive)
 * 
 * @param list  The list into which the new node will be inserted
 * @param index The index where the new value should be inserted [0, list->length]
 * @param value The value to be inserted into the list
 * @return      Returns 0 if operation was successful, otherwise 1
 */
int List_insert(List* list, size_t index, int value) {
    if(list==NULL){//if invalid list
        errno=EFAULT;
        return FUNCTION_FAILURE;
    }
    if(index>list->length||index<0){//if invalid index
        errno=EINVAL;
        return FUNCTION_FAILURE;
    }
    if(index==0){//if inserting as the first item of the list (appending)
        List_prepend(list,value);
    }
    else if(index==list->length){//if adding to the end of the list (appending)
        List_append(list,value);
    }
    else{
        Node* nodeBeforeIndex=list->head;
        for(int x=0;x<index-1;x++){
            nodeBeforeIndex=nodeBeforeIndex->next;
        }//now at the node before the index
        Node* nodeAtIndex=nodeBeforeIndex->next;//get what used to be at the index
        Node* newNode=new_Node(value);//make a new node
        nodeBeforeIndex->next=newNode;//set the new node to be at the index
        newNode->next=nodeAtIndex;//make the newNode point to what used to be at the index
        list->length=list->length+1;//increment length
    }
    if(List_get(list,index)==value){//if the value is actually the data of the node at the index in the list
        return FUNCTION_SUCCESS;
    }
    return FUNCTION_FAILURE;
}

/**
 * @brief Removes and returns the value of the Node at the given index.
 * 
 * This function will remove the Node at the specified index from the list, 
 * safely free the memory allocated for that node, and return the value stored 
 * in that node.
 * 
 * This function should set errno to EFAULT for bad address if list is NULL.
 * 
 * This function should set errno to EINVAL for invalid argument 
 * if the index is out of bounds
 * 
 * @param list  The list from which a node will be removed
 * @param index The index of the node to be removed
 * @return      The value in the node at index i (if any)
 */
int List_remove(List* list, size_t index) {
    //error handling
    if(list==NULL){//if the list is null
        errno=EFAULT;
        return FUNCTION_FAILURE;
    }
    if(index>=list->length||index<0){//if invalid index
        errno=EINVAL;
        return FUNCTION_FAILURE;
    }
    Node* nodeAfterIndex; 
    if(index>0){
        Node* nodeBeforeIndex=list->head;
        for(int x=0;x<index-1;x++){
            nodeBeforeIndex=nodeBeforeIndex->next;
        }//now at the node before the index

        Node* nodeAtIndex=nodeBeforeIndex->next;//get the node at the index
        nodeAfterIndex=nodeAtIndex->next;//get the node after the index
        nodeBeforeIndex->next=nodeAfterIndex;//set the node before the index to connect to the node after the index, cutting off the node at the index
        delete_Node(nodeAtIndex);//delete the nodeAtIndex
        nodeAtIndex=NULL;
    }
    else{//if the index is 0
        nodeAfterIndex=list->head->next;
        delete_Node(list->head);//delete the current head node
        list->head=nodeAfterIndex;//set the head to the element after the old head
    }
    list->length=list->length-1;//update length
    return FUNCTION_SUCCESS;
}

/**
 * @brief deletes all nodes from a starting point (inclusive)
 * 
 * @param node to start deleting notes
 */
void freeNodes(Node* node){
    if(node==NULL){//BASE CASE
        return;
    }
    // printf("\tstarted freeing %d\n", node->data);
    freeNodes(node->next);//Free the next node
    // printf("\tfinished freeing %d\n", node->data);
    delete_Node(node);//delete the node
}

/**
 * @brief Safely removes and frees memory for all nodes in the list
 * 
 * This function should call delete_Node to safely free memory for every Node in 
 * the list, be careful to ensure that every node is freed without losing track 
 * of later nodes in the list. Once all pointers to a node are lost it cannot be 
 * safely freed!
 * 
 * @param list the list to be reset to an empty list
 * @return 0 if the operation was successful otherwise 1 (e.g. null list)
 */
int List_clear(List* list) {
    if(list!=NULL){
        //printf("freeing nodes\n");
        freeNodes(list->head);//clear all nodes
        //printf("finished freeing nodes\n");
        list->head=NULL;//set head to NULL (currently a pointer that points to NULL)
        list->length=0;//update length
        return FUNCTION_SUCCESS;
    }
    return FUNCTION_FAILURE;
}

/**
 * @brief Safely deletes an entire list freeing memory for all nodes.
 * 
 * @param list the list to be deleted
 * @return 0 if the operation was successful otherwise 1 (e.g. null list)
 */
int delete_List(List* list) {
    if(list!=NULL){
        List_clear(list);//deallocate memory for the nodes, remove the nodes, deinitialize the list
        free(list);//deallocate memory for the list
        list=NULL;//set the List to null
        return FUNCTION_SUCCESS; 
    }
    return FUNCTION_FAILURE;
}