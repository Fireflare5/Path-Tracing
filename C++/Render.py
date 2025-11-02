import subprocess
import os
import sys
import time 
import numpy as np
from PIL import Image
import tkinter as tk
from tkinter import colorchooser

def render(resolution=(1280,720), samples=32, color=(195,195,195), n_bits=32):
    data, tmp = os.pipe()
    t = time.time()
    os.write(tmp, bytes(f'{resolution[0]} {resolution[1]} {samples}\n',"utf-8"))
    os.close(tmp)
    print(f'Settings Loaded in {time.time() - t}s')
    t = time.time()
    out = subprocess.check_output('cd ./C++ && g++ Raytrace.cpp -o RayTrace && ./RayTrace', stdin=data, shell=True)
    print(f'Image prepped in {time.time() - t}s')
    t = time.time()
    cooked = np.array([_.split() for _ in [i for i in out.decode("utf-8").strip().split("\n")]])
    img = Image.new('RGB', resolution)
    for x in range(resolution[0]):
        for y in range(resolution[1]):
            r = int(float(cooked[x,y]) * color[0])
            g = int(float(cooked[x,y]) * color[1])
            b = int(float(cooked[x,y]) * color[2])
            img.putpixel((x, y), (r, g, b))
    print(f'Image rendered in {time.time() - t}s')
    img.show("Rendered Image")
    img.save(f'./Images/{np.random.randint(0,2**n_bits)}.png')

def pick_color():
    color = colorchooser.askcolor(title="Choose sphere color")
    if color[1]:
        return color[0]
    else:
        return (195,195,195)

if __name__ == "__main__":
    window = tk.Tk()
    window.withdraw()
    color = pick_color()
    window.destroy()
    render(color=color)
    