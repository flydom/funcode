
# exc3.py
# print("I will now count my chickens:")

# print("Hens", 25 + 30 /6)
# print("Roosters", 100 - 25 * 3 % 4)

# print("Now I will count the eggs:")

# print(3 + 2 + 1 - 5 + 4 % 2 - 1 / 4 + 6)

# print("Is it true that 3 + 2 < 5 - 7?")
# print(3 + 2 < 5 - 7)

# print("What is 3 + 2?", 3 + 2)
# print("What is 5 + 7?", 5 - 7)

# print("Oh, that's why it's False.")

# print("How about some more.")

# print("Is it greater?", 5 > -2)
# print("Is it greater or equal?", 5 >= -2)
# print("Is it less or equal?", 5 <= -2)

# exc4.py
# cars = 100
# space_in_a_car = 4
# drivers = 30
# passengers = 90
# cars_not_driven = cars - drivers
# cars_driven = drivers
# carpool_capacity = cars_driven * space_in_a_car
# average_passengers_per_car = passengers / cars_driven

# print("There are", cars, "cars availabe.")
# print("There are only", drivers, "drivers availabe.")
# print("There will be", cars_not_driven, "empty cars today.")
# print("We can transport", carpool_capacity, "people today.")
# print("We have", passengers, "to carpool today.")
# print("we need to put about", average_passengers_per_car, "in each car.")

# exc5.py
# my_name = 'Zed A. Shaw'
# my_age = 35 # not a lie
# my_height = 74 # inches
# my_weight = 180 # lbs
# my_eyes = 'Blue'
# my_teeth = 'White'
# my_hair = 'Brown'

# print(f"Let's talk about {my_name}")
# print(f"He's {my_height} inches tall.")
# print(f"He's {my_weight} pounds heavy.")
# print(f"Actually that's not too heavy.")
# print(f"He's got {my_eyes} eyes and {my_hair} hair")
# print(f"His teeth are usually {my_teeth} depending on the coffee.")

# this line is tricky, try to get it exactly right
# total = my_age + my_height + my_weight
# print(f"If I add {my_age}, {my_height}, {my_weight}, I get {total}")

# exc6.py
# types_of_people = 10
# x = f"There are {types_of_people} types of people."

# binary = "binary"
# do_not = "don't"
# y = f"Those who know {binary} and those who {do_not}."

# print(x)
# print(y)

# print(f"I said: {x}")
# print(f"I also said: '{y}'")

# hilarious = False
# joke_evalution = "Isn't that joke so funny?! {}"
# print(joke_evalution.format(hilarious))

# w = "This is the left side of..."
# e = "a string with a right side."
# print(w + e)

# exc7.py
# print("Mary had a little lamb.")
# print("Its fleece was white as {}.".format('show'))
# print("And everywhere that Mary went.")
# print("." * 10) # what'd that do?

# end1 = "C"
# end2 = "h"
# end3 = "e"
# end4 = "e"
# end5 = "s"
# end6 = "e"
# end7 = "B"
# end8 = "u"
# end9 = "r"
# end10 = "g"
# end11 = "e"
# end12 = "r"

# watch that comma at the end. try removing it to see what happen
# print(end1 + end2 + end3 + end4 + end5 + end6, end=' ')
# print(end7 + end8 + end9 + end10 + end11 + end12)

# exc8.py
# formatter = "{} {} {} {}"

# print(formatter.format(1, 2, 3, 4))
# print(formatter.format("one", "two", "three", "four"))
# print(formatter.format(True, False, False, True))
# print(formatter.format(formatter, formatter, formatter, formatter))
# print(formatter.format(
	# "Try your",
	# "Own text here",
	# "Maybe a poem",
	# "Or a song about fear"
# ))

# exc9.py
# Here's some new strange stuff, remember type it exactly.

# days = "Mon Tue Wed Thu Fri Sat Sun"
# months = "Jan\nFeb\nMar\nApr\nMay\nJun\nJul\nAug"

# print("Here are the days: ", days)
# print("Here are the months: ", months)

# print("""
# There's something going on here.
# With the three double-quotes.
# We'll be able to type as much as we like.
# Even 4 lines if we want, or 5, or 6.
# """)

# exc10_py
# tabby_cat = "\tI'm tabbed in."
# persian_cat = "I'm split\non a line."
# backslash_cat = "I'm \\ a \\ cat."
# fat_cat = '''
# I'll do a list:
# \t* Cat food
# \t* fishies
# \t* Catnip\n\t* Grass
# '''

# print(tabby_cat)
# print(persian_cat)
# print(backslash_cat)
# print(fat_cat)

# exc11.py
# print("How old are you?", end = ' ')
# age = input()
# print("How tall are you?", end = ' ')
# height = input()
# print("How much do you weigh?", end = '')
# weight = input()

# print(f"So, you're {age} old, {height} tall and {weight} heavy.")

# exc12.py
# age = input("How old are you? ")
# height = input("How tall are you? ")
# weight = input("How much do you weigh? ")

# print(f"So, you're {age} old, {height} tall and {weight} heavy.")

# exc13.py
# from sys import argv
# read the WYSS section for how to run this
# script, first, second, third = argv

