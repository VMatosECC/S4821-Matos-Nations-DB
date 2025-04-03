// S4821-Matos-Nations-DB.cpp 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
//--------------------------------------------------------------
class Nation {
private:
public:
    string country;
    string capital;
    string currency;
    string language;

    Nation(string c = "NoCountryName", string cap = "NoCapYet", string curr = "NoCurr", string lan = "NoLang")
        : country(c), capital(cap), currency(curr), language(lan) {};

    void print() {
        cout << " Country:  " << country << endl
<< " Capital:  " << capital << endl
<< " Currency: " << currency << endl
<< " Language: " << language << endl << endl;

    }

    bool operator< (const Nation& other) const {
        return (this->country < other.country);
    }
};
// ----------------------------------------------------------------------
void experiment0() {
    Nation n("Wakanda", "Wakanda City", "USD", "English; Spanish");
    n.print();
}
//------------------------------------------------------------------------
void experiment01(vector<Nation>& db) {
    //Create the Nations database
    ifstream countryFile("c:/temp/xcountry.txt");
    ifstream capitalFile("c:/temp/xcapital.txt");
    ifstream currencyFile("c:/temp/xcurrency.txt");
    ifstream languageFile("c:/temp/xlanguage.txt");

    if (!countryFile || !capitalFile || !currencyFile || !languageFile)
    {
        cout << "Severe error - file not found \n";
        exit(101);
    }

    string strCountry, strCapital, strCurrency, strLanguage;

    while (getline(countryFile, strCountry)) {
        getline(capitalFile, strCapital);
        getline(currencyFile, strCurrency);
        getline(languageFile, strLanguage);

        db.push_back(Nation(strCountry, strCapital, strCurrency, strLanguage));
        //db.emplace_back(strCountry, strCapital, strCurrency, strLanguage);

    }
    countryFile.close();
    capitalFile.close();
    currencyFile.close();
    languageFile.close();

}

//---------------------------------------------------------------------
void experiment02(vector<Nation>& db)
{
    //string test = "English; Spanish; Italian";
    ////is "Italian" held in string test?
    //string key = "Italian";
    //int pos = test.find(key);
    //if (pos == string::npos) {
    //    cout << "String not found!\n";
    //}
    //else {
    //    cout << "Found - pos " << pos << endl;
    //}

    string lang = "Spanish";
    set<Nation> enNations;
    for (Nation n : db) {
        if (n.language.find(lang) != string::npos) {
            enNations.insert(n);
        }
    }

    int spy = 0;
}

//-------------------------------------------------------------
void experiment03(vector<Nation> db) {
    //TODO - Transfer vector data into a set<Nation>

    //Create a Map to index capital city

    //Test retrieval using country name -or- capital city

    //Create a menu - Ask user to provide country / capital
    //Search - display results

}

int main()
{
    //experiment0();

    vector<Nation> db;
    experiment01(db);

    experiment02(db);

    experiment03(db);

    cout << "All done!\n";
}

