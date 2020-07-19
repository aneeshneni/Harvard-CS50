import csv
import cs50
from sys import exit, argv

#checks input to make sure it is the correct format
if len(argv) > 2 or len(argv) < 2:
    print("Input Error")
    exit(1)
    
#open the database
open(f"students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

#create table in database
db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC)")

#imports data from the given file name
with open(argv[1]) as file:
    reader = csv.DictReader(file)
    for row in reader:
        numnames = 1
        first = ""
        mid = ""
        last = ""
        for x in row["name"]:
            if x == " ":
                numnames += 1
        first = row["name"].split(" ")[0]
        if numnames > 2:
            mid = row["name"].split(" ")[1]
            last = row["name"].split(" ")[2]
        else:
            last = row["name"].split(" ")[1]
        
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, mid, last, row["house"], row["birth"])
