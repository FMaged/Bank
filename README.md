# Bank Management System

This repository contains the code for a **Bank Management System** built using C++. The system enables management of clients, users, currency exchange,


## Features
- **Client Management**: Add, delete, update, and search clients.
- **User Management**: Manage bank users with screens for adding, deleting, and updating users.
- **Currency Exchange**: View, list, find, and update exchange rates for various currencies.
- **Transaction Management**: Perform deposits, withdrawals, and transfers between accounts.
- **Logging**: Track transfers and transactions using log files.
  
## Project Structure

Here is an overview of the folder and file structure of the project:

### Header Files (`Headerdateien`)
- **core**
  - `ClsClient.hh`: Manages client data and operations.
  - `ClsCurrency.hh`: Handles currency exchange rates and conversions.
  - `ClsPerson.hh`: Defines a base class for a person (inherited by clients and users).
  - `ClsUser.hh`: Manages user data and operations.
  
- **Lib**
  - `ClsDate.hh`: Date handling functionality.
  - `ClsString.hh`: String utility functions.
  - `ClsUtil.hh`: General utility functions.
  - `ClsValidate.hh`: Input validation functionality.
  
- **Screens**
  - **Client**
    - **TransactionMenue**:
      - `ClsDepositScreen.hh`: Screen for depositing funds.
      - `ClsTotalBalancesScreen.hh`: Screen to display total balances.
      - `ClsTransactionMenueScreen.hh`: Main transaction menu.
      - `ClsTransfer.hh`: Handles fund transfers.
      - `ClsTransferLog.hh`: Log for tracking transfers.
      - `ClsWithdrawScreen.hh`: Screen for withdrawals.
    - `ClsAddNewClientScreen.hh`: Screen for adding a new client.
    - `ClsClientListScreen.hh`: Displays a list of clients.
    - `ClsDeleteClientScreen.hh`: Screen for deleting a client.
    - `ClsFindClientScreen.hh`: Screen for finding clients.
    - `ClsUpdateClientScreen.hh`: Screen for updating client information.

  - **CurrencyExchange**
    - `ClsCurrencyExchangeMenueScreen.hh`: Main currency exchange menu.
    - `ClsCurrencyListScreen.hh`: Screen displaying available currencies.
    - `ClsFindCurrencyScreen.hh`: Screen for finding a currency.
    - `ClsUpdateRateScreen.hh`: Screen for updating exchange rates.

  - **ManageUsers**
    - `ClsLoginRegisterScreen.hh`: Screen for user login and registration.
    - `ClsLoginScreen.hh`: Screen for user login.
    - `ClsAddNewUserScreen.hh`: Screen for adding a new user.
    - `ClsDeleteUserScreen.hh`: Screen for deleting a user.
    - `ClsFindUserScreen.hh`: Screen for finding a user.
    - `ClsListUsersScreen.hh`: Screen for listing all users.
    - `ClsUpdateUserScreen.hh`: Screen for updating user information.
    - `ManageUsersScreen.hh`: Main screen for managing users.

  - **Global.hh**: Global project definitions.
  - **ClsMainScreen.hh**: Main menu screen.


### Source Files (`Quelldateien`)
- **Lib**
  - `ClsClient.cpp`: Implementation of client management.
  - `ClsDate.cpp`: Implementation for date handling.
  - `ClsPerson.cpp`: Implementation for general person management.
  - `ClsString.cpp`: Implementation of string utility functions.
  - `ClsUtil.cpp`: General utility functions.
  - `ClsValidate.cpp`: Input validation functions.
  
- **main.cpp**: Entry point of the application.

### Resource Files (`Ressourcendateien`)
- `Clients.txt`: Stores client data.
- `Currencies.txt`: Stores currency information.
- `LoginRegister.txt`: Stores login and registration information.
- `TransferLog.txt`: Log of all transfer activities.
- `Users.txt`: Stores user data.



