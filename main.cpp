#include <bits/stdc++.h>
using namespace std;

string selectFileName(int fileNumber) {
    string fileName = "";
    if (fileNumber == 1) {
        fileName = "Input_01.txt";
    } else if (fileNumber == 2) {
        fileName = "Input_02.txt";
    }
    return fileName;
}

bool isCompoundWord(const string& word, const set<string>& wordsSet) {
    if (word.empty()) {
        return false;
    }

    size_t n = word.length();

    for (size_t i = 1; i < n; ++i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);

        if (wordsSet.count(prefix) && (wordsSet.count(suffix) || isCompoundWord(suffix, wordsSet))) {
            return true;
        }
    }

    return false;
}

void findLongestCompoundedWords(const vector<string>& sortedWords, const set<string>& wordsSet,
                                 string& longestCompoundedWord, string& secondLongestCompoundedWord) {
    for (const auto& word : sortedWords) {
        if (isCompoundWord(word, wordsSet)) {
            if (longestCompoundedWord.empty()) {
                longestCompoundedWord = word;
            } else if (word.length() > longestCompoundedWord.length()) {
                secondLongestCompoundedWord = longestCompoundedWord;
                longestCompoundedWord = word;
            } else if (secondLongestCompoundedWord.empty() || word.length() > secondLongestCompoundedWord.length()) {
                secondLongestCompoundedWord = word;
            }
        }
    }
}

int main() {
    clock_t start_time, end_time;
    

    // Ask the user to input the file number
    int fileNumber;
    cout << "Enter the file number (1 or 2): ";
    cin >> fileNumber;
    start_time = clock();

    string fileName = selectFileName(fileNumber);

    // Open the selected input file
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        return 1;
    }

    // Read words from the file and store in a set
    set<string> wordsSet;
    string word;

    while (inputFile >> word) {
        wordsSet.insert(word);
    }

    // Sort words by length in descending order
    vector<string> sortedWords(wordsSet.begin(), wordsSet.end());
    sort(sortedWords.begin(), sortedWords.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });

    // Find the longest and second-longest compound words
    string longestCompoundedWord;
    string secondLongestCompoundedWord;

    findLongestCompoundedWords(sortedWords, wordsSet, longestCompoundedWord, secondLongestCompoundedWord);

    // Finding the end time of the program
    end_time = clock();
    clock_t time_taken = end_time - start_time;

    // Output
    cout << "Longest Compounded Word: " << longestCompoundedWord << endl;
    cout << "Second Longest Compounded Word: " << secondLongestCompoundedWord << endl;
    cout << "Time taken to process input file: " << time_taken << " milliseconds" << endl;

    return 0;
}
