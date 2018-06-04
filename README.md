# Document-Topic-Identification

Identifying the main topic(s) of a document is a huge area of research. The most obvious application is through search engines, which must identify the topics of a document in order to connect search terms with the appropriate documents. Equally, there are numerous medical and legal documents that must be automatically classified for a number of reasons – identifying trends over time, finding legal precedence, etc. These are just a few of the most obvious uses for automatic topic identification.

<br/>

In order to identify the topic of a document, one must first read in a text document (we will be reading in the words into an alphabetically-ordered linked list). Words known as “stop words” that have little or no value in identifying the topic (e.g., words like “the”,”I”,”a”,”that”, etc.) should be eliminated. The list should keep a count of how often each word occurs (so in our case we’ll have a linked list of nodes that have as their data a word, or string, and a count of the occurrence of the word in the form of a float (for reasons I’ll explain later). Then when we go to insert a word, we first check to see if the word is already in the list, and, if it is, increase the count of that word’s node by 1. Otherwise, insert the new word node in the proper location and set that node’s count to 1). You should also keep track of the total number of words in the document (in our case, the linked list will have a first, a last, a size (the number of nodes), and a wordcount field that keeps track of the total number of words. This should be the same number you’d get if, once the document was completely read in, you traversed the list and added all the node counts up.

<br/>

Once the document is completely read in, you will “normalize” the counts by traversing the linked list and dividing each node’s count by the linked lists’ total wordcount. And then you should eliminate anything that’s at 2% or below. To do this, you should traverse the list and look at the normalized wordcount, eliminating the word nodes from the list that have a count value below 2%. Finally, you should print out the list.
