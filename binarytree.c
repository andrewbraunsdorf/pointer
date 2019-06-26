#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//minichallenge create the NODE for a binary tree.
typedef struct NODE
{
    int value;
    struct NODE *low;
    struct NODE *high;
} NODE;

// typedef struct QNODE
// {
//     NODE *value;
//     struct QNODE *next;
// } QNODE;
typedef struct QNODE
{
    NODE *node;
    struct QNODE *next;
} QNODE;

NODE *rootNode;

QNODE *headNode;
// function declarations
NODE* pop();
void pushed(NODE*);


// void push(NODE *value)
// {
//     QNODE *newNode = malloc(sizeof(QNODE));
//     newNode->value = value;
//     newNode->next = NULL;
//     if (headNode == NULL)
//     {
//         headNode = newNode;
//         return;
//     }

//     // NODE *trav = homeNode;
//     QNODE *trav = headNode;
//     while (trav->next != NULL)
//     {
//         trav = trav-> next;
//     }

//     trav->next = newNode;
// }

// void displayList()
// {
//     QNODE *trav = headNode;
//     // should display
//     // 5, 10, 8, 17
//      while(trav->next != NULL)
//      {
//          printf("%i, ", trav->value);
//          trav = trav-> next;
//      }
//      printf("%i\n", trav->value);
// }

void addNode(int value)
{
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = value;
    newNode->high = NULL;
    newNode->low = NULL;

    if (rootNode == NULL)
    {
        rootNode = newNode;
        // push(rootNode);
        return;
    }

    // if value of new node is less the root node attach to low
    // else add to high.
    NODE *trav = rootNode;
    // printf("trying to add node %i\n", newNode->value);
    while(1)
    {
        if (newNode->value < trav->value)
        {
            if (trav->low == NULL)
            {
                // printf("found empty spot\n");
                trav->low = newNode;
                // push(trav->low);
                return;
            }
            // printf("found a low node valued: %i moving to it\n", trav->low->value);
            trav = trav->low;
            continue;
        }
        else
        {
            if (trav->high == NULL)
            {
                // printf("found empty spot\n");
                trav->high = newNode;
                // push(trav->high);
                return;
            }
            // printf("found a high node valued: %i moving to it\n", trav->high->value);
            trav = trav->high;
            continue;
        }
    }
}

void displayTreeOnEnter(NODE *curNode)
{
    printf("%i ", curNode->value);

    if (curNode->low)
    {
        displayTreeOnEnter(curNode->low);
    }

    if (curNode->high)
    {
        displayTreeOnEnter(curNode->high);
    }
}

void displayTreeOnDeparture(NODE *curNode)
{
    //4 7 6 5 9 8 13 18 20 17 15 10

    if (curNode->low)
    {
        displayTreeOnEnter(curNode->low);
    }

    if (curNode->high)
    {
        displayTreeOnEnter(curNode->high);
    }

    printf("%i ", curNode->value);
}

int doesContain(int value)
{
    NODE *trav = rootNode;
    while(1)
    {
        if (trav->value == value)
        {
            return 1;
        }
        if (value < trav->value)
        {
            if (trav->low == NULL)
            {
                return 0;
            }
            trav = trav->low;
            continue;
        }
        if (!trav->high)
        {
            return 0;
        }
        trav = trav->high;
        continue;
    }
}

void freeList(NODE *curNode)
{
    if (curNode == NULL)
    {
        return;
    }

    freeList(curNode->low);
    freeList(curNode->high);
    printf("Deleting node: %d\n", curNode->value);

    free(curNode);
}

void freeNode(NODE *curNode)
{
    if (curNode->low)
    {
        freeNode(curNode->low);
    }

    if (curNode->high)
    {
        freeNode(curNode->high);
    }

    free(curNode);
}

void tests()
{
    assert(doesContain(10) && "tree does contain 10");
    assert(doesContain(8) && "tree does contain 8");
    assert(doesContain(4) && "tree does contain 4");
    assert(!doesContain(1) && "tree does not contain 1");
    assert(doesContain(15) && "tree does contain 15");
    assert(!doesContain(100) && "Tree does not contain 100");
    assert(doesContain(13) && "tree does contain 13");
    assert(doesContain(7) && "tree does contain 7");
    assert(!doesContain(16) && "tree does not contain 16");
}

int main(void)
{
    printf("hello\n");
    addNode(10);
    addNode(8);
    addNode(15);
    addNode(17);
    addNode(20);
    addNode(18);
    addNode(5);
    addNode(6);
    addNode(9);
    addNode(4);
    addNode(13);
    addNode(14);
    addNode(7);

    pushed(rootNode);
    pushed(rootNode->low);
    pushed(rootNode->high);
    displayTreeOnEnter(rootNode);
    printf("\n");

    displayTreeOnDeparture(rootNode);
    printf("\n");

    freeList(rootNode);
    // doesContain(10);
    printf("%i\n", pop()->value);
    printf("%i\n", pop()->value);
    // tests();
    // push(rootNode);
}

void pushed(NODE* address)
{
    QNODE *newQNode = malloc(sizeof(QNODE));
    newQNode->node = address;
    newQNode->next = NULL;
    if (headNode == NULL)
    {
        headNode = newQNode;
        return;
    }
    QNODE *trav = headNode;
        while (trav->next != NULL)
    {
        trav = trav-> next;
    }

    trav->next = newQNode;
}

NODE* pop()
{
    // create temp store the headNode
    // reassign the headNode
    // return the address of a binarytree node


    ////this also works
    // NODE *temp = headNode;
    // //both the same thing
    // headNode = headNode->next;
    // // headNode = headNode->next;
    // return temp;

    NODE *temp = headNode->node;
    QNODE *qTemp = headNode;
    //both the same thing
    headNode = qTemp->next;
    free(qTemp);
    // headNode = headNode->next;
    return temp;

}

// display level
// 10-8-15-5-9-13
// add children to queue //push
// display
// get next item in queue //pop
// mvp one line in correct order
// how do we know when we go down a new level