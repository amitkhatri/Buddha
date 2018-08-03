#!/usr/bin/python
import urllib
import time
def printBuddha():
    "Prints ASCII Buddha to the screen"
    fileObj = open("buddha.txt", "r")
    print fileObj.read()
    fileObj.close()
    return

def quoteoftheDay():
    "Prints the QOD from TinyBuddha"
    qotd = urllib.urlopen("http://tinybuddha.com/wp-content/plugins/tiny-buddha-host/wisdom.txt")
    print qotd.read()
    return

def displayMenu():
    "Display main menu"
    print "\n\n"
    print "WELCOME TO BUDDHA: A TERMINAL-BASED MEDITATION TIMER"
    print "===================================================="
    print "PRESS 1 TO START A NEW TIMER"
    print "PRESS 2 TO EXIT"
    print "===================================================="
    return

def hello():
    print "test"
    return

def startTimer(mins):
    print "Focus on your breath..."
    while mins != 0:
        time.sleep(60)
        mins -= 1
    #Send a system "beep" to signal end of session
    print '\a'
    return

#Main
printBuddha()
quoteoftheDay()
displayMenu()

while True:
    selection = input()
    if selection == 1:
        mins = input("Enter time in minutes: ")
        startTimer(mins)
        exit()
    else:
        exit()

