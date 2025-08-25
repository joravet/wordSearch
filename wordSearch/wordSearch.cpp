/*Jackson Oravetz; Professor Ahmed, Kishwar; 9/11/2024.
* This code is a C++ program that when given a txt file, finds the longest word in the file containing only one vowel and 
* can also take a user inputted word and determine whether it is in the file or not.
*/

#include <iostream>
#include <fstream>      //needed for fileIO purposes
#include <string>       //needed for .at function to parse through string
using namespace std;

int main()
{
    int numLetters1 = 0;    //placeholder variables to find longest word
    int numLetters2 = 0;
    char holdLet;         
    string bigWord;         //string variables to hold different words needed throughout program
    string word; 
    string userWord;
    bool wordExists = false;    //flips to true if the users word is found

    fstream myFile;             //open the file
    string filename = "words.txt";
    myFile.open(filename);

    if (myFile.is_open())       //if the inputted file is open, begin parsing words
    {
        while (getline(myFile, word))   //loops until an empty line is reached
        {
            int numVowels = 0;
            for (int i = 0; i < word.length(); i++) //loops for every letter of the word and counts the number of vowels in word
            {
                holdLet = word.at(i);
                if (holdLet == 'A' || holdLet == 'a' || holdLet == 'E' || holdLet == 'e' || holdLet == 'I' || holdLet == 'i'
                    || holdLet == 'O' || holdLet == 'o' || holdLet == 'U' || holdLet == 'u')
                {
                    numVowels++;
                }
            }

            if (numVowels == 1)     //if the number of vowels in current word is one, then compare its number of letters to the
            {                       //previous one vowel word. If its a longer word, save it as the new lognest word
                numLetters1 = word.length();
                if (numLetters1 > numLetters2)
                {
                    bigWord = word;
                    numLetters2 = numLetters1;
                }
                else if (numLetters1 == numLetters2)
                    bigWord = word;
            }

        }
        cout << "The longest word with one vowel is " << bigWord << endl;   //print the longest one vowel word
        
        myFile.close(); //close the file for next run
    }
    else   //if no file is found, output nof file to console and end program
    {
        cout << "The input file " << filename << " could not be opened";
        return 0;
    }

    cout << "Enter the word to search for: ";   //prompt user for word
    cin >> userWord;
    myFile.open(filename);      //open file again and loop through file same as last time
    if (myFile.is_open())
    {
        while (getline(myFile, word))
        {
            if (userWord == word)       //if the users word is found, change wordExists to true
                wordExists = true;
        }
        if (wordExists == true)         //output whether or not userWord is found
            cout << "Found " << userWord;
        else
            cout << "Could not find " << userWord;
        myFile.close();
    }
    
    else cout << "The input file " << filename << " could not be opened";   //if file is not found, output text and end program

    return 0;
}


