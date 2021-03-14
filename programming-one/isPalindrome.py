def ReverseNumber(n, partial=0):
    if n == 0:
        return partial
    return ReverseNumber(n // 10, partial * 10 + n % 10)

def inputs():
    number = int(input('Number is: '))
    if(number < 1000 or number > 9999):
        print("Values invalid")
    else:
        if ReverseNumber(number) == number:
            print("It's a Palindrome!")
        else:
            print("It's not a Palindrome!")
inputs()