import pyautogui as pg # for automation
import subprocess as sp # for calling the c++ script
import os

# read the 9x9 Sudoku board from the user
file = open("in.in", 'w')
for i in range(9):
    print(f"Enter row no {i+1}")
    temp = list(map(int,input().split()))
    for val in temp:
        file.write(str(val) + " ")
    file.write("\n")
file.close()

# running the c++ script (assuming it is already compiled) and generating the output file (out.out)
sp.call("./sudoko")


ans = open("out.out", 'r')
if (os.stat("out.out").st_size() == 0):
    print("NO SOLUTION!")

i = 1
key = '' # indicates the pressed key (left ot right)
ind = 0
for line in ans: # for each row in the board
    ind+=1
    line  = line.split()
    if(ind % 2 == 0): # if reached the right edge, reverse the list and go left
        line = list(reversed(line))
        key = 'left'
    else: # if reached the left edge, go left
        key = 'right'

    for val in line:
        pg.press(val) 
        pg.press(key)
        i+=1

    pg.press('down') # when reaching the edge of the row, go to the next one
