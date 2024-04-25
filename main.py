import random

highLimit = 10
lowLimit = 1
comGuess = 0
count = 0

hiddenNumber = int(input('Enter a hidden number: '))

while True:
    comGuess = random.randint(lowLimit, highLimit)
    print('Computer guess: ', comGuess)
    userRecommendation = input('Guide this model IF [High => h] [Low => l] [Correct => c]: ')
    if userRecommendation == 'h':
        highLimit = comGuess
    elif userRecommendation == 'l':
        lowLimit = comGuess
    elif userRecommendation == 'c':
        break
    count += 1

print('Thank you for guiding me. It took me', count, 'tries to complete the game!')