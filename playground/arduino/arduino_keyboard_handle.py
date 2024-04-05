import tkinter as tk
from tkinter import ttk
import serial
import keyboard

# Global variables for shortcut entries
shortcut_entries = []

# Function to handle button actions
def handle_button_action(button_number):
    if button_number in shortcuts:
        keyboard.send(shortcuts[button_number])
    else:
        print("Shortcut for button {} is not defined.".format(button_number))

# Function to save the selected shortcuts
def save_shortcuts():
    global shortcuts
    shortcuts = {
        1: shortcut_entries[0].get(),
        2: shortcut_entries[1].get(),
        3: shortcut_entries[2].get(),
        4: shortcut_entries[3].get(),
        5: shortcut_entries[4].get()
    }

# Open serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)  # Adjust the port accordingly

# GUI setup
root = tk.Tk()
root.title("Assign Shortcuts")

# Create a frame for better organization
main_frame = ttk.Frame(root, padding="20")
main_frame.grid(row=0, column=0)

# Create labels and entry fields for each button
shortcut_labels = []
for i in range(1, 6):
    label = ttk.Label(main_frame, text="Button {}: ".format(i))
    label.grid(row=i, column=0, padx=10, pady=5, sticky="e")
    shortcut_labels.append(label)

    entry = ttk.Entry(main_frame, width=20)
    entry.grid(row=i, column=1, padx=10, pady=5)
    shortcut_entries.append(entry)

# Set default shortcuts if available
default_shortcuts = {
    1: 'ctrl+n',
    2: 'ctrl+r',
    3: 'ctrl+w',
    4: 'ctrl+t',
    5: 'ctrl+h'
}
for i in range(1, 6):
    if i in default_shortcuts:
        shortcut_entries[i-1].insert(0, default_shortcuts[i])

# Button to save changes
save_button = ttk.Button(main_frame, text="Save Shortcuts", command=save_shortcuts)
save_button.grid(row=6, columnspan=2, pady=10)

# Function to switch between presets
def switch_preset(preset):
    if preset == "chrome":
        shortcut_entries[0].insert(0, 'ctrl+t')
        shortcut_entries[1].insert(0, 'ctrl+r')
        shortcut_entries[2].insert(0, 'ctrl+w')
        shortcut_entries[3].insert(0, 'ctrl+n')
        shortcut_entries[4].insert(0, 'ctrl+h')
    elif preset == "vs_code":
        shortcut_entries[0].insert(0, 'ctrl+s')
        shortcut_entries[1].insert(0, 'ctrl+shift+o')
        shortcut_entries[2].insert(0, 'ctrl+f')
        shortcut_entries[3].insert(0, 'ctrl+b')
        shortcut_entries[4].insert(0, 'ctrl+h')
    elif preset == "fl_studio":
        shortcut_entries[0].insert(0, 'ctrl+z')
        shortcut_entries[1].insert(0, 'ctrl+y')
        shortcut_entries[2].insert(0, 'ctrl+s')
        shortcut_entries[3].insert(0, 'ctrl+t')
        shortcut_entries[4].insert(0, 'ctrl+shift+s')
    elif preset == "day_to_day":
        shortcut_entries[0].insert(0, 'ctrl+c')
        shortcut_entries[1].insert(0, 'ctrl+v')
        shortcut_entries[2].insert(0, 'ctrl+x')
        shortcut_entries[3].insert(0, 'ctrl+z')
        shortcut_entries[4].insert(0, 'ctrl+y')

# Preset buttons
chrome_button = ttk.Button(main_frame, text="Chrome", command=lambda: switch_preset("chrome"))
chrome_button.grid(row=7, column=0, pady=5)

vs_code_button = ttk.Button(main_frame, text="VS Code", command=lambda: switch_preset("vs_code"))
vs_code_button.grid(row=7, column=1, pady=5)

fl_studio_button = ttk.Button(main_frame, text="FL Studio", command=lambda: switch_preset("fl_studio"))
fl_studio_button.grid(row=8, column=0, pady=5)

day_to_day_button = ttk.Button(main_frame, text="Day to Day", command=lambda: switch_preset("day_to_day"))
day_to_day_button.grid(row=8, column=1, pady=5)

# Start GUI loop
root.mainloop()

# Display the selected shortcuts
print("Selected Shortcuts:")
for button, shortcut in shortcuts.items():
    print("Button {}: {}".format(button, shortcut))

# Main loop
while True:
    # Read serial data from Arduino
    data = ser.readline().strip().decode('utf-8')

    # Check if data is for volume control or button action
    if data.startswith('VOLUME'):
        try:
            volume_level = int(data.split(':')[1])
            # Adjust volume level using volume_level
            print("Volume adjusted:", volume_level)
        except ValueError:
            print("Invalid volume data:", data)
    elif data.startswith('BUTTON'):
        try:
            button_number = int(data.split(':')[1])
            handle_button_action(button_number)
        except ValueError:
            print("Invalid button data:", data)
