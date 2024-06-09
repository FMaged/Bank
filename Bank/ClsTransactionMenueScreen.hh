#pragma once 
#include "ClsScreen.hh"
#include "ClsMainScreen.hh"
#include "ClsValidate.hh"
#include "ClsDepositScreen.hh"
#include "ClsWithdrawScreen.hh"
#include "ClsTotalBalancesScreen.hh"
#include "ClsTransfer.hh"
#include "ClsTransferLog.hh"
#include <iomanip>



class ClsTransactionMenueScreen :protected ClsScreen {
private:
    enum enTransactionScreenOption { Deposit = 1, Withdraw = 2, TotalBalances = 3, Transfer=4, TransferLog=5,MainMenue = 6 };

    static short _readTransactionScreenOption() {
        cout << setw(37) << left << "" << "Chose what do you want [1 - 6]" << endl;
        short choice = ClsValidate::readIntNumberBetween(1, 6, "Enter Number between 1 to 6?");
        return choice;
    }
    static void _goBackToTransactionMenue() {
        system("pause");
        showTransactionMenue();
    }
    static void _deposit() {
        ClsDepositScreen::showDepositScreen();
    }
    static void _withdraw() {
        ClsWithdrawScreen::showWithdrawScreen();
    }
    static void _totalBalances() {
        ClsTotalBalancesScreen::showTotalBalancesScreen();
    }
    static void _transfer() {
        ClsTransferScreen::showTransferScreen();
    }
    static void _transferLog() {
        ClsTransferLogScreen::showTransferLogScreen();
    }
    static void _goBackToMainMenue() {
        //dont need to do anything it will go back to the main menue.          
    }













    static void _prefomTransactionMenueOption(enTransactionScreenOption TransactionScreenOption) {
        switch (TransactionScreenOption) {
        case enTransactionScreenOption::Deposit:
            system("cls");
            _deposit();
            _goBackToTransactionMenue();
            break;
        case enTransactionScreenOption::Withdraw:
            system("cls");
            _withdraw();
            _goBackToTransactionMenue();
            break;
        case enTransactionScreenOption::TotalBalances:
            system("cls");
            _totalBalances();
            _goBackToTransactionMenue();
            break;
        case enTransactionScreenOption::Transfer:
            system("cls");
            _transfer();
            _goBackToTransactionMenue();
            break;
        case enTransactionScreenOption::TransferLog:
            system("cls");
            _transferLog();
            _goBackToTransactionMenue;
            break;
        case enTransactionScreenOption::MainMenue:
            system("cls");
            _goBackToMainMenue();
            break;
        }

    }
public:

    static void showTransactionMenue() {
        system("cls");
        if (!checkAccessRight(ClsUser::enPermission::pTransactios)) {
            return;
        }
        _drawScreenHeader("\t   Transaction Screen");
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\t   Transaction Menue\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _prefomTransactionMenueOption((enTransactionScreenOption)_readTransactionScreenOption());
    }













};