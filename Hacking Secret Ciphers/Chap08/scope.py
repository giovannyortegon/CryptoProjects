#!/usr/bin/env python3

spam = 42

def egg():
    spam = 99       # Local
    print("In egg(): ", spam)

def ham():
    print('In ham():', spam) # global

def bacon():
    global spam         # spam in this function is global
    print("In bacon(): ", spam)
    spam = 0

def CRASH():
    print(spam)     # spam in this function is local
    spam = 0

print(spam)
egg()
print(spam)
ham()
print(spam)
bacon()
print(spam)
CRASH()
