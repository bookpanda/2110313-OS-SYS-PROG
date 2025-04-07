# Opening VSCode in linux container
- `ctrl+shift+p` -> "Dev Containers: Attach to Running Container..."
- Select the container you want to attach to.

# Setup
```bash
# ubuntu 22.04 (debian not working), t3.medium, 30GB EBS
ssh -i "cloud-computing.pem" ubuntu@ec2-18-138-229-207.ap-southeast-1.compute.amazonaws.com

# to open VSCode in EC2, add this to /.ssh/config
Host ec2-18-138-229-207.ap-southeast-1.compute.amazonaws.com
  HostName ec2-18-138-229-207.ap-southeast-1.compute.amazonaws.com
  IdentityFile ~/.ssh/cloud-computing.pem
  User ubuntu

sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
sudo apt install flex bison libelf-dev

sudo apt install gcc-12 g++-12
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 60
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 
gcc --version # 12.3.0


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
sudo dmesg | tail # get major number

# create interface for user
sudo mknod /dev/osinfo c <major_number> 0
cat /dev/osinfo
sudo rmmod osinfo
sudo rm /dev/osinfo
```

## Checkpoint 3
```bash
sudo make all
sudo insmod osinfo.ko
sudo dmesg | tail # get major number
sudo mknod /dev/osinfo c <major_number> 0
sudo mknod /dev/osinfo1 c <major_number> 1
ls -al /dev/osinfo*

cat /dev/osinfo
cat /dev/osinfo1

sudo rmmod osinfo # removes insmod 
sudo rm /dev/osinfo # removes mknod
sudo rm /dev/osinfo1
```

## Checkpoint 4
```bash
sudo make all

```