#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/browserHistory.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[]) {

    // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
    // DO NOT MODIFY ABOVE.

    // TODO
    BrowserHistory browser;
    int x = 0;
    int ID = -1;
    string url = "";
    string lastUrl = "";
    string owner = "";
    bool game = true;
    while (game == true){
        x = 0;
        displayMenu();
        cin >> x;
        switch(x){
            case 1:
                browser.buildBrowserHistory();
                browser.displayHistory();
                break;
            case 2:
                browser.displayHistory();
                break;
            case 3:
                cout << "Enter the new web page's url:\n";
                cin >> url;
                while (browser.searchPageByURL(url) != nullptr) {
                   cout << "This url already exists. Try again.\n";
                   cout << "Enter the new web page's url:\n";
                   cin >> url;
                }
                cout << "Enter the new web page's id:\n";
                cin >> ID;
                while (browser.searchPageByID(ID) != nullptr) {
                   cout << "This ID already exists. Try again.\n";
                   cout << "Enter the new web page's id:\n";
                   cin >>ID;
                }
                cout << "Enter the previous page's url (or First):\n";
                cin >> lastUrl;
                while (lastUrl != "First" && browser.searchPageByURL(lastUrl) == nullptr) {
                   cout << "INVALID(previous page url)... Please enter a VALID previous page url!" << endl;
                   cout << "Enter the previous page's url (or First):\n";
                   cin >> lastUrl;
                }
                browser.addWebPage(browser.searchPageByURL(lastUrl), new WebPage{ID, 0, url, "", nullptr});
                browser.updateViews(url);
                break;
            case 4:
                cout << "Enter url of the web page to add the owner:" << endl;
                cin.ignore(10000, '\n');
                getline(cin, url);

               while(browser.searchPageByURL(url) == nullptr) {
                   cout << "Page not found. Try again.\n";
                   cin.ignore(10000, '\n');
                   getline(cin, url);
               }
               cout << "Enter the owner:";
               getline(cin, owner);
               browser.addOwner(url, owner);
                break;
            case 5:
                cout << "Enter url of the web page to check the view count: \n";
                cin.ignore(10000, '\n');
                getline(cin, url);
                while(browser.searchPageByURL(url) == nullptr) {
                   cout << "Page not found. Try again.\n";
                   cout << "Enter url of the web page to check the view count: \n";
                   getline(cin, url);
               }
                cout << "View count for URL - " << url << " is " << browser.searchPageByURL(url)->views << "\n"; 
                break;
            case 6:
                cout << "Quitting...Goodbye!" << endl;;
                game = false;
                break;
        }
    }
    return 0;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{
    // COMPLETE: You DO NOT need to edit this
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build history " << endl;
    cout << " 2. Display history " << endl;
    cout << " 3. Add web page " << endl;
    cout << " 4. Add owner" << endl;
    cout << " 5. View count for a web page" << endl;
    cout << " 6. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
