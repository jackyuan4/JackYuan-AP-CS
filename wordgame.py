# word game
# Jack Yuan
# Worked with Emrick

# first created a function to display the Introduction for the game and the Menu to select what topic
# once the Intro and Menu is displayed, ask the user for their input of what choice
# implement a function to pick a random word from the selection's list
# create another function so the user can play the game
# create a function to display the scoreboard that is altered by the function controlling playing the game
# create a main function to control the whole wordgame and handles user's inputs for the menu

# don't accept numbers
# only accept letters
import random

scores = []  # list to store the user's scores


# randomly selects a category fromt he list and then run the play_game function
# one random selcetion
def play_game_random_category():
    categories = ["sports", "foods", "video_games"]
    category = random.choice(categories)
    play_game(category)


# how to score my game
# guesses left for the player * the length of the word they are guessing
def calculate_score(guesses_left, word_length):
    return guesses_left * word_length


# my Game Menu
def menu():
    print("                    Livelaughlove                      ")
    print("1. Instructions")
    print("2. Games (Sports)")
    print("3. Games (Foods)")
    print("4. Games (Video Games)")
    print("5. Random Category")
    print("6. Display Scoreboard")
    print("7. Exit Game")


# instructions to play the game
def instructions():
    print("\nInstructions to play Livelaughlove")
    print("You need to guess the random word from the category you selected")
    print(
        "The amount of chances you get to guess the word is calculated by subtracting 1 to the length of the word."
    )
    print("You could guess one letter at a time or the whole word at once.")
    print("There two ways the game ends")
    print("Either you win and your name is added to the scoreboard")
    print("or you lose!")


def add_score(player_name, score):
    # appends the name & score to the scores list
    scores.append((player_name, score))
    # creates a file "scoreboard.txt" if the file is already created, open the file
    with open("scoreboard.txt", "a") as file:
        # store player's score to "scoreboard.txt"
        file.write(f"{player_name} - {score}\n")


def sort_scores():
    # Load scores from file
    with open("scoreboard.txt", "r") as file:
        score_records = file.readlines()

    # After seperating the name and score, we append it to scores list
    scores = []
    for individual_score in score_records:
        name, score_str = individual_score.split(":")
        # Convert score_str (string) to integer
        score = int(score_str)
        scores.append((name, score))

    # Sort the scores by descending order
    # https://developers.google.com/edu/python/sorting#:~:text=The%20easiest%20way%20to%20sort,original%20list%20is%20not%20changed.&text=It's%20most%20common%20to%20pass,any%20sort%20of%20iterable%20collection.
    # "sorted() takes an optional "key=" specifying a "key" function that transforms each element before comparison"
    # https://stackoverflow.com/questions/16310015/what-does-this-mean-key-lambda-x-x1
    # function takes the thing at index 1 which is the user's scores
    # (reverse = True) sorts the list in descending order
    sorted_scores = sorted(scores, key=lambda x: x[1], reverse=True)
    return sorted_scores


# Displaying the scoreboard
def display_scoreboard():
    # Load and sort scores
    sorted_scores = sort_scores()

    # Display scoreboard
    print("Scoreboard for Livelaughlove:")
    # scoreboard prints player's placement, name, and score
    placement = 1
    for player_name, score in sorted_scores:
        print(f"{placement}. {player_name}: {score}")
        placement += 1


def play_game(word_length=None, category=None):
    def random_word(words):
        return random.choice(words)

    words = {
        "sports": ["baseball", "softball", "basketball", "football", "soccer"],
        "foods": ["pizza", "burger", "taco", "salad", "donut", "steak", "sausages"],
        "video_games": ["fortnite", "roblox", "apexlegend", "minecraft"],
    }

    if category is None:
        category = random.choice(["sports", "foods", "video_games"])

    seleted_word = random_word(words[category])
    guessed_letters = set()
    guesses_left = len(seleted_word)

    while guesses_left > 0:
        current_state = "".join(
            letter if letter in guessed_letters else "#" for letter in seleted_word
        )
        print(f"Current Word: {current_state}")

        guess = input("Enter a letter or guess the whole word: ").strip().lower()

        if len(guess) == 1:  # One letter at a time
            guessed_letters.add(guess)

            if guess in seleted_word:
                print(f"Good job! '{guess}' is in the word.")
                if set(seleted_word).issubset(guessed_letters):
                    print(f"WWW! You guessed the word '{seleted_word}' correctly!")
                    player_name = input("Enter your name: ")
                    score = calculate_score(guesses_left, len(seleted_word))
                    add_score(player_name, score)
                    print(f"Your score is {score}.")
                    return
            else:
                guesses_left -= 1
                print(
                    f"LLLLLLLLL '{guess}' is not in the word. You have {guesses_left} guesses left."
                )

        else:  # the whole word at once
            if guess == seleted_word:
                print(f"WWW! You guessed the word '{seleted_word}' correctly!")
                player_name = input("Enter your name: ")
                score = calculate_score(guesses_left, len(seleted_word))
                add_score(player_name, score)
                print(f"Your score is {score}.")
                return
            else:
                for letter in guess:
                    if letter in seleted_word:
                        guessed_letters.add(letter)
                current_state = "".join(
                    letter if letter in guessed_letters else "#"
                    for letter in seleted_word
                )
                guesses_left -= 1
                print(
                    f"RIP! Your word '{guess}' is not correct. You have {guesses_left} guesses left."
                )

    print(f"RIP you lose! The word was: {seleted_word}")


def main():
    while True:
        menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            instructions()
        elif choice == "2":
            play_game(category="sports")
        elif choice == "3":
            play_game(category="foods")
        elif choice == "4":
            play_game(category="video_games")
        elif choice == "5":
            play_game_random_category()
        elif choice == "6":
            display_scoreboard()
        elif choice == "7":
            break  # end the game
        else:
            print("Invalid choice. Please enter a number between 1 and 7.")


if __name__ == "__main__":
    main()
