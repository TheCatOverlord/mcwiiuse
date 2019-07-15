# Minecraft Wiiuse
A C program that uses keyboard simulation and wiimote events to bring minecraft and wii remotes together.
This is still a work in progress.
```
TODO
Smooth the nunchuk controls out
map the rest of the keys (inventory and such)
fix the lag issue
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
