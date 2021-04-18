#!/usr/bin/env python3
# Transposition Cipher Encryption

import pyperclip

def main():
    myMessage = "Common sense is not so common."
    myKey = 8

    ciphertext = encrypMessage(myKey, myMessage)
    # Print the encrypted string
    print(ciphertext + '|')

    # Copy the encrypted string in cyphertext
    pyperclip.copy(ciphertext)

def encrypMessage(key, message):
    # Each string in ciphertext represent a column in the grid.
    ciphertext = [""] * key

    # loop through each column in ciphertext.
    for col in range(key):
        pointer = col

        # keop looping until pointer goes past the length of the message.
        while pointer < len(message):
            # Place the character at point in message at the end of the
            # current column in the ciphertext list.
            ciphertext[col] += message[pointer]

            # move pointer over
            pointer += key

    return ''.join(ciphertext)

# If transpositionEncrypt.py is run
# the main() function
if __name__ == '__main__':
    main()
