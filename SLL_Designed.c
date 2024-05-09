#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define MAGNETA "\x1b[35m" 
#define BOLD  "\x1b[1m"
#define RESET "\x1b[0m"


//--------------------------------- Defines a structure for linked list nodes----------------------//
struct LL
{
    int data;
    struct LL* pointer;
} *start = NULL;




// -------------------------------Function prototypes-----------------------------------------//
int menu();
void createNewnode();
void displayLL();
void addNode();
void updateNode();
void deleteNode(int n);
void operation();


//---------------------------- main function-------------------------------------------//

int main()
    {
        int choice = 0;
        while (choice != 99)
        {
            choice = menu();
        }
        
        printf("\n"BOLD GREEN"----------------------Exited successfully---------------------------\n"RESET);
        return 0;
    }



//--------------------------- Displays the menu and takes the user's choice--------------------------//


int menu()
{
    printf("\n\n"BOLD GREEN"-------------------- Select an Option ----------------------------"RESET);
    printf("\n1. Create a new list");
    printf("\n2. Display the list");
    printf("\n3. Insert a node");
    printf("\n4. Update a node");
    printf("\n5. Delete a node");
    printf("\n6. Do Operations On Link List");
    printf("\n99. Exit the program\n");

    int input;
    int check= scanf(" %d", &input);
        if(check!=1)
            input=0;
     
    switch (input)
    {
    case 1:
        createNewnode();
        printf("\n"BOLD GREEN"Linked list created"RESET);
        break;
    case 2:
        displayLL();
        break;
    case 3:
        addNode();
        break;
    case 4:
        updateNode();
        break;
    case 5:
        deleteNode(0);
        break;
    case 6:
        operation();
        break;
    case 99:deleteNode(input);
        return input;
        break;
    default:
        if (check != 1)
        {
            while (getchar() != '\n');
        }
        printf("\n"RED BOLD"Invalid input select valid options only\n"RESET);
    }
    return 0;
}





//------------------------------------- Creates a new linked list--------------------------------------------//
void createNewnode()
{   if(start!=NULL)
    {
        deleteNode(99);
        printf("\nCreating New One:\n");
    }
    struct LL *temp = start;
    int input, count = 1;
    printf(RED"\nEnter data to be stored. Enter -1 to terminate.\n");
    printf("Any other data type than integer will be ignored.\n"RESET);

    while (true)
    {
        printf("Enter data to be stored at"BOLD RED" %d", count);
        switch (count)
        {
        case 1:
            printf("st"RESET" node:");
            break;
        case 2:
            printf("nd"RESET" node:");
            break;
        case 3:
            printf("rd"RESET" node:");
            break;
        default:
            printf("th"RESET" node:");
        }

        int check = scanf("%d", &input);

        if (check != 1)
        {
            while (getchar() != '\n');
            printf("\t\t"BOLD RED"Invalid input\n"RESET);
            continue;
        }

        if (input == -1)
        {
            printf("\n"BOLD RED"Terminated"RESET);
            printf("\nAddress saved at"BOLD RED" %d"RESET" is: %p", count - 1, temp->pointer);
            printf("\tAddress of"BOLD RED" %d"RESET" is: %p", count - 1, temp);
            break;
        }
        else
        {
            struct LL *new_node = (struct LL *)malloc(sizeof(struct LL));

            if (new_node == NULL)
            {
                printf("\n"BOLD RED"Failed to create the node: No disk space left"RESET);
                break;
            }
            if (start == NULL)
            {    start = new_node;
                new_node->data = input;
                new_node->pointer = NULL;
                temp = new_node;
                printf(BOLD GREEN"Creating a linked list from scratch at address:"RESET" %p\n\n", start);
                count++;
            }
            else
            {
                while (temp->pointer != NULL)
                {
                    temp = temp->pointer;
                    printf("\nTraversing to find a null value");
                }
                temp->pointer = new_node;
                new_node->data = input;
                new_node->pointer = NULL;
                temp = new_node;
                count++;
                printf(BOLD GREEN"\tInserted node at the end at address "RESET" %p\n\n", temp);
            }
        }
    }
}


