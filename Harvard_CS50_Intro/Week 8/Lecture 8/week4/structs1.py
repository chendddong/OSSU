import cs50
import csv
from student import Student

students = []
for i in range(3):

    # save inputs from user and them save those values in
    # a class and append that object to a list called students    
    print("name: ", end="")
    name = cs50.get_string()

    print("dorm: ", end="")
    dorm = cs50.get_string()

    students.append(Student(name, dorm))

# open a file obj
file = open("students.csv", "w")
# get a writer obj
writer = csv.writer(file)
for student in students:
    writer.writerow((student.name, student.dorm))
file.close()
