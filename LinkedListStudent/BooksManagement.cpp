#include <iostream>
#include <string>

using namespace std;
int get_main_menu();
int get_add_book_menu();
int get_remove_book_menu();
int add_book_tail();
void display_all_book();
int add_book_head();
int get_number_elements();
int remove_book_head();
void display_number_elements();
int remove_book_tail();
int add_book_between();
int remove_book_between();
void search_book();
void sort_book();

struct Book
{
	string book_id;
	string author;
	string title;
};

struct Node
{
	Book *new_book = new Book();
	Node * next_node;
};

Node * head_node = NULL;
Node * tail_node = new Node();
Node * node = new Node();
int i = 0;

int main()
{
	bool add_condition = true;
	bool remove_condition = true;
	while (true)
	{
		switch (get_main_menu())
		{
		case 1:
			add_condition = true;
			while (add_condition)
			{
				switch (get_add_book_menu())
				{
				case 1:
					add_book_head();
					break;
				case 2:
					add_book_tail();
					break;
				case 3:
					add_book_between();
					break;
				case 4:
					add_condition = false;
					break;
				}
			}
			break;
		case 2:
			remove_condition = true;
			while (remove_condition)
			{
				switch (get_remove_book_menu())
				{
				case 1:
					remove_book_head();
					break;
				case 2:
					remove_book_tail();
					break;
				case 3:
					remove_book_between();
					break;
				case 4:
					remove_condition = false;
					break;
				}
			}
			break;
		case 3:
			display_all_book();
			break;
		case 4:
			display_number_elements();
			break;
		case 5:
			search_book();
			break;
		case 6:
			sort_book();
			break;
		case 7:
			return 0;
			break;
		}
	}
	return 0;
}

int add_book_head()
{
	node = new Node();
	string b_id = "";
	printf("\n\t\tEnter book Id or 'Q' to quit input > ");
	cin >> b_id;
	printf("\n");
	if (b_id.length() == 1 && (b_id[0] == 'q' || b_id[0] == 'Q'))
		return 0;

		i++;
		node->new_book->book_id = b_id;

		printf("\n\t\tEnter book author name > ");

		cin >> node->new_book->author;

		printf("\n\t\tEnter book title name > ");

		cin >> node->new_book->title;

		node->next_node = head_node;
		head_node = node;
		if (i == 1)
			tail_node = node;

		printf("\n");
		for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
		{
			cout << "\n\t\t"
				<< "ID: " << ndx->new_book->book_id << ", "
				<< "Title: " << ndx->new_book->title << ", "
				<< "Author: " << ndx->new_book->author << endl;
		}
		system("pause");
}

int add_book_tail()
{
	if (head_node != NULL)
	{
		tail_node->next_node = new Node();
		node = tail_node->next_node;
		string b_id = "";
		printf("\n\t\tEnter book Id or 'Q' to quit input > ");
		cin >> b_id;
		printf("\n");
		if (b_id.length() == 1 && (b_id[0] == 'q' || b_id[0] == 'Q'))
			return 0;

		i++;
		node->new_book->book_id = b_id;

		printf("\n\t\tEnter book author name > ");

		cin >> node->new_book->author;

		printf("\n\t\tEnter book title name > ");

		cin >> node->new_book->title;

		node->next_node = NULL;

		tail_node = node;

		if (i == 1)
			head_node = node;

		printf("\n");
		for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
		{
			cout << "\n\t\t"
				<< "book ID: " << ndx->new_book->book_id << ", "
				<< "book title: " << ndx->new_book->title << ", "
				<< "book author: " << ndx->new_book->author << endl;
		}
		system("pause");
	}
	else
	{
		cout << "\n\t\tThe list is empty, add first of all to head!" << endl;
		system("pause");
	}
}

int add_book_between()
{
	string b_id = "";
	string new_b_id = "";
	bool condition = false;
	cout << "\n\t\tEnter book Id after which you want to add new book > ";
	cin >> b_id;
	cout << "\n";

	for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
	{
		if (ndx->new_book->book_id == b_id)
		{
			Node * temp_node = ndx->next_node;

			cout << "\n\t\tEnter book Id or 'Q' to quit input > ";
			cin >> new_b_id;

			if (new_b_id.length() == 1 && (new_b_id[0] == 'q' || new_b_id[0] == 'Q'))
				return 0;
			node = new Node();
			ndx->next_node = node;
			i++;
			node->new_book->book_id = new_b_id;

			cout << "\n\t\tEnter book author name > ";

			cin >> node->new_book->author;

			cout << "\n\t\tEnter book title name > ";

			cin >> node->new_book->title;

			node->next_node = temp_node;

			cout << "\n";
			for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
			{
				cout << "\n\t\t"
					<< "ID: " << ndx->new_book->book_id << ", "
					<< "Title: " << ndx->new_book->title << ", "
					<< "Author: " << ndx->new_book->author << endl;
			}
			system("pause");
			condition = true;
			break;
		}
	
	}
		if(!condition)
		{
			cout << "\n\t\tAny book with ID";
			system("pause");
			return 0;
		}
}

int remove_book_head()
	{
		if (get_number_elements() > 0)
		{
			if (head_node == tail_node)
			{
				i = 0;
			}
		
			head_node = head_node->next_node;
			for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
			{
				cout << "\n\t\t"
					<< ndx->new_book->book_id << " "
					<< ndx->new_book->title << ", "
					<< ndx->new_book->author << endl;
			}
		}
		else
		{
			printf("\n\t\tNo elements!\n");
		}
		system("pause");
		return 0;
	}

