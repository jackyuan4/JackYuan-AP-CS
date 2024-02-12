#word game
#Jack Yuan
#Worked with Emrick
#2/11/24

#first created a function to display the Introduction for the game and the Menu to select what topic
#once the Intro and Menu is displayed, ask the user for their input of what choice
#implement a function to pick a random word from the selection's list
#create another function so the user can play the game
#create a function to display the scoreboard that is altered by the function controlling playing the game
#create a main function to control the whole wordgame and handles user's inputs for the menu

# don't accept numbers
# only accept letters
import random

scores =[]

def play_game_random_category():
    categories = ['sports', 'foods', 'video_games']
    category = random.choice(categories)
    play_game(category=category)

def calculate_score(guesses_left, word_length):
    return guesses_left * word_length

def menu():
    print("                    Livelaughlove                      ")
    print("1. Instructions")
    print("2. Games (Sports)")
    print("3. Games (Foods)")
    print("4. Games (Video Games)")
    print("5. Random Category")
    print("6. Display Scoreboard")
    print("7. Exit Game")

def instructions():
    print("\nInstructions to play Livelaughlove")
    print("You need to guess the random word from the category you selected")
    print("The amount of chances you get to guess the word is calculated by subtracting 1 to the length of the word.")
    print("You could guess one letter at a time or the whole word at once.")
    print("There two ways the game ends")
    print("Either you win and your name is added to the scoreboard")
    print("or you lose!")

def save_score(player_name, score):
    # Append the player's name and score to the scores list
    scores.append((player_name, score))

    # Save the scores to a file
    with open("scoreboard.txt", "a") as file:
        file.write(f"{player_name}: {score}\n")



def load_and_sort_scores():
    # Load scores from the file
    with open("scoreboard.txt", "r") as file:
        lines = file.readlines()

    # Extract names and scores from the lines
    scores = [(line.split(":")[0].strip(), int(line.split(":")[1].strip())) for line in lines]

    # Sort scores in descending order based on the score
    sorted_scores = sorted(scores, key=lambda x: x[1], reverse=True)

    return sorted_scores



def display_scoreboard():
    # Load and sort the scores
    sorted_scores = load_and_sort_scores()

    # Display the sorted scoreboard
    print("Scoreboard:")
    for i, (player_name, score) in enumerate(sorted_scores, start=1):
        print(f"{i}. {player_name}: {score}")



def play_game(word_length=None, category=None):
    def random_word(words):
        return random.choice(words)

    words = {
        "sports": ["baseball", "softball", "basketball", "football", "soccer"],
        "foods": ["pizza", "burger", "taco", "salad", "donut", "steak", "sausages"],
        "video_games": ["fortnite", "roblox", "apexlegend", "minecraft"]
        }

    def get_guess():
        while True:
            guess = input("Enter a letter: ").strip().lower()
            if len(guess) == 1 and guess.isalpha():
                return guess
            else:
                print("Invalid input. Please enter a single letter.")

    if word_length is None:
        word_length = random.randint(2, 10)
    if category is None:
        category = random.choice(['sports', 'foods', 'video_games'])

    secret_word = random_word(words[category])
    guessed_letters = set()
    guesses_left = len(secret_word)

    while guesses_left > 0:
        current_state = ''.join(letter if letter in guessed_letters else '_' for letter in secret_word)
        print(f"Current Word: {current_state}")

        guess = get_guess()
        guessed_letters.add(guess)

        if guess in secret_word:
            print(f"Good job! '{guess}' is in the word.")
        else:
            guesses_left -= 1
            print(f"Tuff lucky! '{guess}' is not in the word. You have {guesses_left} guesses left.")

        if set(secret_word.lower()) <= guessed_letters:
            print(f"WWW! You guessed the word '{secret_word}' correctly!")
            player_name = input("Enter your name: ")
            score = calculate_score(guesses_left, len(secret_word))
            save_score(player_name, score)
            print(f"Your score is {score}.")
            return

    print(f"RIP you lose! The word was: {secret_word}")

def main():
    while True:
        menu()
        choice = input("Enter your choice: ")

        if choice == '1':
            instructions()
        elif choice == '2':
            play_game(category='sports')
        elif choice == '3':
            play_game(category='foods')
        elif choice == '4':
            play_game(category='video_games')
        elif choice == '5':
            play_game_random_category()
        elif choice == '6':
            display_scoreboard()
        elif choice == '7':
            break  # Exit the loop and end the game
        else:
            print("Invalid choice. Please enter a number between 1 and 7.")


if __name__ == "__main__":
    main()
