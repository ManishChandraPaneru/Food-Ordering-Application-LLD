#include <bits/stdc++.h>
using namespace std;

// Base abstract class - only deposit functionality
class NonWithdrawableAccount
{
public:
  virtual void deposit() = 0;
  virtual void getBalance() = 0;
  virtual ~NonWithdrawableAccount() {}
};

// Derived abstract class - adds withdrawal functionality
class WithdrawableAccount : public NonWithdrawableAccount
{
public:
  virtual void withdraw() = 0;
  virtual ~WithdrawableAccount() {}
};

// Fixed Deposit - inherits from NonWithdrawableAccount (no withdrawal)
class FixedDeposit : public NonWithdrawableAccount
{
public:
  void deposit() override
  {
    cout << "Fixed Deposit Account" << endl;
    cout << "Money Deposited successfully." << endl;
  }

  void getBalance() override
  {
    cout << "Fixed Deposit Balance: Rs. 50,000" << endl;
  }
};

// Savings Account - inherits from WithdrawableAccount (supports withdrawal)
class SavingsAccount : public WithdrawableAccount
{
public:
  void deposit() override
  {
    cout << "Savings Account" << endl;
    cout << "Money Deposited." << endl;
  }

  void withdraw() override
  {
    cout << "Savings Account" << endl;
    cout << "Money withdrawn." << endl;
  }

  void getBalance() override
  {
    cout << "Savings Account Balance: Rs. 25,000" << endl;
  }
};

// Current Account - inherits from WithdrawableAccount (supports withdrawal)
class CurrentAccount : public WithdrawableAccount
{
public:
  void deposit() override
  {
    cout << "Current Account" << endl;
    cout << "Money Deposited." << endl;
  }

  void withdraw() override
  {
    cout << "Current Account" << endl;
    cout << "Money withdrawn." << endl;
  }

  void getBalance() override
  {
    cout << "Current Account Balance: Rs. 75,000" << endl;
  }
};

// Recurring Deposit - another NonWithdrawableAccount type
class RecurringDeposit : public NonWithdrawableAccount
{
public:
  void deposit() override
  {
    cout << "Recurring Deposit Account" << endl;
    cout << "Monthly installment deposited." << endl;
  }

  void getBalance() override
  {
    cout << "Recurring Deposit Balance: Rs. 12,000" << endl;
  }
};

// Functions that work with NonWithdrawableAccount (LSP compliant)
void performBasicOperations(NonWithdrawableAccount *account)
{
  cout << "\n=== Basic Account Operations ===" << endl;
  account->deposit();
  account->getBalance();
}

// Functions that work with WithdrawableAccount (LSP compliant)
void performFullBankingOperations(WithdrawableAccount *account)
{
  cout << "\n=== Full Banking Operations ===" << endl;
  account->deposit();
  account->withdraw();
  account->getBalance();
}

// Process multiple non-withdrawable accounts
void processNonWithdrawableAccounts(vector<NonWithdrawableAccount *> accounts)
{
  cout << "\n=== Processing Non-Withdrawable Accounts ===" << endl;

  for (NonWithdrawableAccount *account : accounts)
  {
    cout << "\nProcessing account..." << endl;
    account->deposit();
    account->getBalance();
    cout << "Account operations completed successfully." << endl;
  }
}

// Process multiple withdrawable accounts
void processWithdrawableAccounts(vector<WithdrawableAccount *> accounts)
{
  cout << "\n=== Processing Withdrawable Accounts ===" << endl;

  for (WithdrawableAccount *account : accounts)
  {
    cout << "\nProcessing account..." << endl;
    account->deposit();
    account->withdraw();
    account->getBalance();
    cout << "Account operations completed successfully." << endl;
  }
}

int main()
{
  cout << "=== LSP COMPLIANT IMPLEMENTATION ===" << endl;

  // Create different account types
  NonWithdrawableAccount *fd = new FixedDeposit();
  NonWithdrawableAccount *rd = new RecurringDeposit();
  WithdrawableAccount *savings = new SavingsAccount();
  WithdrawableAccount *current = new CurrentAccount();

  cout << "\n1. Non-Withdrawable Account Operations:" << endl;

  // These work perfectly - no LSP violations
  cout << "\n--- Fixed Deposit ---" << endl;
  performBasicOperations(fd);

  cout << "\n--- Recurring Deposit ---" << endl;
  performBasicOperations(rd);

  cout << "\n2. Withdrawable Account Operations:" << endl;

  // These work perfectly with full functionality
  cout << "\n--- Savings Account ---" << endl;
  performFullBankingOperations(savings);

  cout << "\n--- Current Account ---" << endl;
  performFullBankingOperations(current);

  cout << "\n3. Polymorphic Operations (LSP Demonstration):" << endl;

  // All non-withdrawable accounts work consistently
  vector<NonWithdrawableAccount *> nonWithdrawableAccounts = {fd, rd};
  processNonWithdrawableAccounts(nonWithdrawableAccounts);

  // All withdrawable accounts work consistently
  vector<WithdrawableAccount *> withdrawableAccounts = {savings, current};
  processWithdrawableAccounts(withdrawableAccounts);

  cout << "\n4. Demonstrating LSP Compliance:" << endl;

  // Savings can be used as NonWithdrawableAccount (LSP compliant)
  cout << "\n--- Using Savings as NonWithdrawableAccount ---" << endl;
  NonWithdrawableAccount *savingsAsBase = savings;
  performBasicOperations(savingsAsBase);

  // Current can be used as NonWithdrawableAccount (LSP compliant)
  cout << "\n--- Using Current as NonWithdrawableAccount ---" << endl;
  NonWithdrawableAccount *currentAsBase = current;
  performBasicOperations(currentAsBase);

  cout << "\n=== LSP COMPLIANCE EXPLANATION ===" << endl;
  cout << "This design follows LSP because:" << endl;
  cout << "1. Each derived class can be substituted for its base class without issues" << endl;
  cout << "2. No exceptions are thrown where the base class doesn't expect them" << endl;
  cout << "3. Behavioral contracts are maintained throughout the hierarchy" << endl;
  cout << "4. Inheritance relationships reflect true behavioral subtypes" << endl;
  cout << "5. Client code works consistently with any subtype" << endl;

  cout << "\n=== DESIGN BENEFITS ===" << endl;
  cout << "1. Clear separation of concerns (withdrawable vs non-withdrawable)" << endl;
  cout << "2. Type safety - impossible to call withdraw() on FixedDeposit" << endl;
  cout << "3. Extensible - new account types can be added easily" << endl;
  cout << "4. Polymorphism works correctly at each level" << endl;

  // Clean up
  delete fd;
  delete rd;
  delete savings;
  delete current;

  return 0;
}