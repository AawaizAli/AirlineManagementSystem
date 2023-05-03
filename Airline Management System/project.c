#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

#include <time.h>

#include <windows.h>

char choice;

struct user {
  char firstname[15];
  char lastname[15];
  char username[15];
  char password[15];
  char second_password[15];
};

char ch[10][130] = {
  "LAHORE",
  "ISLAMABAD",
  "QUETTA",
  "MULTAN",
  "PESHAWAR"
};
char name[32][100] = {
  '\0'
};
char number[32][2] = {
  '\0'
};
int num1[32] = {
  0
};
int airline_no;
void airline();
void name_number(int booking, char numstr[100], int * price);
void booking();
int read_number(int airline_no);
void read_name(int airline_no);
void status();
void status_1(int airline_no);
void delay(int number_of_seconds);
void cancel();
void login();
void _Exit( int exit_argument );
void regis();
void payment();
void welcomeMessage();
int t_price = 0;
int i = 0;
char numstr[100];

int main() {

  int log;
  
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t    AIRLINE RESERVATION");
  printf("\n\n\n\t\t\t ___________________________________________________________\n");
  printf(" \t\t\t ***********************************************************");
  printf("\n\t\t\t ___________________________________________________________\n");
  printf("\n\n  [1]. LOGIN");
  printf("\n\n  [2]. SIGN UP");
  scanf("%d", &log);

  if (log == 1){
    login();
    welcomeMessage();
  } else if (log == 2){
    regis();
    login();
    welcomeMessage();
  } else {
    printf("INVALID CHOICE!");
  }

  int num, i;
  do {
    system("cls");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t    AIRLINE RESERVATION");
    printf("\n\n\n\t\t\t ___________________________________________________________\n");
    printf(" \t\t\t ***********************************************************");
    printf("\n\t\t\t ___________________________________________________________\n");

    printf("\n\t\t\t\t\t[1]. LIST");
    printf("\n\t\t\t ___________________________________________________________\n");
    printf("\n\n\t\t\t\t\t[2].FLIGHT BOOKING");
    printf("\n\t\t\t ___________________________________________________________\n");
    printf("\n\n\t\t\t\t\t[3].CANCEL BOOKING");
    printf("\n\t\t\t ___________________________________________________________\n");
    printf("\n\n\t\t\t\t\t[4].AIRPLANE STATUS BOARD");
    printf("\n\t\t\t ___________________________________________________________\n");
    printf("\n\n\t\t\t\t\t[5].EXIT");
    printf("\n\t\t\t ___________________________________________________________\n");
    printf(" \t\t\t ***********************************************************");

    printf("\n\t\t\t ___________________________________________________________\n\n");
    label:
      printf(" \n\n  ENTER YOUR CHOICE: ");
    scanf("%d", & num);
    switch (num) {
    case 1:
      airline(); //for list of airline
      break;
    case 2:
      booking(); //for booking the tickets
      break;
    case 3:
      cancel();
      break;
    case 4:
      status();
      break;
    default:
      printf("WRONG OPERATION SELECTED!!! TRY AGAIN");
      break;

    }
    getch();
  } while (num != 5);
  system("CLS");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("   THANK YOU FOR USING THIS AIRLINE RESERVATION SYSTEM");
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  getch();
  return 0;
}

void regis(){
	struct user c;
    int i = 0;
    char character = ' ';
    
    start:
	
	system("cls");
	
    FILE *fp = fopen("username.txt", "a");

    printf("\n\t\t\t ______________________________________________________________\n");

    printf("  \t\t\t **************************************************************");

    printf("\n\t\t\t ______________________________________________________________\n");

    printf("\n\t\t\t\t       A I R L I N E   R E G I S T R A T I O N\n");

    printf("\n\t\t\t\t\t\tS I G N   U P   F O R M \n");

    printf("\n\t\t\t ");

    printf("\n\t\t\t _______________________________________________________________\n");

    printf("\t\t\t ***************************************************************\n");

    printf("\t\t\t _______________________________________________________________\n");

    fflush(stdin); 
    printf("ENTER FIRST NAME: ");
    gets(c.firstname);
    fflush(stdin); 
    printf("ENTER LAST NAME: ");
    gets(c.lastname);
    fflush(stdin); 
    printf("ENTER USERNAME: ");
    gets(c.username);
    fflush(stdin); 
    printf("ENTER YOUR PASSWORD: ");
    while (i < 10) {
      c.password[i] = getch();
      character = c.password[i];
      if (character == 13){ 
        c.password[i] = 0;
        break;
      } else printf("*");
      i++;
    }
    i = 0;
    printf("\nCONFIRM YOUR PASSWORD: ");
    while (i < 10) {
      c.second_password[i] = getch();
      character = c.second_password[i];
      if (character == 13){ 
        c.second_password[i] = 0;
        break;
      } else printf("*");
      i++;
    }

    int k = strcmp(c.password, c.second_password);

    if (k == 0) {
        fprintf(fp, "\n%s %s %s %s", c.username, c.password, c.firstname, c.lastname);
        printf("\nID CREATED SUCCESSFULLY! PRESS ANY KEY TO CONTINUE..");
        getch();
    } else {
    	char k;
        printf("\nPasswords do not match!\nPress any key to restart, Press 'E' to exit..");
        k = getch();
        if (k == 'E'){
        	_Exit(0);
		} else {
			goto start;
		}
    }
    fclose(fp);

}

