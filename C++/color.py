import tkinter as tk
from tkinter import colorchooser

def choose_color():
    color_code = colorchooser.askcolor(title="Choose color")
    if color_code[1]:  # Check if a color was selected (not cancelled)
        print(f"Selected color (RGB): {color_code[0]}")
        print(f"Selected color (Hex): {color_code[1]}")

root = tk.Tk()
root.withdraw()  # Hide the main Tkinter window

choose_color()
root.destroy()