//-------------------------------- Displays the linked list-----------------------------------------//
void displayLL()
{
    int i = 1;
    struct LL *temp = start;

    if (start == NULL)
    {
        printf(BOLD RED"\nBro, first create a linked list"RESET);
    }
    else
    { int input;
        printf("\nfor numerical output enter"BOLD RED" 1"RESET"\nfor diagrammatic output enter"BOLD RED" 2"RESET" \n(diagram may not show value properly when "BOLD RED"data > 999 or <-999"RESET")\n");
        int check= scanf("%d",&input);
        
        if (check==0||input>2||input<1)
        {
            printf(BOLD RED"\t\t Invalid Input. Going to default mode(numerical)\n"RESET);
            input=1;
        }
       
        while (temp != NULL)
        {
            if(input==1)
                {   printf("\nData part of node"BOLD RED" %d:"RESET, i);
                    printf("\t%d", temp->data);
                    printf("\tPointer part of node"BOLD RED" %d"RESET" stores %p", i, temp->pointer);
                    i++;
                }
                
            else
                {
                    printf(BOLD RED"+-------------------+\n");
                    printf("|"RESET);
                    if(temp->data<10 && temp->data>0)
                    printf(" ");
                    if(temp->data<100 && temp->data>9 || temp->data>-10)
                    printf(" ");
                    printf("%d",temp->data);
                    if(temp->data<100 && temp->data>-100)
                    printf(" ");
                    if(temp->data==0)
                    printf(" ");
                    printf(BOLD MAGNETA"|"RESET"  ""%p",temp->pointer);
                   if(temp->pointer==NULL)
                        printf("\t    ");
                    
                    printf(BOLD RED"|"RESET);
                    if(temp->pointer!=NULL)
                        printf(BOLD GREEN"-----+"RESET);
                    printf(BOLD RED"\n+-------------------+"RESET);
                    if(temp->pointer!=NULL)
                    printf(BOLD GREEN"\t  |"RESET);
                    printf("\n    (node %d)",i);
                    if(temp->pointer!=NULL)
                    printf(BOLD GREEN"\t\t  |\n\t\t\t  |\n   +----------------------+ \n   |\n   ↓\n"RESET);
                    i++;
                }
            temp = temp->pointer;
       }
       
    }
}


//-------------------------------- Adds a new node to the linked list--------------------------------------//
void addNode()
{   struct LL *temp = start;
    struct LL *temp_previous = start;

    int position, input, value;
    printf(BOLD GREEN"\n----------- Where do you want to insert the new node? --------"RESET);
    printf("\nTo insert at the beginning, enter:"BOLD RED" 1"RESET);
    printf("\nTo insert before a node, enter:"BOLD RED" 2"RESET);
    printf("\nTo insert after a node, enter:"BOLD RED" 4"RESET);
    printf("\nTo insert at the end, enter:"BOLD RED" 5"RESET);
    printf("\n\nChoose: ");
    int check = scanf("%d", &position);
    if (check != 1)
    {
        while (getchar() != '\n');
        printf(BOLD RED"\nInvalid input\n"RESET);
    }

    struct LL *new_node = (struct LL *)malloc(sizeof(struct LL));
    if (new_node == NULL)
    {
        printf(BOLD RED"\nDisk space not available"RESET);
        exit(0);
    }

    printf(BOLD GREEN"\nPlease enter the data to be stored: "RESET);
    check = scanf("%d", &input);

    if (check != 1)
    {
        while (getchar() != '\n');
        printf(BOLD RED"\nInvalid input\n"RESET);
        exit(0);
    }

    if (start == NULL)
    {
        printf(RED"\nList is empty, making the node the first node"RESET);
        start = new_node;
        new_node->data = input;
        new_node->pointer = NULL;
        position = 99;
    }

    switch (position)
    {
    case 1:
        new_node->pointer = start;
        start = new_node;
        new_node->data = input;
        printf(BOLD GREEN"\nNew node has been successfully inserted at the beginning"RESET);
        break;

    case 2:
        printf(BOLD GREEN"Inserting a new node before a given node\nPlease enter the node value: "RESET);
        scanf(" %d", &value);
        if (start->data == value)
        {
            new_node->pointer = start;
            start = new_node;
            new_node->data = input;
            break;
        }
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                break;
            }
            temp_previous = temp;
            temp = temp->pointer;
        }
        if (temp == NULL)
            printf(BOLD RED"\nGiven value not found throughout the list"RESET);
        else
        {
            temp_previous->pointer = new_node;
            new_node->pointer = temp;
            new_node->data = input;
            printf(BOLD GREEN"Insertion successful"RESET);
        }
        break;

    case 4:
        printf(BOLD GREEN"Inserting a new node after a given node"RESET"\nPlease enter the node value: ");
        scanf(" %d", &value);
        while (temp != NULL)
        {
            if (temp->data == value)
                break;
            temp = temp->pointer;
        }
        if (temp == NULL)
            printf(BOLD RED"\nGiven value not found in the list"RESET);
        else
        {
            new_node->pointer = temp->pointer;
            temp->pointer = new_node;
            new_node->data = input;
        }
        break;

    case 5:
        printf(GREEN"\nInserting a new node at the end"RESET);
        while (temp->pointer != NULL)
        {
            temp = temp->pointer;
        }
        temp->pointer = new_node;
        new_node->pointer = NULL;
        new_node->data = input;
        printf("\nNew node inserted at the end");
        break;
        
    case 99:
        printf("\nNew linked list created with the given data");
        break;

    default:
        printf(BOLD RED"\nInvalid input"RESET);
    }
}


