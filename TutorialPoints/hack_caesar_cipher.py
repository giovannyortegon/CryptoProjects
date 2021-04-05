#!/usr/bin/env python3

message = "GiewivrGmtlivrHiqs" # encrypted message

letters = "abcdefghijklmnopqrstvwxyzABCDEFGHIJKLMNOPQRSTVWXYZ"

for key in range(len(letters)):
    translated = ""

    for symbol in message:
        if symbol in letters:
            num = letters.find(symbol)
            num = num - key

            if num < 0:
                num = num + len(letters)
            
            translated = translated + letters[num]

        else:
            translated = translated + symbol

    print("Key: #%s: %s" %(key, translated))
