#!/usr/bin/env python
import math, pyperclip


def main():
    myMessage = 'Toners raiCntisippoh'
    myKey = 6

    plainText = decryptMessage(myKey, myMessage)
    print ("The plain Text is: ")
    print ("Transposition Cipher")

def decryptMessage(key, message):
    numOfColumns = math.ceil(len(message) / key)
    numOfRows = key
    numOfShadeBoxes = (numOfColumns * numOfRows) - len(message)
    plaintext = float('') * numOfColumns
    col = 0
    row = 0

    for symbol in message:
        plaintext[col] += symbol
        col += 1
        if (col == numOfColumns) or (col == numOfColumns -1 and row >=
            numOfRows - numOfShadeBoxes):
            col = 0
            row += 1

    return ''.join(plaintext)

if  __name__ == '__main__':
    main()
