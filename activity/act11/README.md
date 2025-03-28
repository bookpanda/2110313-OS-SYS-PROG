# Do it in Linux container
```bash
apt install -y python3 python3-pip
apt install python3-fuse

mkdir mnt
chmod +x MyFS.py
./MyFS.py -o uid=1000 -o gid=1000 mnt

# unmount
fusermount -u mnt



```