#include<stdio.h>
#include<malloc.h>
struct node
{
        int data;
        struct  node *left;
        struct  node *right;

}*tree;
struct node* findsmallest(struct node *tree)
{
        if(tree==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(tree->left) /* Go to the left sub tree to find the min element */
                return findsmallest(tree->left);
        else 
                return tree;
}
struct node* findlargest(struct node *tree)
{
        if(tree==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(tree->right) /* Go to the right sub tree to find the max element */
                findlargest(tree->right);
        else 
                return tree;
}

struct node * Insert(struct node *tree,int data)
{
        if(tree==NULL)
        {
                struct node *temp;
                temp = (struct node *)malloc(sizeof(struct node));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }
        if(data >(tree->data))
        {
                tree->right = Insert(tree->right,data);
        }
        else if(data < (tree->data))
        {
                tree->left = Insert(tree->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */
        return tree;

}
struct node * delete(struct node *tree, int data)
{
        struct node *temp;
        if(tree==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < tree->data)
        {
                tree->left = delete(tree->left, data);
        }
        else if(data > tree->data)
        {
                tree->right = delete(tree->right, data);
        }
        else
        {
 /* Now We can delete this tree and replace with either minimum element in the right sub tree or maximum element in the left subtree */
            if(tree->right && tree->left)// to delete a node  with 2 childrens
                {
      
                        temp = findlargest(tree->left);
                        tree -> data = temp->data; 
    /* As we replaced it with some other node, we have to delete that node */
                        tree -> left = delete(tree->left,temp->data);
                }
                else
                {
  /* If there is only one or zero children then we can directly 
         remove it from the tree and connect its parent to its child */
                        temp = tree;
                        if(tree->left == NULL)
                                tree = tree->right;
                        else if(tree->right == NULL)
                                tree = tree->left;
                        free(temp); /* temp is  no longer required */ 
                }
        }
        return tree;

}

struct node * Find(struct node *tree, int data)
{
        if(tree==NULL)
        {
                /* Element is not found */
                return NULL;
        }
        if(data > tree->data)
        {
                /* Search in the right sub tree. */
                return Find(tree->right,data);
        }
        else if(data < tree->data)
        {
                /* Search in the left sub tree. */
                return Find(tree->left,data);
        }
        else
        {
                /* Element Found */
                return tree;
        }
}

void inorder(struct node *tree)
{
        if(tree==NULL)
        {
                return;
        }
        inorder(tree->left);
        printf("%d ",tree->data);
        inorder(tree->right);
}

void preorder(struct node *tree)
{
        if(tree==NULL)
        {
                return;
        }
        printf("%d ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
}

void postorder(struct node *tree)
{
        if(tree==NULL)
        {
                return;
        }
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->data);
}

int main()
{
        struct node *root = NULL,  * temp;
	int data,i,delno,n,no, total, option,val;
	do
	{
	printf("\n------------MENU------------");
	printf("\n 1. insert ");
	printf("\n 2.inorder");
	printf("\n 3.preorder");
	printf("\n 4.postorder");
	printf("\n 5. findlargest element");
	printf("\n 6. findsmallest element");
	printf("\n 7. delete ");
	printf("\n 8. total nodes");
	printf("\n 9. total Internal nodes");
	printf("\n 10. total external nodes");
	printf("\n 11. height of tree");
	printf("\n 12. mirror image");
	printf("\n 13. delete tree");
	printf("\n 14 search a node");
	printf("\n 15. exit");
	printf("\n Enter the option: ");
	scanf("%d", &option);
	switch (option)
	{
		case 1: 
		
		printf("How many data's do you want to insert ?\n");
   	 	scanf("%d", &n);
		for( i=0; i<n; i++)
		{
        	printf("Data %d: ", i+1);
        	scanf("%d", &data);
        	root = Insert(root, data);
       		}
		break;	
		case 2:printf("\n inorder\n");
		       inorder(root);
			break;
		case 3:printf("\n preorder\n");
		       preorder(root);
			break;
		case 4:printf("\n postorder\n");
		       postorder(root);
			break;
		case 5:  temp=findlargest(root);
			printf("Maximum element is %d\n",temp->data);
			break;
		case 6:temp=findsmallest(root);
			printf("Minimum element is %d\n",temp->data);
			break;
		case 7: printf("enter the data u want to delete:");
			scanf("%d",&delno);
			 root = delete(root,delno);
			inorder(root);
			break;
		
		case 8:default:break;

		
			}}while(option!=8);
}
