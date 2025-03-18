```bash
# do it linux

ln -s test.txt test.s
ln test.txt test.h

ln -s mydir mydir.s 

ls -li
# 23 lrwxr-xr-x 1 root root   5 Mar 18 06:29 mydir.s -> mydir
# 23 = inode
# 1 = hard link count
# 5 = file size (bytes) "hello" in test.txt
# mydir.s -> mydir = symbolic link

stat mydir/test.txt
  File: mydir/test.txt
  Size: 6               Blocks: 8          IO Block: 4096   regular file
Device: 0,176   Inode: 21          Links: 2
Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2025-03-18 06:27:55.424423196 +0000
Modify: 2025-03-18 06:27:25.276209910 +0000
Change: 2025-03-18 06:27:54.198367651 +0000
 Birth: -

stat -f mydir/test.txt
  File: "mydir/test.txt"
    ID: 0        Namelen: 255     Type: UNKNOWN (0x6a656a63)
Block size: 1048576    Fundamental block size: 4096
Blocks: Total: 120699413  Free: 17853042   Available: 17853042
Inodes: Total: 719644693  Free: 714121680

df -T mydir/test.txt 
Filesystem       Type      1K-blocks      Used Available Use% Mounted on
/host_mark/Users fakeowner 482797652 411404180  71393472  86% /root

# after 1024 lines
stat test.txt
  File: test.txt
  Size: 6144            Blocks: 16         IO Block: 4096   regular file
Device: 0,176   Inode: 21          Links: 2
Access: (0644/-rw-r--r--)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2025-03-18 07:29:09.768443028 +0000
Modify: 2025-03-18 07:29:08.431627989 +0000
Change: 2025-03-18 07:29:08.431627989 +0000
 Birth: -

stat -f test.txt
  File: "test.txt"
    ID: 0        Namelen: 255     Type: UNKNOWN (0x6a656a63)
Block size: 1048576    Fundamental block size: 4096
Blocks: Total: 120699413  Free: 17845104   Available: 17845104
Inodes: Total: 719329047  Free: 713804160

df -T test.txt
Filesystem       Type      1K-blocks      Used Available Use% Mounted on
/host_mark/Users fakeowner 482797652 411417288  71380364  86% /root


root@54beb0c01050:/proc/130# ls
attr        comm             fd        map_files   net            personality  setgroups     status          uid_map
autogroup   coredump_filter  fdinfo    maps        ns             projid_map   smaps         syscall         wchan
auxv        cpuset           gid_map   mem         oom_adj        root         smaps_rollup  task
cgroup      cwd              io        mountinfo   oom_score      sched        stack         timens_offsets
clear_refs  environ          limits    mounts      oom_score_adj  schedstat    stat          timers
cmdline     exe              loginuid  mountstats  pagemap        sessionid    statm         timerslack_ns
```
## /proc/<pid>/fd/
- contains symbolic links to the files that the process has open
```bash
ls /proc/130/fd/
0  1  2  255

ls -l /proc/130/fd/
lrwx------ 1 root root 64 Mar 18 06:26 0 -> /dev/pts/6
lrwx------ 1 root root 64 Mar 18 06:26 1 -> /dev/pts/6
lrwx------ 1 root root 64 Mar 18 06:26 2 -> /dev/pts/6
lrwx------ 1 root root 64 Mar 18 07:32 255 -> /dev/pts/6
```

## a. What is the name of the filesystem used by your system? Please also briefly explain its features (e.g. maximum number of files and file size limitation)
- filesystem: /host_mark/Users (type: fakeowner)
- features:
  - maximum number of files: 719644693
  - maximum file size: 120699413 blocks

## b. What will happen if you change the permission of the file test.txt? Does the permission affect both test.s and test.h?
- The permission of test.txt will affect ONLY test.h (hard link) and not test.s (symbolic link)

## c. What is the difference between symbolic link and hard link?
- symbolic link: a file that contains a reference to another file or directory in the form of an absolute or relative path (different inode from the original file)
- hard link: a directory entry that associates a name with a file on a filesystem (same inode as the original file)
- if edit