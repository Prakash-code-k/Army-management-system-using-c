Username = user
password = your system current time in { HHMM } format

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
// Define structures
struct personal_info {
    int soldier_id;
    char sf_name[50];
    char sl_name[50];
    char dob[11];
    char blood_group[5];
    char date_of_join[11];
    char gender[10];
    char regi_name[50];
}pi;
struct address_info {
    int soldier_id;
    char fulladdress[100];
}ai;
struct award_info {
    int soldier_id;
    char a_name[50];
}awdi;
struct family_info {
    int soldier_id;
    char ph_no[14];
    char relationship[20];
}fi;
struct weapon_info {
    int soldier_id;
    char wp_name[30];
}wi;
struct training_info {
    int soldier_id;
    int duration; //In days
    char t_place[50];
}ti;
void addAllInfo();
void viewPersonalInfo();
void viewAddressInfo(char *);
void viewFamilyInfo(char *);
void viewAwardInfo(char *);
void viewWeaponInfo(char *);
void viewTrainingInfo(char *);
void end();
// Function to add all information to file...
void addAllInfo() {
    FILE *fp_per,*fp_add,*fp_fam,*fp_awa,*fp_wea,*fp_tra;
    fp_per=fopen("personal_info.txt","a");
    fp_add=fopen("address_info.txt","a");
    fp_fam=fopen("family_info.txt","a");
    fp_awa=fopen("award_info.txt","a");
    fp_wea=fopen("weapon_info.txt","a");
    fp_tra=fopen("training_info.txt","a");
    if (fp_per==NULL || fp_add==NULL || fp_fam==NULL || fp_awa==NULL || fp_wea==NULL || fp_tra==NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fflush(stdin);
    int n;
    printf("Enter Soldier ID: ");
    scanf("%d",&n);
    pi.soldier_id=n,ai.soldier_id=n,fi.soldier_id=n,awdi.soldier_id=n,wi.soldier_id=n,ti.soldier_id=n;
    printf("Enter Soldier First Name: ");
    scanf("%s",pi.sf_name);
    printf("Enter Soldier Last Name: ");
    scanf("%s",pi.sl_name);
    printf("Enter DOB (DD-MM-YYYY): ");
    scanf("%s",pi.dob);
    printf("Enter Blood Group: ");
    scanf("%s",pi.blood_group);
    printf("Enter Date of Joining (DD-MM-YYYY): ");
    scanf("%s",pi.date_of_join);
    printf("Enter Gender: ");
    scanf("%s",pi.gender);
    printf("Enter Regiment Name: ");
    scanf("%s",pi.regi_name);
    printf("Enter Full Address Name: ");
    gets(ai.fulladdress);gets(ai.fulladdress);
    printf("Enter Award Name: ");
    gets(awdi.a_name);
    printf("Enter Phone No : ");
    scanf("%s",fi.ph_no);
    printf("Enter Marital Status: ");
    scanf("%s",fi.relationship);
    printf("Enter Weapon Name : ");
    gets(wi.wp_name);gets(wi.wp_name);
    printf("Enter Training duration(days) : ");
    scanf("%d",&ti.duration);
    printf("Enter Training place : ");
    scanf("%s",ti.t_place);
    fprintf(fp_per,"%d %s %s %s %s %s %s %s\n",pi.soldier_id,pi.sf_name,pi.sl_name,pi.dob,pi.blood_group,pi.date_of_join,pi.gender,pi.regi_name);
    fprintf(fp_add,"%d : %s\n",ai.soldier_id,ai.fulladdress);
    fprintf(fp_awa,"%d : %s\n",awdi.soldier_id,awdi.a_name);
    fprintf(fp_fam,"%d : %s , %s\n",fi.soldier_id,fi.ph_no,fi.relationship);
    fprintf(fp_wea,"%d : %s\n",wi.soldier_id,wi.wp_name);
    fprintf(fp_tra,"%d : %d , %s\n",ti.soldier_id,ti.duration,ti.t_place);
    fclose(fp_per);
    fclose(fp_add);
    fclose(fp_awa);
    fclose(fp_fam);
    fclose(fp_wea);
    fclose(fp_tra);
    printf("All information added successfully.\n");
}
// Function to view personal information from file
void viewPersonalInfo() {
    FILE *fp=fopen("personal_info.txt","r");
    if (fp==NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|Soldier ID\t|\tSoldier Name\t|\tDate Of Birth\t|\tBlood Group\t|\tDate of Joining\t|\tGender\t|\tRegiment Name   |\n");
    printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    while (fscanf(fp,"%d %s %s %s %s %s %s %s",&pi.soldier_id,pi.sf_name,pi.sl_name,pi.dob,pi.blood_group,pi.date_of_join,pi.gender,pi.regi_name)!=EOF) {
        printf("|%d\t\t|\t%s %s\t|\t%s\t|\t%s\t\t|\t%s\t|\t%s\t|\t%s\t\t|\n",pi.soldier_id,pi.sf_name,pi.sl_name,pi.dob,pi.blood_group,pi.date_of_join,pi.gender,pi.regi_name);
    }
    printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    fclose(fp);
}
//View Address with code...
void viewAddressInfo(char *ptr) {
    FILE *fp;
    char line[256];
    fp=fopen("address_info.txt","r");
    if (fp==NULL) {
        printf("Error opening file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line,ptr)) {
            printf("|-------------------------------------------------------|\n");
            printf("|ID  : Address\n");
            printf("|-------------------------------------------------------|\n");
            printf("|%s",line);
            printf("|-------------------------------------------------------|\n");
            fclose(fp);
        }
    }
}
//View Family information with code...
void viewFamilyInfo(char *ptr) {
    FILE *fp;
    char line[256];
    fp=fopen("family_info.txt","r");
    if (fp==NULL) {
        printf("Error opening file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line,ptr)) {
            printf("|-------------------------------------|\n");
            printf("|ID  : Phone no   , Marital Status\n");
            printf("|-------------------------------------|\n");
            printf("|%s",line);
            printf("|-------------------------------------|\n");
            fclose(fp);
        }
    }
}
//View Award information with code...
void viewAwardInfo(char *ptr) {
    FILE *fp;
    char line[256];
    fp=fopen("award_info.txt","r");
    if (fp==NULL) {
        printf("Error opening file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line,ptr)) {
            printf("|-------------------------------|\n");
            printf("|ID  : Award Name\n");
            printf("|-------------------------------|\n");
            printf("|%s",line);
            printf("|-------------------------------|\n");
            fclose(fp);
        }
    }
}
//View Weapon information with code...
void viewWeaponInfo(char *ptr) {
    FILE *fp;
    char line[256];
    fp=fopen("weapon_info.txt","r");
    if (fp==NULL) {
        printf("Error opening file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line,ptr)) {
            printf("|-----------------------|\n");
            printf("|ID  : Weapon Name\n");
            printf("|-----------------------|\n");
            printf("|%s",line);
            printf("|-----------------------|\n");
            fclose(fp);
        }
    }
}
//View Training information with code...
void viewTrainingInfo(char *ptr) {
    FILE *fp;
    char line[256];
    fp=fopen("training_info.txt","r");
    if (fp==NULL) {
        printf("Error opening file");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line,ptr)) {
            printf("|------------------------------------------------|\n");
            printf("|ID  : Training Duration(days) , Training Place\n");
            printf("|------------------------------------------------|\n");
            printf("|%s",line);
            printf("|------------------------------------------------|\n");
            fclose(fp);
        }
    }
}
void end(){
    FILE *fp3=fopen("log.txt","a");
    if (fp3==NULL) {
        printf("Error opening file");
        exit(1);
    }
    time_t t;
    struct tm *tmp;
    char log_time[20];
    t = time(NULL);
    tmp = localtime(&t);
    strftime(log_time,sizeof(log_time),"%d-%m-%Y %H:%M:%S",tmp);
    fprintf(fp3," : %s\n",log_time);
    fclose(fp3);
}
int main() {
    int choice;
    //Checking person is authentic or not...
    printf("\t\t+---------------------+\n");
    printf("\t\t+        LOGIN        +\n");
    printf("\t\t+---------------------+\n");
    bool login=false;
    FILE *fp1=fopen("user.txt","r");
    if (fp1==NULL) {
        printf("Error opening file");
        exit(1);
    }
    FILE *fp2=fopen("log.txt","a");
    while (!login) {
        char username[10],PIN[5],line[100];
        printf("Enter Username : ");
        scanf("%s",username);
        //Currently username=_________ and PIN=???...
        printf("Enter SECURITY PIN : ");
        scanf("%s",PIN);
        fgets(line, sizeof(line), fp1);
        time_t t;
        struct tm *tmp;
        char time_str[5];
        t = time(NULL);
        tmp = localtime(&t);
        strftime(time_str,sizeof(time_str),"%H%M",tmp);
        if (strstr(line,username) && strcmp(time_str,PIN)==0) {
            login=true;
            printf("=====Access Granted=====");
            fprintf(fp2,"%s : ",username);
            fclose(fp1);
        }
    }
    time_t t;
    struct tm *tmp;
    char log_time[30];
    t = time(NULL);
    tmp = localtime(&t);
    strftime(log_time,sizeof(log_time),"%d-%m-%Y %H:%M:%S",tmp);
    fprintf(fp2,"%s",log_time);
    fclose(fp2);
    char key[5];
    while (1) {
        //Main Menu...
        printf("\n\t\t|---------------------------------|\n");
        printf("\t\t|     Army Management System      |\n");
        printf("\t\t|---------------------------------|\n");
        printf("\t\t|1 -> Add Information Information.|\n");
        printf("\t\t|2 -> View Personal Info.         |\n");
        printf("\t\t|3 -> View Address Info.          |\n");
        printf("\t\t|4 -> View Family Info.           |\n");
        printf("\t\t|5 -> View Award Info.            |\n");
        printf("\t\t|6 -> View Weapon Info.           |\n");
        printf("\t\t|7 -> View Training Info.         |\n");
        printf("\t\t|0 -> Exit              .         |\n");
        printf("\t\t|---------------------------------|\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case (1):
                addAllInfo();
                break;
            case (2):
                viewPersonalInfo();
                break;
            case (3):
                printf("Enter Soldier ID : ");
                scanf("%s",key);
                viewAddressInfo(key);
                break;
            case (4):
                printf("Enter Soldier ID : ");
                scanf("%s",key);
                viewFamilyInfo(key);
                break;
            case (5):
                printf("Enter Soldier ID : ");
                scanf("%s",key);
                viewAwardInfo(key);
                break;
            case (6):
                printf("Enter Soldier ID : ");
                scanf("%s",key);
                viewWeaponInfo(key);
                break;
            case (7):
                printf("Enter Soldier ID : ");
                scanf("%s",key);
                viewTrainingInfo(key);
                break;
            case (0):
                end();
                exit(0);
            default:
                printf("Invalid choice. Please try again...\n");
        }
    }
    return 0;
}
