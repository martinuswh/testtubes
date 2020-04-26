import tkinter as tk
import os
import numpy as np
import matplotlib.pyplot as plt
from tkinter import ttk
from PIL import Image, ImageTk

#FUNCTION
def runSimRC():
    combo_value = combo1_RC.get()
    combo_value2 = combo2_RC.get()
    vi = ent_vi_RC.get()
    r1 = ent_r1_RC.get()
    r2 = ent_r2_RC.get()
    c = ent_c_RC.get()

    if (combo_value == "1st Circuit" and combo_value2 == "Voltage"):
        file_name = "rangkaian1_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian1_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "1st Circuit" and combo_value2 == "Current"):
        file_name = "rangkaian1_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian1_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "2nd Circuit" and combo_value2 == "Voltage"):
        file_name = "rangkaian2_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian2_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "2nd Circuit" and combo_value2 == "Current"):
        file_name = "rangkaian2_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian2_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "3rd Circuit" and combo_value2 == "Voltage"):
        file_name = "rangkaian3_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian3_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "3rd Circuit" and combo_value2 == "Current"):
        file_name = "rangkaian3_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian3_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "4th Circuit" and combo_value2 == "Voltage"):
        file_name = "rangkaian4_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian4_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "4th Circuit" and combo_value2 == "Current"):
        file_name = "rangkaian4_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian4_current.csv",  unpack=True, delimiter=",")
    elif (combo_value == "5th Circuit" and combo_value2 == "Voltage"):
        file_name = "rangkaian5_voltage "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian5_voltage.csv",  unpack=True, delimiter=",")
    elif (combo_value == "5th Circuit" and combo_value2 == "Current"):
        file_name = "rangkaian5_current "
        os.system(file_name +vi+" "+r1+" "+r2+" "+c)
        print(file_name, vi, r1, r2, c)         #debug
        x, y = np.loadtxt("rangkaian5_current.csv",  unpack=True, delimiter=",")

    plt.plot(x,y)
    plt.xlabel("Time (s)")
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

def runSimDiff():
    combo_value = combo1_diff.get()
    combo_value2 = combo2_diff.get()
    A = ent_A_diff.get()
    T = ent_T_diff.get()
    R = ent_R_diff.get()
    C = ent_C_diff.get()

    if (combo_value == "Sine" and combo_value2 == "Input Voltage"):
        file_name = "diff_sinus "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("input_voltage_sinus.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Sine" and combo_value2 == "Output Voltage"):
        file_name = "diff_sinus "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_voltage_sinus.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Sine" and combo_value2 == "Output Current"):
        file_name = "diff_sinus "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_current_sinus.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Cosine" and combo_value2 == "Input Voltage"):
        file_name = "diff_cosinus "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("input_voltage_cosinus.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Cosine" and combo_value2 == "Output Voltage"):
        file_name = "diff_cosinus "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_voltage_cosinus.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Cosine" and combo_value2 == "Output Current"):
        file_name = "diff_cosinus "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_current_cosinus.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Triangle" and combo_value2 == "Input Voltage"):
        file_name = "diff_triangular "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("input_voltage_triangular.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Triangle" and combo_value2 == "Output Voltage"):
        file_name = "diff_triangular "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_voltage_triangular.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Triangle" and combo_value2 == "Output Current"):
        file_name = "diff_triangular "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_current_triangular.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Square" and combo_value2 == "Input Voltage"):
        file_name = "diff_square "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("input_voltage_square.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Square" and combo_value2 == "Output Voltage"):
        file_name = "diff_square "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_voltage_square.csv",  unpack=True, delimiter=",")
    elif (combo_value == "Square" and combo_value2 == "Output Current"):
        file_name = "diff_square "
        os.system(file_name +A+" "+T+" "+R+" "+C)
        print(file_name, A, T, R, C)         #debug
        x, y = np.loadtxt("output_current_square.csv",  unpack=True, delimiter=",")

    plt.plot(x,y)
    plt.xlabel("Time (s)")
    plt.grid()
    plt.xlim(0)

    if (combo_value2 == "Output Voltage"):
        plt.title("Output Voltage-Time Graph")
        plt.ylabel("Output Voltage (V)")
    else:
        plt.title("Input Voltage-Time Graph")
        plt.ylabel("Input Voltage (V)")

    plt.show()

