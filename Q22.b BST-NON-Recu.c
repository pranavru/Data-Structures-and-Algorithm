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

        if(tree==NULL)							       /* There is no element in the tree */

        {
	       return NULL;

        }


        if(tree->left)								/* Go to the left sub tree to find the min element */

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

        if(tree->right)
		 	/* Go to the right sub tree to find the max element */

                findlargest(tree->right);

        else
 
               return tree;

}


struct node *insertwithoutrecursion(struct node * tree, int val)

{

	struct node *temp,*nodeptr,*parent;

	temp=(struct node*)malloc(sizeof(struct node));
	
temp->data=val;
	
temp->left=NULL;

	temp->right=NULL;

	if (tree==NULL)

	{
		
tree=temp;
		
tree->left=NULL;
		
tree->right=NULL;

	}
	
else
	
{
		
parent=NULL;

		nodeptr=tree;
		
while(nodeptr!=NULL)
		
{
	
		parent=nodeptr;

			if(val<nodeptr->data)

				nodeptr=nodeptr->left;

			else

				nodeptr=nodeptr->right;

		}

		if(val<parent->data)

			parent->left=temp;

		else
			
parent->right=temp;
			

return tree;

	}
}



struct node *delete (struct node *tree, int val)

{

	struct node *ptr, *preptr, *inorder_pre;

	ptr=tree;
	if(tree==NULL)

		printf("\n tree empty");

	while(ptr!=NULL && ptr->data!=val)

	{

	 	if(val<ptr->data)					//value in left subtree

		{

			preptr=ptr;

			ptr=ptr->left;
					//delete(ptr,val);

		} 							//end if
	
	if(val>ptr->data)					//value in right subtree

		{

			preptr=ptr;

			ptr=ptr->right;					//delete(ptr,val);
 
		}							// end if

	}

	if(ptr==NULL)

		printf("\n Elelement not found");


	else 								//value found n matches ptr->data

	//if(val==ptr->data)  //value matches node data

	{

		if(ptr->left==NULL && ptr->right==NULL) 		//no left and right child of node to be deleted  i.e. ptr

		{

			if(preptr->left==ptr)				//ptr is left child of preptr

			{

					preptr->left=NULL;

					free(ptr);

			}

			else

			{

					preptr->right=NULL;

					free(ptr);

			}

		}							 //end if

		else if (ptr->left!=NULL && ptr->right==NULL) 		 //has left child but no right child

		{

			if(preptr->left==ptr)				 //ptr is left child of preptr

			{

				preptr->left=ptr->left;

				free(ptr);

			}

			else

			{

				preptr->right=ptr->left;

				free(ptr);

			}

		}							//end if
 
		else if(ptr->right!=NULL && ptr->left==NULL)		//has right child but no left child

		{

			if(preptr->left==ptr)				//ptr is left child of preptr

			{

				preptr->left=ptr->right;

				free(ptr);

			}

			else

			{

				preptr->right=ptr->right;

				free(ptr);

			}

		} 							//end if
 
		else if (ptr->left!=NULL && ptr->right!=NULL )		//has both left and right child

		{

			inorder_pre=findlargest(ptr->left);

			ptr->data=inorder_pre->data;

			/*if(preptr->left==ptr)

				preptr->left=inorder_pre;

			  else

				preptr->right=inorder_pre;*/

			free(inorder_pre);

		} 							// end if

	}  								//end else

	return tree;

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

int totalnodes(struct node *tree)

{

	if (tree==NULL)

		return 0;

	else
	 
	return (totalnodes(tree->left)+totalnodes(tree->right)+1);

}

int totalinternalnodes(struct node *tree)

{

	if ((tree==NULL)||((tree->left==NULL)&&(tree->right==NULL)))

		return 0;

	else 

		return (totalinternalnodes(tree->left)+totalinternalnodes(tree->right)+1);

}

int totalexternalnodes(struct node *tree)

{

	if (tree==NULL)

		return 0;

	else
	 
	if((tree->left==NULL)&&(tree->right==NULL))

			return 1;
	
	else 
return (totalexternalnodes(tree->left)+totalexternalnodes(tree->right));

}

int  height(struct node *tree)

{

	int left_height,right_height;


	if(tree==NULL)

		return 0;

	else

	{

		left_height=height(tree->left);

		right_height=height(tree->right);

		if(left_height>right_height)

		{
		 
	return(left_height+1);

		}

		else

		{

			return(right_height+1);

		}

	}

}

struct node *mirrorimage(struct node *tree)

{

	struct node *ptr;

	if (tree!=NULL)

	{
	//mirrorimage(tree->left);
	//mirrorimage(tree->right);
	//ptr=tree->left;
	//ptr->left=ptr->right;
	//tree->right=ptr;

		ptr=tree->left;

		tree->left=mirrorimage(tree->right);

		tree->right=mirrorimage(ptr);

	}

	return tree;

}


struct node *deletetree(struct node *tree)

{

	
if (tree!=NULL)

	{

		deletetree(tree->left);

		deletetree(tree->right);

		free(tree);

	}

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

		printf("\n 14. exit");

		printf("\n Enter the option: ");

		scanf("%d", &option);

		switch (option)

		{

			case 1:
	 
			printf("enter the newnode data ?\n");	

		   	 	scanf("%d", &data);
	
			root = insertwithoutrecursion(root, data);

				break;
	
		case 2:
				printf("\n inorder\n");

			        inorder(root);

				break;

			case 3:
				printf("\n preorder\n");

		 	        preorder(root);

				break;

			case 4:
				printf("\n postorder\n");

			        postorder(root);

				break;

			case 5:
				temp=findlargest(root);

				printf("Maximum element is %d\n",temp->data);

				break;

			case 6:
				temp=findsmallest(root);

				printf("Minimum element is %d\n",temp->data);

				break;

			case 7: 
				printf("enter the data u want to delete:");

				scanf("%d",&delno);
			 	root = delete(root,delno);

				inorder(root);
	
			printf("\n element deleted");

				break;

			case 8: 
				printf("\n total number of nodes=%d",totalnodes(root));

				break;


			case 9: 
				printf("\n total number of Internal nodes=%d",totalinternalnodes(root));

				break;

			case 10: 
				printf("\n total number of external nodes=%d",totalexternalnodes(root));

				break;

		
	case 11: 
				printf("\n height=%d",height(root));

			  	break;
		
	case 12: 
				printf("\n mirror image=");
		
		tree= mirrorimage(tree);

				inorder(root);

				break;


			case 13: 
				root= deletetree(root);

				printf("\n tree is deleted");

				break;

			default:
				break;


		
}
	}while(option!=14);

}
