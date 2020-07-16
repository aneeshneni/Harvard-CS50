length = int(input("Height: "))

while length > 8 or length < 1:
    length = int(input("Height: "))
    
for i in range(length+1):
    if i != 0 :
        print(" " * (length-i), end = "")
        print("#" * i)
