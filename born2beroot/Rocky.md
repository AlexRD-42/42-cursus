# Basic
- Basic differences between Rocky and Debian
- What SELinux and DNF is
____
Debian is more focused on open source users while rocky is aimed at enterprises and is controlled by red hat. Rocky has a focus on security and enterprise compatibility. They use different package managers (debian uses .deb with APT package manager, and rocky uses .rpm with DNF package manager or RPM). Rocky also is server focused, minimal install by default. 

DNF: Dandified YUM
SELINUX and APParmor are both linux security modules (LSMs) and provide mandatory access control (MAC). MAC (not to be confused with a mac address) is similar to windows UAC in the sense that it restricts what a program can or cannot do, but unlike UAC it requires no user prompting. LSMs enforce mandatory security policies at the system level, aka security priviliges.

In short, SELinux and APParmor really are just LSMs (linux security modules) that enforce security privileges to applications

# Partitions
LVMs (logical volume manager) manages disk storage and gives you more flexibility with resizing. They abtract physical disks and organize into volume groups, and allows you to have partitions that occupy dynamic disk space. 
-- ASK SOMEONE FOR MORE INFO ON FILE SYSTEMS

## User accounts
- adeimlin user belonging to sudo and user42 group
password policy must be followed

- Create a new user:
	Assign a password of your choice
	Must follow password policy (and block invalid attempts)
- Create a new group called evaluating
	Check that the user belongs to evaluating group
- Hostname of the machine must be adeimlin42
	Change the hostname to a login of yours
	Reboot machine, changes must have stuck
- How to display the partitions on the VM and compare output
- Verify that SUDO is installed
	Must add new user to sudo group
	Var/log/sudo must exist
___
lsblk probably?
hostnamectl set-hostname

/etc/login.defs for expiry date
/etc/security/pwquality.conf for general rules
/etc/pam.d/system-auth
/etc/pam.d/password-auth

# Strong Password Policy
- Password must expire every 30 days, min days before modification of password is 2 days, user has to receive a warning 7 days before their password expires
- Password must at least 10 characters long: 
	Upper, Lower and number
	No 3 consecutive identical characters
	No username inside
	(NOT ROOT) At least 7 characters not equal to the former password

# Sudo authentication
- Maximum of 3 attempts
- Message shown if an error due to wrong password
- Each sudo action has to be archived, both inputs and outputs (/var/log/sudo)
- TTY mode enabled
- Paths used by sudo must be restricted. Ex:
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

___
TTY (teletypewriter mode): using CLI od LINUX

# Firewall, SSH and Ports
Verify that firewalld is running, ports 4242 are open, add 8080 port
List active rules to see if it has been added, and then delete this rule
Verify that SSH is running, and it only uses port 4242
SSH cannot have root access
Connect through SSH to the new user created (key or simple password)
___


Default ports used by ssh is 22, but you will change this.

# Script
Cron that displays every 10 minutes then every minute
Ensure script does not run at server launch, without modifying the script
Verify that script still exists and has not been modified

Bash script called monitoring.sh, that every 10 minutes shows this info on all terminals:
The architecture of your operating system and its kernel version.

• The number of physical processors.
• The number of virtual processors.
• The current available RAM on your server and its utilization rate as a percentage.
• The current available storage on your server and its utilization rate as a percentage.
• The current utilization rate of your processors as a percentage.
• The date and time of the last reboot.
• Whether LVM is active or not.
• The number of active connections.
• The number of users using the server.
• The IPv4 address of your server and its MAC (Media Access Control) address.
• The number of commands executed with the sudo program

# Bonus
Wordpress with services:  lighttpd, MariaDB, and PHP
Free choice service (not NGINX and apache2)
