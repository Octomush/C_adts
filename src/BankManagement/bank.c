#include "bank.h"
#include <stdio.h>
#include <stdlib.h>

BankAccount *createAccount(const char *accountHolder, double initialBalance) {
  // TODO: write a suitable function that creates the BankAccount as defined in bank.h
  return NULL;
}

void freeAccounts(BankAccount *accounts, int numAccounts) {
  // TODO: write a suitable function to free the bank accounts
}

void performCustomOperation(BankAccount *accounts, int numAccounts, CustomOperation operation) {
  // TODO: very simple, so do not overthink for this one!
  // TODO: Make a function that applies the func-pointer: CustomOperation to each of the account in accounts.
}

void customOperationPrintBalance(BankAccount *account) {
  printf("Account Holder: %s, Balance: $%.2lf\n", account->accountHolder, account->balance);
}

void customOperationDoubleBalance(BankAccount *account) {
  account->balance *= 2;
}

int compareAccountNumber(const void *a, const void *b) {
  // TODO: self-explanatory
  return 0;
}

int compareAccountHolder(const void *a, const void *b) {
  // TODO: self-explanatory
  return 0;
}

int compareBalance(const void *a, const void *b) {
  // TODO: self-explanatory
  return 0;
}

void sortAccounts(BankAccount *accounts, int numAccounts, SortCriteria criteria) {
  // TODO: sort the accounts in the accounts list according the criteria
  // TODO: What type of sorting function can you use?
  // use qsort()
}