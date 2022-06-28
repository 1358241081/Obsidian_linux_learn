```toc
title: "## udev" 
```

## 参考链接：
1. udev 中文手册 <http://www.jinbuguo.com/systemd/udev.html>译者：**[金步国](http://www.jinbuguo.com/)**


## udev 描述
__为什么需要udev的存在：__
>内核通常仅根据设备被发现的先后顺序给设备文件命名，因此___很难___在设备文件与物理硬件之间建立___稳定的对应关系___。
>而根据设备的___物理属性或配置特征___创建有意义的符号链接名称或网络接口名称，就可以在物理设备与设备文件之间___建立稳定的对应关系___。



udev能够处理设备事件、管理设备文件的权限、在/dev目录下创建额外的符号链接、重命名网络接口等。

udev守护进程([systemd-udevd.service(8)](http://www.jinbuguo.com/systemd/systemd-udevd.service.html#))从内核接收设备的插入，拔出，改变状态等事件，并根据这些事件的各种属性，到规则库中进行匹配，以确定触发事件的设备。被匹配成功的规则有可能提供-

## udev规则


## 配置文件

## 相关命令
### udevadm
```bash
liuwh@liuwh-PC ~/Desktop> udevadm --help 
udevadm [--help] [--version] [--debug] COMMAND [COMMAND OPTIONS]

Send control commands or test the device manager.

Commands:
  info          Query sysfs or the udev database
  trigger       Request events from the kernel
  settle        Wait for pending udev events
  control       Control the udev daemon
  monitor       Listen to kernel and udev events
  test          Test an event run
  test-builtin  Test a built-in command

See the udevadm(8) man page for details.
```
