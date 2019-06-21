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