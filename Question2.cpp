/* LinkList node
struct Node { 
	int data; 
	struct Node* next; 
}; 
*/

// Function to delete the node without head 
void deleteNode(struct Node* n_node) 
{ 
	if (n_node == NULL)
	{
		// If linked list is empty 
		return; 
	}
	else 
	{ 

		if (n_node->next == NULL) 
		{ 
			cout<<"This is last node, require head, can't be freed\n"; 
			return; 
		} 

		struct Node* temp = n_node->next; 

		// Copy data of the next node to current node 
		n_node->data = n_node->next->data; 

		// Perform conventional deletion 
		n_node->next = n_node->next->next; 

		free(temp); 
	} 
} 

