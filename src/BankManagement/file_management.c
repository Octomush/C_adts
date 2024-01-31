#include "file_management.h"
#include "bank.h"
#include <stdio.h>

void saveAccountsToFile(const char *filename, BankAccount *accounts, int numAccounts) {
  // TODO: write a suitable function that saves the account information into a file
  // TODO: if a file does not exist, it should create one, and if one already exists, simply modify them.
  // TODO: The account information is the best if it is stored in a table-like format.
  FILE *file = fopen(filename, "wb");
}

void loadAccountsFromFile(const char *filename, BankAccount **accounts, int *numAccounts) {
  // TODO: write a suitable function to read all the bank account details in the file into the array of BankAccounts.
  FILE *file = fopen(filename, "rb");
}