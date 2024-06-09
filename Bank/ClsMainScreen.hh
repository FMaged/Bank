#pragma once 
#include "ClsScreen.hh"
#include "ClsClientListScreen.hh"
#include "ClsAddNewClientScreen.hh"
#include "ClsDeleteClientScreen.hh"
#include "ClsUpdateClientScreen.hh"
#include "ClsFindClientScreen.hh"
#include "ClsTransactionMenueScreen.hh"
#include "ManageUsersScreen.hh"
#include "ClsLoginRegisterScreen.hh"
#include "ClsCurrencyExchangeMenueScreen.hh"
#include "ClsValidate.hh"
#include "Global.hh"
#include <iomanip>


class ClsMainScreen :protected ClsScreen {

private:

    enum enMainScreenOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eShowLoginRegister=8, eCurrencyExchange=9,eExit = 0
    };

    static short _readMainMenueOption() {
        cout << setw(37) << left << "" << "Chose what do you want [0 - 9]" << endl;
        short choice = ClsValidate::readIntNumberBetween(0,9, "Enter Number between 0 to 9?");
        return choice;
    }
    static void _goBackToMainMenue() {
        // cout<<setw(37)<<left<<"Press any Key to go back to Main Menue...\n";
        system("pause");
        showMainMenue();
    }
    static void _showAllClientScreen() {
        ClsClientListScreen::showClientsList();
    }
    static void _addNewClientnScreen() {
        ClsAddNewClientScreen::showAddNewClientScreen();
    }
    static void _deleteClientScreen() {
        ClsDeleteClientScreen::showDeleteClientScreen();
    }
    static void _updateClientScreen() {
        ClsUpdateClientScreen::showUpdateClientScreen();
    }
    static void _findClientScreen() {
        ClsFindClientScreen::showFindClientScreen();
    }
    static void _transactionsMenueScreen() {
        ClsTransactionMenueScreen::showTransactionMenue();
    }
    static void _manageUsersScreen() {
        ClsManageUsersScreen::showManageUserScreen();
    }
    static void _loginRegisterScreen() {
        ClsLoginRegisterScreen::showLoginRegisterScreen();
    }
    static void _currencyExchangeScreen() {
        ClsCurrencyExchangeScreen::showCurrencyExchange();
    }
    static void _logOut() {
        CurrentUser = ClsUser::find("", "");
    }







    static void _preformMainMenueOption(enMainScreenOptions MainMenueOption) {
        switch (MainMenueOption) {
        case enMainScreenOptions::eListClients:
            system("cls");
            _showAllClientScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eAddNewClient:
            system("cls");
            _addNewClientnScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eDeleteClient:
            system("cls");
            _deleteClientScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eUpdateClient:
            system("cls");
            _updateClientScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eFindClient:
            system("cls");
            _findClientScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eShowTransactionsMenue:
            system("cls");
            _transactionsMenueScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eManageUsers:
            system("cls");
            _manageUsersScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eShowLoginRegister:
            system("cls");
            _loginRegisterScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eCurrencyExchange:
            system("cls");
            _currencyExchangeScreen();
            _goBackToMainMenue();
            break;
        case enMainScreenOptions::eExit:
            system("cls");
            _logOut();
            break;

        }
    }
public:
    static void showMainMenue() {
        system("cls");
        _drawScreenHeader("\t     Main Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t     Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[0] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _preformMainMenueOption((enMainScreenOptions)_readMainMenueOption());
    }





};