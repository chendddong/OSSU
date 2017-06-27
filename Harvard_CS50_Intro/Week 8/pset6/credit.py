import cs50
import sys

def main():
    # Get credit number
    card_number = get_number()
    # print(card_number)
    
    # Check the card number and print out the company name
    check_number(card_number)

def get_number():
    while True:
        print("Number: ", end="")
        card_number = cs50.get_int()
        break
    return card_number


def check_number(card_number):
    sumOfEven = get_sum_even(card_number)
    # print(sumOfEven)
    sumOfOdd = get_sum_odd(card_number)
    # print(sumOfOdd)
    if (sumOfOdd + sumOfEven) % 10 == 0:
        num = star_with(card_number) 
        le = len(str(card_number)) 
        if (num == 34 or num == 37) and le == 15:
            print("AMEX")
        elif num >= 51 and num <= 55 and le == 16:
            print("MASTERCARD"); 
        elif num == 4 and (le == 13 or le == 16):
            print("VISA"); 
        else:
            print("INVALID"); 
    else:
        print("INVALID")

def star_with(card_number):
    if str(card_number)[0] == "4":
        return 4
    else:
        return int(str(card_number)[:2])

def get_sum_even(card_number):
    double_list = []
    sum = 0
    for i in range(len(str(card_number)) - 2, -1, -2):
        val = int(str(card_number)[i]) * 2
        double_list.append(str(val))
    for word in double_list:
        for n in word:
            sum += int(n)
    return sum    

def get_sum_odd(card_number):
    sum = 0
    for i in range(len(str(card_number)) - 1, -1, -2):
        sum += int(str(card_number)[i])
    return sum

if __name__ == "__main__":
    main()

