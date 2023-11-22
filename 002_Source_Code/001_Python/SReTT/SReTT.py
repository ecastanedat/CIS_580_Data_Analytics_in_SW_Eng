'''
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * $Source: SReTT.py $
 * $Revision: 0.9$
 * $Author: LCastaneda $
 * $Date: Nov 18, 2023 10:44:23 AM$
 */
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2023                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
'''
import sys
import pandas as pd
import nltk
from nltk.corpus import stopwords
from nltk.corpus import wordnet
import re
import string

print('============================================================================')
print('                              SReTT v0.9                                    ')
print('                CIS 580 Data Analytics in SW Engineering.                   ')
print('============================================================================')

nltk.download('stopwords')
nltk.download('punkt')
nltk.download('wordnet')
nltk.download('omw-1.4')


for arg in sys.argv:
    print(arg)

'''
This section will be used for future implementation in Command Line execution
'''
def get_synonyms(word):
    synonyms = []
    for syn in wordnet.synsets(word):
        for lemma in syn.lemmas():
            synonyms.append(lemma.name())
    return synonyms

'''
This section will be used for future implementation in Command Line execution
'''
def remove_known_words(lst):
    words_to_remove = ['Error', 'set', 'error']

    return [word for word in lst if word not in words_to_remove]

'''
This section will be used for future implementation in Command Line execution
'''
def remove_punctuation(sentence):
    # Define a translation table to remove punctuation
    translator = str.maketrans('', '', string.punctuation)

    # Use the translation table to remove punctuation from the sentence
    cleaned_sentence = sentence.translate(translator)

    return cleaned_sentence

'''
This section will be used for future implementation in Command Line execution
'''
def remove_stopwords(sentence):

    # Use a regular expression to match and remove newline characters
    cleaned_sentence = re.sub(r'\n', ' ', sentence)
    
    # Get the list of English stopwords from NLTK
    stop_words = set(stopwords.words('english'))

    # Tokenize the sentence into words
    words = nltk.word_tokenize(cleaned_sentence)

    # Remove known words
    words = remove_known_words(words)

    # Remove stopwords from the list of words
    filtered_words = [word for word in words if word.lower() not in stop_words]

    # Join the filtered words back into a sentence
    filtered_sentence = ' '.join(filtered_words)

    return filtered_sentence

'''
Function: search_word_in_file
Parameters: file_path and target_word
Description: Searches a target_word in the file_path and returns the results in a
             list form.
'''
def search_word_in_file(file_path, target_word):
    thislist = []

    try:
        with open(file_path, 'r') as file:
            for line_number, line in enumerate(file, start=1):
                if target_word in line:
                    thislist.append(target_word)
                    thislist.append('Yes')
                    thislist.append(file_path)
                    thislist.append(str(line_number))
                    thislist.append(line.strip())

    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

    if not thislist:
        thislist.append(target_word)
        thislist.append('No')
        thislist.append(file_path)
        thislist.append('NA')
        thislist.append('NA')

    return thislist


'''
This section will be used for future implementation in Command Line execution
'''
def main():
    file_path = 'D:\\DSUsers\\uib01493\\000_SD_Card\\009_Projects\\CIS_580\\Dependencies\\CAN_Wrapper_test.c.test'
    target_word = 'TS_CAN_173'

    search_word_in_file(file_path, target_word)


if __name__ == "__main__":
    main()
