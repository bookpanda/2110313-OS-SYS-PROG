# Do it in Linux container
```bash
apt install -y python3 python3-pip
apt install python3-fuse

mkdir mnt
chmod +x MyFS.py
./MyFS.py -o uid=1000 -o gid=1000 mnt

# see my id
id


# unmount
fusermount -u mnt

echo "1:2:3" >> participation


fusermount -u mnt
rm -rf mnt
rm MyFS.py
mkdir mnt
nano MyFS.py

chmod +x MyFS.py
./MyFS.py -o uid=0 -o gid=0 mnt
echo "1:2:3" >> ./mnt/participation

```