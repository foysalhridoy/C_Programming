//structure datafile
# include <stdio.h>
# include <conio.h>
# include <string.h>


typedef struct Student{
        int id ;
        char name[50];
        float cgpa;
} student;


main()
{
    student t;
    FILE *fp;
    FILE *fp2;
    float cgpa;
    char sname[60],c;
    int ch;
    while(1)
    {
        system("cls");
        printf("\t\t\t\tMenu\n");
        printf("1. Add a student in file.\n");
        printf("2. Delete a student from file.\n");
        printf("3. Search a student by name.\n");
        printf("4. Search a student by ID\n");
        printf("5. See all the record.\n");
        printf("6. Update student CGPA by ID.\n");
        printf("7. Update student name by ID.\n");
        printf("8. EXIT.\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    fp=fopen("student.txt","ab");
                    while (1)
                    {
                      system("cls");
                      printf("Enter cgpa:");
                      scanf("%f",&t.cgpa);
                      fflush(stdin);
                      printf("\nEnter name:");
                      //scanf("%s",t.name);
                      gets(t.name);
                      fflush(stdin);
                      printf("\nEnter ID:");
                      scanf("%d",&t.id);
                      fwrite(&t,sizeof(t),1,fp);
                      fflush(stdin);
                      printf("\n\nDo you wish to continues?(Y/N):");
                      scanf("%c",&c);
                      if(c=='n' || c=='N')
                            break;
                    }
                    fclose(fp);
                    break;
            case 2:
                    fp=fopen("student.txt","rb");
                    system("cls");
                    printf("Delete student by ID.\n");
                    printf("Enter ID:");
                    int id;
                    scanf("%d",&id);
                    fp2=fopen("copy.txt","wb");

                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(id!=t.id)
                        {
//                            t.id[0]='\0';
//                            t.name[0]='\0';
//                            t.cgpa=0;
                            fwrite(&t,sizeof(t),1,fp2);
                        }
                    }
                    fclose(fp2);
                    fclose(fp);
                    system("Del student.txt");
                    system("Ren copy.txt student.txt");
                    printf("Deletion complete!\n");
                    getch();
                    break;

            case 3:
                    fp=fopen("student.txt","rb");
                    system("cls");
                    printf("Search student by name.\n");
                    printf("Enter name:");
                    scanf("%s",sname);
                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(strcmp(sname,t.name)==0)
                        {
                            printf("\n\t%d\t %s\t %f",t.id,t.name,t.cgpa);
                            getch();
                            break;
                        }
                    }
                    fclose(fp);
                    getch();
                    break;
            case 4:
                    fp=fopen("student.txt","rb");
                    system("cls");
                    printf("Search student by ID.\n");
                    printf("Enter ID:");
                    int id2;
                    scanf("%d",&id2);
                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(id2==t.id)
                        {
                            printf("\n\t%d\t %s\t %f",t.id,t.name,t.cgpa);
                            getch();
                            break;
                        }
                    }
                    fclose(fp);
                    getch();
                    break;
            case 5:
                    fp=fopen("student.txt","rb");
                    system("cls");
                    printf("\tList of Records in File");
                    printf("\n\tID\tName\tCGPA");

                    while(fread(&t,sizeof(t),1,fp))
                    {
                     printf("\n\t%d\t %s\t %f",t.id,t.name,t.cgpa);
                    }
                    fclose(fp);
                    getch();
                    break;

            case 6:
                    fp=fopen("student.txt","rb");
                    system("cls");
                    printf("Update student CGPA.\n");
                    printf("Enter ID:");
                    int id3,flag=0;
                    float cg;
                    scanf("%d",&id3);
                    printf("Enter new CGPA:");
                    scanf("%f",&cg);
                    fp2=fopen("copy.txt","wb");

                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(id3==t.id)
                        {
                            t.cgpa = cg;
                            flag = 1;
                        }
                        fwrite(&t,sizeof(t),1,fp2);
                    }
                    fclose(fp2);
                    fclose(fp);
                    system("Del student.txt");
                    system("Ren copy.txt student.txt");
                    if(flag)
                    {
                        printf("Student CGPA updated!\n");
                    }
                    else
                    {
                        printf("Student not found!\n");
                    }
                    flag=0;
                    getch();
                    break;
            case 7:
                    fp=fopen("student.txt","rb");
                    system("cls");
                    printf("Update student name.\n");
                    printf("Enter ID:");
                    scanf("%d",&id3);
                    fflush(stdin);
                    printf("Enter new name:");
                    char name2[50];
                    scanf("%s",name2);
                    flag=0;
                    fp2=fopen("copy.txt","wb");

                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(id3==t.id)
                        {
                            strcpy(t.name,name2);
                            flag=1;
                        }
                        fwrite(&t,sizeof(t),1,fp2);
                    }
                    fclose(fp);
                    fclose(fp2);

                    system("Del student.txt");
                    system("Ren copy.txt student.txt");
                    if(flag)
                    {
                        printf("Student name has been updated!\n");
                    }
                    else
                    {
                        printf("Student not found!\n");
                    }
                    getch();
                    break;
            case 8:
                    exit(1);
        }
    }
        getch();

}
