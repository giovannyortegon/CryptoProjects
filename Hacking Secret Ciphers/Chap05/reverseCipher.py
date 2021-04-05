#!/usr/bin/env python3
# Reverse Cipher

message = "Three can keep a secret, if two them are dead."
translated = ''

i = len(message) - 1

while i >= 0:
    translated = translated + message[i]
    i = i - 1

print(translated)

decipher = ''

i = len(translated) - 1

for idx in range(i, -1, -1):
    decipher = decipher + translated[idx]

print(decipher)
