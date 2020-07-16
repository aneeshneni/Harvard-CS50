from cs50 import get_string

text = get_string("Text: ")

words = 1.0
chars = 0.0
sentences = 0.0
for x in text:
    if x == " ":
        words += 1
    elif x in [".","!","?"]:
        sentences += 1
    else:
        chars += 1
grade = int(0.0588 * (100/words * chars) - 0.296 * (100/words * sentences) - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print("Grade ", grade)
