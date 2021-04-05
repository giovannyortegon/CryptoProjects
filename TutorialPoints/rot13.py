#!/usr/bin/env python3
#from string import maketrans

rot13trans = str.maketrans("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm9876543210")

# Function to tranlate plain text
def rot13(text):
    return text.translate(rot13trans)

def main():
    txt = "ROT13 Algorithm"
    print(rot13(txt))

if __name__ == "__main__":
    main()
