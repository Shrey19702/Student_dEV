import pyautogui
import time

time.sleep(10)
i = 0
g = open("Hey there! ", "r")
for word in g:
    pyautogui.typewrite(word)
    i = i + 1
    pyautogui.press("enter")
    print(i)
 
