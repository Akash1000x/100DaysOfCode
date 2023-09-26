import random
logo = [
    "=================================",
    "  Password Generator",
    "=================================",
]

for line in logo:
    print(line)

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers_list =  ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

symbols_list = ['@', '#', '$', '*', '+', '=', '<', '>','?','%']


password_list = []

print("Welcome to the PyPassword Generator!\n")

letter = int(input("How many letters would you like in your password?\n"))
password_list += random.choices(letters,k=letter)

symbols = int(input("How many symbols would you like?\n"))
for i in range(0,symbols):
    password_list += random.choice(numbers_list)

number = int(input("How many numbers would you like?\n"))
password_list += random.choices(symbols_list,k=number)

random.shuffle(password_list)
password = ""
for char in password_list:
    password += char

print("your password is:  " + password)