# print("The script is called:", script)
# print("Your first variable is:", first)
# print("Your second variable is:", second)
# print("Your third variable is:", third)

# exc14.py
# from sys import argv

# script, user_name = argv
# prompt = "> "

# print(f"Hi {user_name}, I'm the {script} script")
# print(f"I'd like to ask you a few questions.")
# print(f"Do you like me {user_name}?")
# likes = input(prompt)

# print(f"Where do you live {user_name}?")
# lives = input(prompt)

# print(f"What kind of computer do you have?")
# computer = input(prompt)

# print(f"""
# Alright, so you said {likes} about liking me.
# You live in {lives}. Not sure where that is.
# And you have a {computer} computer. Nice.
# """)

# exc15.py
# from sys import argv

# script, filename = argv

# txt = open(filename)

# print(f"Here's your file {filename}:")
# print(txt.read())

# print("Type the filename again:")
# file_again = input("> ")
# txt_again = open(file_again)
# print(txt_again.read())

# exc16.py
# from sys import argv

# script, filename = argv

# print(f"We're going to erase {filename}.")
# print("If you don't want that, hit CTRL-C (^C).")
# print("If you do want that, hit RETURN.")

# input("?")

# print("Opening the file...")
# target = open(filename, 'w')

# print("Truncating the file. Goodbye!")
# target.truncate()

# print("Now I'm going to ask you for three lines.")
# line1 = input("line 1: ")
# line2 = input("line 2: ")
# line3 = input("line 3: ")

# print("I'm going to write these to the file.")

# target.write(line1)
# target.write("\n")
# target.write(line2)
# target.write("\n")
# target.write(line3)
# target.write("\n")

# print("And finally, we close it.")
# target.close()

# exc17.py
# from sys import argv
# from os.path import exists

# script, from_file, to_file = argv

# print(f"Copying from {from_file} to {to_file}")

# We could do these two on one line how?
# in_file = open(from_file)
# indata = in_file.read()

# print(f"The input file is {len(indata)} bytes long")

# print(f"Does the output file exist? {exists(to_file)}")
# print("Ready, hit RETURN to continue, CRTL-C to abort.")

# input()

# out_file = open(to_file, 'w')
# out_file.write(indata)

# print("Alright, all done.")

# out_file.close()
# in_file.close()

# exc18.py
# this one is like your scripts with argv
# def print_two(*args):
	# arg1, arg2 = args
	# print(f"arg1: {arg1}, arg2: {arg2}")
	
# ok, that *args is actually pointless, we can just do this
# def print_two_again(arg1, arg2):
	# print(f"arg1: {arg1}, arg2: {arg2}")
	
# this just takes one argument
# def print_one(arg1):
	# print(f"arg1: {arg1}")
	
# this one takes no arguments
# def print_none():
	# print("I got nothing.")
	
# print_two("Zed", "Shaw")
# print_two_again("Zed", "Shaw")
# print_one("First!")
# print_none()

# exc19.py
# def cheese_and_crackers(cheese_count, boxes_of_crackers):
	# print(f"You have {cheese_count} cheeses!")
	# print(f"You have {boxes_of_crackers} boxes of crackers!")
	# print("Man that's enough for a party")
	# print("Get a blanket.\n")
	
# print("We can just give the function numbers directly:")
# cheese_and_crackers(20, 30)

# print("OR, we can use variables from our script:")
# amount_of_cheese = 10
# amount_of_crackes = 50

# cheese_and_crackers(amount_of_cheese, amount_of_crackes)

# print("We can even do math inside too:")
# cheese_and_crackers(10 + 20, 5 + 6)

# print("And we can combine the two, variables and math:")
# cheese_and_crackers(amount_of_cheese + 100, amount_of_crackes + 1000)

# exc20.py
# from sys import argv

# script, input_file = argv

# def print_all(f):
	# print(f.read())
	
# def rewind(f):
	# f.seek(0)
	
# def print_a_line(line_count, f):
	# print(line_count, f.readline())
	
# current_file = open(input_file)

# print("First let's print the whole file:\n")

# print_all(current_file)

# print("Now let's rewind, kink of like a tape.")

# rewind(current_file)

# print("Let's print three lines:")

# current_line = 1
# print_a_line(current_line, current_file)

# current_line += 1
# print_a_line(current_line, current_file)

# current_line = current_line + 1
# print_a_line(current_line, current_file)


# exc21.py
# def add(a, b):
	# print(f"ADDING {a} + {b}")
	# return a + b
	
# def subtract(a, b):
	# print(f"SUBTRACTING {a} - {b}")
	# return a - b
	
# def multiply(a, b):
	# print(f"MULTIPLYING {a} * {b}")
	# return a * b
	
# def divide(a, b):
	# print(f"DIVIDING {a} / {b}")
	# return a / b
	
# print("Let's do some math with just functions!")

# age = add(30, 5)
# height = subtract(78, 4)
# weight = multiply(90, 2)
# iq = divide(100,2)

# print(f"Age: {age}, Height: {height}, Weight: {weight}, IQ: {iq}")

# A puzzle for extra credit, type it in anyway.
# print("Here is a puzzle.")

# what = add(age, subtract(height, multiply(weight, divide(iq, 2))))

# print("That becomes: ", what, "Can you do it by hand?")






















	































	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
