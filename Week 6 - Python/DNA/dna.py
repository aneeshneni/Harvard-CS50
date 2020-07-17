import csv
from sys import argv, exit

#Input Error analysis
if len(argv) < 3 or len(argv) > 3:
    print("Input error: python dna.py [database] [file.txt]")
    exit(1)

##Global variables
x = False
first = 0
second = 0
third = 0
lem = ""

##Open directory file
with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

    ##Length of each given string calculator/open text file
    with open(argv[2], "r") as text:
        reader2 = csv.reader(text)
        for row in reader2:
            lem = row[0]
            for i in range(len(lem) - 5):
                if lem[i:i+5] == "AGATC":
                    strlen = 5
                    strlen2 = 10
                    count = 1
                    if first == 0:
                        first = 1
                    while lem[i+strlen:i+strlen2] == "AGATC":
                        strlen += 5
                        strlen2 += 5
                        count += 1
                        if first < count:
                            first = count
                if lem[i: i + 4] == "TATC":
                    strlen = 4
                    strlen2 = 8
                    count = 1
                    if second == 0:
                        second = 1
                    while lem[i+strlen:i+strlen2] == "TATC":
                        strlen += 4
                        strlen2 += 4
                        count += 1
                        if second < count:
                            second = count
                if lem[i:i+4] == "AATG":
                    strlen = 4
                    strlen2 = 8
                    count = 1
                    if third == 0:
                        third = 1
                    while lem[i+strlen:i+strlen2] == "AATG":
                        strlen += 4
                        strlen2 += 4
                        count += 1
                        if third < count:
                            third = count
    
    ## Output and directory reader
    for row in reader:
        if int(row['AGATC']) == first and int(row['TATC']) == second and int(row['AATG']) == third:
            print(row['name'])
            x = True
    if x == False:
        print ("No match")
