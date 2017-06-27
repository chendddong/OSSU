import cs50
import sys

def main():
    # Get the input Height
    # height = get_height()
    # print(height)

    # Print stairs
    print_stairs(get_height())

def get_height():
    while True:
        print("Height: ", end="")
        height = cs50.get_int()
        if height >= 1 and height <= 23:
            break
    return height   

def print_stairs(height):
    for i in range(1, height + 1):
        for j in range(height - i):
            print(" ", end="") # left-side space
        for j in range(i):
            print("#", end="") # left-side hashes
        for j in range(2):
            print(" ", end="") # middle space
        for j in range(i):
            print("#", end="") # right-side hashes
        print("")

if __name__ == "__main__":
    main()