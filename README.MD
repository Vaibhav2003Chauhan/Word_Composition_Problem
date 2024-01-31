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

1. Determining Compound Words (isCompoundword function):
The isCompoundword function is responsible for determining whether a given word is a compounded word. It uses a recursive approach to check all possible splits of the word into a prefix and a suffix. The key steps are as follows:
Base Case:

If the input word is empty, it is not a compounded word, and the function returns false.
Iteration through Splits:

The function iterates through all possible splits of the word using a loop with an index i.
For each split, it creates a prefix (in_start substring from the beginning of the word up to index i) and a suffix (in_end substring from index i to the end of the word).
Checking Prefix in the Set:

It checks if the prefix (in_start) is present in the given set (sentence) using sentence.find(in_start) != sentence.end().
Recursive Call:

If the prefix is found, it checks whether the suffix (in_end) is either in the set or is itself a compounded word. It does this by making a recursive call to the isCompoundword function with the suffix and the set.
Result:

If either of the conditions in the recursive call is true, the function returns true, indicating that the word is compounded.

2. Finding Longest and Second-Longest Compound Words (main function):
Iterating Through Words:
The main function iterates through each word in the set obtained from the input file.
Checking Compound Nature:

For each word, it calls the isCompoundword function to check if the word is compounded.

3. Updating Longest and Second-Longest:
If a word is determined to be compounded, it compares its length with the lengths of the current longest and second-longest compounded words.
If the length of the word is greater than the length of the current longest compounded word, it updates the second-longest compounded word and then updates the longest compounded word.
If the length of the word is greater than the length of the current second-longest compounded word, it updates the second-longest compounded word.

4. Displaying Results:
After iterating through all words, the program displays the longest and second-longest compounded words found.

Example:
Consider the word "basketball" with the set {"basket", "ball"}. The isCompoundword function would iterate through the splits ("bas" and "ketball"), check if "bas" is in the set (which it is), and then make a recursive call with "ketball". In the recursive call, it would split "ketball" into ("ket" and "ball"), check if "ket" is in the set (which it is), and make another recursive call with "ball". Finally, it would check if "ball" is in the set (which it is), and since the base case is reached, it returns true, indicating that "basketball" is a compounded word.