void airline() {
  system("cls");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t    AIRLINE RESERVATION");
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
  printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  AIRLINE LIST  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd \n\n");
  printf("   [1]  =>  %s\n\n", ch[0]);
  printf("   [2]  =>  %s\n\n", ch[1]);
  printf("   [3]  =>  %s\n\n", ch[2]);
  printf("   [4]  =>  %s\n\n", ch[3]);
  printf("   [5]  =>  %s\n\n", ch[4]);
}

void booking() {

  system("cls");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t    AIRLINE RESERVATION");
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
  airline(); //for seeing train least
  printf("   ENTER THE AIRLINE NUMBER: ");
  scanf("%d", & airline_no);
  system("cls");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t    FLIGHT RESERVATION");
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
  printf("YOUR AIRLINE NUMBER %d ********** %s", airline_no, ch[airline_no - 1]);
  status_1(airline_no);
  FILE * f1, * fopen(); //for reading the seats from the user.
  char str1[80] = "32", str2[4], str3[4];
  int seat1, seat2, booking = 0;
  if (airline_no == 1) {
    f1 = fopen("tr1.txt", "r+");
    fgets(str1, 80, f1);
    fclose(f1);
  } else if (airline_no == 2) {
    f1 = fopen("tr2.txt", "r+");
    fgets(str1, 80, f1);
    fclose(f1);
  } else if (airline_no == 3) {
    f1 = fopen("tr3.txt", "r+");
    fgets(str1, 80, f1);
    fclose(f1);
  } else if (airline_no == 4) {
    f1 = fopen("tr4.txt", "r+");
    fgets(str1, 80, f1);
    fclose(f1);
  } else if (airline_no == 5) {
    f1 = fopen("tr5.txt", "r+");
    fgets(str1, 80, f1);
    fclose(f1);
  }
  seat1 = atoi(str1); //covert the string into number
  if (seat1 <= 0) {
    printf("THERE IS NO SEATS LEFT ");
  } else {
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n\tseat 1-15 : economy class (pkr 200)\n\tseat 16-25 : airlineiness class (pkr 400)\n\tseat 26-32 : first class (pkr 600)\n");
    printf("\n   AVAILABLE SEATS: %d\n", seat1);
    printf("\n   NUMBER OF TICKETS: ");
    scanf("%d", & booking);
    printf("\n");

    seat1 = seat1 - booking;
    itoa(airline_no, numstr, 10);
    name_number(booking, numstr, & t_price);
    printf("   THE TOTAL BOOKING AMOUNT IS %d\n   Press any key to proceed to payment...\n", t_price);
    getch();
    payment();
    itoa(seat1, str1, 10);
    //for reading the seats from the user.
    if (airline_no == 1) {
      f1 = fopen("tr1.txt", "w");
      fputs(str1, f1);
      fclose(f1);
    } else if (airline_no == 2) {
      f1 = fopen("tr2.txt", "w");
      fputs(str1, f1);
      fclose(f1);
    } else if (airline_no == 3) {
      f1 = fopen("tr3.txt", "w");
      fputs(str1, f1);
      fclose(f1);
    } else if (airline_no == 4) {
      f1 = fopen("tr4.txt", "w");
      fputs(str1, f1);
      fclose(f1);
    } else if (airline_no == 5) {
      f1 = fopen("tr5.txt", "w");
      fputs(str1, f1);
      fclose(f1);
    }
  }
}

int read_number(int airline_no) //for putting the numeric value in the array
{
  char tempstr[100], tempstr2[12] = "number";
  FILE * a, * b;
  char numstr[100];
  int i = 0, j = 0, k;
  itoa(airline_no, numstr, 10);
  strcat(numstr, ".txt");
  strcat(tempstr2, numstr);
  a = fopen(tempstr2, "a+"); //for open the file to write the name in the file
  while (!feof(a)) {
    number[i][j] = fgetc(a);

    if (number[i][j] == ' ') {
      j = 0;
      i++;
    } else {
      j++;
    }
  }
  k = i;
  for (i = 0; i < k; i++) {
    num1[i] = atoi(number[i]);
  }
  fclose(a);
  return k;
}

