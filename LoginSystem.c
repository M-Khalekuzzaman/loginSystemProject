#include<stdio.h>
#include<conio.h>
struct Login
{
    char fname[25];
    char lname[15];
    char username[10];
    int password,id;
};
registe()
{
    FILE *log;
    log  = fopen("dataStoreFile.txt","w");
    if(log == NULL)
        printf("File doest not opened,some thing is error\n");
    else
    {
        printf("File create successfully\n");
        struct Login person1;

        printf("\nEnter Person First name : ");
        fflush(stdin);
        gets(person1.fname);

        printf("Enter Person Last name : ");
        gets(person1.lname);

        printf("Enter Person user name : ");
        gets(person1.username);

        printf("Enter Person ID : ");
        scanf("%d",&person1.id);

        printf("Enter Person Password : ");
        scanf("%d",&person1.password);
        fwrite(&person1,sizeof(person1),1,log);
        printf("\nFile data written successful");

        fclose(log);

        printf("\n\nYour user name is your UserID\n");
        printf("Now,Login with UserID and Password\n");
        printf("\nPress any key to continue......................\n");
        getch();
        system("CLS");
        login();
    }
}
login()
{
    char username[10];
    int password;
    FILE *log;
    log  = fopen("dataStoreFile.txt","r");
    if(log == NULL)
        printf("File doest not opened,some thing is error\n");
    else
    {
        struct Login person1;
        printf("UserID : ");
        scanf("%s",&username);
        printf("Password : ");
        scanf("%d",&password);
        while(fread(&person1,sizeof(person1),1,log))
        {
            if(strcmp(username,person1.username) == 0 && person1.password == password)
            {
                printf("Successfully Login\n");
            }
            else
            {
                printf("Please !!!!!.......... Enter your correct UserID and Password ");
            }
        }
        fclose(log);
    }
}
int main()
{
    int cho;
    printf("Press '1' for Register........... \nPress '2' for Login.........\n");
    scanf("%d",&cho);
    if(cho == 1)
    {
        system("CLS");
        registe();
    }
    else if(cho == 2)
    {
        system("CLS");
        login();
    }
    else
        printf("Incorrect option !!!!!!!!!!!.......Please correct option secleted");



    return 0;
}