#MAIN
window = tk.Tk()
window.title("Tugas Besar PMC - Kelompok 2")
window.geometry("900x650")
window.resizable(width=True, height=True)

lbl_judul = tk.Label(text="RC AND DIFFERENTIATOR CIRCUIT SIMULATOR", font="Tahoma 18 bold", bg="white")
lbl_judul.grid(row=0, columnspan=10)

lbl_penjelasan = tk.Label(text="by Group 2 of EL2008\nThis simulator is a simulator for simulating RC circuits and first-order differentiator op-amp circuits.\nThe form on the left is the form to do RC simulation while the right form is to simulate the differentiator circuit.\nTo conduct a simulation, the user immediately fills in all the required data on each form then presses the submit button and the simulation will run.\nEnjoy simulating!", bg="white")
lbl_penjelasan.grid(columnspan=10, row=1, pady=10)

photo1 = tk.PhotoImage(file="rsz_rangkaian1.png")
pict_circuit1 = tk.Label(window, image=photo1, bg="white")
pict_circuit1.grid(row=2, column=0, columnspan=2)

photo2 = tk.PhotoImage(file="rsz_rangkaian2.png")
pict_circuit2 = tk.Label(window, image=photo2, bg="white")
pict_circuit2.grid(row=2, column=2, columnspan=2)

photo3 = tk.PhotoImage(file="rsz_rangkaian3.png")
pict_circuit3 = tk.Label(window, image=photo3, bg="white")
pict_circuit3.grid(row=2, column=4, columnspan=2)

photo4 = tk.PhotoImage(file="rsz_rangkaian4.png")
pict_circuit4 = tk.Label(window, image=photo4, bg="white")
pict_circuit4.grid(row=2, column=6, columnspan=2)

photo5 = tk.PhotoImage(file="rsz_rangkaian5.png")
pict_circuit5 = tk.Label(window, image=photo5, bg="white")
pict_circuit5.grid(row=2, column=8, columnspan=2)

photo6 = tk.PhotoImage(file="rsz_differentiator.png")
pict_circuit6 = tk.Label(window, image=photo6, bg="white")
pict_circuit6.grid(row=3, column=0, columnspan=2)

photo7 = tk.PhotoImage(file="rsz_sinus.png")
pict_sin = tk.Label(window, image=photo7, bg="white")
pict_sin.grid(row=3, column=2, columnspan=2)

photo8 = tk.PhotoImage(file="rsz_cosinus.png")
pict_cos = tk.Label(window, image=photo8, bg="white")
pict_cos.grid(row=3, column=4, columnspan=2)

photo9 = tk.PhotoImage(file="rsz_triangle.png")
pict_triangle = tk.Label(window, image=photo9, bg="white")
pict_triangle.grid(row=3, column=6, columnspan=2)

photo10 = tk.PhotoImage(file="rsz_square.png")
pict_square = tk.Label(window, image=photo10, bg="white")
pict_square.grid(row=3, column=8, columnspan=2)

#Gap
lbl_gap = tk.Label(bg="white")
lbl_gap.grid(column=0, row=4, columnspan=10, pady=0)

#RC Circuit
lbl_headingRC = tk.Label(text="RC Circuit", font="Tahoma 12 bold underline", bg="white")
lbl_headingRC.grid(column=0, row=5, columnspan=5, pady=10)

#Combobox 1 RC
lbl_combo1_RC = tk.Label(text="Circuit Type = ", bg="white")
lbl_combo1_RC.grid(column=0, row=6, columnspan=2)
combo1_RC = ttk.Combobox(window, values=["1st Circuit", "2nd Circuit", "3rd Circuit", "4th Circuit", "5th Circuit"])
combo1_RC.grid(column=2, row=6)
combo1_RC.current(0)

#Combobox 2 RC
lbl_combo2_RC = tk.Label(text="Output Variable  = ", bg="white")
lbl_combo2_RC.grid(column=0, row=7, columnspan=2)
combo2_RC = ttk.Combobox(window, values=["Voltage", "Current"])
combo2_RC.grid(column=2, row=7)
combo2_RC.current(0)

#Entry vi
lbl_vi_RC = tk.Label(text="Vi = ", bg="white")
lbl_vi_RC.grid(column=0, row=8, columnspan=2)
ent_vi_RC = tk.Entry(width=20)
ent_vi_RC.grid(column=2, row=8)
lbl_vi2_RC = tk.Label(text=" V", bg="white")
lbl_vi2_RC.grid(column=3, row=8)

