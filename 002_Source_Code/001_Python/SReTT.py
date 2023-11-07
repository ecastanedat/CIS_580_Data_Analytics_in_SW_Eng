import sys
import pandas as pd
import nltk
from nltk.corpus import stopwords
from nltk.corpus import wordnet
import re
import string

print('============================================================================')
print('                              SReTT v0.1                                    ')
print(' This is a demo that only prints the passed arguments from the command line.')
print('============================================================================')

nltk.download('stopwords')
nltk.download('punkt')
nltk.download('wordnet')
nltk.download('omw-1.4')


for arg in sys.argv:
    print(arg)

def get_synonyms(word):
    synonyms = []
    for syn in wordnet.synsets(word):
        for lemma in syn.lemmas():
            synonyms.append(lemma.name())
    return synonyms

def remove_known_words(lst):
    words_to_remove = ['Error', 'set', 'error']

    return [word for word in lst if word not in words_to_remove]

def remove_punctuation(sentence):
    # Define a translation table to remove punctuation
    translator = str.maketrans('', '', string.punctuation)

    # Use the translation table to remove punctuation from the sentence
    cleaned_sentence = sentence.translate(translator)

    return cleaned_sentence

def remove_stopwords(sentence):

    #sentence = remove_punctuation(sentence)

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

def search_word_in_file(file_path, target_word):
    thislist = []

    try:
        with open(file_path, 'r') as file:
            for line_number, line in enumerate(file, start=1):
                if target_word in line:
                    print(f"Found '{target_word}' on line {line_number}: {line.strip()}")
                    thislist.append(f"Found '{target_word}' on line {line_number}: {line.strip()}\n")
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

    return thislist

def main():
    file_path = 'D:\\DSUsers\\uib01493\\000_SD_Card\\009_Projects\\CIS_580\\Dependencies\\CAN_Wrapper_test.c.test'
    target_word = 'FSM_Error_Reaction_Init'
    
    original_sentence = 'TS_CAN_173'
    filtered_sentence = remove_stopwords(original_sentence)

    #search_word_in_file(file_path, target_word)
    #print("Original Sentence:", original_sentence)
    #print("Filtered Sentence:", filtered_sentence)

    lst = nltk.word_tokenize(filtered_sentence)

    print(lst)

    for word in lst:
        synonyms = get_synonyms(word)
        synonyms.insert(0, word)
        #print(synonyms)
        for word in synonyms:
            search_word_in_file(file_path, word)


if __name__ == "__main__":
    main()