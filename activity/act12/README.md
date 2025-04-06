# Opening VSCode in linux container
- `ctrl+shift+p` -> "Dev Containers: Attach to Running Container..."
- Select the container you want to attach to.

# Setup
```bash
# t3.medium
ssh -i "cloud-computing.pem" ubuntu@ec2-54-255-220-205.ap-southeast-1.compute.amazonaws.com

# to open VSCode in EC2, add this to /.ssh/config
Host ec2-54-255-220-205.ap-southeast-1.compute.amazonaws.com
  HostName ec2-54-255-220-205.ap-southeast-1.compute.amazonaws.com
  IdentityFile ~/.ssh/cloud-computing.pem
  User ubuntu

sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
sudo apt install flex bison libelf-dev build-essential

sudo apt install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison
cd /usr/src
sudo git clone https://github.com/torvalds/linux.git
cd linux
sudo make oldconfig && sudo make prepare


git clone https://github.com/bookpanda/2110313-OS-SYS-PROG.git
# download C++, Makefile VSCode extensions
```

## Checkpoint 1
```bash
# list all modules
lsmod

# list all modules with details
dmesg

# load module
insmod

# remove module
rmmod

sudo make all
sudo insmod dummy.ko
```

## Checkpoint 2
```bash
sudo make all
sudo insmod osinfo.ko
```