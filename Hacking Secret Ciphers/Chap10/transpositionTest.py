#!/usr/bin/env python3
import random, sys, transpositionEncrypt, transpositionDecrypt

def main():
	random.seed(42)		# set the random "seed" to a static value

	for i in range(20):
		""" Generate random message to test

			The message will have a random length
		"""
		message = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" * random.randint(4, 40)

		# Convert the message string to a list to shuffle it.
		message = list(message)
		random.shuffle(message)

		message = ''.join(message) # convert listt to string
		print('Test #%s: "%s..."' %(i + 1, message[:50]))

		# Check all possible keys for each message
		for key in range(1, len(message)):
			encrypted = transpositionEncrypt.encryptMessage(key, message)
			decrypted = transpositionDecrypt.decryptMessage(key, encrypted)

			# If the decryption doesn't match the original messge display
			# an error message and quit
			if message != decrypted:
				print("Mismatch with key %s and message %s." %(key, message))
			#	print(decrypted)
				sys.exit()

#	print("Message: %s" % message)
#	print("Decrypt: %s" %decrypted)
	print("Transposition cipher test passed.")

if __name__ == "__main__":
	main()
