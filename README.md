# IoT-Seminar

## Home Assistant

### Home Assistant installation
**Requirements:**
- Raspberry Pi 4
- min. 8GB micro SD Card

**Installation:**
1. Download [Raspberry Pi Imager](https://www.raspberrypi.com/software/).
2. Choose the your Raspberry Pi Device and choose `Operating System -> Other specific-purpose OS -> Home Assistant and Home Automation -> Home Assistant -> Home Assistant OS 14.1`.   
![image](https://github.com/user-attachments/assets/6e625f45-b186-4a00-a16a-40fd9f2efff0)
3. After it is finished you can place the SD card into the Raspberry Pi and boot it up.
4. You can access the Home Assistant dashboard by typing in `http://homeassistant.local:8123` in your web browser. If you know the IP address, you can also access it with `http://YOUR_HA_IP:8123`.
![image](https://github.com/user-attachments/assets/3d479bb3-97cf-4f1f-8205-e0bf9e3926fa)

  

### Restore Home Assistant Backup
There are two ways to restore Home Assistant backup. The first one is by doing it from the beggining where the Home Assistant just installed. The second one is after you create an account. You can choose whatever needed.
**First option:**
1. Here you can create a new account or restore it directly from the backup file.
2. If you choose restore backup, chose the backup file that you downloaded from this repo and choose `Full backup` to restore.
![image](https://github.com/user-attachments/assets/b8f18bb2-1ac8-40c1-997f-570d4bf63156)

**Second option:**
1. Download the Home Assistant backup file from this repo.
2. In Home Assistant Dashboard, go to `Settings -> System -> Backups`. Here, click on the three dots icon at the upper right side and click on `Upload backup`. 
  ![image](https://github.com/user-attachments/assets/5a9defa1-7e33-49e7-9f1b-3541d9b7df43)
  ![image](https://github.com/user-attachments/assets/356f7584-7028-4edf-b78d-8093b6d5ffcd)
3. Choose the file that you are downloaded from this repo. Choose Full backup and Restore.
   ![image](https://github.com/user-attachments/assets/53be26a2-6ce4-4513-a2f5-c43d37a7e5a8)
4. After it is succesfully restored, change the IP address and the Hostname of the device in `Settings -> System -> Network`. If you **cannot access** the device, type in `http://mxr-lab-1.local:8123` in your web browser.

## Arduino
Give description here
