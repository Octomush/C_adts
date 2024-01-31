#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include "bank.h"

void saveAccountsToFile(const char *filename, BankAccount *accounts, int numAccounts);
void loadAccountsFromFile(const char *filename, BankAccount **accounts, int *numAccounts);

#endif