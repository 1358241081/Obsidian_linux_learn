## PedDevice

### Data Structures

[_PedCHSGeometry](https://www.gnu.org/software/parted/api/struct__PedCHSGeometry.html)

A cylinder-head-sector "old-style" geometry. [More...](https://www.gnu.org/software/parted/api/struct__PedCHSGeometry.html#_details)  

[_PedDevice](https://www.gnu.org/software/parted/api/struct__PedDevice.html)
A block device - for example, /dev/hda, not /dev/hda3.
块设备 - 例如，/dev/hda，而不是 /dev/hda3。 [More...](https://www.gnu.org/software/parted/api/struct__PedDevice.html#_details)  

[_PedDeviceArchOps](https://www.gnu.org/software/parted/api/struct__PedDeviceArchOps.html)

List of functions implementing architecture-specific operations. 
实现特定于架构的操作的函数列表。
[More...](https://www.gnu.org/software/parted/api/struct__PedDeviceArchOps.html#_details)



### funclist
1.  当[调用 ped_device_probe_all() 时](https://www.gnu.org/software/parted/api/group__PedDevice.html#g20c2f25799a9b6a8f491251f7d8a7f49 "尝试检测所有设备。")，libparted 会尝试检测所有设备。它构造了一个可以使用[ped_device_get_next()](https://www.gnu.org/software/parted/api/group__PedDevice.html#ga2fd6c1e89622940d0a880d0e9391cb2 "返回 ped_device_probe_all() 检测到的下一个设备，或调用...")访问的列表。

如果要使用不在列表中的设备，请使用[ped_device_get()](https://www.gnu.org/software/parted/api/group__PedDevice.html#g6b98cceb42641728ce5ec0ddbca98493 "获取设备 ")。此外，可能有特定于操作系统的构造函数，用于从文件描述符、存储等创建设备。例如，ped_device_new_from_store()。



2.[PedDevice](https://www.gnu.org/software/parted/api/struct__PedDevice.html) * ped_device_get_next(const [PedDevice](https://www.gnu.org/software/parted/api/struct__PedDevice.html) * _dev_) 

Returns the next device that was detected by [ped_device_probe_all()](https://www.gnu.org/software/parted/api/group__PedDevice.html#g20c2f25799a9b6a8f491251f7d8a7f49 "Attempts to detect all devices."), or calls to [ped_device_get_next()](https://www.gnu.org/software/parted/api/group__PedDevice.html#ga2fd6c1e89622940d0a880d0e9391cb2 "Returns the next device that was detected by ped_device_probe_all(), or calls to...").

If dev is NULL, returns the first device.

**Returns:**

NULL if dev is the last device.