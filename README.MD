## Vaibhav Chauhan
## Inderprastha Engineering College 
## vishuchauhan461@gmail.com 

# ***Compounded Words Finder (C++)***

## *Overview*
This C++ program is designed to find the longest and second longest compounded words within a input file. A compounded word is defined as a word that can be constructed by concatenating shorter words found within the same input file.

The program accomplishes this by implementing a trie data structure to efficiently store and search for words, along with a recursive approach to determine whether a word is compounded. It also records the time taken to process the input files.

## *Prerequisites*
- A C++ compiler (e.g., g++)
- Input text files (Input_01.txt and Input_02.txt) containing  words, with one word per line. The input files should be present in the current working directory.

## *How to Execute*
1. Clone or download the source code from the provided GitHub URL.
2.  Compile the program using a C++ compiler. For example:
   ```bash
   g++ main.cpp -o compound_word_finder
3. Run the program with the following command:
    ```bash
    ./CompoundedWordsFinder
    ```
4. The program will prompt you to select either 'Input_01.txt' or 'Input_02.txt' for processing. Follow the on-screen instructions to make your selection.

5. After processing, the program will display the longest compounded word, the second longest compounded word, and the time taken to process the input file.

## *Approach Used*

1. File Selection:
The user is prompted to enter a file number (1 or 2).
The selectFileName function is used to determine the file name based on the user's input.

2. File Reading:
The selected file is opened using ifstream.
Words from the file are read and stored in a set<string> (wordsSet).
The set ensures unique words for quick lookup.

3. Sorting Words:
The words are sorted in descending order of length using sort.

4. Finding Compounded Words:
The isCompoundWord function checks if a word can be compounded by combining shorter words in the set.
findLongestCompoundedWords function iterates through the sorted words and finds the longest and second-longest compounded words using the isCompoundWord function.

5. Time Measurement:
The program measures the time taken to process the input file using the clock() function and shows it in console.

6. Output:
The longest and second-longest compounded words, along with the processing time, are printed to the console.


## understand working with example

1. Input File Selection : 
The program first prompts the user to enter a file number (1 or 2).
Let's say the user enters 1. The selectFileName function is then called with fileNumber = 1, and it returns "Input_01.txt" as the selected file name.


2. File Reading and Set Population : 
The program opens the selected input file ("Input_01.txt" in this case).
It reads words from the file and inserts them into a set (wordsSet). The set automatically ensures that each word is unique.

Example set after reading the provided input file:
{"apple", "banana", "pear", "app", "le", "ban", "a"}


3. Sorting Words: 
The program converts the set into a vector (sortedWords) and sorts it based on word length in descending order.

Example sortedWords vector:
{"banana", "apple", "pear", "app", "ban", "le", "a"}


4. Compound Word Identification : 
The findLongestCompoundedWords function is called to identify the longest and second-longest compound words.
It iterates through the sorted words and uses the isCompoundWord function to check if each word is a compound word.

Example compound word identification:
"banana" is identified as a compound word (banana = ban + ana).
"apple" is identified as a compound word (apple = app + le).
"pear" is not identified as a compound word.
"app" is identified as a compound word (app = a + pp).
"ban" is identified as a compound word (ban = b + an).
"le" is not identified as a compound word.
"a" is not identified as a compound word.
The program identifies "banana" as the longest compound word and "apple" as the second-longest compound word.


5. Output : 
The program prints the results, including the longest and second-longest compound words, and the time taken to process the input file.
Example output:
Longest Compounded Word: banana
Second Longest Compounded Word: apple
Time taken to process input file: 1011 milliseconds