#Entry R1
lbl_r1_RC = tk.Label(text="R1 = ", bg="white")
lbl_r1_RC.grid(column=0, row=9, columnspan=2)
ent_r1_RC = tk.Entry(width=20)
ent_r1_RC.grid(column=2, row=9)
lbl_r12_RC = tk.Label(text=" Ω", bg="white")
lbl_r12_RC.grid(column=3, row=9)

#Entry R2
lbl_r2_RC = tk.Label(text="R2 = ", bg="white")
lbl_r2_RC.grid(column=0, row=10, columnspan=2)
ent_r2_RC = tk.Entry(width=20)
ent_r2_RC.grid(column=2, row=10)
lbl_r22_RC = tk.Label(text=" Ω", bg="white")
lbl_r22_RC.grid(column=3, row=10)

#Entry C
lbl_c_RC = tk.Label(text="C = ", bg="white")
lbl_c_RC.grid(column=0, row=11, columnspan=2)
ent_c_RC = tk.Entry(width=20)
ent_c_RC.grid(column=2, row=11)
lbl_c2_RC = tk.Label(text=" F", bg="white")
lbl_c2_RC.grid(column=3, row=11)

#Submit RC
btn_submit_RC = tk.Button(text="Submit Data", bg='#C2EDFD', command=runSimRC)
btn_submit_RC.grid(column=0, row=12, columnspan=5)

#Gap
lbl_gap2 = tk.Label(bg="white")
lbl_gap2.grid(column=4, row=6, columnspan=2, rowspan=7)

#Differentiator
lbl_headingDiff = tk.Label(text="Differentiator Circuit", font="Tahoma 12 bold underline", bg="white")
lbl_headingDiff.grid(column=6, row=5, columnspan=5, pady=10)

#Combobox 1 Diff
lbl_combo1_diff = tk.Label(text="Input Wave = ", bg="white")
lbl_combo1_diff.grid(column=6, row=6, columnspan=2)
combo1_diff = ttk.Combobox(window, values=["Sine", "Cosine", "Triangle", "Square"])
combo1_diff.grid(column=8, row=6)
combo1_diff.current(0)

#Combobox 2 Diff
lbl_combo2_diff = tk.Label(text="Variable  = ", bg="white")
lbl_combo2_diff.grid(column=6, row=7, columnspan=2)
combo2_diff = ttk.Combobox(window, values=["Input Voltage", "Output Voltage", "Output Current"])
combo2_diff.grid(column=8, row=7)
combo2_diff.current(0)

#Entry A
lbl_A_diff = tk.Label(text="Input Amplitude = ", bg="white")
lbl_A_diff.grid(column=6, row=8, columnspan=2)
ent_A_diff = tk.Entry(width=20)
ent_A_diff.grid(column=8, row=8)
lbl_A2_diff = tk.Label(text=" V", bg="white")
lbl_A2_diff.grid(column=9, row=8)

#Entry T
lbl_T_diff = tk.Label(text="Period (T) = ", bg="white")
lbl_T_diff.grid(column=6, row=9, columnspan=2)
ent_T_diff = tk.Entry(width=20)
ent_T_diff.grid(column=8, row=9)
lbl_T2_diff = tk.Label(text=" s", bg="white")
lbl_T2_diff.grid(column=9, row=9)

#Entry R Diff
lbl_R_diff = tk.Label(text="R = ", bg="white")
lbl_R_diff.grid(column=6, row=10, columnspan=2)
ent_R_diff = tk.Entry(width=20)
ent_R_diff.grid(column=8, row=10)
lbl_R2_diff = tk.Label(text=" Ω", bg="white")
lbl_R2_diff.grid(column=9, row=10)

#Entry C Diff
lbl_C_diff = tk.Label(text="C = ", bg="white")
lbl_C_diff.grid(column=6, row=11, columnspan=2)
ent_C_diff = tk.Entry(width=20)
ent_C_diff.grid(column=8, row=11)
lbl_C2_diff = tk.Label(text=" F", bg="white")
lbl_C2_diff.grid(column=9, row=11)

#Submit Diff
btn_submit_diff = tk.Button(text="Submit Data", bg='#C2EDFD', command=runSimDiff)
btn_submit_diff.grid(column=6, row=12, columnspan=5)

window.configure(bg="white")
window.mainloop()