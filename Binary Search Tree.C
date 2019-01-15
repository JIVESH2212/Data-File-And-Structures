# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

typedef struct BST {
   int data;
   struct BST *lchild, *rchild;
} node;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);
struct BST* deleteNode(node*,int);

void main() {
   int choice;
   char ans = 'N';
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   root = NULL;


   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Create");
      printf("\n2.Search");
      printf("\n3.Recursive Traversals");
      printf("\n4.Delete");
      printf("\n5.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
	 do {
	    new_node = get_node();
	    printf("\nEnter The Element ");
	    scanf("%d", &new_node->data);

	    if (root == NULL)
	       root = new_node;
	    else
	       insert(root, new_node);

	    printf("\nWant To enter More Elements?(y/n)");
	    ans = getch();
	 } while (ans == 'y');
	 break;

      case 2:
	 printf("\nEnter Element to be searched :");
	 scanf("%d", &key);

	 tmp = search(root, key, &parent);
	 printf("\nParent of node %d is %d", tmp->data, parent->data);
	 break;

      case 3:
	 if (root == NULL)
	    printf("Tree Is Not Created");
	 else {
	    printf("\nThe Inorder display : ");
	    inorder(root);
	    printf("\nThe Preorder display : ");
	    preorder(root);
	    printf("\nThe Postorder display : ");
	    postorder(root);
	 }
	 break;

      case 4:
      if(root == NULL){
      printf("Tree is not created\n"); }
      else {
      scanf("%d",&key);
      deleteNode(root,key);
       }
      inorder(root);
      break;
      case 5: exit (0);
	      break;
      }
   } while (choice != 4);
   getch();
}

node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
struct BST * minValueNode(struct BST* node)
{
    struct BST* current = node;

	while (current->lchild != NULL)
	current = current->lchild;

    return current;
}

 struct BST* deleteNode(struct BST* root, int key)
{
    struct BST* temp;
    if (root == NULL) return root;


    if (key < root->data){
	root->lchild = deleteNode(root->lchild, key);
	printf("Successful\n");
	return root;
	}
	 else if (key > root->data) {
	root->rchild = deleteNode(root->rchild, key);

	 return root;
	 }
    else
    {
	if (root->lchild == NULL)
	{
	    struct BST *temp = root->rchild;
	    free(root);
	       return temp;
	}
	else if (root->rchild == NULL)
	{
	    struct BST *temp = root->lchild;
	    free(root);
	    return temp;
	}


	 temp = minValueNode(root->rchild);


	root->data = temp->data;


	root->rchild = deleteNode(root->rchild, temp->data);
	printf("Successful\n");
    }
    return root;
}
void insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->lchild == NULL)
	 root->lchild = new_node;
      else
	 insert(root->lchild, new_node);
   }

   if (new_node->data > root->data) {
      if (root->rchild == NULL)
	 root->rchild = new_node;
      else
	 insert(root->rchild, new_node);
   }
}

node *search(node *root, int key, node **parent) {
   node *temp;
   temp = root;
   while (temp != NULL) {
      if (temp->data == key) {
	 printf("\nThe %d Element is Present", temp->data);
	 return temp;
      }
      *parent = temp;

      if (temp->data > key)
	 temp = temp->lchild;
      else
	 temp = temp->rchild;
   }
   return NULL;
}

void inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d ", temp->data);
      inorder(temp->rchild);
   }
}

void preorder(node *temp) {
   if (temp != NULL) {
      printf("%d ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}


void postorder(node *temp) {
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d ", temp->data);
   }
}
