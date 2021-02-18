# Drive Selector
# Description
The drive selector gives an Array, that includes all mounted drives on your computer.

## Windows 
On Windows the tool looks for all logical disks with a name ``(C:, D:, ...)``, drives that are not mounted would not be listed in the array.
## Linux
On Linux the tool looks in the ``/mnt`` folder, because on Linux it is normal to mount USB-Drives etc. to ``/mnt/xyz``

## Example Content of the Array
### Windows
Index| Content
-----|------
0   | C
1   | D
2   | X

### Linux
Index| Content
-----|------
0   | /mnt/usb-a
1   | /mnt/c
2   | /mnt/mySecretDrive

# HowToUse
The best way to see how the driveSelector is working, look at my [driveSelectorTests](https://github.com/LukasLJL/CryptTool/blob/master/tests/driveSelectorTests.c) that I wrote.

Detailed description how to use the drive selector:
1. You need to get the number of Drives that are mounted on your computer, just use ``getNumberOfDrives()``.
2. Than you can use ``getAllDrives`` and provide an 2-Dim Array, to get all Drives. Provide the 2-Dim Array by reference.
3. Now you have a 2-Dim Array which includes all Drives on the Computer.
4. If you want, you can use the ``getMasterKeyPath`` function to get the Path to the encryption/decryption key.
   The functions needs to Values, 1. The Drive where the Key is stored and 2. A reference to a "String", where the Path should be saved.


