import random
import hangman_art
import hangman_words

print(hangman_art.logo)

word = random.choice(hangman_words.word_list)

# print(word)

word_length = len(word)


char_list = ['_']*word_length


lives = 6


while lives>0 :

    guess_letter = input("Guess a letter:").lower()

    if guess_letter in char_list:
        print(f"You've already guessed {guess_letter}")

    for i in range(word_length):
        if word[i] == guess_letter:
            char_list[i] = guess_letter

    if guess_letter not in word:
        print(f"\nYou guessed {guess_letter}, that's not in the word. You lose a life.")
        lives -= 1

    
            
        
    
    print(" ".join(char_list))
    print()
    print(hangman_art.stages[lives])
    
    if '_' not in char_list:
        print("You win")
        break


if(lives <= 0):
    print("You lose\n")

print(f"The word was {word}")
print("Game Over")


