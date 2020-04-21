import tkinter as tk
import os
import numpy as np
import matplotlib.pyplot as plt
from tkinter import ttk
from PIL import Image, ImageTk

def inputComp():
    combo_value = combo.get()
    combo_value2= combo2.get()
    vi = ent_vi.get()
    r1 = ent_r1.get()
    r2 = ent_r2.get()
    c = ent_c.get()

    if (combo_value == "Rangkaian 1" and combo_value2 == "Voltage"):
        file_name = "rangkaian1_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian1_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 1" and combo_value2 == "Current"):
        file_name = "rangkaian1_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian1_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 2a" and combo_value2 == "Voltage"):
        file_name = "rangkaian2a_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian2a_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 2a" and combo_value2 == "Current"):
        file_name = "rangkaian2a_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian2a_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 2b" and combo_value2 == "Voltage"):
        file_name = "rangkaian2b_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian2b_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 2b" and combo_value2 == "Current"):
        file_name = "rangkaian2b_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian2b_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 3" and combo_value2 == "Voltage"):
        file_name = "rangkaian3_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian3_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 3" and combo_value2 == "Current"):
        file_name = "rangkaian3_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian3_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 4" and combo_value2 == "Voltage"):
        file_name = "rangkaian4_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian4_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 4" and combo_value2 == "Current"):
        file_name = "rangkaian4_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian4_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Rangkaian 5" and combo_value2 == "Voltage"):
        file_name = "rangkaian5_voltage "
    plt.plot(x,y)
    plt.xlabel("Time (S)")
    plt.grid()
    plt.xlim(0)
    plt.ylim(0)

    if(combo_value2 == "Voltage"):
        plt.title("Output Voltage-Time Graph")
        plt.ylabel("Output Voltage (V)")
    else:
        plt.title("Output Current-Time Graph")
        plt.ylabel("Output Current (A)")

    plt.show()

window = tk.Tk()
window.title("Tugas Besar PMC - Kelompok 2")
window.geometry("500x500")
window.resizable(width=True, height=True)

lbl_judul = tk.Label(text="Simulator rangkaian oleh kelompok 2 EL2208\nPilih jenis rangkaian yang ingin disimulasikan!", bg="white")
lbl_judul.grid(columnspan=2)

#Combobox 1
lbl_combo = tk.Label(text="Jenis Rangkaian = ", bg="white")
lbl_combo.grid(column=0, row=2)
combo = ttk.Combobox(window, values=["Rangkaian 1", "Rangkaian 2a", "Rangkaian 2b", "Rangkaian 3", "Rangkaian 4", "Rangkaian Differentiator"])
combo.grid(column=1, row=2)
combo.current(0)

#Combobox 2
lbl_combo2 = tk.Label(text="Variabel  = ", bg="white")
lbl_combo2.grid(column=0, row=3)
combo2 = ttk.Combobox(window, values=["Voltage", "Current"])
combo2.grid(column=1, row=3)
combo2.current(0)

#Entry vi
lbl_vi = tk.Label(text="Vi = ", bg="white")
lbl_vi.grid(column=0, row=4)
ent_vi = tk.Entry(width=20)
ent_vi.grid(column=1, row=4)
lbl_vi2 = tk.Label(text=" V", bg="white")
lbl_vi2.grid(column=2, row=4)

#Entry R1
lbl_r1 = tk.Label(text="R1 = ", bg="white")
lbl_r1.grid(column=0, row=5)
ent_r1 = tk.Entry(width=20)
ent_r1.grid(column=1, row=5)
lbl_r12 = tk.Label(text=" Ω", bg="white")
lbl_r12.grid(column=2, row=5)

#Entry R2
lbl_r2 = tk.Label(text="R2 = ", bg="white")
lbl_r2.grid(column=0, row=6)
ent_r2 = tk.Entry(width=20)
ent_r2.grid(column=1, row=6)
lbl_r22 = tk.Label(text=" Ω", bg="white")
lbl_r22.grid(column=2, row=6)

#Entry C
lbl_c = tk.Label(text="C = ", bg="white")
lbl_c.grid(column=0, row=7)
ent_c = tk.Entry(width=20)
ent_c.grid(column=1, row=7)
lbl_c2 = tk.Label(text=" F", bg="white")
lbl_c2.grid(column=2, row=7)

#Submit button
gambar = ImageTk.PhotoImage(Image.open("rangkaian1 - Copy.png"))
img = tk.Label(image=gambar)
img.grid(columnspan=2)

btn_submit = tk.Button(
    text="Submit Data",
    command=inputComp,
    bg='#C2EDFD'
)
btn_submit.grid(column=1, row=9)

window.configure(bg="white")
window.mainloop()

