#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adress {
    char *avenue;
    int number;
    char *country;
} TAdress;

typedef struct record {
    char *lastName;
    char *firstName;
    char *middleName;
    TAdress adr;
} TNameAndAdress;

typedef struct recordAll {
    TNameAndAdress name;
    int employeeNumber;
    float hoursWorked;
} TInputRecord;

int main() {
    TInputRecord *ptrDataInput;
    // Letra a)
    ptrDataInput = (TInputRecord *)calloc(1, sizeof(TInputRecord));
    // Letra b)
    ptrDataInput->name.adr.avenue = (char *)calloc(100, sizeof(char));
    // Letra c)
    ptrDataInput->name.adr.country = (char *)calloc(50, sizeof(char));
    // Letra d)
    ptrDataInput->name.lastName = (char *)calloc(10, sizeof(char)); 
    // Letra e)
    ptrDataInput->name.firstName = (char *)calloc(100, sizeof(char));
    // Letra f)
    ptrDataInput->name.middleName = (char *)calloc(50, sizeof(char));
    // Letra g)
    ptrDataInput->name.adr.avenue;
    // Letra h)
    printf("Informe a avenida: ");
    fflush(stdin);
    fgets(ptrDataInput->name.adr.avenue, 99, stdin);
    // Letra i)
    printf("Informe o primeiro nome: ");
    fflush(stdin);
    fgets(ptrDataInput->name.firstName, 99, stdin);
    // letra j)
    printf("\nPrimeiro Nome: %s", ptrDataInput->name.firstName);
    printf("Avenida: %s", ptrDataInput->name.adr.avenue);
    // letra k)
    free(ptrDataInput->name.firstName);
    free(ptrDataInput->name.adr.avenue);
    free(ptrDataInput);
    
    return 0;
}