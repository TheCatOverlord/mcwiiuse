# Minecraft Wiiuse
A C program that uses keyboard simulation and wiimote events to bring minecraft and wii remotes together.
This is still a work in progress.
```
TODO
Smooth the nunchuk controls out
fix the lag issue
Convert the terminal output into a more cli interface
```

# Needed Libraries
libxdo
```
sudo dnf install libxdo-devel
```
wiiuse
```
sudo dnf install wiiuse
```
# Installation
clone the repo with
```
git clone https://github.com/TheCatOverlord/mcwiiuse.git
```
and run
```
cd mcwiiuse/
make
```
to compile the code.
# Running
You can run the program with
```
./minecraftwiiuse
```

# Button layout
Currently everything is mapped as follows
```
Arrow keys -> 'wasd'
A          -> left mouse click
B          -> right mouse click
Home       -> e
1          -> mouse scroll up
2          -> mouse scroll down
+          -> Increase the joystick sensivity
-          -> Decrease the joystick sensivity
z          -> space
c          -> shift
joystick   -> Mouse movement
```
