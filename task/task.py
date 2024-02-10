import random
import string

# Generet random password
def generatePassword():
    length = random.randint(12, 20) # Length can be [12, 20]
    UpperCase = string.ascii_uppercase
    LowerCase = string.ascii_lowercase
    Number = string.digits
    Symbol = "!@#$%^&*()_-+=[]{}|;:,.<>?`"
    AllSymbol = UpperCase + LowerCase + Number + Symbol 

    password = random.choice(UpperCase) + random.choice(LowerCase)
    password += random.choice(Symbol) + random.choice(Number)
    password += "".join(random.choice(AllSymbol) for _ in range(length-4))
    password = "".join(random.choice(password) for _ in range(length)) # Mix password 

    return password # return generated password

# Write generated password in the file
def write_to_file(fileName,count): 
    with open(fileName, "w") as file: # Open file for writing
        while count:
            file.write(generatePassword())
            file.write('\n')
            count -= 1
    

count = 30
write_to_file("generatedPassword.txt", count) # Call function which generates and writes in the file 
