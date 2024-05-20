#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[20];
    int id;
    struct student * next;

};
struct node{
    char name[20];
    int id;
    int pass;
    float deposit;
    float withdraw;
    float fee;
    float paid;
    float due;
    struct node * next;
};

struct student * User(){
    struct student *s1, *s2, *s3, *s4;
    s1 = (struct student*)malloc(sizeof(struct student));
    s2 = (struct student*)malloc(sizeof(struct student));
    s3 = (struct student*)malloc(sizeof(struct student));
    s4 = (struct student*)malloc(sizeof(struct student));
    strcpy(s1 -> name,"Minhajul");
    s1 -> id = 23215931;
    s1 -> next = s2;

    strcpy(s2 -> name,"Ziad");
    s2 -> id = 23215935;
    s2 -> next = s3;

    strcpy(s3 -> name,"Zarif");
    s3 -> id = 23215914;
    s3 -> next = s4;

    strcpy(s4 -> name,"Bayzid");
    s4 -> id = 23215927;
    s4 -> next = NULL;

    return s1;
}
struct node* signUp(struct student *s1,struct node* tail){
    printf("------------------------------------------\n");
    int id, pass;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    up :
    printf("Enter your student ID -> ");
    scanf("%d",&id);

    struct student * h = s1;
    while(h != NULL){
        if(h -> id == id){
            strcpy(temp -> name, h -> name);
            temp -> id = id;
            temp -> deposit = 0.0;
            temp -> withdraw = 0.0;
            temp -> fee = 0.0;
            temp -> paid = 0.0;
            temp -> due = 0.0;
            temp -> next = NULL;
            tail -> next = temp;
            tail = temp;
            break;
        }
        h = h -> next;
    }
    if( h == NULL){
        printf("------------------------------------------\n");
        printf("| Incorrect ID, Please insert a valid ID. |\n");
        printf("------------------------------------------\n");
        goto up;
    }
    printf("Enter a strong password -> ");
    scanf("%d",&pass);
    temp -> pass = pass;

    return tail;

}
struct node* login(struct node* head){
    struct node* temp = head;
    int id, pass,k;
    float amount;
    printf("------------------------------------------\n");
    Login :

    printf("Enter your student ID -> ");
    scanf("%d",&id);
    printf("Enter your password -> ");
    scanf("%d",&pass);
    while(temp != NULL){
        if((temp -> id == id) && (temp -> pass == pass)){
            print :
            printf("\n");
            printf("------------------------------------------------\n");
            printf("-----------\n");
            printf("| PROFILE |\n");
            printf("-----------\n");
            printf(" Welcome back %s.\n", temp -> name);
            printf(" Your student id is %d \n",temp -> id);
            printf(" Your password is %d\n",temp -> pass);
            printf(" Your current available bank balance is %.2f TK.\n",temp -> deposit);
            printf(" Your total withdraw money is %.2f TK.\n", temp -> withdraw);
            printf("------------------------------------------------\n");
            break;
        }
        else if(temp -> next == NULL){
            printf("\n");
            printf("Your entered ID or password is wrong.\nPlease insert right id and password.\n");
            goto Login;
        }
        temp = temp -> next;
    }
    calc:
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    printf("|         >>Do you wanna deposit or withdraw you money???       |\n");
    printf("|                     Press 1 for deposit.                      |\n");
    printf("|                     Press 2 for withdraw.                     |\n");
    printf("|                     Press 3 for payment.                      |\n");
    printf("|                     Press 4 for logout.                       |\n");
    printf("-----------------------------------------------------------------\n");
    printf("\nEnter your choice -> ");
    scanf("%d",&k);
    switch(k){
        case 1:
              printf("Enter deposit amount -> ");
              scanf("%f", &amount);
              temp -> deposit =(temp -> deposit) + amount;
              printf("Congratulations , deposit succesfull.\n");
              printf("Your current available bank balance is %.2f TK.\n",temp -> deposit);
              goto print;
              break;
        case 2:
              printf("Enter amount for withdraw -> ");
              scanf("%f",&amount);
              if(amount > temp -> deposit){
                  printf("Sorry, You dont have enough money in your account\n");
                  goto calc;
              }else if(amount <= temp -> deposit){
                  temp -> deposit -= amount;
                  printf("Withdraw Succesful\n");
                  temp -> withdraw += amount;
                  printf("available bank balance is %.2f TK.\n",temp -> deposit);
                  goto print;
              }
              break;

        case 3:
               payment :
               printf("|------------------------------------|\n");
               printf("Total Payable : %f TK.\n",temp -> fee);
               printf("Total paid : %f TK.\n",temp -> paid);
               printf("Total due : %f TK.\n", temp -> due);
               printf("|------------------------------------|\n");

               printf("|---------------------------------------------|\n");
               printf("|                                             |\n");
               printf("|        Press 1 to pay your fee.             |\n");
               printf("|        Press 2 to go to profile.            |\n");
               printf("|                                             |\n");
               printf("|---------------------------------------------|\n");
               printf("\nEnter your choice : ");
               int choice = 0;
               scanf("%d", &choice);
               if(choice == 2) goto print;
               else {
                printf("Enter amount : ");
               }

               float semesterFee = 0;
               scanf("%f", &semesterFee);

               if(semesterFee > temp -> deposit){
                  printf("Sorry, You dont have enough money in your account\n");
                  goto payment;

               }else if(semesterFee <= temp -> deposit){
                  temp -> deposit -= semesterFee;
                  printf("fee paid Succesful\n");
                  temp -> paid += semesterFee;
                  temp -> due = (temp -> fee) - (temp -> paid);
                  goto payment;
                  break;
               }

        case 4:
              return head;
    }