//------------------------------ performs delete operation on the linked list-------------------------------//
void deleteNode(int n)
{
    if(start!=NULL){
    struct LL *temp = start;
    struct LL *temp_previous = start;
    int input;
    if(n!=99)
    {
    printf(BOLD GREEN"\nYou have selected to delete a node from the linked list.\nPlease select an option:\n"RESET);
    printf("1. To delete the first node, enter:"BOLD RED" 1\n"RESET);
    printf("2. To delete a given node, enter:"BOLD RED" 2\n"RESET);
    printf("3. To delete the last node, enter:"BOLD RED" 4\n"RESET);
    printf("4. To delete the whole linked list, enter:"BOLD RED" 5\n"RESET);
    printf("Choose: ");
    scanf("%d", &input);
    }
    else
     input=5;

    
    switch (input)
    {
    case 1:
        start = start->pointer;
        free(temp);
        printf(RED"\nFirst node deleted"RESET);
        break;

    case 2:
        printf("\nEnter the data value of the node to be deleted: ");
        scanf("%d", &input);
        while (temp != NULL)
        {
            if (temp->data == input)
            {
                break;
            }
            temp_previous = temp;
            temp = temp->pointer;
        }
        if (temp == NULL)
            printf(BOLD RED"Data not found throughout the list"RESET);
        else
        {
            temp_previous->pointer = temp->pointer;
            printf(BOLD RED"Successfully deleted the first node having the given data value"RESET);
            free(temp);
        }
        break;

    case 4:
        while (temp->pointer != NULL)
        {
            temp_previous = temp;
            temp = temp->pointer;
        }
        temp_previous->pointer = NULL;
        free(temp);
        printf(BOLD RED"\nLast node deleted"RESET);
        break;

    case 5:
        printf(BOLD RED"\nDeleting the whole/previous list if available"RESET);
        while (temp != NULL)
        {
            temp_previous = temp;
            temp = temp->pointer;
            free(temp_previous);
        }
        free(temp);
        start = NULL;
        break;

    default:
        printf(BOLD RED"\nInvalid input entered"RESET);
    }
  }
  else if(n!=99)
  printf(BOLD RED"\nfirst create a linked list\n"RESET);
}




//------------------------------ Updates the value of a given node----------------------------------------//

void updateNode()
{   if(start!=NULL){
    struct LL *temp = start;
    int choice, input, value, flag=0;
    printf(BOLD GREEN"\n----------------You have chosen to update the value of a given node.------------"RESET);
    printf("\nWhat's your requirement?\n");
    printf("1. To update the first node with the same value, choose"BOLD RED" 1\n"RESET);
    printf("2. To update all nodes with the same value, choose"BOLD RED" 2\n"RESET);
    printf("Choose: ");
    scanf("%d", &choice);
    printf(GREEN"\nEnter the node to be updated: "RESET);
    scanf("%d", &value);
    printf(GREEN"\nEnter the new value to be inserted: "RESET);
    scanf("%d", &input);
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            temp->data = input;
            if (choice == 1)
            {
                printf(BOLD GREEN"\nUpdated the first node with the same value"RESET);
                break;
            }
            else if(choice==2)
                flag=1;
        }
        temp = temp->pointer;
    }
    if(flag==1)
        printf(BOLD GREEN"\nUpdated all nodes with the same value"RESET);
    if(temp == NULL && flag !=1)
        printf(BOLD RED"Given value not found throughout the linked list"RESET);
    }
    else
        printf(BOLD RED"\nfirst create a linked list\n"RESET);
}


//-----------------------performs some basic operations on the link list------------------------------//

