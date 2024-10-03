# Inverted_Search
## Introduction
An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full-text searches, at a cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, such as search engines.

## Forward Indexing
Creating the initial word list requires several operations:
1. **Word Recognition**: Identify individual words from the text.
2. **Storage**: Store these words using a dynamic linked list or hashing. Along with the words, store information about the corresponding document or file.
3. **Document Indexing**: Index all documents in the database. Words repeated in different or the same files are not indexed separately; instead, the same word is updated with a list of file names in which they occur.

Each word in the list is mapped with all the files in which it is contained. The details of the files can be stored as URLs or names.

## Inverted Indices
The forward index is sorted to transform it into an inverted index using the best sorting method. The list is arranged in the sorted order of words, making it easier to search the words in the list and produce information about the documents in which they are present.

### Efficiency Considerations
Most computers cannot sort very large disk files needed to hold the initial word list within a reasonable time frame, and do not have enough storage to hold a sorted and unsorted version of the word list, plus the intermediate files involved in the internal sort. This can be avoided by implementing:
- Hashing
- Sorted linked list
- Binary search tree

During indexing, words are compared and arranged in sorting order before storing, reducing the time complexity in searching for a word through the list. Efficiency is increased by implementing hashing, which stores words based on unique indices. This index can only determine whether a word exists within a particular document and is considered a boolean index.

## Data Structures Projects
Such an index determines which documents match a query but does not rank matched documents. In some designs, the index includes additional information such as:
- The frequency of each word in each document
- The positions of a word in each document

Position information enables the search algorithm to identify word proximity to support searching for phrases; frequency can help rank the relevance of documents to the query.

## Requirement Details
Implementing this project consists of two main functions:
1. **Indexing**
2. **Querying**

### Indexing
By indexing, we create a database file that contains the index of all words. This process can be termed Database Creation. All files whose index is to be created are selected and input to this function. The files are parsed, words are separated and indexed, and arranged in sorted order using a sorted linked list or hashing, storing the words and related file details. The index thus created is stored in the file as a database and updated when files are removed or added.

### Querying
Once indexing is over, querying or searching is performed. The text to be searched is input and parsed into words, which are searched in the index file. To avoid the overhead of reading the file again, the file is converted back to a linked list or hashing program, in which the words are searched. Information about the files containing the words is collected, and files with more matches are filtered and produced as the result.
