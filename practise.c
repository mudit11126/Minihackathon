#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    int marks[5];
    int total;
    float per;
    char grade;
    int pass;
};

int getNumber() {
    int num;
    char extra;
    while(scanf("%d%c", &num, &extra)!=2 || extra!='\n') {
        printf("Invalid input! Enter numbers only: ");
        while(getchar()!='\n');
    }
    return num;
}

char getGrade(float p) {
    if(p>=90)
        return 'A';
    else if(p>=75)
        return 'B';
    else if(p>=60)
        return 'C';
    else
        return 'D';
}

int main() {
    struct Student s[50];
    int n=0, i, j, ch, top;
    float sum, avg;

    do {
        printf("\n------Student Marks Management System------\n");
        printf("\n1. Enter Student Marks\n");
        printf("2. Show Result and Class Report\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        ch=getNumber();

        switch(ch) {
            case 1:
                printf("\nEnter number of students (1-50): ");
                n=getNumber();
                while(n<1 || n>50) {
                    printf("Invalid! Enter between 1 and 50: ");
                    n=getNumber();
                }

                for(i=0; i<n; i++) {
                    printf("\nStudent %d\n", i+1);
                    printf("Enter Roll No: ");
                    s[i].roll=getNumber();
                    printf("Enter Name: ");
                    scanf("%s", s[i].name);

                    s[i].total=0;
                    s[i].pass=1;

                    for(j=0; j<5; j++) {
                        printf("Subject %d marks: ", j+1);
                        s[i].marks[j]=getNumber();

                        while(s[i].marks[j]<0 || s[i].marks[j]>100) {
                            printf("Invalid marks, enter again (0-100): ");
                            s[i].marks[j]=getNumber();
                        }

                        s[i].total=s[i].total+s[i].marks[j];

                        if(s[i].marks[j]<40) {
                            s[i].pass=0;
                        }
                    }

                    s[i].per=s[i].total/5.0;

                    if(s[i].pass==0)
                        s[i].grade='F';
                    else
                        s[i].grade=getGrade(s[i].per);
                }
                printf("\nData entered successfully.\n");
                break;

            case 2:
                if(n==0) {
                    printf("\nNo data found. Enter marks first.\n");
                }
                else {
                    sum=0;
                    top=0;

                    printf("\nRoll\tName\tTotal\tPercent\tGrade\tResult\n");
                    printf("----------------------------------------------\n");

                    for(i=0; i<n; i++) {
                        sum=sum+s[i].per;

                        if(s[i].total>s[top].total) {
                            top=i;
                        }

                        printf("%d\t%s\t%d\t%.2f%%\t%c\t", s[i].roll, s[i].name, s[i].total, s[i].per, s[i].grade);

                        if(s[i].pass==1)
                            printf("PASS\n");
                        else
                            printf("FAIL\n");
                    }

                    avg=sum/n;
                    printf("----------------------------------------------\n");
                    printf("Class Average: %.2f%%\n", avg);
                    printf("Class Topper: %s (Roll %d) - %d/500\n", s[top].name, s[top].roll, s[top].total);
                }
                break;

            case 3:
                if(n==0) {
                    printf("\nPlease enter at least one student's record before exiting!\n");
                    ch=0;
                }
                else {
                    printf("Exiting...\n");
                }
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(ch!=3);

    return 0;
} 