void operation()
{
    int input,count=0;
    struct LL*temp=start;
    struct LL*temp1=start;
    
    if(start!=NULL)
     {
        printf(BOLD GREEN"\n----------which operation do you want to perform ?---------"RESET);
        printf("\n1: to count number of nodes enter "BOLD RED" 1"RESET);
        printf("\n2: to sort the list in ascending order enter "BOLD RED" 2"RESET);
        printf("\n4: to sort the list in descending order enter "BOLD RED" 4"RESET);
        printf("\n5: to count number of even/odd values in the list enter "BOLD RED" 5"RESET);
        printf("\n6: to print alternate nodes enter"BOLD RED" 6"RESET);
        printf("\n7: To insert in a sorted manner, enter "BOLD RED" 7\n"RESET);
        scanf("%d",&input);
        
        switch(input)
        {
            case 1: while(temp!=NULL)
                    {
                        temp=temp->pointer;
                        count++;
                    }
                    printf(BOLD GREEN"\nThere are total of %d node(s) in the link list"RESET,count);
                    break;
                    
            case 2: printf(GREEN"\nsorting the list in ascending manner"RESET);
                    
                    while(temp!=NULL)
                    {
                        while(temp1!=NULL)
                        {
                            if (temp->data>temp1->data)
                            {
                                int swap=temp->data;
                                temp->data=temp1->data;
                                temp1->data=swap;
                            }
                            temp1=temp1->pointer;
                        }
                      temp=temp->pointer;
                      temp1=temp;
                        
                        
                    }
                    break;
                    
            case 4: printf(GREEN"\nsorting the list in descending manner"RESET);
                     while(temp!=NULL)
                    {
                        while(temp1!=NULL)
                        {
                            if (temp->data<temp1->data)
                            {
                                int swap=temp->data;
                                temp->data=temp1->data;
                                temp1->data=swap;
                            }
                            temp1=temp1->pointer;
                        }
                      temp=temp->pointer;
                      temp1=temp;
                        
                        
                    }
                    break;
                    
            case 5: ;/*TO AVOID ERROR(lables can only be followed by statements 
                        and declaration doesn't count as statements in c*/
                    int even=0,odd=0;
                    
                    while(temp!=NULL)
                    {
                        if(temp->data%2==0)
                          even++;
                        else
                          odd++;
                        temp=temp->pointer;
                    }
                    printf(GREEN"\nThere are total of"BOLD RED" %d"RESET" even values"RESET,even);
                    printf(GREEN"\nThere are total of"BOLD RED" %d"RESET" odd values"RESET,odd);
                    break;
                    
            case 6: printf(BOLD GREEN"\nprinting nodes at odd places: "RESET);
                    
                    while(temp!=NULL)
                    {
                        printf("\t%d",temp->data);
                        temp=temp->pointer;
                        if(temp!=NULL)
                         {
                             temp=temp->pointer;
                             
                         }
                        
                    }
                    printf("\tend\n");
                  
                    printf(BOLD GREEN"\nprinting nodes at even places: "RESET);
                    temp=start->pointer;
                    while(temp!=NULL)
                    {
                        printf("\t%d",temp->data);
                        temp=temp->pointer;
                        if(temp!=NULL)
                         {
                             temp=temp->pointer;
                             
                         }
                        
                    }
                    printf("\tend\n");
                    break;
                
                
            case 7: ;/*TO AVOID ERROR(lables can only be followed by statements 
                        and declaration doesn't count as statements in c*/
                    int input;
                    printf(BOLD GREEN"\ninserting in a sorted list"RESET);    
                    printf(BOLD RED"\nMake Sure Your List is Already Sorted in Ascending Manner "RESET);
                    printf("\nInput the value to be stored:");
                    int check= scanf("%d",&input);
                    while(check!=1)
                        {
                            printf(BOLD RED"\nInvalid Input, please enter again:"RESET);
                            check= scanf(" %d",&input);
                            
                        }
                    while(temp!=NULL)
                    {
                        if(input<temp->data)
                            break;
                        temp1=temp;
                        temp=temp->pointer;
                        
                        
                    }
                    struct LL* new_node=(struct LL*)malloc(sizeof(struct LL));
                    if(temp==start)
                    {
                        new_node->pointer=start;
                        start=new_node;
                        new_node->data=input;
                    }
                    
                    else
                    {
                        new_node->pointer=temp;
                        temp1->pointer=new_node;
                        new_node->data=input;
                        
                    }
                    
                    break;
             default:
                    printf(BOLD RED"\nInvalid input entered"RESET);
                    
        }
         
     }
     else
        printf(BOLD RED"\nfirst create a linked list"RESET);
}

//----------------------------------------------END-----------------------------------------------//




