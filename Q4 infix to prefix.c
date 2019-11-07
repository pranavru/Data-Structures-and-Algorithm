# include <stdio.h>
# include <string.h>

# define MAX 20

int top = -1;

char stack[MAX];




//--------------------------------------------------------

void infixtoprefix(char infix[20], char prefix[20])
{

	int i, j = 0;

	char ch;

	push('#');
	
reverse(infix);

	for (i = 0; i < strlen(infix); i++)
	

{

		ch = infix[i];

		//if (isOperator(ch)==0)

			if (isalnum(ch))
			
{

				prefix[j] = ch;

  				j++;

			}
			 
else
			
{
				if (ch == ')')
				
{
				
    push(ch);	

				}
				
else if (ch == '(')
				
{
    
					while (stack[top] != ')')
					{
					
      prefix[j] = pop();
					
      j++;
					}

					//pop();

				}
				
else
				{
				
     if (prcd(stack[top]) <= prcd(ch))
					{
					
      push(ch);
					}
				     else
				 	{
					
      while (prcd(stack[top]) >= prcd(ch))
					      {
					       		prefix[j++] = pop();
						
        //j++;
					
      }
					
      push(ch);
					}
					
  //end for else

				}
			   //end for else
			
   }
	
  //end for for
	}

 	while (stack[top] != '#')
	{

    		prefix[j++] = pop();
		//j++;
	
}
	prefix[j] = '\0';
 
}
////--------------------------------------------------------

void reverse(char array[30])
{

// for reverse of the given expression
 
int i, j;
 
char temp[100];
 
for (i = strlen(array)-1 , j=0; (i+1)!=0; --i,  ++j)

{

	temp[j] = array[i];

}

temp[j] = '\0';

strcpy(array, temp);
//copying temp array to array
  
// return array;
 
}

//--------------------------------
  
char pop() 
{
  
	char a;

	a = stack[top];
  
	top--;
  
	return a;

}
 
//----------------------------------
 
void push(char ch) 
{

	top++;

	stack[top] = ch;

}
 
//------------------------------------------
 
int prcd(char ch) 
{
 
// returns the value that helps in the precedence
 
	switch (ch) 
	{
  
		case '+':
   	
		case '-':
    
			return 2;
    
			break;
  
		case '*':
   
		case '/':
    
			return 4;
    	
			break;
   
		case '$':
   
		case '^':
    
			return 6;
    
			break;
   
		case '#':
   	
		case '(':
   
		case ')':
    
			return 1;
    
			break;
  
	}

}

//-------------------------------------------------

int isOperator(char ch) 
{

	switch (ch) 
	{

		case '+':

		case '-':

		case '*':

		case '/':

		case '^':

		case '$':

		case '&':

		case '(':

		case ')':

			return 1;

			break;

		default:

  			return 0;

// returns 0 if the ch is other than given above

	}

}
void main() 
{

	char infix[20], prefix[20], temp;

	printf("Enter infix operation: ");

	gets(infix);

	infixtoprefix(infix, prefix);

	reverse(prefix);

	puts((prefix));

}