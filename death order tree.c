#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node*left;
    struct node*right;
};

struct node* newNode(char data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
};

int inorder(struct node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf(" %c", node->data);
    inorder(node->right);
}

int preorder(struct node* node)
{
   if (node == NULL)
        return;
    printf(" %c", node->data);
    preorder(node->left);
    preorder(node->right);
}

int postorder(struct node* node)
{
   if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf(" %c", node->data);
}

int main()
{
    int ch;
    struct node* root = newNode('s');
    root->left = newNode('o');
    root->right = newNode('l');
    root->left->left = newNode('a');
    root->left->right = newNode('i');
    root->right->left = newNode('m');
    root->right->right = newNode('a');
    root->right->right->right = newNode('n');
    do
    {
        printf("\n 1. In order\n 2. Pre order\n 3. Post order\n 4. Exit");
        printf("\n Enter your choice = ");
        scanf("%d", &ch);
		
        switch(ch)
        {
            case 1:
                printf("\n In-order traversal of Binary tree is =");
                inorder(root);
            break;
			
            case 2:
                printf("\n Pre-order traversal of Binary tree is =");
                preorder(root);
            break;
			
            case 3:
                printf("\n Post-order traversal of Binary tree is =");
                postorder(root);
            break;
			
            case 4:
                exit(1);
            break;
			
			default:
                printf("\n Invalid.... Please enter your right choice = ");
				continue;
        }
    }while(ch!=4);
	
    return 0;
}
