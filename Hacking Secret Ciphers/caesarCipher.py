#!/usr/bin/env python3
# Caesar Cipher
import pyperclip

# the string to be encrypted/decrypted
# message = "This is my secret message."
message = input("Enter message: ")

# the encryption/decyption key
# key = 13
key = int(input("Enter key: "))
# tells the program to encrypt or decrypt
#mode = "encrypt"  # set to 'encrypt' or 'decrypt'
mode = input("(1) encrypt or (2) decrypt: \n")

# every possible symbol that can be encrypted
LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

# stores the encrypted/decrypted form of the message
translated = ''

# capitalize the string in massage
message = message.upper()

# run the encryption/decryption code on each symbol in the message string
for symbol in message:
    if symbol in LETTERS:
        # get the encrypted (or decrypted) number for thid symbol
        num = LETTERS.find(symbol)  # get the number of the symbol
        if mode == '1':
            num = num + key
        elif mode == '2':
            num = num - key
        # handle the wrap-around if num is larger than the length of

        # LETTER or less than 0
        if num >= len(LETTERS):
            num = num - len(LETTERS)
        elif num < 0:
            num = num + len(LETTERS)

        # add encrypted/decrypted number's symbol at the end of translated
        translated = translated + LETTERS[num]
    else:
        # just add the symbol without encrypting/decrypting
        translated = translated + symbol

# print the encrypted/decrypted string to the screen
print(translated)

# print the encrypted/decrypted string to the clipborad
pyperclip.copy(translated)
