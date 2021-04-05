#!/usr/bin/python3

def split_len(seq, length):
    return [seq[i:i + length] for i in range(0, len(seq), length)]

def encode(key, plaintext):
    order = {
        int(val): num for num, val in enumerate(key)
    }
#    print(order)

    ciphertext = ""

    for index in sorted(order):
        for part in split_len(plaintext, len(key)):
            try:
                ciphertext += part[order[index]]
            except IndexError:
                continue

    return ciphertext

print(encode("3214", "HELLO"))
print(encode("3214", "Cryptography transposition"))