void read_name(int airline_no) //for putting the numeric value in the array
{
  char tempstr1[12] = "status";
  FILE * b;
  char numstr[100];
  int i = 0, j = 0, k = 0;
  itoa(airline_no, numstr, 10);
  strcat(numstr, ".txt");
  strcat(tempstr1, numstr);
  b = fopen(tempstr1, "a+"); //for open the file to write the name in the file
  while (!feof(b)) {
    name[i][j] = fgetc(b);

    if (name[i][j] == ' ') {
      j = 0;
      i++;
    } else {
      j++;
    }

  }
  name[i][j] = '\0';
  k = i;
  fclose(b);
}

void status() {
  system("cls");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t\t      AIRLINE RESERVATION");
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
  int i, airline_no, index = 0, j;
  printf("   ENTER THE AIRLINE NUMBER: ");
  scanf("%d", & airline_no);
  j = read_number(airline_no);
  read_name(airline_no);
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t\t   AIRLINE NUMBER.%d: %s\n", airline_no, ch[airline_no - 1]);
  printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
  char tempname[33][10] = {
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty "
  };
  for (i = 0; i < j; i++) {
    strcpy(tempname[num1[i]], name[i]);
  }
  for (i = 0; i < 8; i++) {
    printf("   ");
    for (j = 0; j < 4; j++) {
      printf("%d.%s\t", index + 1, tempname[index + 1]);
      index++;
    }
    printf("\n");
  }
}

void status_1(int airline_no) {
  printf("Your Airline Number is %d ********** %s", airline_no, ch[airline_no - 1]);
  system("cls");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("\t\t      AIRLINE RESERVATION");
  printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
  int i, index = 0, j;
  j = read_number(airline_no);
  read_name(airline_no);
  char tempname[33][10] = {
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty ",
    "Empty "
  };
  for (i = 0; i < j; i++) {
    strcpy(tempname[num1[i]], name[i]);
  }
  for (i = 0; i < 8; i++) {
    printf("   ");
    for (j = 0; j < 4; j++) {
      printf("%d.%s\t", index + 1, tempname[index + 1]);
      index++;
    }
    printf("\n");
  }
}

void cancel() {
  int seat_no, i, j;
  char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
  printf("\n   ENTER THE AIRLINE NUMBER: ");
  scanf("%d", & airline_no);
  itoa(airline_no, numstr, 10);
  strcat(numstr, ".txt");
  strcat(tempstr1, numstr);
  strcat(tempstr2, numstr);
  read_number(airline_no);
  read_name(airline_no);
  status_1(airline_no);
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  printf("   ENTER THE SEAT NUMBER: ");
  scanf("%d", & seat_no);
  FILE * a, * b;
  a = fopen(tempstr1, "w+");
  b = fopen(tempstr2, "w+");
  for (i = 0; i < 32; i++) {
    if (num1[i] == seat_no) {
      for (j = 0; j < 32; j++) {
        if (num1[j] != seat_no && num1[j] != 0) {
          fprintf(b, "%d ", num1[j]);
          fprintf(a, "%s", name[j]);
        } else if (num1[j] == seat_no && num1[j] != 0) {
          strcpy(name[j], "Empty ");
        }
      }
    }
  }
  fclose(a);
  fclose(b);
  printf("\n\n");
  printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
  if (seat_no > 0 && seat_no < 16) {
      printf("   Your 200 rupees have been Returned\n");
    } else if (seat_no > 15 && seat_no < 26) {
      printf("   Your 400 rupees have been Returned\n");
    } else if (seat_no > 26 && seat_no < 33) {
      printf("   Your 600 rupees have been Returned\n");
    }
  printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
}

