#include "bank.h"
#include "file_management.h"
#include <stdio.h>

int main() {
  BankAccount *accounts = NULL;
  int numAccounts = 0;

  // Load accounts from file
  loadAccountsFromFile("accounts.dat", &accounts, &numAccounts);

  // Bank management operations...
  // Sort accounts by balance
  sortAccounts(accounts, numAccounts, SORT_BY_BALANCE);

  // Perform custom operation: print balance
  performCustomOperation(accounts, numAccounts, customOperationPrintBalance);

  // Perform custom operation: double balance
  performCustomOperation(accounts, numAccounts, customOperationDoubleBalance);

  // Save accounts to file before exiting
  saveAccountsToFile("accounts.dat", accounts, numAccounts);

  // Free allocated memory
  freeAccounts(accounts, numAccounts);

  return 0;
}