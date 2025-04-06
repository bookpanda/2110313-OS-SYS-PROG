# Opening VSCode in linux container
- `ctrl+shift+p` -> "Dev Containers: Attach to Running Container..."
- Select the container you want to attach to.

# Setup
```bash
# t3.small
ssh -i "cloud-computing.pem" ubuntu@ec2-13-229-205-41.ap-southeast-1.compute.amazonaws.com

# to open VSCode in EC2, add this to /.ssh/config
Host ec2-13-229-205-41.ap-southeast-1.compute.amazonaws.com
  HostName ec2-13-229-205-41.ap-southeast-1.compute.amazonaws.com
  IdentityFile ~/.ssh/cloud-computing.pem
  User ubuntu

sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
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