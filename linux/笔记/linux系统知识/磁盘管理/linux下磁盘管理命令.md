## linux下磁盘管理的命令
fdisk
gdisk
lsblk
blkid
df
dd
df
fdisk
shred
partprobe
dump2fs
swapon
swapoff
quota
fsck ：检查分区表
badblocks
fuser -mv /path
tune2fs
e2label
hdparm

![[inode,block,superblock#查看inode相关命令]]

### 查看磁盘信息命令

## 操作磁盘命令



### dumpe2fs
日志文件系统ext3/ext4　查看日志所占大小和inode  

![[Pasted image 20211012133237.png]]


<iframe 
 height=500
 width=800  
src="https://blog.csdn.net/test_soy/article/details/48182145"　
>
</iframe>



### linux ext2/3/4设置uuid


<iframe 
 height=500
 width=800  
src="https://www.cnblogs.com/yjken/p/3922063.html"　
>
</iframe>




### lsblk& blkid

<iframe 
 height=500
 width=900  
src="https://linux.cn/article-4734-1.html"　
>
</iframe>


```bash
root@uos-PC /h/u/Desktop# lsblk
NAME        MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
loop0         7:0    0  99.3M  1 loop /snap/core/11743
loop1         7:1    0  61.9M  1 loop /snap/core20/1169
loop2         7:2    0  61.8M  1 loop /snap/core20/1081
loop3         7:3    0  99.4M  1 loop /snap/core/11993
loop4         7:4    0  99.5M  1 loop /snap/core/11798
sda           8:0    0 931.5G  0 disk 
├─sda1        8:1    0    16M  0 part 
├─sda2        8:2    0 195.3G  0 part /media/uos/2E50C0F250C0C237
└─sda3        8:3    0 736.2G  0 part /media/uos/ext4
nvme0n1     259:0    0 238.5G  0 disk 
├─nvme0n1p1 259:1    0   300M  0 part /boot/efi
├─nvme0n1p2 259:2    0   1.5G  0 part /boot
├─nvme0n1p3 259:3    0    15G  0 part /
├─nvme0n1p4 259:4    0    15G  0 part 
├─nvme0n1p5 259:5    0 181.7G  0 part /data
├─nvme0n1p6 259:6    0    14G  0 part /recovery
└─nvme0n1p7 259:7    0    11G  0 part [SWAP]
```
```bash
root@uos-PC /h/u/Desktop# blkid
/dev/nvme0n1p1: LABEL_FATBOOT="EFI" LABEL="EFI" UUID="7CA3-3E11" TYPE="vfat" PARTUUID="81af3950-b94d-4b11-a2c8-41ed26ae454e"
/dev/nvme0n1p2: LABEL="Boot" UUID="ec336ab8-b333-41cc-aad0-211769c69a44" TYPE="ext4" PARTUUID="ab3224d6-5cd2-414a-9ca1-0a02ed63568b"
/dev/nvme0n1p3: LABEL="Roota" UUID="fc0f5306-16f1-4a2c-b9a2-8434f8d72bc9" TYPE="ext4" PARTUUID="142f0f48-cf2b-445f-9a1c-d75d7321259d"
/dev/nvme0n1p4: LABEL="Rootb" UUID="3512cef6-368f-49af-ae3e-3739f9ef4c66" TYPE="ext4" PARTUUID="f7201b10-02b0-48f0-b787-385a90b28b35"
/dev/nvme0n1p5: LABEL="_dde_data" UUID="934bf91a-a943-417a-b679-b33b8cdabc55" TYPE="ext4" PARTUUID="d1235fc8-1612-44c5-9cde-5fde31e76db1"
/dev/nvme0n1p6: LABEL="Backup" UUID="2dcf9896-698e-4374-99c9-fcdfd6856caa" TYPE="ext4" PARTUUID="bc6e1163-df45-4ff7-8749-188d777b3488"
/dev/nvme0n1p7: LABEL="SWAP" UUID="322859f6-63b9-469d-9efb-b3b125d7aa4e" TYPE="swap" PARTUUID="f3a9b123-e501-462e-862f-8afb6a4e742e"
/dev/sda2: UUID="2E50C0F250C0C237" TYPE="ntfs" PARTLABEL="Basic data partition" PARTUUID="29984ad3-2bba-4f0a-8820-c99671340970"
/dev/sda3: LABEL="ext4" UUID="4723d1da-fbf7-46ba-9715-31a5df2eca18" TYPE="ext4" PARTUUID="fab1bb52-74a5-432e-9cb7-f3ee09d1028a"
/dev/loop0: TYPE="squashfs"
/dev/loop1: TYPE="squashfs"
/dev/loop2: TYPE="squashfs"
/dev/loop3: TYPE="squashfs"
/dev/loop4: TYPE="squashfs"
/dev/nvme0n1: PTUUID="bc629b89-57ac-4145-aba3-39a0d75a7160" PTTYPE="gpt"
/dev/sda1: PARTLABEL="Microsoft reserved partition" PARTUUID="2ded83c1-b239-491a-8a2a-a58700250594"
```



![[Pasted image 20211101104907.png]]

