/* 
Name : Dev Saraswat
Student ID : 202351173
Section : 2
Branch : CSE
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 4096
int count_lines(const char *buffer){
    int count=0;
    for(int i=0;buffer[i];i++){
        if(buffer[i]=='\n') count++;
    }
    return count+1;
}
void edit_line(char* buffer,int curr_line){
    char* start=buffer;
    for(int i=0;i<curr_line;i++){
        char* nl=strchr(start,'\n');
        if(!nl){ 
            start+=strlen(start);
            break;
        }
        start=nl+1;
    }

    char* line_end=strchr(start,'\n');
    char saved[MAX]={0};
    int res=(line_end!=NULL);

    if(line_end) strcpy(saved,line_end+1);
    else saved[0]='\0';

    printf("Enter new text:\n");
    getchar();
    char new_line[MAX];
    fgets(new_line,MAX,stdin);
    new_line[strcspn(new_line,"\n")]=0;

    if(res)
        sprintf(start,"%s\n%s",new_line,saved);
    else
        sprintf(start,"%s%s",new_line,saved);
}
int main(int argc,char** argv){
    FILE* f=fopen(argv[1],"r");
    char buffer[MAX]={0};
    fread(buffer,MAX,1,f);
    fclose(f);

    int curr_line=0;
    printf("Contents:\n%s\n",buffer);
    printf("Total lines: %d\n",count_lines(buffer));
    printf("Enter line number to edit:\n");
    scanf("%d",&curr_line);
    edit_line(buffer,curr_line);

    f=fopen(argv[1],"w");
    fwrite(buffer,strlen(buffer),1,f);
    fclose(f);
    printf("Changes saved\n");
    return 0;
}



/*----------------------OUTPUT----------------------
Contents:
Hello
World
How
Are
You
Total lines: 5

Enter line number to edit:
1

Enter new text:
C++

Changes saved



Before --> test.txt
Hello
World
How
Are
You


After --> test.txt
Hello
C++
How
Are
You
--------------------------------------------------*/    