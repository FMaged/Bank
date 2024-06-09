#pragma once 
#include <fstream>
#include "ClsString.hh"

class ClsCurrency {
private:
	enum enMode {EmptyMode=0,UpdateMode=1};
	enMode _mode;
	string _country;
	string _currencyCode;
	string _currencyName;
	float _rate;

	static ClsCurrency _convertLinetoCurrencyObject(string Line, string Seperator = "#//#") {
		vector<string>vCurrencyData = ClsString::splitString(Line, Seperator);
		return ClsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],stod(vCurrencyData[3]));
	}
	static string _converCurrencyObjectToLine(ClsCurrency Currency, string Seperator="#//#") {
		string stCurrencyRecord="";
		stCurrencyRecord += Currency._country + Seperator;
		stCurrencyRecord += Currency._currencyCode + Seperator;
		stCurrencyRecord += Currency._currencyName + Seperator;
		stCurrencyRecord += to_string(Currency._rate);
		return stCurrencyRecord;
	}
	static vector<ClsCurrency>_loadCurrencysDataFromFile() {
		vector<ClsCurrency>vCurrencies;
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)){
				vCurrencies.push_back(_convertLinetoCurrencyObject(line));

			}
			myFile.close();
		}
		return vCurrencies;
	}
	static void _saveCurrencyDataToFile(vector<ClsCurrency>vCurrencies) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::out);
		if (myFile.is_open()) {
			for (ClsCurrency& Currency : vCurrencies) {
				myFile << _converCurrencyObjectToLine(Currency)<<endl;
				
			}
			myFile.close();

		}
	}
	static ClsCurrency _getEmptyCurrencyObject() {
		return ClsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	void _update() {
		vector<ClsCurrency>vCurrencies = _loadCurrencysDataFromFile();
		for (ClsCurrency& Currency : vCurrencies) {
			if (Currency._currencyCode == _currencyCode) {
				Currency = *this;
				break;
			}
		}
		_saveCurrencyDataToFile(vCurrencies);

		
	}







public:

	ClsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_mode = Mode;
		_country = Country;
		_currencyCode = CurrencyCode;
		_currencyName = CurrencyName;
		_rate = Rate;
	}

	static vector<ClsCurrency>getCurrenciesList() {
		return _loadCurrencysDataFromFile();
	}
	bool IsEmpty() {
		return (_mode == enMode::EmptyMode);
	}
	string getCountry() {
		return _country;
	}
	string getCurrencyCode() {
		return _currencyCode;
	}
	string getCurrencyName() {
		return _currencyName;
	}
	float getRate() {
		return _rate;
	}
	void updateRate(float NewRate) {
		_rate = NewRate;
		_update();
	}
	static ClsCurrency findByCode(string CurrencyCode) {
		CurrencyCode = ClsString::upperAllString(CurrencyCode);
		vector<ClsCurrency>vCurrencies = _loadCurrencysDataFromFile();
		for (ClsCurrency Currency : vCurrencies) {
			if (ClsString::upperAllString(Currency._currencyCode) ==  CurrencyCode) {
				return Currency;
			}
		}
		return _getEmptyCurrencyObject();
	}
	static ClsCurrency findByCountry(string CurrencyName) {
		CurrencyName = ClsString::upperAllString(CurrencyName);
		vector<ClsCurrency>vCurrencies = _loadCurrencysDataFromFile();
		for (ClsCurrency Currency : vCurrencies) {
			if (ClsString::upperAllString(Currency._currencyName) == CurrencyName) {
				return Currency;
			}
		}
		return _getEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		ClsCurrency C = findByCode(CurrencyCode);
		return (!C.IsEmpty());
	}










};