#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // TODO: Handle memory leak

    vector<Account *> sav_accounts;
    sav_accounts.push_back(new Savings_Account{});
    sav_accounts.push_back(new Savings_Account{"Superman"});
    sav_accounts.push_back(new Savings_Account{"Batman", 2000});
    sav_accounts.push_back(new Savings_Account{"Wonderwoman", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    vector<Account *> check_accounts;
    check_accounts.push_back(new Checking_Account{});
    check_accounts.push_back(new Checking_Account{"Kirk"});
    check_accounts.push_back(new Checking_Account{"Spock", 2000});
    check_accounts.push_back(new Checking_Account{"Bones", 5000});

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    vector<Account *> trust_accounts;
    trust_accounts.push_back(new Trust_Account{});
    trust_accounts.push_back(new Trust_Account{"Athos", 10000, 5.0});
    trust_accounts.push_back(new Trust_Account{"Porthos", 20000, 4.0});
    trust_accounts.push_back(new Trust_Account{"Aramis", 30000});

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    for (int i = 1; i <= 5; i++)
        withdraw(trust_accounts, 1000);

    for (const auto &vec : {sav_accounts, check_accounts, trust_accounts})
    {
        for (const auto &ptr : vec)
        {
            delete ptr;
        }
    }

    return 0;
}
