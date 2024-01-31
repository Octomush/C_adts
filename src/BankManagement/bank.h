#ifndef BANK_H
#define BANK_H

typedef struct {
    int accountNumber;
    char accountHolder[50];
    double balance;
} BankAccount;

typedef enum {
    SORT_BY_ACCOUNT_NUMBER,
    SORT_BY_ACCOUNT_HOLDER,
    SORT_BY_BALANCE,
} SortCriteria;

void sortAccounts(BankAccount *accounts, int numAccounts, SortCriteria criteria);
BankAccount *createAccount(const char *accountHolder, double initialBalance);
void freeAccounts(BankAccount *accounts, int numAccounts);

typedef void (*CustomOperation)(BankAccount *account);
void performCustomOperation(BankAccount *accounts, int numAccounts, CustomOperation operation);
void customOperationPrintBalance(BankAccount *account);
void customOperationDoubleBalance(BankAccount *account);

#endif