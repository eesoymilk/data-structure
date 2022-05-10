user_random = int(input())
lower_bound = 1
upper_bound = 100

while True:
    print(lower_bound, "< ? <", upper_bound)
    guess = int(input())

    if guess == user_random:
        break
    if guess >= upper_bound or guess <= lower_bound:
        print("out of range")
        continue

    print("wrong answer, guess ", end="")

    if guess > user_random:
        print("smaller")
        upper_bound = guess
    else:
        print("larger")
        lower_bound = guess

print("bingo answer is", user_random)
