#include <stdio.h>
#include <stdlib.h> //for memory alloc

char *getstring(char *string_to_print);

int main(void)
{
	//creating file pointer and creating a csv file opening in append mode
	FILE *fp;
	fp=fopen("C:\\Users\\Abdul\\Desktop\\phonebook.csv","a");

	//getting data from user 
    //is not working
    int c;
    do
    {
        char *name=getstring("Enter the name of person:");
        fprintf(fp, "%s,",name);
        free(name);

        //we use two fprintf and two free because the name and phoneno may have same pointee

        char *phone_no=getstring("Enter the phone number:");
        fprintf(fp, "%s\n",phone_no );
        free(phone_no);

        //terminating condition
        printf("to exit program press 0 else any other key\n");
        if ((c=getchar())=='0')
        {
            break;
        }
       
        fflush(stdin);

    } while (1);   
    

    printf("\n\tA file has been created in cwd(current working directory) by the name phonebook.csv");
    fclose(fp);
}

char *getstring(char *string_to_print)
{
    int temp;//to store current character
    char *string=malloc(sizeof(char)); //allocating string(pointer to first index) to 1 byte    
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (string == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    
    
    //getting the string character by character
    printf("%s",string_to_print);    
    int i=0;
    for ( ; (temp=getchar())!='\n'; ++i)
    {
        string[i]=temp;
        string=realloc(string,i+1+sizeof(char));    //makes space for the next(i+1) character
    }
    string[i]='\0';

    return (string);
}