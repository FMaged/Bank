
#pragma once
#include <fstream>
#include "ClsPerson.hh"
#include "ClsString.hh"
#include "CLsDate.hh"





static string ClientsFileName = "Clients.txt";
class ClsClient :public ClsPerson {
public:
    struct stTransferLogRecord {
        string dateTime;
        string sourceAccountNumber;
        string destinationAccountNumber;
        double amount;
        double srcBalanceAfter;
        double destBalanceAfter;
        string userName;
    };
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
    enMode _Mode;
    string _accountNumber;
    std::string _pinCode;
    double _balance;
    bool _markForDelete = false;

private:
    static ClsClient _convertLineToClient(string Line, string Seperator = "#//#");
    static string _converClientToLine(ClsClient Client, string Seperator = "#//#");
    static ClsClient _getEmptyClientObj();
    static vector<ClsClient>_loadClientsFromFile();
    static void _saveClientsDataToFile(vector<ClsClient>vClients);
    void _update();
    void _addNew();
    void _registerTransferLog(float Amount, ClsClient DestinationClient, string UserName);
    string _prepareTrasferLogRecord(float Amount, ClsClient DestinationClient, string UserName,string Seperator ="#//#");
    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#");

    void _addDataLineToFile(string Line);


public:
    ClsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
        :ClsPerson(FirstName, LastName, Email, Phone) {
        _Mode = Mode;
        _accountNumber = AccountNumber;
        _pinCode = PinCode;
        _balance = Balance;
    }

    bool isEmpty()const;
    string getAccountNumber()const;
    double getBalance()const;
    string getPinCode()const;

    void setBalance(double Balance);
    void setPinCode(string PinCode);
    //void print();
    static ClsClient find(string AccountNumber);
    static bool isClientExist(string AccountNumber);
    static ClsClient addNewClient(string AccountNumber);

    void deposit(double Amount);
    bool withdraw(double Amount);
    bool deleteClient();
    static vector<ClsClient> getClientsList();
    static double getTotalBalances();


    enum enSaveResult { svFaildEmptyObj = 0, svSucceeded = 1, svFaildAccNumberExists = 2 };
    enSaveResult save();
    bool transfer(float Amount, ClsClient& DestinationClient,string UserName);
    
   

    static vector<stTransferLogRecord> getTransferLogList();





    



};