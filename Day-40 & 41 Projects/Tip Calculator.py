print("Welcome to the tip calculator!")

bill = float(input("What was the total bill? $"))

tip = int(input("How much tip would you like to give? 10, 12, 15?"))

total_bill = bill + (bill * tip)/100

person = int(input("how many people to split the bill?"))

pay = round(total_bill/person,2)

print(f"Each person should pay {pay}$")
