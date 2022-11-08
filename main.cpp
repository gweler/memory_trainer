// FIX Ctrl+C results in an endless loop

// FIX Ctrl+C results in an endless loop

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
        int score;
        int n;
        fstream file;
        string entered_word;
        string word;
        vector<string> words;

        file.open("text_to_memorise.txt");
        n = 0;
        while (file >> word) {
                n++;
                words.push_back(word);
        }
        file.close();

        score = 0;
        cout << "The first word is: " << words[0] << "\n\n";

        for(int i = 1; i < n; i++) {
                for(;;) {
                        cout << i + 1 << " (st/nd/rd/th) word: ";
                        cin >> entered_word;
                        if (entered_word == "?") {
                                cout << "Skipping the word. A point is taken away.\n";
                                score--;
                                break;
                        }
                        if (entered_word != words[i]) {
                                cout << "Wrong word, try again.\n";
                        } else {
                                score++;
                                break;
                        }
                }
        }
        cout << "\nThe end :-)" << "\nScore: " << score << "\n";

        return 0;
}
