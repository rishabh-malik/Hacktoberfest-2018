# This program calculates either the factorial or double factorial of the user's inputted number. The program receives
# the mode (factorial or double factorial) and number from the user.

print("This program calculates the factorial of the user's inputted number. \nThe factorial of a number is the product "
      "of all the integers below it. Factorial is represented by the '!' algebraic character following the integer. "
      "\nFor example, 5! = 5 * 4 * 3 * 2 * 1 = 120. \nA double factorial (represented by the '!!' algebraic character "
      "following the integer) is the product of all odd numbers up to the entered odd number. \nFor example, "
      "9!! = 1 * 3 * 5 * 7 * 9 = 945.")

keepCalculating = True
while keepCalculating:
    factorialMode = ""
    answer = 1
    while True:
        factorialMode = str(input("Enter 'factorial' to use the factorial calculator, and enter 'double' to use the "
                                  "double factorial calculator. "))
        if factorialMode != "factorial" and factorialMode != "double":
            print("Invalid input, please try again. ")
            continue
        break

    if factorialMode == "factorial":
        while True:
            try:
                userNum = float(input("Please input a positive integer to find its factorial: "))
            except ValueError:
                print("Invalid input, please input a positive integer.")
            else:
                if userNum >= 0 == userNum % 1:
                    userNum = int(userNum)
                    for i in range(1, userNum + 1):
                        answer *= i

                    print("The factorial of " + str(userNum) + " is " + str(answer) + ". " + str(
                        userNum) + "! means the factorial "
                                   "of " + str(userNum) + ", so " + str(userNum) + "! = " + str(answer))
                    break
                print("Invalid input, please input a positive integer.")

    else:
        while True:
            try:
                userNum = float(input("Please input a positive odd integer to find its double factorial "
                                      "(zero can also be entered): "))
            except ValueError:
                print("Invalid input, please input a positive odd integer (zero can also be entered).")
            else:
                userNum = int(userNum)
                if userNum > 0 and userNum % 1 == 0 and (userNum & 1) == 1:
                    for i in range(1, userNum + 1, 2):
                        answer *= i
                    print("The double factorial of " + str(userNum) + " is " + str(answer) + ". " + str(
                        userNum) + "!! means the double factorial of "
                          + str(userNum) + ", so " + str(userNum) + "!! = " + str(answer))
                    break
                elif userNum == 0:
                    print("The double factorial of " + str(userNum) + " is " + str(answer) + ". " + str(
                        userNum) + "!! means the double factorial of "
                          + str(userNum) + ", so " + str(userNum) + "!! = " + str(answer))
                    break
                print("Invalid input, please input a positive odd integer.")

    while True:
        userInput = str(input("Enter 'quit' to stop the program. To find the factorial of another number, enter "
                              "'continue'. "))
        if userInput == "quit":
            keepCalculating = False
            print("The program has ended.")
        elif userInput == "continue":
            print("Program restarting... ")
        else:
            print("Invalid input, please try again. ")
            continue
        break
