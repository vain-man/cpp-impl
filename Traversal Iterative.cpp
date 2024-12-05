void preorder(Node *root)
{
	stack < Node* > st;
	st.push(root);
	while (!st.empty())
	{
		Node * current = st.top();
		st.pop();

		Process(current);
		if (current->right) st.push(current->right);
		if (current->left) st.push(current->left);
	}
}



void inorder(Node *root)
{
	stack < Node * > st;
	Node *curr = root;
	while (!st.empty() || curr != NULL)
	{
		if (curr != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = st.top();
			st.pop();
			Process(curr);
			curr = curr->right;
		}
	}
}


void postorder(Node *root)
{
	//Get Preorder traversal
	//Reverse it
}