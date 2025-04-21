#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h> // for _getcwd()

typedef struct student_struct
{
   char Student_Name[100];
   double Homework[5]; // each one is from 0 - 100
   double Exam[3];     // each one is from 0 - 100
   double Grade_Prcnt; // your program calculates this
   char Letter_Grade;  // your program determines this
} student_info;

// reading the information from the text file pointed to by inp to populate the array myclass.
void read_function(FILE *inp, student_info myclass[])
{
   int i, j;

   for (i = 0; i < 15; i++)
   {
      fgets(myclass[i].Student_Name, sizeof(myclass[i].Student_Name), inp);
      // Remove the newline character from the student name, if present
      myclass[i].Student_Name[strcspn(myclass[i].Student_Name, "\n")] = '\0';

      for (j = 0; j < 5; j++)
      {
         fscanf(inp, "%lf", &myclass[i].Homework[j]);
      }
      for (j = 0; j < 3; j++)
      {
         fscanf(inp, "%lf", &myclass[i].Exam[j]);
      }
   }
}

// print_student is to print information of one student.
void print_student(student_info student)
{
}

int main(void)
{

   char cwd[1024];
   if (_getcwd(cwd, sizeof(cwd)) != NULL)
   {
      printf("Current working dir: %s\n", cwd);
   }
   else
   {
      perror("getcwd() error");
      exit(1);
   }

   char quitKey = 'n';
   FILE *inp = NULL;
   student_info myclass[15];

   while (quitKey != 'q' && quitKey != 'Q')
   {

      inp = fopen("ClassData.txt", "r");

      if (inp == NULL)
      {
         printf("Error opening file.\n");
         return 1;
      }
      else
      {
         read_function(inp, myclass);
      }
      perror("fopen failed");
      // for debug
      quitKey == 'q';
   }
   // Close the file after reading
   fclose(inp);

   // Example: Print the data for the first student to check
   printf("Student: %s\n", myclass[0].Student_Name);
   for (int i = 0; i < 5; i++)
   {
      printf("Homework[%d] = %.2lf\n", i, myclass[0].Homework[i]);
   }
   for (int i = 0; i < 3; i++)
   {
      printf("Exam[%d] = %.2lf\n", i, myclass[0].Exam[i]);
   }

   return 0;
}
