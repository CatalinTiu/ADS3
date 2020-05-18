//Tiu Catalin Group 3 
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class Node {
public:
    char data[50];
    Node* next;
};

void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void sortedInsert(Node** head_ref, Node* new_node)
{
    Node* current;
    // Special case for inserting in the head
    if (*head_ref == NULL || strcmp((*head_ref)->data, new_node->data)>=0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        // locate the node before insertion
        current = *head_ref;
        while (current->next!=NULL &&
            strcmp(current->next->data, new_node->data) < 0)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void deleteNode(Node **head_ref, char key[])
{
   Node* temp = *head_ref, *prev;

    // if head node has the key to be deleted
    if (temp != NULL && strcmp(temp->data, key) == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // search for the key to be deleted, remembering the previous node because we need to change 'prev->next'
    while (temp != NULL &&  strcmp(temp->data, key) != 0 )
    {
        prev = temp;
        temp = temp->next;
    }

    // if key was not in linked list
    if (temp == NULL) return;

    // unlink the node from linked list
    prev->next = temp->next;

    free(temp);
}

bool search(Node* head, char a[])
{
    Node* current = head;
    while (current != NULL)
    {
        if (strcmp(current->data, a) == 0)
            return true;
        current = current->next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    int choice, i = 0, size = 0;
    char a[50][50];

  do{

      cout << "1.Reserve ticket" << endl;
      cout << "2.Cancel reservation" << endl;
      cout << "3.Check if the ticket is reserved" << endl;
      cout << "4.List of the passengers" << endl;
      cout << "5.Exit" << '\n';
      cin >> choice;
      switch (choice) {
              case 1:{

                Node* n = NULL;
                n = new Node();
                cout << "In order to create a reservation, please write your name without space in between(ex: TiuCatalin)" << endl;
                cout << "Name under the reservation:";
                cin >> n->data;
                sortedInsert(&head, n);
                cout << endl;
                break;
              }

              case 2:{
                char a[50];
                cout << "In order to delete a reservation, please write your name without space in between(ex: TiuCatalin)" << endl;
                cout << "Name under the reservation:";
                cin >> a;
                deleteNode(&head, a);
                cout << endl;
                break;
              }
              case 3:{
                char a[50];
                cout << "In order to search a reservation, please write your name without space in between(ex: TiuCatalin)" << endl;
                cout << "Name under the reservation:";
                cin >> a;
                cout << endl;
                search(head, a)? cout<<"Yes" : cout<<"No";
                cout << endl;
                break;
              }

              case 4:{
                printList(head);
                cout << endl;
                break;
              }
              case 5: return 0;
            }

    }while (choice != 5);




    return 0;
}