    return head;
}
struct node * userProfile(struct node* h, int id, int pass){
    struct node * head = h;
    struct node * temp = h;
    struct node * check = h;
    head = head -> next;
    int AdminId = 2328, AdminPass = 2222;
    int i = 0;
    if(AdminId == id && AdminPass == pass){

         while(check != NULL){
            i++;
            check = check -> next;
        }
        printf("|---------------------------------------------|\n");
        printf("|                                             |\n");
        printf("|     Total Registared Student -> %d          |\n",i-1);
        printf("|                                             |\n");
        printf("|---------------------------------------------|\n\n");

        printf("|---------------------------------------------|\n");
        printf("|                                             |\n");
        printf("|     1. Search individual student profile.   |\n");
        printf("|         2.All student Profile check.        |\n");
        printf("|              3. Fee update.                 |\n");
        printf("|                                             |\n");
        printf("|---------------------------------------------|\n");
        printf("\nEnter your choice : ");
        int k = 0;
        scanf("%d",&k);

        if(k == 1) {
            printf("Enter student ID:");
            int t = 0;
            scanf("%d", &t);
            while(temp -> id != t) {
                temp = temp -> next;
            }
            if(temp == NULL) {
                printf("|---------------------------------------------|\n");
                printf("|        Student profile not found.           |\n");
                printf("|---------------------------------------------|\n");
            }
            else {
                printf("--------------------------------------------------------\n");
                printf("Student name -> %s\n",temp -> name);
                printf("student id is %d \n",temp -> id);
               // printf("Student password is %d\n",head -> pass);
               printf("Students total fee %.2f\n", temp -> fee);
               printf("Students due %.2f\n", temp -> due);
               // printf("Students current available bank balance is %.2f TK.\n",temp -> deposit);
                printf("Student's total withdraw money is %.2f TK.\n", temp -> withdraw);
                printf("--------------------------------------------------------\n");
            }
        }
        else if(k == 2){
            while(head != NULL){
               printf("--------------------------------------------------------\n");
               printf("Student name -> %s\n",head -> name);
               printf("student id is %d \n",head -> id);
              // printf("Student password is %d\n",head -> pass);
               printf("Students total fee %.2f TK.\n", head -> fee);
               printf("Students due %.2f TK.\n", head -> due);
               // printf("Students current available bank balance is %.2f TK.\n",head -> deposit);
               printf("Student's total withdraw money is %.2f TK.\n", head -> withdraw);
               head = head -> next;
               printf("--------------------------------------------------------\n");
           }
           printf("|---------------------------------------------|\n");
           printf("|     Total Registared Student -> %d          |\n",i-1);
           printf("|---------------------------------------------|\n\n");
        }
        else if(k == 3) {
            printf("|---------------------------------------------|\n");
            printf("|          Update semester fee.               |\n");
            printf("|---------------------------------------------|\n");
            printf("Enter fee : ");
            float fee = 0;
            scanf("%f", &fee);
            while(head != NULL){
               head -> fee += fee;
               head -> due += fee;
               head = head -> next;
           }
           printf("Fee updated succesful.\n");
        }
    }
    return h;
}
void print(struct student *head){
    struct student *p = head;
    while(p != NULL){
        printf("Student name -> %s\n",p -> name);
        printf("Student ID -> %d\n", p -> id);
        p = p -> next;
    }
}
int main(){
    int k, n;
    int AdminId = 0, AdminPass = 0;
    struct student *student1 = NULL;
    student1 = User();
    //create a null node for starting nodes for userinput
    struct node * node1 = (struct node*)malloc(sizeof(struct node));
    strcpy(node1 -> name,"TOTO BANK");
    node1 -> id = 12;
    node1 -> pass = 123;
    node1 -> deposit = 0.0;
    node1 -> withdraw = 0.0;
    struct node *head, *tail;
    head = node1;
    tail = node1;

    homepage :
    printf("|------------------------------------------|\n");
    printf("|                ------------              |\n");
    printf("|                | PAY EASE |              |\n");
    printf("|                ------------              |\n");
    printf("|      1.Want to create new accout.        |\n");
    printf("|      2.Login your excisting accout.      |\n");
    printf("|      3.Admin                             |\n");
    printf("|      4.Exit                              |\n");
    printf("|------------------------------------------|\n");
    printf("\nEnter your choice -> ");
    scanf("%d",&k);

    switch(k){
        case 1:
              printf("------------------------------------------\n");
              printf("Welcome to DIU family .\n");
              tail = signUp(student1,tail);
              printf("Congratulation , Your account was created succesfully.\n");
              printf("-------------------------------------------\n");
              goto homepage;

        case 2:
              head = login(head);
              goto homepage;
              break;

        case 3:
              printf("------------------------------------------\n");
              printf("Enter your Admin Id please ->");
              scanf("%d",&AdminId);
              printf("Enter your Admin password please ->");
              scanf("%d",&AdminPass);
              head = userProfile(head,AdminId,AdminPass);
              goto homepage;
              break;
        case 4:
              printf("----------------------------------------------------------------\n");
              printf("| Thankes for explore PAY EASE. Hope You enjoyed the service.  |\n");
              printf("----------------------------------------------------------------\n");
              break;
    }





    return 0;
}
