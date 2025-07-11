#python -m venv myenv
#. myenv/bin/activate
#sudo nano /lib/systemd/system/bluetooth.service
#sudo nano /etc/bluetooth/main.conf

#bluetotth commands:
bluetoothctl 
discoverable on
advertise on
menu advertise
appearance 961 #keyboard
back


#from bluepy.btle import Peripheral, UUID, Characteristic, Service ARE YOU KIDDING ME ANOTHER CLIENT ORIENTED LIBRARY!!!!!!

first thing to do tomorrow is to watch that python bluetooth video I bookmarked on chrome

#import bluetooth --> maybe the next attempt
#bumble??

class HIDPeripheral(Peripheral):
	def __init__(self):
		Peripheral.__init__(self)
		self.hid_service = Service(UUID("1812"))	#HID Service
		self.report_char = Characteristic(UUID("2A4D"), properties=Characteristic.PROP_NOTIFY)
		self.hid_service.addCharacteristic(self.report_char)
		self.addService(self.hid_service)
		print("HID device ready")
		
hid_device = HIDPeripheral();		01111111111111111111111111111/