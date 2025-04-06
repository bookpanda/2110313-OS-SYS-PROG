# Opening VSCode in linux container
- `ctrl+shift+p` -> "Dev Containers: Attach to Running Container..."
- Select the container you want to attach to.

# Setup
```bash
ssh -i "cloud-computing.pem" ubuntu@ec2-13-229-98-67.ap-southeast-1.compute.amazonaws.com

# to open VSCode in EC2, add this to /.ssh/config
Host ec2-13-229-98-67.ap-southeast-1.compute.amazonaws.com
  HostName ec2-13-229-98-67.ap-southeast-1.compute.amazonaws.com
  IdentityFile ~/.ssh/cloud-computing.pem
  User ubuntu

sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
```