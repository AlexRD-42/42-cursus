1) Learn about the layers of abstraction for internet protocols
HTTP -> TCP -> IP -> Ethernet
Wireshark, OSI Model

symbols, the encoding at the physical level
data link (2), MAC addresses, switches, ethernet, broadcast
network (3), IP addresses, routing tables, ARP, broadcast, subnets, ICMP, etc
transport (4), TCP, UDP

NAT, SSH, Ports, MAC, FTP, DNS, Firewalls, NTP
PPPOE, DSL, Bluetooth, MTU, DHCP
Packets, WebRTC

BSSID vs SSID
HTTP  vs HTTPS
TCP   vs UDP
Proxy vs VPN
HWFW  vs Software Firewall

How each device plays a role in this abstraction:
Modem, Router, Access Points, Ad-Hoc, etc

Encapsulation/Decapsulation, QOS

2) File systems
Learn about the significance of file systems, like FAT32/NTFS/EXT4
Journalling, checksums, self-healing, bit-rot detection
Raid levels, LVM, thin-provisioning, snapshots
SSD: Trim, wear-leveling, over-provisioning
Encrypted partitions and why

Difference between server hardware and user hardware

3) Password Policy
How to choose a strong password
Why it is important to have a strong password (review salted hash tables and decryption)
Wi-Fi security (WPA)
Entropy math, Key stretching and hashing
Password entropy, multiple rounds of salting
SHA-256
Argon-2id and GPU resistant
Hashing (collisions) and encryption

symmetric means the same key both decrypts and encrypts

asymmetric means you have 1 key, a public key which can only encrypt and verify signatures, and a private key that can only decrypt and sign

4) Grep
Learn GREP properly and not just copy paste

5) Curiosities
Why is TOR good for privacy
And why not use it with a VPN
Hidden onion services
Daemons
Warowl video on netcode
nftables, curl, DDOS, domains and filters list for adblocks
https://www.riverandsoftware.com/p/programming-as-theory-building-peter-naur
https://gist.github.com/onlurking/fc5c81d18cfce9ff81bc968a7f342fb1
https://wiki.archlinux.org/title/File_systems
https://www.cyber.gc.ca/en/guidance/best-practices-passphrases-and-passwords-itsap30032
Cisco CCNA 200-301

Thus, again, the program text and its documentation has proved insufficient as a carrier of some of the most important design ideas.

Interaction vs Abstraction: Managed copy and paste
Up and Down the ladder of abstraction Bret Victor