firewall-cmd --add-port "xxx/tcp"
firewall-cmd --remove
firewall-cmd --list-all
hostnamectl set-hostname

sestatus
useradd, groupadd, usermod (-a -G)

/etc/lighttpd/lighttpd.conf
/etc/lighttpd/modules.conf
/etc/lighttpd/conf.d/fastcgi.conf

/etc/php-fpm.d/www.conf

/var/www/lighttpd/info.php
/var/www/lighttpd/database42

/usr/local/bin/scripts/monitoring.sh
@reboot /usr/local/bin/scripts/monitoring.sh