void login() {
  FILE *fp = fopen("username.txt", "r");
    char buffer[256];
    char delim[] = " ";
    char pass[10];
    char user[10];
    int a = 0;

    do{
    
    system("cls");

    printf("\n\t\t\t ______________________________________________________________\n");

    printf("  \t\t\t **************************************************************");

    printf("\n\t\t\t ______________________________________________________________\n");

    printf("\n\t\t\t\t       A I R L I N E   R E G I S T R A T I O N\n");

    printf("\n\t\t\t\t\t\tL O G I N  F O R M \n");

    printf("\n\t\t\t ");

    printf("\n\t\t\t _______________________________________________________________\n");

    printf("\t\t\t ***************************************************************\n");

    printf("\t\t\t _______________________________________________________________\n");

    printf("\n   ENTER USERNAME: ");
    fflush(stdin);
    gets(user);
    fflush(stdin);
    printf("   ENTER PASSWORD: ");
    char character = ' ';
    i = 0;
    while (i < 10) {
      pass[i] = getch();
      character = pass[i];
      if (character == 13){ 
        pass[i] = 0;
        break;
      } else printf("*");
      i++;
    }
    char flag = 'N';


    while(fgets(buffer,256,fp) != NULL){
        char *portion1 = strtok(buffer, delim);
        int i = strcmp(portion1, user);
        char *portion2 = strtok(NULL, delim);
        int j = strcmp(portion2, pass);

        //printf("%s %s\n", portion1, portion2);

        if(i == 0){
            if (j == 0){
            flag = 'Y';
            }
        }
    }

    if (flag == 'Y'){
        printf("  \n\n   WELCOME USER !!!!\n   Press any key to continue...");
        getch();
        break;
    } else {
        printf("\n   Password is incorrect, press any key to try again.... (%d tries remaining)", 2-a);
        getch();
        a++;
    }
    fclose(fp);
    } while (a <= 2);

    if (a > 2){
        printf("   Sorry you have entered the wrong username and password for 3 times!\n");
    }
    system("cls");
}

void welcomeMessage() {

  printf("\n\n\n\n\n");

  printf("\n\t\t\t ______________________________________________________________\n");

  printf("  \t\t\t **************************************************************");

  printf("\n\t\t\t ______________________________________________________________\n");

  printf("\n\t\t\t\t\t\tW E L C O M E\n   ");

  printf("\n\t\t\t \t\t\t     T O \n");

  printf("\n\t\t\t\t\t\tA I R L I N E\n");

  printf("\n\t\t\t\t \t  B O O K I N G  S Y S T E M \n");

  printf("\n\t\t\t ");

  printf("\n\t\t\t _______________________________________________________________\n");

  printf("\t\t\t ***************************************************************\n");

  printf("\t\t\t _______________________________________________________________\n");

  printf("\n\n\n\t\t\t Enter any key to continue.....");

  getch();
  system("cls");

}

void name_number(int booking, char numstr[100], int * price) {
  char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
  int number;
  FILE * a, * b;
  int i = 0;
  strcat(numstr, ".txt");
  strcat(tempstr1, numstr);
  strcat(tempstr2, numstr);
  a = fopen(tempstr1, "a"); //for open the file to write the name in the file
  b = fopen(tempstr2, "a"); //for open the file for writing the number in the file
  for (i = 0; i < booking; i++) //for entering the person name and seat number in the file
  {
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Enter the details for ticket no %d \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n", i + 1);
    fflush(stdin);
    printf("   ENTER THE SEAT NUMBER: ");
    scanf("%d", & number);
    if (number > 0 && number < 16) {
      * price += 200;
    } else if (number > 15 && number < 26) {
      * price += 400;
    } else if (number > 26 && number < 33) {
      * price += 600;
    }
    fflush(stdin);
    printf("\n   ENTER THE PERSON NAME: ");
    scanf("%s", name[number - 1]);
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n");
    itoa(number, tempstr, 10);
    fprintf(a, "%s ", name[number - 1]);
    fprintf(b, "%s ", tempstr);

  }
  fclose(a);
  fclose(b);
}

void delay(int number_of_seconds)
{
    
    int milli_seconds = 1000 * number_of_seconds;
 
    
    clock_t start_time = clock();
 
    
    while (clock() < start_time + milli_seconds)
        ;
}

void payment() {

  system("cls");

  int number, expiry_month, expiry_year, cvv;
  printf("\n\t\t\t ___________________________________________________________\n");
  printf("\n\t\t\t\t\t[1]. PAYMENT OPTION");
  printf("\n\t\t\t ___________________________________________________________\n");
  
  printf("\n\t\t\t\tCHOOSE YOUR PAYMENT OPTION:\n\n\t\t\t\tA CASH\n\n\t\t\t\tB.CARD\n");
  fflush(stdin);
  scanf("%c",&choice);
  if (choice == 'A') {

    printf("\t\t\t\tPROCEED TO COUNTER AND DEPOSIT YOUR CASH\n");

  } else if(choice == 'B') {

    printf("\t\t\t\tENTER CARD NUMBER: ");
    scanf("%d", & number);

    fflush(stdin);
    printf("\t\t\t\tENTER EXPIRY DATE: (MM/YY): ");
    scanf("%d/%d", &expiry_month, &expiry_year);

    fflush(stdin);
    printf("\t\t\t\tENTER CVV FROM BACK OF YOUR CARD: ");
    scanf("%d", & cvv);
    
    printf("\t\t\t\tPLEASE WAIT.............\n");
    delay(4);
    printf("\t\t\t\tYOUR TRANSACTION WAS SUCCESSFUL");

  }
}
