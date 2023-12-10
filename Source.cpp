#include<iostream>
using namespace std;

struct node
{
	float coeff;
	int expo;
	node *link;
};

node *insert(node *head, float co, int ex)
{
	node *temp;
	node *pnew = (node *)malloc(sizeof(node));
	
	pnew->coeff = co;
	pnew->expo = ex;
	pnew->link = NULL;

	if (head == NULL || ex > head->expo)
	{
		pnew->link = head;
		head = pnew;
	}
	else
	{
		temp = head;
		while (temp->link != NULL && temp->link->expo >= ex)
			temp = temp->link;
		pnew->link = temp->link;
		temp->link = pnew;
	}
	return head;
}

node *create_node(node *head)
{
	int n, i;
	float coeff;
	int expo;

	cout << "Enter the number of trem : ";
	cin >> n;
	cout << endl;

	for (i = 0; i < n; i++)
	{
		cout << "Enter the Co-efficient for the term " << i + 1 << " : ";
		cin >> coeff;

		cout << "Enter the Exponent for term " << i + 1 << " : ";
		cin >> expo;

		head = insert(head, coeff, expo);
	}
	cout << endl;
	return head;
}

void print(node *head)
{
	if (head == NULL)
	{
		cout << "NO POLYNOMIAL !";
	}
	else
	{
		node *temp = head;
		cout << "The Resultant Polynomial Term :  ";
		while (temp != NULL)
		{
			cout << temp->coeff << ".0x^" << temp->expo;
			temp = temp->link;

			if (temp != NULL)
				cout << " + ";
			else
				cout << endl;
		}
	}
}

void poly_add(node *head1, node* head2)
{
	node *ptr1 = head1;
	node *ptr2 = head2;
	node *head3 = NULL;

	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->expo == ptr2->expo)
		{
			head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if (ptr1->expo > ptr2->expo)
		{
			head3 = insert(head3, ptr1->coeff , ptr1->expo);
			ptr1 = ptr1->link;
		}
		else if (ptr1->expo < ptr2->expo)
		{
			head3 = insert(head3, ptr2->coeff, ptr2->expo);
			ptr2 = ptr2->link;
		}
	}
	while (ptr1 != NULL)
	{
		head3 = insert(head3, ptr1->coeff , ptr1->expo);
		ptr1 = ptr1->link;
	}
	while (ptr2 != NULL)
	{
		head3 = insert(head3, ptr2->coeff, ptr2->expo);
		ptr2 = ptr2->link;
	}
	print(head3);
}

int main()
{
	node *head1 = NULL;
	node *head2 = NULL;

	cout << "			Enter the First Polynomials !			" << endl;
	cout << endl;
	head1 = create_node(head1);
	print(head1);
	cout << endl << endl;

	
	cout << "			Enter the Second Polynomials :			 " << endl;
	cout << endl;
	head2 = create_node(head2);
	cout << endl << endl;

	poly_add(head1, head2);
 
	return 0;
}