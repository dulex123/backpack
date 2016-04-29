void SwitchEveryTwo(node **root) {
	if( *root == NULL || *root->next == NULL )
		return;
	node *first=*root, *second=*root->next;
	*root = second;
	while(true) {
		node * third = second->next;	
		second->next = first;
		if( third == NULL ) {
			first->next = NULL;
			return;		
		}
		first->next = next->next;
		second = next->next;
	}
}
