bool	search(node*	list,	int	n)
{
    node* ptr	=	list;
    while (ptr	!=	NULL)
    {
    	 	if	(ptr->n	==	n)
    					{
    			return	true;
    					}
    	 	ptr	=	ptr->next;
    }
    return	false;
}

void insert(int n)
{
    // create new node
    node *new = malloc(sizeof(node));
    //check for NULL
    if (new == NULL)
    {
        exit(1);
    }
    //	initialize	new	node
    new->n = n;
    new->next = NULL;
    // insert new node at head
    new->next = head;
    head = new;
}