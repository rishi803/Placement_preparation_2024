Using LENGTH() is incorrect. The question is asking for the number of characters used in the content. LENGTH() returns the length of the string measured in bytes. CHAR_LENGTH() returns the length of the string measured in characters.
​
SELECT LENGTH('€')  # is equal to 3
SELECT CHAR_LENGTH('€') # is equal to 1