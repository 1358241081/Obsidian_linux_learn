## 常用命令
- [[linux 网络管理#route|route]]
- ifconfig
- ip
- [[linux 网络管理#arp|arp]]　：取得本机的 ARP 表格内的 IP/MAC 对应数据，也可以利用『 arp -s 』这个选项来定义静态的 ARP 对应
- 











<br/>
<br/>

#### route
***route***
```
uos@uos-PC ~/Desktop> route
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
default         10.10.77.1      0.0.0.0         UG    100    0        0 eno1
10.10.77.0      0.0.0.0         255.255.255.0   U     100    0        0 eno1
172.17.0.0      0.0.0.0         255.255.0.0     U     0      0        0 docker0
192.168.122.0   0.0.0.0         255.255.255.0   U     0      0        0 virbr0
```
***route -n***  
-n ： 将主机名以 IP 的方式显示
```
uos@uos-PC ~/Desktop> route -n
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         10.10.77.1      0.0.0.0         UG    100    0        0 eno1
10.10.77.0      0.0.0.0         255.255.255.0   U     100    0        0 eno1
172.17.0.0      0.0.0.0         255.255.0.0     U     0      0        0 docker0
192.168.122.0   0.0.0.0         255.255.255.0   U     0      0        0 virbr0
uos@uos-PC ~/Desktop> 
```

 
   - Destination ：其实就是 Network 的意思； 
   - Gateway ：就是该接口的 Gateway 那个 IP 啦！若为 0.0.0.0 表示需要额外的 IP； 
   -  Genmask ：就是 Netmask 啦！与 Destination 组合成为一部主机或网域； 
   -  Flags ：共有多个旗标可以来表示该网域或主机代表的意义： 
   			-   U：代表该路由可用； 
   			-   G：代表该网域需要经由 Gateway 来帮忙转递； 
   			-   H：代表该行路由为一部主机，而非一整个网域； 
   - Iface ：就是 Interface (接口) 的意思。


<br/>
<br/>

#### arp
相关配置文件　
- /etc/hosts: 
```
uos@uos-PC ~/Desktop> cat /etc/hosts
127.0.0.1       localhost
127.0.1.1 uos-PC
10.10.77.135 uostest
# The following lines are desirable for IPv6 capable hosts
::1     localhost ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
34.192.204.44 registry-1.docker.io


```

***arp -a***  ：第一列内容参考/etc/hosts文件内容　查询不到则想dns服务器查询　仍查询不到显示？
```bash
uos@uos-PC ~/Desktop> arp -a
? (10.10.77.206) at 00:e0:70:c4:64:ef [ether] on eno1
? (10.10.77.239) at f4:b5:20:2e:9b:c7 [ether] on eno1
? (10.10.77.209) at 00:0b:2f:1b:7f:fb [ether] on eno1
? (10.10.77.74) at f4:b5:20:1e:ef:49 [ether] on eno1
? (10.10.77.126) at 1c:69:7a:92:b8:47 [ether] on eno1
? (10.10.77.129) at 8c:8c:aa:1c:35:79 [ether] on eno1
hn.kd.dhcp (61.54.25.98) at <incomplete> on virbr0
? (10.10.77.68) at 1c:69:7a:92:b8:c1 [ether] on eno1
? (10.10.77.222) at 00:e0:70:c4:66:9c [ether] on eno1
? (10.10.77.123) at f4:b5:20:1e:ef:68 [ether] on eno1
? (10.10.77.175) at 00:e0:70:c4:63:8f [ether] on eno1
hn.kd.dhcp (61.54.25.98) at <incomplete> on vnet0
? (10.10.77.120) at f4:b5:20:24:5f:a2 [ether] on eno1
? (10.10.77.183) at 00:23:9e:06:2f:ea [ether] on eno1
? (10.10.77.172) at f4:b5:20:24:63:67 [ether] on eno1
? (10.10.77.241) at 34:97:f6:31:a9:e7 [ether] on eno1
? (10.10.77.37) at 00:e0:70:c4:67:ff [ether] on eno1
? (10.10.77.73) at f4:b5:20:24:63:63 [ether] on eno1
? (10.10.77.246) at 34:b2:0a:de:ad:f6 [ether] on eno1
? (10.10.77.45) at a8:a1:59:2e:a8:f6 [ether] on eno1
? (10.10.77.114) at f4:b5:20:1e:ec:ba [ether] on eno1
? (192.168.122.13) at <incomplete> on virbr0
? (10.10.77.169) at 8c:8c:aa:1c:50:47 [ether] on eno1
? (10.10.77.1) at a4:fa:76:73:9c:01 [ether] on eno1
? (10.10.77.89) at f4:b5:20:24:60:1d [ether] on eno1
? (10.10.77.207) at 00:e0:70:c4:bd:57 [ether] on eno1
? (10.10.77.218) at f4:b5:20:24:5f:68 [ether] on eno1
? (10.10.77.50) at f4:b5:20:24:5f:69 [ether] on eno1
uostest (10.10.77.135) at 00:14:4a:d5:4c:62 [ether] PERM on eno1
? (10.10.77.223) at 1c:69:7a:92:be:23 [ether] on eno1
? (10.10.77.58) at a8:a1:59:2e:a9:00 [ether] on eno1
? (10.10.77.132) at 00:2b:67:ca:8e:63 [ether] on eno1
? (10.10.77.30) at b8:c3:85:47:b8:0f [ether] on eno1
? (10.10.77.63) at 00:e0:70:c4:5d:06 [ether] on eno1
? (10.10.77.33) at 00:e0:70:db:4f:ae [ether] on eno1
? (10.10.77.99) at a8:a1:59:2e:a9:6b [ether] on eno1

```
