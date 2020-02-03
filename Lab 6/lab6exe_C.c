// ENSF 337 - fall 2018 - lab 6 - exercise C
// M. Moussavi
// lab6exe_C.c

#include <stdio.h>
#include <stdlib.h>
#include "lab6exe_C.h"

int main(void) {
    char input_filename[30] = "lab6exe_C.txt";
    char output_filename[30]= "lab6exe_C_output.txt";
    IntVector intVec;
    intVec.number_of_data = 0;

    read_text_file(&intVec, input_filename);

    display_single_column(&intVec);

    display_multiple_column(&intVec, 4, output_filename);

    return 0;
}

void read_text_file (IntVector* vec, const char* input_filename){
    int nscan;
    FILE *fp = fopen (input_filename, "r");

    if(fp == NULL){
        fprintf(stderr, "Sorry cannot open the text file %s.\n", input_filename);
        exit(1);
    }

    do{
        nscan = fscanf(fp,"%d", &vec->storage[vec->number_of_data]);
        if(nscan == 1)
            (vec->number_of_data)++;
        else if (nscan != EOF){
            fprintf(stderr, "Invalid data in %s.\n", input_filename);
            exit(1);
        }
    }while ((nscan != EOF) & (vec->number_of_data < MAX_CAPACITY));

    fclose(fp);
}

void display_single_column(const IntVector* intV){
    int i;
    for (i = 0; i < intV ->number_of_data; i++ )
        printf("%10d\n", intV ->storage[i]);
}

void display_multiple_column(const IntVector *intV, int col, const char* output_filename)
{
  // STUDENTS MUST COMPLETE THE DEFINITION OF THIS FILE
  int i = 0, j = 1;

  FILE* fp = fopen(output_filename, "w");
  if (fp == NULL) {
    fprintf(stderr, "Sorry cannot open the text file %s.\n", output_filename);
    exit(1);
  }

  col = (col > intV->number_of_data) ? intV->number_of_data : col;
  while (1) {
    for (int i = 0; i < col; i++) {
       if (i >= (intV->number_of_data)) {
        j = 0;
        break;
      }
      if (intV->storage[i]<10)
         fprintf(fp, "%d ", intV->storage[i]);
       else if (intV->storage[i]<100)
         fprintf(fp, "%d ", intV->storage[i]);
      else if (intV->storage[i]<1000)
         fprintf(fp, "%d ", intV->storage[i]);
      i++;
    }
    if (!(j))
       break;
    fprintf(fp, "\n");
  }
  fclose(fp);
}

/*    FILE *outp = fopen (output_filename, "w");
    if (outp == NULL) {
      fprintf (stderr, "Error: cannot open the file file");
      exit(1);
    }

    int i = 0;
    int j;

    while (i < intV->number_of_data){
      j = 0;
      while (j < col){
        fprintf(outp, "%10d ", intV->storage[i]);
        i++;
        j++;
      }
      fprintf(outp, "\n");
    }
  fclose(outp);*/
  // STUDENTS MUST COMPLETE THE DEFINITION OF THIS FILE
