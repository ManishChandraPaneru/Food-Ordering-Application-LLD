#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
  virtual void deposit() = 0;
  virtual void withdraw() = 0;
  virtual ~Account() {}
};

class SavingsAccount : public Account
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
};

class CurrentAccount : public Account
{
public:
  void deposit() override
  {
    cout << "Current Account" << endl;
    cout << "Money Deposited" << endl;
  }

  void withdraw() override
  {
    cout << "Current Account" << endl;
    cout << "Money withdrawn." << endl;
  }
};

class FixedDeposit : public Account
{
public:
  void deposit() override
  {
    cout << "Fixed Deposit Account" << endl;
    cout << "Money Deposited" << endl;
  }

  // LSP VIOLATION: FixedDeposit can't support withdrawal
  // But we're forced to implement it due to inheritance
  void withdraw() override
  {
    cout << "Fixed Deposit Account" << endl;
    cout << "ERROR: Withdrawal not allowed in Fixed Deposit!" << endl;
    // Throwing exception or doing nothing violates LSP
    throw runtime_error("Fixed Deposit accounts don't support withdrawal!");
  }
};

// Function that expects any Account type
void performBankingOperations(Account *account)
{
  cout << "\n=== Banking Operations ===" << endl;

  // This should work for any Account subclass (LSP expectation)
  account->deposit();

  // This breaks for FixedDeposit - violates LSP!
  try
  {
    account->withdraw();
  }
  catch (const exception &e)
  {
    cout << "Exception caught: " << e.what() << endl;
  }
}

// Another function demonstrating LSP violation
void processMultipleAccounts(vector<Account *> accounts)
{
  cout << "\n=== Processing Multiple Accounts ===" << endl;

  for (Account *account : accounts)
  {
    cout << "\nProcessing account..." << endl;
    account->deposit();

    // This assumption fails for FixedDeposit accounts
    try
    {
      account->withdraw();
      cout << "Account operations completed successfully." << endl;
    }
    catch (const exception &e)
    {
      cout << "Account operation failed: " << e.what() << endl;
    }
  }
}

int main()
{
  cout << "=== LSP VIOLATION DEMONSTRATION ===" << endl;

  // Create different account types
  Account *savings = new SavingsAccount();
  Account *current = new CurrentAccount();
  Account *fd = new FixedDeposit();

  cout << "\n1. Individual Account Operations:" << endl;

  // These work fine for Savings and Current accounts
  cout << "\n--- Savings Account ---" << endl;
  performBankingOperations(savings);

  cout << "\n--- Current Account ---" << endl;
  performBankingOperations(current);

  // This breaks LSP - FixedDeposit can't be substituted properly
  cout << "\n--- Fixed Deposit Account (LSP VIOLATION) ---" << endl;
  performBankingOperations(fd);

  cout << "\n2. Multiple Accounts Processing:" << endl;
  vector<Account *> accounts = {savings, current, fd};
  processMultipleAccounts(accounts);

  cout << "\n=== LSP VIOLATION EXPLANATION ===" << endl;
  cout << "The FixedDeposit class violates LSP because:" << endl;
  cout << "1. It cannot be substituted for Account without changing behavior" << endl;
  cout << "2. It throws exceptions where the base class contract doesn't expect them" << endl;
  cout << "3. Client code that works with Account* breaks when given FixedDeposit*" << endl;
  cout << "4. The inheritance relationship is inappropriate - FD is not a behavioral subtype of Account" << endl;

  // Clean up
  delete savings;
  delete current;
  delete fd;

  return 0;
}