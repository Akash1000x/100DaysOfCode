import random

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

games_image = [rock,paper,scissors]

player = int(input(
    "What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors.\n"))

if player >2 or player <0:
    print("please type valid input!")
else:
    print(games_image[player])

    computer_choose = random.randint(0, 2)

    print("computer_choose:" + games_image[computer_choose])



    if player == computer_choose:
        print("It's a draw")

    elif (player == 0 and computer_choose == 1) or (player == 1 and computer_choose == 2) or (player == 2 and computer_choose == 0):
        print("you lose")

    else:
        print("you win")