int remove_book_tail()
{
	if (get_number_elements() > 0)
	{
		if (head_node == tail_node)
		{
			i = 0;
			head_node = NULL;
			tail_node = new Node();
		}
		else
		{
			for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
			{
				if (ndx->next_node == tail_node)
				{
					tail_node = ndx;
					ndx->next_node = NULL;
				}
			}
		}

		for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
		{
			cout << "\n\t\t"
				<< ndx->new_book->book_id << " "
				<< ndx->new_book->title << ", "
				<< ndx->new_book->author << endl;
		}
	}
	else
	{
		printf("\n\t\tNo elements!\n");
	}
	system("pause");
	return 0;
}
int remove_book_between()
{
	string b_id = "";
	bool condition = false;
	cout << "\n\t\tEnter removing book Id > ";
	cin >> b_id;
	cout << "\n";

	for (Node * ndx = head_node; ndx != tail_node; ndx = ndx->next_node)
	{
		Node * temp_node = ndx;
		Node * temp_node1 = ndx->next_node;

		if (ndx->next_node->new_book->book_id == b_id)
		{
			i--;
			ndx->next_node->new_book = NULL;
			temp_node->next_node = temp_node1->next_node;
			cout << "\n";
			for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
			{
				cout << "\n\t\t"
					<< "ID: " << ndx->new_book->book_id << ", "
					<< "Title: " << ndx->new_book->title << ", "
					<< "Author: " << ndx->new_book->author << endl;
			}
			system("pause");
			condition = true;
			break;
		}

	}
	if (!condition)
	{
		cout << "\n\t\tAny book with ID";
		system("pause");
		return 0;
	}
}

void display_all_book()
{
	for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
	{
		cout	<< "\n\t\t"
				<< ndx->new_book->book_id << " "
				<< ndx->new_book->title << ", "
				<< ndx->new_book->author << endl;
	}
	system("pause");
}
int get_number_elements()
{	
	int number_elements = 0;
	for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
	{
		number_elements++;
	}
	return number_elements;
}

void display_number_elements()
{
	int number_elements = get_number_elements();
	if (number_elements > 0)
	{
		cout << "\n\t\tNumber of elements = " << number_elements << endl;
	}
	else 	printf("\n\t\tNo elements!\n");
	system("pause");
}

int get_add_book_menu()
{
	system("cls");
	int chose = 0;
	printf("\n\t\t1.	Add at the head.");
	printf("\n\t\t2.	Add at the tail.");
	printf("\n\t\t3.	Add between 2 books.");
	printf("\n\t\t4.	Exit add menu.");
	printf("\n\t\t> ");
	cin >> chose;
	return chose;
}

int get_remove_book_menu()
{
	system("cls");
	int chose = 0;
	printf("\n\t\t1.	Remove from the head.");
	printf("\n\t\t2.	Remove from the tail.");
	printf("\n\t\t3.	Remove between 2 books.");
	printf("\n\t\t4.	Exit remove menu.");
	printf("\n\t\t> ");
	cin >> chose;
	return chose;
}

void search_book()
{
	string b_id = "";
	bool condition = false;
	cout << "\n\t\tEnter book Id or author or title > ";
	cin >> b_id;
	cout << "\n";

	for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
	{
		if (ndx->new_book->book_id == b_id ||
			ndx->new_book->author == b_id ||
			ndx->new_book->title == b_id)
		{
		cout << "\n\t\t"
					<< "ID: " << ndx->new_book->book_id << ", "
					<< "Title: " << ndx->new_book->title << ", "
					<< "Author: " << ndx->new_book->author << endl;
			system("pause");
			condition = true;

		}
	}
	if (!condition)
	{
		cout << "\n\t\tAny book with ID";
		system("pause");
	}
}


void sort_book()
{
	string temp_id = "";
	string temp_author = "";
	string temp_title = "";
	for (Node * ndx_1 = head_node; ndx_1 != NULL; ndx_1 = ndx_1->next_node)
	{
		for (Node * ndx = head_node; ndx->next_node != NULL; ndx = ndx->next_node)
		{
			if (ndx->new_book->book_id > ndx->next_node->new_book->book_id)
			{
				temp_id = ndx->new_book->book_id;
				ndx->new_book->book_id = ndx->next_node->new_book->book_id;
				ndx->next_node->new_book->book_id = temp_id;

				temp_author = ndx->new_book->author;
				ndx->new_book->author = ndx->next_node->new_book->author;
				ndx->next_node->new_book->author = temp_author;

				temp_title = ndx->new_book->title;
				ndx->new_book->title = ndx->next_node->new_book->title;
				ndx->next_node->new_book->title = temp_title;
			}
		}
	}

	for (Node * ndx = head_node; ndx != NULL; ndx = ndx->next_node)
	{
		cout << "\n\t\t"
			<< "ID: " << ndx->new_book->book_id << ", "
			<< "Title: " << ndx->new_book->title << ", "
			<< "Author: " << ndx->new_book->author << endl;
	}
	system("pause");
}

int get_main_menu()
{
	system("cls");
	int chose = 0;
	printf("\n\tMake a chose:");
	printf("\n\t\t1.	Add a book.");
	printf("\n\t\t2.	Remove a book.");
	printf("\n\t\t3.	Display all book.");
	printf("\n\t\t4.	Display the number of elements.");
	printf("\n\t\t5.	Search.");
	printf("\n\t\t6.	Sort book by ID.");
	printf("\n\t\t7.	Exit.");
	printf("\n\t\t> ");
	cin >> chose;
	return chose;
}

