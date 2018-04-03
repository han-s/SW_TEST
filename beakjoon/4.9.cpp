
typedef struct b_tree_node{
	int data;
	b_tree_node *left = NULL;
	b_tree_node *right = NULL;
}
int n;
int main(void)
{
	queue<b_tree_node> q,q2;
	b_tree_node head;
	q.push(head);
	while(!q.empty())
	{
		node = q.front();
		q2.push(q.front());	
		if(node->left !=NULL)
			q.push(node->left);
		else if(node->right !=NULL)
			q.push(node->right);

		q.pop();
	}

	while(!q2.empty())
	{
		node = q2.front();
		node2 = q2.front();
		q.pop();
		int total1. total2;
		while(1)
		{
			if(node->left !=NULL)
			{
				total1 +=node->left->data;
				node=node->left;

				if(total1 > n)
					break;
				else if(total1 == n)
					return true;
			}			
				
				continue;
			}
			if(node->right !=NULL)
			{
				total1 += node->right->data;
				node=node->right;
				continue;
			}

			

		}













			


