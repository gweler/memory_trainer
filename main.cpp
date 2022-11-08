// FIX Ctrl+C results in an endless loop

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
        int bodovi;
        int n;
        fstream file;
        string pogrijec;
        string word;
        vector<string> rijeci;

        file.open("text_to_memorise.txt");
        n = 0;
        while (file >> word) {
                n++;
                rijeci.push_back(word);
        }
        file.close();

        bodovi = 0;
        cout << "The first word is: " << rijeci[0] << "\n\n";

        for(int i = 1; i < n; i++) {
                for(;;) {
                        cout << i + 1 << "st/nd/rd/th word: ";
                        cin >> pogrijec;
                        if (pogrijec == "?") {
                                cout << "Preskakanje rijeci. Oduzima se bod.\n";
                                bodovi--;
                                break;
                        }
                        if (pogrijec != rijeci[i]) {
                                cout << "Netacna rijec. Pokusaj ponovo.\n";
                        } else {
                                bodovi++;
                                break;
                        }
                }
        }
        cout << "\nKraj programa." << "\nBroj bodova: " << bodovi << "\n";

        return 0;
}
