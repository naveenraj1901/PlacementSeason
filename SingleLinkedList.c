#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *head;

void insert_to_ll(head *l, int n)
{
    head temp = *l;
    head newnode = (head)malloc(sizeof(struct node));
    newnode->data = n;
    if(*l == NULL)
    {
        *l = newnode;
        return;
    }
    else
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
        return;
}

void display_ll(head temp)
{
    printf("\n");
    if(find_ll_is_empty(temp))
        printf("Empty list");
    else{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
    }
}

int find_total_node(head temp)
{
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;   
}

int find_ll_is_empty(head temp)
{
    if(temp == NULL)
        return 1;
    else
        return 0;
}

void find_last_element_in_ll(head temp)
{
    printf("\n");
    if(find_ll_is_empty)
        printf("Empty list");
    else{
    while(temp->next!=NULL)
        temp = temp->next;
    printf("%d\n",temp->data);
    }
}

int find_element_position(head temp, int n)
{
    int count = 1;
    if(temp == NULL)
        return 0;
    else{
    while(temp!=NULL && temp->data != n)
    {
        count++;
        temp = temp->next;
    }
    return count;
    }
}

void insert_at_position(head *l, int pos, int n)
{
    int count = 1;
    head temp = *l;
    head newnode = (head)malloc(sizeof(struct node));
    newnode->data = n;
    if(find_ll_is_empty(*l) && pos == 1)
    {
        *l = newnode;
        newnode->next = NULL;
    }
    else if(pos == 1)
    {
        newnode->next = (*l);
        *l = newnode;
    }
    else if(find_total_node(*l)<pos)
        printf("Position not found");
    else
    {
        while(count == pos)
        {
            count++;
            temp = temp->next;
        }
        newnode->next = temp -> next;
        temp ->next = newnode;
    }
    return;
}

void find_next_element(head temp, int n)
{
    int count = 1, total = find_total_node(temp);
    if(find_ll_is_empty(temp))
        printf("no element found");
    else
    {
        while(temp->data != n)
        {
            count++;
            if(total < count)
            {
                printf("Element not found");
                return;
            }
            else
                temp = temp->next;       
        }
        if(count >= total)
            printf("No elements avoilable after %d",n);
        else if(temp->data == n)
            printf("%d\n",temp->next->data);
    }
}

void find_previous_element(head temp, int n)
{
    int count = 2, total = find_total_node(temp);
    if(find_ll_is_empty(temp))
        printf("no element found");
    else if(total==1 && temp->data == n)
        printf("no element avoilable before %d",n);
    else if(total==1 && temp->data != n)
        printf("Element not found");
    else
    {
        while(temp->next->data != n)
        {
            count++;
            if(total < count)
            {
                printf("Element not found");
                return;
            }
            else
                temp = temp->next;       
        }
        printf("%d\n",temp->data);
    }
}

void delete_element(head *l, int n)
{
    head temp, pos;
    pos = *l;
    if(find_ll_is_empty(*l))
        printf("Empty list");
    else
    {
        if(find_element_position(*l, n) == 1)
        {
            temp = *l;
            *l = (*l)->next;
            free(temp); 
        }
        else
        {
            while(pos!=NULL && pos->next->data != n)
                pos = pos->next;
            if(pos == NULL)
                printf("No element found in the list as %d",n);
            else
            {
                temp = pos->next;
                pos->next = pos->next->next;
                free(temp);
            }
        }
    }
}

void delete_list(head *l)
{
    head temp = *l;
    head pos;
    if(*l == NULL)
        printf("List is Already Empty");
    else
    {
        while(temp!=NULL)
        {
            pos = temp->next;
            free(temp);
            temp = pos;
        }
    }
    (*l) = NULL;   
}

int main()
{
    int ele, pos, ch, tch;
    head h = NULL;
    do{
    printf("\n1  -> Insert\n2  -> display\n3  -> Find total element\n4  -> Find empty\n5  -> Find last element\n6  -> Find elements postion\n7  -> Insert at position\n8  -> find next element\n9  -> find previous element\n10 -> Delete element\n11 -> Delete list");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        scanf("%d",&ele);
        insert_to_ll(&h,ele);
        break;
    case 2:
        display_ll(h);
        break;
    case 3:
        printf("%d\n",find_total_node(h));
        break;
    case 4:
        printf("%d\n",find_ll_is_empty(h));
        break;
    case 5:
        find_last_element_in_ll(h);
        break;
    case 6:
        scanf("%d",&ele);
        printf("%d",find_element_position(h, ele));
        break;
    case 7:
        scanf("%d %d",&pos,&ele);
        insert_at_position(&h, pos, ele);
        break;
    case 8:
        scanf("%d",&ele);
        find_next_element(h,ele);
        break;
    case 9:
        scanf("%d",&ele);
        find_previous_element(h,ele);
        break;
    case 10:
        scanf("%d",&ele);
        delete_element(&h, ele);
        break;
    case 11:
        delete_list(&h);
        break;
    default:
        printf("Wrong input");
    }
    printf("\n1 -> Menu\n0 -> Exit\nEnter your choice");
    scanf("%d",&tch);
    }while(tch == 1);
    return 0;
}
