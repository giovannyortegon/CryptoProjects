#!/usr/bin/env python3
import pyperclip

def main():
    myMessage = "Transposition Cipher"
    myKey = 10
    cipherText = encrypMessage(myKey, myMessage)
    print("Cipher Text is")
    print(cipherText + '|')
    pyperclip.copy(cipherText)

def encrypMessage(key, message):
    ciphertext = [''] * key
    for col in range(key):
        position = col
        while position < len(message):
            ciphertext[col] += message[position]
            position += key

    return ''.join(ciphertext) # Cipher text

if __name__ == '__main__':
    main()
